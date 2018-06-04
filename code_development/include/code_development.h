#pragma once
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/******************************************************************************* Header for pCT reconstruction program *******************************************************************************/
/*****************************************************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************************************************/
#include <algorithm>    // std::transform
#include <array>
#include <chrono>		// chronology: system_clock::now().time_since_epoch().count(), duration, duration_cast
#include <cmath>
#include <cstdarg>		// variable arguments: va_list, va_arg, va_start, va_end, va_copy
#include <cstddef>		// offsetof
#include <cstdio>		// printf, sprintf,  
#include <cstdlib>		// standard library: rand, srand
#include <cstring>
#include <ctime>		// clock(), time() 
#include <ctype.h>
#include <fstream>
#include <functional>	// std::multiplies, std::plus, std::function, std::negate
#include <iostream>
#include <limits>		// Numeric limits of fundamental data types
#include <map>			// Mapping provides ability to access an element's mapped value using the element's unique key value identifier 
#include <memory>
#include <new>			// dynamic memory allocation/destruction
#include <numeric>		// inner_product, partial_sum, adjacent_difference, accumulate
#include <omp.h>		// OpenMP
#include <random>		// uniform_int_distribution, uniform_real_distribution, bernoulli_distribution, binomial_distribution, geometric_distribution
#include <sstream>		// string stream
#include <stdexcept>
#include <string>
#include "sys/types.h"	// stat f
#include "sys/stat.h"	// stat functions
#include <typeinfo>		//operator typeid
#include <unordered_map>//std::unordered_map
#include <utility>		// for std::move
#include <vector>

using namespace std;
using std::cout;
using std::endl;
using std::chrono::system_clock;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned int UINT;
typedef unsigned int uint;
typedef void (*TEST_FUNCTION)(void); // function pointer type
//#define PAIR_CONTROL
//#define TUPLE_CONTROL
#ifdef TUPLE_CONTROL
	typedef std::tuple<TEST_FUNCTION, bool> TEST_CONTROL;
#else
	typedef std::pair<TEST_FUNCTION, bool> TEST_CONTROL;
#endif
typedef std::unordered_map<std::string, TEST_CONTROL> TEST_CONTROL_MAP;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
extern TEST_CONTROL			test_controls;
extern TEST_CONTROL_MAP		test_control_map;
extern const bool			pCT_test;
	extern const bool		pCT_printing_test;
	extern const bool		preprocessing_test;
	extern const bool		pCT_general_test;
	extern const bool		pCT_stringops_test;
	extern const bool		TVS_beta_sequence_test;
	extern const bool		TVS_ell_assign_test;
	extern const bool		block_ordering_test;
	extern const bool		slice_merging_test;
	extern const bool		TV_CSV_to_TXT_test;
extern const bool			AKS_test;
extern const bool			walker_test;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#define ON						(0==0)									// [T/F] Definition of boolean "ON" as equivalent to 'true'
#define OFF						(!ON)									// [T/F] Definition of boolean "OFF" as equivalent to 'false' (technically 'not true')
#define START					true									// [T/F] Used as an alias for true for starting timer
#define STOP					false									// [T/F] Used as an alias for false for stopping timer
#define pCT						"pCT"
#define AKS						"AKS"
#define walker					"walker"
#define pCT_preprocessing		"pCT_preprocessing"
#define pCT_general				"pCT_general"
#define pCT_stringops			"pCT_stringops"
#define pCT_printing			"pCT_printing"
#define TVS_beta_sequence		"TVS_beta_sequence"
#define TVS_ell_assign			"TVS_ell_assign"
#define pCT_block_ordering		"pCT_block_ordering"
#define pCT_slice_merging		"pCT_slice_merging"
#define TV_CSV_to_TXT			"TV_CSV_to_TXT"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
extern void exit_program();
extern void exit_program_if( bool early_exit);
extern void exit_program_if( char* exit_statement, char continue_character);
extern bool exit_prompt( char* exit_statement, char continue_character);
extern void test_routine( void (*TEST_FUNCTION)(), bool );
extern void init_test_control();
extern void test_of(const std::string);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Project test routine control
extern void pCT_development();
extern void AKS_development();
extern void walker_development();
// Project test subtest routine control
extern void preprocessing_testing();
extern void pCT_general_testing();
extern void pCT_stringops_testing();
extern void pCT_printing_testing();
extern void TVS_beta_sequence_testing();
extern void TVS_ell_assign_testing();
extern void block_ordering_testing();
extern void slice_merging_testing();
extern void TV_measurements_testing();

