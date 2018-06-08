/*
 * Macro for C99 designated initializer -> C89/90 non-designated initializer
 *
 * Tested.  Works with MSVC if you undefine HAVE_DESIGNATED_INITIALIZERS.  Cscope also
 * groks this.
 *
 * ("SFINIT" == struct field init, but really, it can be used for array initializers too.)
 */
//#ifdef HAVE_DESIGNATED_INITIALIZERS
//#define SFINIT(f, v) f = v
//#else
//#define SFINIT(f, v) v
//#endif
//
//struct t {
//    char f1;
//    int f2;
//    double f3;
//};
//
//struct t t = {
//    SFINIT(.f1, 'a'),
//    SFINIT(.f2, 42),
//    SFINIT(.f3, 8.13)
//};
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

extern unsigned int tcnt;
#ifndef FIRST_RUN
    #define FIRST_RUN 0
#endif

#ifndef STRUCT_FMT_DEF
    /* One time only definitions */
    #define STRUCT_FMT_DEF
    struct struct_fmt {
        char const *struct_name;
        size_t num_members;
        size_t struct_size;
        size_t packed_size;
        size_t *offsets;
        size_t *sizes;
        char const **types;
        char const **names;
        char const **values;
    };
#endif

/* Error Checking */

#ifndef STRUCT_NAME
    #error "Did not define STRUCT_NAME before including fmtgen.h"
#endif

#ifndef STRUCT_FIELDS
    #error "Did not define STRUCT_FIELDS before including fmtgen.h"
#endif

#define MEMACC st.
#define INCREMENT(A) A++
#define GET_OBJNAME(o) #o
#define OBJ_ACCESS(A,B) A::B
#define DOT_ACCESS(object,member) object.member
#define ARROW_ACCESS(object,member) object->member
#define VARPRINT(A) std::cout << #A << " = " << A << std::endl;

#define STR_NOEXPAND(A) #A
#define STR(A) STR_NOEXPAND(A)

#define CAT_NOEXPAND(A, B) A ## B
#define CAT(A, B) CAT_NOEXPAND(A, B)

#define UNIQUE_NAME_NOEXPAND(A,B) A##_##B
#define UNIQUE_NAME(A,B) UNIQUE_NAME_NOEXPAND(A,B)

#define UNIQUE_NUMBERED_NAME_NOEXPAND(A,B,C) A##_##B##C
#define UNIQUE_NUMBERED_NAME(A,B,C) UNIQUE_NUMBERED_NAME_NOEXPAND(A,B,C)

#define ELEM_BASE(A) STR(CAT(STRUCT_NAME,MEMACC))A
#define ELEM_NOEXPAND(A) ELEM_BASE(A)
#define ELEM(A) ELEM_NOEXPAND(A)
#define ELEM_FUNC(str,member,object) {object.str ## member(object);}//ELEM_FUNC(s=get_,m=pCTb,o=tst)->tst.get_pCTb(tst);

#define ENUM_NAME STRUCT_ENUMS
#define ENUM_VARNAME(A) e##A
#define ENUM_INSTANCE_NAME struct_enum
#define MAP_NAME ENUMS_MAP
#define ENUM_PTR_TYPENAME ENUM_PTR
#define ENUM_PTR_INSTANCE_NAME subenum
#define ENUM_PTR_FNAME subenum_ptr
#define FILL_MAP_FNAME fill_fmap
#define PRINT_FMAP_NAME print_fmap

#define ENUM_ACCESS(A,B) OBJ_ACCESS(A,ENUM_VARNAME(B))
#define ENUM_TYPEDNAME(A) OBJ_ACCESS(A,ENUM_NAME)
#define ENUM_PTR_TYPEDNAME(A) OBJ_ACCESS(A,ENUM_PTR_TYPENAME)
#define ENUM_MAP_TYPEDNAME(A) OBJ_ACCESS(A,MAP_NAME)

#define ENUM_CAST_NOEXPAND(A,B) static_cast<ENUM_TYPEDNAME(A)>(B)
#define ENUM_CAST(A,B) ENUM_CAST_NOEXPAND(A,B)

