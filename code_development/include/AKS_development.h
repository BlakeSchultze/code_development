#include "code_development.h"
//#include "pCT_development.h"
#include <algorithm>    // std::transform
#include <array>
#include <chrono>		// chronology: system_clock::now().time_since_epoch().count(), duration, duration_cast
#include <cmath>
#include <cstdarg>		// variable arguments: va_list, va_arg, va_start, va_end, va_copy
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
#include <utility>		// for std::move
#include <vector>

#ifdef _M_IX86

#define umulrem(z, x, y, m)	\
__asm	mov		eax, x	\
__asm	mul		y	\
__asm	div		m	\
__asm	mov		z, edx

#define umuladdrem(z, x, y, a, m)	\
__asm	mov		eax, x	\
__asm	mul		y	\
__asm	add		eax, a	\
__asm	adc		edx, 0	\
__asm	div		m	\
__asm	mov		z, edx

#else

#ifdef _MSC_VER
typedef unsigned __int64	Tu64;
#else
typedef unsigned long long	Tu64;
#endif

#define umulrem(z, x, y, m)	\
	{	\
	z = (unsigned int)(x * (Tu64)y % m);	\
	}

#define umuladdrem(z, x, y, a, m)	\
	{	\
	z = (unsigned int)((x * (Tu64)y + a) % m);	\
	}

#endif

static bool IsPrime(unsigned int n);
static unsigned int LargestPrimeFactor(unsigned int n);
static unsigned int Powm(unsigned int n, unsigned int e, unsigned int m);
static unsigned int Inv(unsigned int n, unsigned int m);

extern void exit_program();
extern void exit_program_if( bool early_exit);
extern void exit_program_if( char* exit_statement, char continue_character);
extern bool exit_prompt( char* exit_statement, char continue_character);
extern void AKS_development(bool);