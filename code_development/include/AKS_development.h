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

//class CPolyMod
//{
//protected:
//	// (mod x^r - 1, n)
//	const unsigned int m_r;
//	const unsigned int m_n;
//	unsigned int m_deg;
//	unsigned int * mp_a;
//
//private:
//	CPolyMod():m_r(0), m_n(0) { mp_a = NULL; };
//
//public:
//	// default value is x
//	CPolyMod(unsigned int r, unsigned int n)
//		: m_r(r), m_n(n)
//	{
//		m_deg = 1;
//		mp_a = new unsigned int [2];
//		mp_a[0] = 0; mp_a[1] = 1;
//	}
//
//	CPolyMod(const CPolyMod & p)
//		: m_r(p.m_r), m_n(p.m_n)
//	{
//		m_deg = p.m_deg;
//		mp_a = new unsigned int [p.m_deg + 1];
//		unsigned int i;
//		for (i = 0; i <= p.m_deg; ++i)
//			mp_a[i] = p.mp_a[i];
//	}
//
//	virtual ~CPolyMod()
//	{
//		if (mp_a != NULL)
//			delete [] mp_a;
//	}
//
//private:
//	void _polySquare()
//	{
//		const unsigned int deg = m_deg;
//		const unsigned int n = m_n;
//		const unsigned int * const p_a = mp_a;
//
//		const unsigned int degr = deg + deg;
//		unsigned int * const p_ar = new unsigned int [degr + 1];
//		unsigned int k;
//		for (k = 0; k <= degr; ++k)
//			p_ar[k] = 0;
//
//		unsigned int j;
//		for (j = 1; j <= deg; ++j)
//		{
//			const unsigned int x = p_a[j];
//			if (x != 0)
//			{
//				unsigned int i;
//				for (i = 0; i < j; ++i)
//				{
//					const unsigned int y = 2 * p_a[i];
//					unsigned int t = p_ar[j + i];
//					umuladdrem(t, x, y, t, n);
//					p_ar[j + i] = t;
//				}
//			}
//		}
//		unsigned int i;
//		for (i = 0; i <= deg; ++i)
//		{
//			const unsigned int x = p_a[i];
//			unsigned int t = p_ar[2 * i];
//			umuladdrem(t, x, x, t, n);
//			p_ar[2 * i] = t;
//		}
//
//		m_deg = degr;
//		delete [] mp_a;
//		mp_a = p_ar;
//	}
//
//	void _polyMul(const CPolyMod & p)
//	{
//		const unsigned int deg = m_deg;
//		const unsigned int n = m_n;
//		const unsigned int * const p_a = mp_a;
//
//		const unsigned int degr = deg + p.m_deg;
//		unsigned int * const p_ar = new unsigned int [degr + 1];
//		unsigned int k;
//		for (k = 0; k <= degr; ++k)
//			p_ar[k] = 0;
//
//		unsigned int j;
//		for (j = 0; j <= p.m_deg; ++j)
//		{
//			const unsigned int x = p.mp_a[j];
//			if (x != 0)
//			{
//				unsigned int i;
//				for (i = 0; i <= deg; ++i)
//				{
//					const unsigned int y = p_a[i];
//					unsigned int t = p_ar[j + i];
//					umuladdrem(t, x, y, t, n);
//					p_ar[j + i] = t;
//				}
//			}
//		}
//
//		m_deg = degr;
//		delete [] mp_a;
//		mp_a = p_ar;
//	}
//
//	void _Mod()
//	{
//		unsigned int deg = m_deg;
//		unsigned int * const p_a = mp_a;
//		while (deg >= m_r)
//		{
//			p_a[deg - m_r] += p_a[deg];
//			if (p_a[deg - m_r] >= m_n) p_a[deg - m_r] -= m_n;
//			--deg;
//
//			while (p_a[deg] == 0) --deg;
//		}
//		m_deg = deg;
//	}
//
//	void _Norm()
//	{
//		const unsigned int deg = m_deg;
//		const unsigned int n = m_n;
//		unsigned int * const p_a = mp_a;
//		if (p_a[deg] != 1)
//		{
//			const unsigned int y = Inv(p_a[deg], m_n);
//			unsigned int i;
//			for (i = 0; i <= deg; ++i)
//			{
//				unsigned int t = p_a[i];
//				umulrem(t, t, y, n);
//				p_a[i] = t;
//			}
//		}
//	}
//
//public:
//	CPolyMod & operator = (const CPolyMod & p)
//	{
//		if (&p == this) return *this;
//		m_deg = p.m_deg;
//		delete [] mp_a;
//		mp_a = new unsigned int [p.m_deg + 1];
//		unsigned int i;
//		for (i = 0; i <= p.m_deg; ++i)
//			mp_a[i] = p.mp_a[i];
//		return *this;
//	}
//
//	int operator != (const CPolyMod & p) const
//	{
//		if (m_deg != p.m_deg)
//			return true;
//		unsigned int i;
//		for (i = 0; i <= m_deg; ++i)
//			if (mp_a[i] != p.mp_a[i])
//				return true;
//		return false;
//	}
//
//	CPolyMod & operator += (unsigned int i)
//	{
//		const unsigned int t = i % m_n;
//		mp_a[0] += t;
//		if (mp_a[0] >= m_n) mp_a[0] -= m_n;
//		return *this;
//	}
//
//	CPolyMod & operator -= (unsigned int i)
//	{
//		const unsigned int t = m_n - i % m_n;
//		mp_a[0] += t;
//		if (mp_a[0] >= m_n) mp_a[0] -= m_n;
//		return *this;
//	}
//
//	CPolyMod Pow(unsigned int e) const
//	{
//		unsigned int er = 1;
//		unsigned int j;
//		for (j = e; j != 1; j /= 2)
//		{
//			er = 2 * er + (j % 2);
//		}
//
//		CPolyMod t(*this);
//		unsigned int i;
//		for (i = er; i != 1; i /= 2)
//		{
//			t._polySquare();
//			t._Mod();
//			if (i % 2 != 0)
//			{
//				t._polyMul(*this);
//				t._Mod();
//			}
//		}
//		t._Norm();
//		return t;
//	}
//};
extern void exit_program();
extern void exit_program_if( bool early_exit);
extern void exit_program_if( char* exit_statement, char continue_character);
extern bool exit_prompt( char* exit_statement, char continue_character);