#define INIT_MAP(A,B) std::map<std::string, A> B;
#define PRINT_ENUM(A,B) VARPRINT(ENUM_TYPEDNAME(A){B})
#define ENUM_INDEX(A,B) ENUM_TYPEDNAME(A) UNIQUE_NUMBERED_NAME(A,ENUM_PTR_INSTANCE_NAME,B) = static_cast<ENUM_TYPEDNAME(A)>(B);
#define ENUM_INDEX_WRAP(A,B) ENUM_INDEX(A,B)

struct STRUCT_NAME
{
    //--------------------------------------------------------------------------------------------------------//
    // Define struct members
    //--------------------------------------------------------------------------------------------------------//
    #define X(L, R) L R;
        STRUCT_FIELDS
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    // Define function for each struct <s,t> member that prints its value
    //      <elem_type> print_<elem_name>(<s,t> g){ return g.<elem_name>; };
    //--------------------------------------------------------------------------------------------------------//
    #define X(L, R) void CAT(print_,R)(STRUCT_NAME g){std::cout << "val = " << g.R << std::endl;};
        STRUCT_FIELDS
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    // Define function for each struct <s,t> member that returns its value
    //      <elem_type> get_<elem_name>(<s,t> g){ return g.<elem_name>; };
    //--------------------------------------------------------------------------------------------------------//
    #define X(L, R) L CAT(get_,R)(STRUCT_NAME g){return g.R;};
        STRUCT_FIELDS
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    // Construct enum, an enum instance, and a std::string-> enum mapping object for struct member lookup
    //      enum STRUCT_ENUMS{ e<mem1>, e<mem2>, ...};
    //      STRUCT_ENUMS struct_enum;
    //      std::map<std::string, STRUCT_ENUMS> ENUMS_MAP;
    //--------------------------------------------------------------------------------------------------------//
    #define X(L, R) ENUM_VARNAME(R),
        enum ENUM_NAME{
        STRUCT_FIELDS \
        X(void,END)
    };
    #undef X
    ENUM_NAME ENUM_INSTANCE_NAME;
    INIT_MAP(ENUM_NAME,MAP_NAME)
    //--------------------------------------------------------------------------------------------------------//
    // Define function to return a variable to access STRUCT_ENUMS member of integer index <i>
    //      <s,t>::STRUCT_ENUMS struct_enum;
    //--------------------------------------------------------------------------------------------------------//
    #define X ENUM_TYPEDNAME(STRUCT_NAME) ENUM_PTR_FNAME(int i){return ENUM_CAST(STRUCT_NAME,i);};
        X
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    // Construct typedef for ENUM_PTR variables
    //      typedef <s,t>::STRUCT_ENUMS ENUM_PTR -> <s,t>::ENUM_PTR;
    //--------------------------------------------------------------------------------------------------------//
    #define X typedef ENUM_TYPEDNAME(STRUCT_NAME) ENUM_PTR_TYPENAME;
        X
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    //      void (*PRINT_FUNCTION)(<s,t>); void (*PRINT_FUNCTION)(<s,t>);
    //--------------------------------------------------------------------------------------------------------//
    #define X typedef void (*PRINT_FUNCTION)(STRUCT_NAME); //typedef void (*ACCESS_FUNCTION)(STRUCT_NAME);
        X
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    //      std::vector<PRINT_FUNCTION> print_fmap; std::vector<ACCESS_FUNCTION> access_fmap;
    //--------------------------------------------------------------------------------------------------------//
    #define X std::vector<PRINT_FUNCTION> PRINT_FMAP_NAME; //std::vector<ACCESS_FUNCTION> access_fmap;
        X
    #undef X
    //--------------------------------------------------------------------------------------------------------//
    // Define function to fill <s,t>_PRINT_FUNCTION vector w/ function pointers to enum value print functions executed at run time
    //--------------------------------------------------------------------------------------------------------//
//    #define Y void fill_fmap
//    Y(){
//        #define X(L,R) OBJ_ACCESS(STRUCT_NAME,PRINT_FMAP_NAME).push_back(UNIQUE_NAME(print,R));
//            STRUCT_FIELDS
//        #undef X
//    }
//    #undef Y
};
//--------------------------------------------------------------------------------------------------------//
// Define function for each struct <s,t> member that prints its value
//      <elem_type> print_<elem_name>(<s,t> g){ return g.<elem_name>; };
//--------------------------------------------------------------------------------------------------------//
#define X(L, R) void UNIQUE_NUMBERED_NAME(STRUCT_NAME,print_,R)(STRUCT_NAME g){std::cout << "val = " << g.R << std::endl;};
    STRUCT_FIELDS
