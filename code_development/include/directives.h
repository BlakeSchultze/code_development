///*************************************************************************************************************************//
///*-----------------------------------------------------------------------------------------------------------------------*//
///*----- directives.h: Defines preprocessor directives (#include/#define), namespaces, and typedef/enum definitions ------*//
///*-----------------------------------------------------------------------------------------------------------------------*//
///*************************************************************************************************************************//
//------------------------------------------------------------------------------------------------//
//--------------------------------- Specify libraries to #include --------------------------------//
//------------------------------------------------------------------------------------------------//
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
#include <type_traits>	//operator typeid
#include <unordered_map>//std::unordered_map
#include <utility>		// for std::move
#include <vector>
//#include <getopt.h>
//------------------------------------------------------------------------------------------------//
//----------------------------- OS/compiler dependent library inclusion --------------------------//
//------------------------------------------------------------------------------------------------//
#if defined(_WIN32) || defined(_WIN64)
	//#include "Shlwapi.h"
	//#include <windows.h>
	#include "getopt.h"
#else
	#include <initializer_list>
    #include <getopt.h>
	#include <unistd.h>

#endif
//------------------------------------------------------------------------------------------------//
//------------------------- Define namespace usage and define typedef/enum -----------------------//
//------------------------------------------------------------------------------------------------//
#ifndef GLOBALS
#define GLOBALS
	//using namespace std;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::chrono::system_clock;
    typedef unsigned long long ULL;
    typedef unsigned long long ull;
    typedef unsigned int UINT;
    typedef unsigned int uint;
    typedef void (*TEST_FUNCTION)(void); // function pointer type
    #ifdef TUPLE_CONTROL
        typedef std::tuple<TEST_FUNCTION, bool> TEST_CONTROL;
    #else
        typedef std::pair<TEST_FUNCTION, bool> TEST_CONTROL;
    #endif
    typedef std::unordered_map<std::string, TEST_CONTROL> TEST_CONTROL_MAP;
    enum OS_ENVIRONMENTS{LINUX, WIN_32, WIN_64, APPLE, ANDROID, AKAROS, NACL, ASMJC, FUSCHIA};
    enum COMPILERS{GCC, MSVC, MINGW32, MINGW32W, MINGW64, CLANG, EMSCRIPTEN};
//    struct configurations;
//    extern configurations parameter_container;
//    extern configurations *configurations_h; //= &parameter_container;
//    extern configurations *configurations_d;
//    typedef std::tuple<configurations, std::string, PARAM_TYPES> PCT_PARAMS;
#endif
//------------------------------------------------------------------------------------------------//
//------------------------------ Detect Operating System environment -----------------------------//
//------------------------------------------------------------------------------------------------//
//Linux and Linux-derived           __linux__
//Android                           __ANDROID__ (implies __linux__)
//Linux (non-Android)               __linux__ && !__ANDROID__
//Darwin (Mac OS X and iOS)         __APPLE__
//Akaros (http://akaros.org)        __ros__
//Windows                           _WIN32
//Windows 64 bit                    _WIN64 (implies _WIN32)
//NaCL                              __native_client__
//AsmJS                             __asmjs__
//Fuschia                           __Fuchsia__
#if defined(__ANDROID__)
    #define ANDROID_ENV
    #define CURRENT_OS
#elseif defined(__linux__) //i.e. __linux__ && !__ANDROID__
	#define LINUX_ENV
#elseif defined(__APPLE__)
	#define APPLE_ENV
#elseif defined(_WIN32) || defined(_WIN64)
    #define WINDOWS_ENV
#elseif defined(__native_client__)
	#define NACL_ENV
#elseif defined(__asmjs__)
	#define ASMJS_ENV
#elseif defined(__ros__)
	#define AKAROS_ENV
#elseif defined(__Fuchsia__)
	#define FUSCHIA_ENV
#else
	#define UNKNOWN_ENV
#endif
#define CURRENT_OS_STR STR()
//------------------------------------------------------------------------------------------------//
//---------------------------------------- Detect compiler ---------------------------------------//
//------------------------------------------------------------------------------------------------//
//Visual Studio         _MSC_VER   _MSC_FULL_VER
//1                         800
//3                         900
//4                         1000
//4                         1020
//5                         1100
//6                         1200
//6 SP6                     1200    12008804
//7                         1300    13009466
//7.1 (2003)                1310    13103077
//8 (2005)                  1400    140050727
//9 (2008)                  1500    150021022
//9 SP1                     1500    150030729
//10 (2010)                 1600    160030319
//10 (2010) SP1             1600    160040219
//11 (2012)                 1700    170050727
//12 (2013)                 1800    180021005
//14 (2015)                 1900    190023026
//14 (2015 Update 1)        1900    190023506
//14 (2015 Update 2)        1900    190023918
//14 (2015 Update 3)        1900    190024210
//15 (2017 Update 1 & 2)    1910    191025017
//15 (2017 Update 3 & 4)    1911
//15 (2017 Update 5)        1912
//gcc                 __GNUC__ (e.g. 5) and __GNUC_MINOR__ (e.g. 1).
//clang               __clang__, __clang_major__, __clang_minor__, __clang_patchlevel__
//emscripten          __EMSCRIPTEN__ (for asm.js and webassembly)
//MinGW (MinGW32)/MinGW-w64 32bit: __MINGW32__, __MINGW32_MAJOR_VERSION and __MINGW32_MINOR_VERSION
//MinGW-w64 64bit     __MINGW64__, __MINGW64_VERSION_MAJOR and __MINGW64_VERSION_MINOR

//#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))
#if defined(__clang__)
    #define CLANG_COMPILER
#elif defined(__GNUC__) || defined(__GNUG__)
    #define GCC_COMPILER
#elif defined(_MSC_VER)
    #define MSVC_COMPILER
#endif // defined
//------------------------------------------------------------------------------------------------//
//---------------------------------- Detect processor architecture -------------------------------//
//------------------------------------------------------------------------------------------------//
//__i386__
//__x86_64__
//__arm__. If defined, you can further check:
//__ARM_ARCH_5T__
//__ARM_ARCH_7A__
//__powerpc64__
//__aarch64__
//#if !(defined __LP64__ || defined __LLP64__) || defined _WIN32 && !defined _WIN64
//	// we are compiling for a 32-bit system
//#else
//	// we are compiling for a 64-bit system
//#endif
//-----------------------------------------------------------------------------------------------------------------//
#define ON						(0==0)									// [T/F] Definition of boolean "ON" as equivalent to 'true'
#define OFF						(!ON)									// [T/F] Definition of boolean "OFF" as equivalent to 'false' (technically 'not true')
#define START					true									// [T/F] Used as an alias for true for starting timer
#define STOP					false									// [T/F] Used as an alias for false for stopping timer
#define pCT						"pCT"
#define AKS						"AKS"
#define walker					"walker"
#define structdefs				"structdefs"
#define pCT_preprocessing		"pCT_preprocessing"
#define pCT_general				"pCT_general"
#define pCT_stringops			"pCT_stringops"
#define pCT_printing			"pCT_printing"
#define TVS_beta_sequence		"TVS_beta_sequence"
#define TVS_ell_assign			"TVS_ell_assign"
#define pCT_block_ordering		"pCT_block_ordering"
#define pCT_slice_merging		"pCT_slice_merging"
#define TV_CSV_to_TXT			"TV_CSV_to_TXT"
//-----------------------------------------------------------------------------------------------------------------//
