#include "../include/code_development.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
TEST_CONTROL		test_controls;
TEST_CONTROL_MAP	test_control_map;
#ifdef PAIR_CONTROL
	TEST_FUNCTION get_test_function(TEST_CONTROL test_control) {return test_control.first; }
	bool get_test_control(TEST_CONTROL test_control) { return test_control.second; }
#else
	TEST_FUNCTION get_test_function(TEST_CONTROL test_control) {return std::get<0>(test_control); }
	bool get_test_control(TEST_CONTROL test_control) { return std::get<1>(test_control); }
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//std::string exec(const char* cmd)
//{
//    std::array<char, 128> buffer;
//    std::string result;
//    std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
//    if (!pipe) throw std::runtime_error("_popen() failed!");
//    while (!feof(pipe.get())) {
//        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
//            result += buffer.data();
//    }
//    return result;
//}
std::string exec(const char* system_command)
{
	#if defined(_WIN32) || defined(_WIN64)
		FILE* pipe = _popen(system_command, "r");
    #else
		FILE* pipe = popen(system_command, "r");
    #endif

    if (!pipe) return "ERROR";
    char buffer[256];
    std::string result;
    while(!feof(pipe)) {
    	if(fgets(buffer, 256, pipe) != NULL)
    		result += buffer;
    }
	#if defined(_WIN32) || defined(_WIN64)
		 _pclose(pipe);
    #else
		 pclose(pipe);
    #endif

    return result;
}
/*template<typename T> std::stringstream  ls (T directory)
{
    #if defined(_WIN32) || defined(_WIN64)
		sprintf( __system_command, "%s %s", __ls_cmd_win, std::string(directory).c_str());
    #else
		sprintf( __system_command, "%s %s", __ls_cmd_linux, std::string(directory).c_str()));
   #endif
	return std::stringstream(exec(__system_command));
}	*/
void test_routine( void (*TEST_FUNCTION)(), bool testing_on){ if(testing_on){ (*TEST_FUNCTION)(); }}
void init_test_control()
{
	// Project test routine control
	test_control_map.emplace("pCT", TEST_CONTROL(pCT_development, pCT_test));
	test_control_map.emplace("AKS", TEST_CONTROL(AKS_development, AKS_test));
	test_control_map.emplace("walker", TEST_CONTROL(walker_development, walker_test));
	// Project test subtest routine control
	test_control_map.emplace("pCT_preprocessing", TEST_CONTROL(preprocessing_testing, preprocessing_test));
	test_control_map.emplace("pCT_general", TEST_CONTROL(pCT_general_testing, pCT_general_test));
	test_control_map.emplace("pCT_stringops", TEST_CONTROL(pCT_stringops_testing, pCT_stringops_test));
	test_control_map.emplace("pCT_printing", TEST_CONTROL(pCT_printing_testing, pCT_printing_test));
	test_control_map.emplace("TVS_beta_sequence", TEST_CONTROL(TVS_beta_sequence_testing, TVS_beta_sequence_test));
	test_control_map.emplace("TVS_ell_assign", TEST_CONTROL(TVS_ell_assign_testing, TVS_ell_assign_test));
	test_control_map.emplace("pCT_block_ordering", TEST_CONTROL(block_ordering_testing, block_ordering_test));
	test_control_map.emplace("pCT_slice_merging", TEST_CONTROL(slice_merging_testing, slice_merging_test));
	test_control_map.emplace("TV_CSV_to_TXT", TEST_CONTROL(TV_measurements_testing, TV_CSV_to_TXT_test));
}
void test_of(const std::string test_alias)
{
	TEST_CONTROL_MAP::const_iterator map = test_control_map.find(test_alias);
	if ( map == test_control_map.end() )
		std::cout << "ERROR: Undefined test routine requested.";
	else
	{
		TEST_CONTROL test_control = map->second;
		TEST_FUNCTION test_function = get_test_function(test_control);
		bool testing_on = get_test_control(test_control);
		test_routine( test_function, testing_on);
	}
}