#undef X
//--------------------------------------------------------------------------------------------------------//
// Construct global typedef for ENUM_PTR variables w/o needing t:: by prefixing with STRUCT_NAME+_
//      typedef <s,t>::ENUM_PTR <s,t>_ENUM_PTR
//--------------------------------------------------------------------------------------------------------//
#define X typedef ENUM_PTR_TYPEDNAME(STRUCT_NAME) UNIQUE_NAME(STRUCT_NAME,ENUM_PTR_TYPENAME);
    X
#undef X
//--------------------------------------------------------------------------------------------------------//
//      typedef void (<s,t>_PRINT_FUNCTION)(<s,t>);
//--------------------------------------------------------------------------------------------------------//
#define X typedef void (*UNIQUE_NAME(STRUCT_NAME, PRINT_FUNCTION))(STRUCT_NAME);
    X
#undef X
//--------------------------------------------------------------------------------------------------------//
//      std::vector<t_PRINT_FUNCTION> t_print_fmap;
//--------------------------------------------------------------------------------------------------------//
#define X std::vector<UNIQUE_NAME(STRUCT_NAME, PRINT_FUNCTION)> UNIQUE_NAME(STRUCT_NAME,PRINT_FMAP_NAME);
    X
#undef X
//--------------------------------------------------------------------------------------------------------//
// Define global function <s,t>_subenum_ptr(i) returning <s,t>_ENUM_PTR to <i>-th STRUCT_ENUMS member w/o accessing via struct instance
//          t_ENUM_PTR t_subenum0 = t_subenum_ptr(0);
//--------------------------------------------------------------------------------------------------------//
#define X ENUM_TYPEDNAME(STRUCT_NAME) UNIQUE_NAME(STRUCT_NAME,ENUM_PTR_FNAME)(int i){return ENUM_CAST(STRUCT_NAME,i);};
    X
#undef X
//--------------------------------------------------------------------------------------------------------//
// Define function to fill <s,t>_PRINT_FUNCTION vector w/ function pointers to enum value print functions executed at run time
//--------------------------------------------------------------------------------------------------------//
#define Y void UNIQUE_NAME(STRUCT_NAME, FILL_MAP_FNAME)
Y(){
    #define X(L,R) UNIQUE_NAME(STRUCT_NAME, PRINT_FMAP_NAME).push_back(UNIQUE_NUMBERED_NAME(STRUCT_NAME,print_,R));
        STRUCT_FIELDS
    #undef X
}
#undef Y
//--------------------------------------------------------------------------------------------------------//
//#ifndef FIRST_RUNB
//    #define FIRST_RUNB 0
//#endif
//--------------------------------------------------------------------------------------------------------//
struct struct_fmt CAT(STRUCT_NAME, _fmt) =
{
    .struct_name = STR(STRUCT_NAME),
    .num_members = (
        #define X(L, R) 1 +
        STRUCT_FIELDS
        #undef X
    0),
    .struct_size = sizeof(struct STRUCT_NAME),
    .packed_size = (
        #define X(L, R) sizeof(L) +
        STRUCT_FIELDS
        #undef X
    0),
    .offsets = (size_t[]){
        #define X(L, R) offsetof(struct STRUCT_NAME, R),
        STRUCT_FIELDS
        #undef X
    },
    .sizes = (size_t []){
        #define X(L, R) sizeof(L),
        STRUCT_FIELDS
        #undef X
    },
    .types = (char const *[]){
        #define X(L, R) #L,
        STRUCT_FIELDS
        #undef X
    },
    .names = (char const *[]){
        #define X(L, R) #R,
        STRUCT_FIELDS
        #undef X
    },
    .values = (char const *[]){
        //#define X(L, R) CATELEM(MEMACC,R),
        #define X(L, R) ELEM(#R),
        //#define X(L, R) STR(MEMACC),
        STRUCT_FIELDS
        #undef X
    },
    //std::cout << "Hello World!\n" << std::endl
};

#undef STRUCT_FIELDS
#undef STRUCT_NAME
#undef STR_NOEXPAND
#undef STR
#undef CAT_NOEXPAND
#undef CAT
