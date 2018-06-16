// common.cpp
#include "../include/code_development.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//TEST_CONTROL		test_controls;
//TEST_CONTROL_MAP	test_control_map;
//#define PAIR_CONTROL
#ifdef PAIR_CONTROL
	TEST_FUNCTION get_test_function(TEST_CONTROL test_control) {return test_control.first; }
	bool get_test_control(TEST_CONTROL test_control) { return test_control.second; }
#else
	TEST_FUNCTION get_test_function(TEST_CONTROL test_control) {return std::get<0>(test_control); }
	bool get_test_control(TEST_CONTROL test_control) { return std::get<1>(test_control); }
#endif

#ifndef BOOL_CONTROLS
#define BOOL_CONTROLS
    const bool pCT_test						=	ON;
        const bool pCT_printing_test		=	OFF;
        const bool preprocessing_test		=	OFF;
        const bool pCT_general_test			=	OFF;
        const bool pCT_stringops_test		=	OFF;
        const bool TVS_beta_sequence_test	=	OFF;
        const bool TVS_ell_assign_test		=	OFF;
        const bool block_ordering_test		=	OFF;
        const bool slice_merging_test		=	ON;
        const bool TV_CSV_to_TXT_test		=	OFF;
    const bool AKS_test						=	OFF;
    const bool walker_test					=	OFF;
    const bool structdef_test				=	OFF;
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool fileExists(const std::string& filename)
{
    std::fstream file;
    file.open(filename.c_str(), std::ios_base::out | std::ios_base::in);  // will not create file
    if (file.is_open())
        return true;
    else
        return false;
    return false;
}
bool fileExists2(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
        return true;
    return false;
}
std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
    cout<< "cmd: " <<cmd << endl;
if (!pipe) throw std::runtime_error("_popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
//std::string exec(const char* system_command)
//{
//	#if defined(_WIN32) || defined(_WIN64)
//		FILE* pipe = _popen(system_command, "r");
//    #else
//		FILE* pipe = popen(system_command, "r");
//    #endif
//    cout<< "system_command: " <<system_command << endl;
//
//    if (!pipe) return "ERROR";
//    char buffer[256];
//    std::string result;
//    while(!feof(pipe)) {
//    	if(fgets(buffer, 256, pipe) != NULL)
//    		result += buffer;
//    }
//	#if defined(_WIN32) || defined(_WIN64)
//		 _pclose(pipe);
//    #else
//		 pclose(pipe);
//    #endif
//
//    return result;
//}
void test_routine( void (*TEST_FUNCTION)(), bool testing_on){ if(testing_on){ (*TEST_FUNCTION)(); }}
void init_test_control()
{
	// Project test routine control
	test_control_map.emplace("pCT", TEST_CONTROL(pCT_development, pCT_test));
	test_control_map.emplace("AKS", TEST_CONTROL(AKS_development, AKS_test));
	test_control_map.emplace("walker", TEST_CONTROL(walker_development, walker_test));
	test_control_map.emplace("structdefs", TEST_CONTROL(structdef_testing, structdef_test));

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
