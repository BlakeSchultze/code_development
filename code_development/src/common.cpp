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
