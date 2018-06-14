#include "directives.h"
#include "externs.h"
////#pragma once
////#include "../include/common.h"
///*****************************************************************************************************************************************************************************************************/
///*****************************************************************************************************************************************************************************************************/
///******************************************************************************* Header for pCT reconstruction program *******************************************************************************/
///*****************************************************************************************************************************************************************************************************/
///*****************************************************************************************************************************************************************************************************/
//#include <algorithm>    // std::transform
//#include <array>
//#include <chrono>		// chronology: system_clock::now().time_since_epoch().count(), duration, duration_cast
//#include <cmath>
//#include <cstdarg>		// variable arguments: va_list, va_arg, va_start, va_end, va_copy
//#include <cstddef>		// offsetof
//#include <cstdio>		// printf, sprintf,
//#include <cstdlib>		// standard library: rand, srand
//#include <cstring>
//#include <ctime>		// clock(), time()
//#include <ctype.h>
//#include <fstream>
//#include <functional>	// std::multiplies, std::plus, std::function, std::negate
//#include <iostream>
//#include <limits>		// Numeric limits of fundamental data types
//#include <map>			// Mapping provides ability to access an element's mapped value using the element's unique key value identifier
//#include <memory>
//#include <new>			// dynamic memory allocation/destruction
//#include <numeric>		// inner_product, partial_sum, adjacent_difference, accumulate
//#include <omp.h>		// OpenMP
//#include <random>		// uniform_int_distribution, uniform_real_distribution, bernoulli_distribution, binomial_distribution, geometric_distribution
//#include <sstream>		// string stream
//#include <stdexcept>
//#include <string>
//#include "sys/types.h"	// stat f
//#include "sys/stat.h"	// stat functions
//#include <typeinfo>		//operator typeid
//#include <type_traits>	//operator typeid
//#include <unordered_map>//std::unordered_map
//#include <utility>		// for std::move
//#include <vector>
////	#include <getopt.h>
//////------------------------------------------------------------------------------------------------//
//////------------------------------ Detect Operating System environment -----------------------------//
//////------------------------------------------------------------------------------------------------//
//////enum OS_ENVIRONMENTS{LINUX, WIN32, WIN64, APPLE, ANDROID, AKAROS, NACL, ASMJC, FUSCHIA};
////enum COMPILERS{GCC, MSVC, MINGW32, MINGW32W, MINGW64, CLANG, EMSCRIPTEN};
//////enum PROCESSOR_ARCHITECTURES{};
////------------------------------------------------------------------------------------------------//
////------------------------------ Detect Operating System environment -----------------------------//
////------------------------------------------------------------------------------------------------//
////Linux and Linux-derived           __linux__
////Android                           __ANDROID__ (implies __linux__)
////Linux (non-Android)               __linux__ && !__ANDROID__
////Darwin (Mac OS X and iOS)         __APPLE__
////Akaros (http://akaros.org)        __ros__
////Windows                           _WIN32
////Windows 64 bit                    _WIN64 (implies _WIN32)
////NaCL                              __native_client__
////AsmJS                             __asmjs__
////Fuschia                           __Fuchsia__
//#if defined(__ANDROID__)
//    #define ANDROID_ENV
//    #define CURRENT_OS
//#elseif defined(__linux__) //i.e. __linux__ && !__ANDROID__
//	#define LINUX_ENV
//#elseif defined(__APPLE__)
//	#define APPLE_ENV
//#elseif defined(_WIN32) || defined(_WIN64)
//    #define WINDOWS_ENV
//#elseif defined(__native_client__)
//	#define NACL_ENV
//#elseif defined(__asmjs__)
//	#define ASMJS_ENV
//#elseif defined(__ros__)
//	#define AKAROS_ENV
//#elseif defined(__Fuchsia__)
//	#define FUSCHIA_ENV
//#else
//	#define UNKNOWN_ENV
//#endif
//#define CURRENT_OS_STR STR()
////------------------------------------------------------------------------------------------------//
////---------------------------------------- Detect compiler ---------------------------------------//
////------------------------------------------------------------------------------------------------//
////Visual Studio         _MSC_VER   _MSC_FULL_VER
////1                         800
////3                         900
////4                         1000
////4                         1020
////5                         1100
////6                         1200
////6 SP6                     1200    12008804
////7                         1300    13009466
////7.1 (2003)                1310    13103077
////8 (2005)                  1400    140050727
////9 (2008)                  1500    150021022
////9 SP1                     1500    150030729
////10 (2010)                 1600    160030319
////10 (2010) SP1             1600    160040219
////11 (2012)                 1700    170050727
////12 (2013)                 1800    180021005
////14 (2015)                 1900    190023026
////14 (2015 Update 1)        1900    190023506
////14 (2015 Update 2)        1900    190023918
////14 (2015 Update 3)        1900    190024210
////15 (2017 Update 1 & 2)    1910    191025017
////15 (2017 Update 3 & 4)    1911
////15 (2017 Update 5)        1912
////gcc                 __GNUC__ (e.g. 5) and __GNUC_MINOR__ (e.g. 1).
////clang               __clang__, __clang_major__, __clang_minor__, __clang_patchlevel__
////emscripten          __EMSCRIPTEN__ (for asm.js and webassembly)
////MinGW (MinGW32)/MinGW-w64 32bit: __MINGW32__, __MINGW32_MAJOR_VERSION and __MINGW32_MINOR_VERSION
////MinGW-w64 64bit     __MINGW64__, __MINGW64_VERSION_MAJOR and __MINGW64_VERSION_MINOR
//
////#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))
//#if defined(__clang__)
//    #define CLANG_COMPILER
//#elif defined(__GNUC__) || defined(__GNUG__)
//    #define GCC_COMPILER
//#elif defined(_MSC_VER)
//    #define MSVC_COMPILER
//#endif // defined
////------------------------------------------------------------------------------------------------//
////---------------------------------- Detect processor architecture -------------------------------//
////------------------------------------------------------------------------------------------------//
////__i386__
////__x86_64__
////__arm__. If defined, you can further check:
////__ARM_ARCH_5T__
////__ARM_ARCH_7A__
////__powerpc64__
////__aarch64__
////------------------------------------------------------------------------------------------------//
////------------------------------------ OS/compiler dependencies ----------------------------------//
////------------------------------------------------------------------------------------------------//
//#if defined(_WIN32) || defined(_WIN64)
//	//#include "Shlwapi.h"
//	//#include <windows.h>
//	#include "getopt.h"
//#else
//	#include <initializer_list>
//    #include <getopt.h>
//	#include <unistd.h>
//
//#endif
//-----------------------------------------------------------------------------------------------------------------
//#ifndef GLOBALS
//#define GLOBALS
//	//using namespace std;
//    using std::cin;
//    using std::cout;
//    using std::endl;
//    using std::chrono::system_clock;
//    typedef unsigned long long ULL;
//    typedef unsigned long long ull;
//    typedef unsigned int UINT;
//    typedef unsigned int uint;
//    typedef void (*TEST_FUNCTION)(void); // function pointer type
//    #ifdef TUPLE_CONTROL
//        typedef std::tuple<TEST_FUNCTION, bool> TEST_CONTROL;
//    #else
//        typedef std::pair<TEST_FUNCTION, bool> TEST_CONTROL;
//    #endif
//    typedef std::unordered_map<std::string, TEST_CONTROL> TEST_CONTROL_MAP;
////    char __print_statement[512];
////    char __system_command[512];
////    char __ls_cmd_win[] = "dir -/b /a:d";
////    char __ls_cmd_linux[] = "find -maxdepth 1 -type d -printf \"%f\n\"";
////    char __folder[512];
////    char __filename[512];
////    char __csvfile[512];
////    char __textfile[512];
////    int __i = 0;
////    std::ifstream __input_file;
////    std::ofstream __output_file;
////    std::string __termout;
////    std::string		__line__input;
////    std::string __input_value;
////    std::string __string;
////    std::string __outstring;
////    std::stringstream  __line_sstream;
////    std::vector<std::string> strcat_elements;
//#endif
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//#ifndef COMMON_TEM_H
//    #define COMMON_TEM_H
//	template<typename T> std::stringstream  ls (T);
//	template<typename T> std::string stringify(T string_input);
//	template<typename T> char* charify(T string_input);
//    #include "..//src//common.tem"  // Include the implementation
//#endif
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//#ifndef PCT_TEM_H  // Prevent duplicate definition
//#define PCT_TEM_H
//	template<typename T> std::string echo_cmd(T);
//	template<typename T> std::string colored_text(T, const char*, const char*, const char* );
//	template<typename T> std::string echo_statement(T, const char*, const char*, const char* );
//	template<typename T> void print_colored_text(T, const char*, const char*, const char* );
//	template<typename T> void print_labeled_value(const char*, T, const char*, const char*, const char*, const char* );
//    #include "..//src//pCT_development.tem"  // Include the implementation
//#endif
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//extern TEST_CONTROL			test_controls;
//extern TEST_CONTROL_MAP		test_control_map;
//extern const bool			pCT_test;
//	extern const bool		pCT_printing_test;
//	extern const bool		preprocessing_test;
//	extern const bool		pCT_general_test;
//	extern const bool		pCT_stringops_test;
//	extern const bool		TVS_beta_sequence_test;
//	extern const bool		TVS_ell_assign_test;
//	extern const bool		block_ordering_test;
//	extern const bool		slice_merging_test;
//	extern const bool		TV_CSV_to_TXT_test;
//extern const bool			AKS_test;
//extern const bool			walker_test;
//extern const bool           structdef_test;
//#pragma once
//#ifndef BOOL_CONTROLS
//#define BOOL_CONTROLS
//const bool pCT_test						=	ON;
//	const bool pCT_printing_test		=	OFF;
//	const bool preprocessing_test		=	OFF;
//	const bool pCT_general_test			=	OFF;
//	const bool pCT_stringops_test		=	OFF;
//	const bool TVS_beta_sequence_test	=	OFF;
//	const bool TVS_ell_assign_test		=	OFF;
//	const bool block_ordering_test		=	OFF;
//	const bool slice_merging_test		=	ON;
//	const bool TV_CSV_to_TXT_test		=	OFF;
//const bool AKS_test						=	OFF;
//const bool walker_test					=	OFF;
//const bool structdef_test				=	OFF;
//#endif
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//#define ON						(0==0)									// [T/F] Definition of boolean "ON" as equivalent to 'true'
//#define OFF						(!ON)									// [T/F] Definition of boolean "OFF" as equivalent to 'false' (technically 'not true')
//#define START					true									// [T/F] Used as an alias for true for starting timer
//#define STOP					false									// [T/F] Used as an alias for false for stopping timer
//#define pCT						"pCT"
//#define AKS						"AKS"
//#define walker					"walker"
//#define structdefs				"structdefs"
//#define pCT_preprocessing		"pCT_preprocessing"
//#define pCT_general				"pCT_general"
//#define pCT_stringops			"pCT_stringops"
//#define pCT_printing			"pCT_printing"
//#define TVS_beta_sequence		"TVS_beta_sequence"
//#define TVS_ell_assign			"TVS_ell_assign"
//#define pCT_block_ordering		"pCT_block_ordering"
//#define pCT_slice_merging		"pCT_slice_merging"
//#define TV_CSV_to_TXT			"TV_CSV_to_TXT"
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//extern char __print_statement[512];
//extern char __system_command[512];
//extern char __ls_cmd_linux[];
//extern char __ls_cmd_win[];
//extern char __folder[512];
//extern char __filename[512];
//extern char __csvfile[512];
//extern char __textfile[512];
//extern char* __str;
//extern int __i;
//extern std::ifstream __input_file;
//extern std::ofstream __output_file;
//extern std::string __termout;
//extern std::string	__line__input;
//extern std::string __input_value;
//extern std::string __string;
//extern std::string __outstring;
//extern std::stringstream  __line_sstream;
//extern std::vector<std::string> strcat_elements;
//extern const char* C_CONST_CHAR;
//extern const char* CONTINUE_PROMPT;
//extern const char BASH_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
//extern const char WIN_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//extern std::string exec(const char*) ;
//extern void exit_program();
//extern void exit_program_if( bool);
//extern void exit_program_if( const char*, char);
//extern bool exit_prompt( const char*, char);
//extern std::string color_encoding_statement(const char*, const char*, const char* );
//extern std::string change_text_color_cmd(const char*, const char*, const char*, bool);
//extern void change_text_color(const char*, const char*, const char*, bool);
//extern void print_section_separator(const char, const char*, const char*, const char* );
//extern void print_section_header( const char*, const char, const char*, const char*, const char*, const char* );
//extern void print_section_exit( const char*, const char*, const char*, const char*, const char*, const char* );
//extern void print_multiline_bash_results(const char*, const char*, const char*, const char* );
//extern void test_routine( void (*TEST_FUNCTION)(), bool );
//extern void init_test_control();
//extern void test_of(const std::string);
//extern void construct_pCT_params();
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
////------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
////-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//// Project test routine control
//extern void pCT_development();
//extern void AKS_development();
//extern void walker_development();
//extern void structdef_testing();
//
//// Project test subtest routine control
//extern const bool preprocessing_test;
//extern const bool pCT_general_test;
//extern const bool pCT_stringops_test;
//extern const bool pCT_printing_test;
//extern const bool TVS_beta_sequence_test;
//extern const bool TVS_ell_assign_test;
//extern const bool block_ordering_test;
//extern const bool slice_merging_test;
//
//extern void preprocessing_testing();
//extern void pCT_general_testing();
//extern void pCT_stringops_testing();
//extern void pCT_printing_testing();
//extern void TVS_beta_sequence_testing();
//extern void TVS_ell_assign_testing();
//extern void block_ordering_testing();
//extern void slice_merging_testing();
//extern void TV_measurements_testing();
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//class arglist_typed
//{
//    public:
//        template<typename ...Args,
//        typename=std::void_t<std::enable_if_t
//        <std::is_same_v<Args, int>>...>>
//        void operator()(Args ...args){}
//};
//class foo {
//
//public:
//
//    template<typename ...Args,
//         typename=std::void_t<std::enable_if_t
//                      <std::is_same_v<Args, int>>...>>
//    void operator()(Args ...args)
//    {
//    }
//};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//#include "../include/common.h"

