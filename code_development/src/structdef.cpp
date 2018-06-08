/*
 * Macro for C99 designated initializer -> C89/90 non-designated initializer
 *
 * Tested.  Works with MSVC if you undefine HAVE_DESIGNATED_INITIALIZERS.  Cscope also
 * groks this.
 *
 * ("SFINIT" == struct field init, but really, it can be used for array initializers too.)
 */
#define STRUCT_NAME t
#define STRUCT_FIELDS \
    X(int, pCTa) \
    X(float, pCTb) \
    X(char, pCTc)
#include "../include/fmtgen.h"

#define STRUCT_NAME s
#define STRUCT_FIELDS \
    X(long, pCTl) \
    X(double, pCTg) \
    X(unsigned long long, pCTf) \
    X(int, pCTx)
#include "../include/fmtgen.h"

struct RETURN_VALS
{
    int type_val;
    int int_val;
    unsigned int uint_val;
    long long_val;
    unsigned long ul_val;
    long long ll_val;
    unsigned long long ull_val;
    float float_val;
    double double_val;
    char char_val;
    char* char_ptr_val;
    std::string string_val;
    void print_int(){std::cout << "val = " << int_val << std::endl;};
    void print_float(){std::cout << "val = " << float_val << std::endl;};
    void print_char(){std::cout << "val = " << char_val << std::endl;};
};
template <typename T> struct template_structs {T struct_val;};
template_structs<int> template_struct;
RETURN_VALS return_vals;
std::vector<const char*> struct_types;
std::vector<const char*> struct_names;
std::vector<const char*> struct_vals;
std::vector<const char*> struct_values;

void print_buffer(unsigned char *buffer, size_t size)
{
    for (size_t j = 0; j < size; j++)
        printf(" %02x", buffer[j]);
}
size_t struct_pack(struct struct_fmt *fmt, void *structure, unsigned char *buffer)
{
    size_t pos = 0;
    for (size_t i = 0; i < fmt->num_members; i++)
    {
        memcpy(buffer+pos, ((unsigned char*)structure)+fmt->offsets[i], fmt->sizes[i]);
        pos += fmt->sizes[i];
    }
    return pos;
}
size_t struct_unpack(struct struct_fmt *fmt,  unsigned char *buffer, void *structure)
{
    size_t pos = 0;
    for (size_t i = 0; i < fmt->num_members; i++)
    {
        memcpy(((unsigned char*)structure)+fmt->offsets[i], buffer+pos, fmt->sizes[i]);
        pos += fmt->sizes[i];
    }
    return pos;
}
void struct_print(struct struct_fmt *fmt, void *structure)
{
    printf("%s:\n", fmt->struct_name);
    for (size_t i = 0; i < fmt->num_members; i++)
    {
        printf("\t%s:%s: %Iu %Iu =", fmt->types[i], fmt->names[i], fmt->offsets[i], fmt->sizes[i]);
        print_buffer(((unsigned char*)structure)+fmt->offsets[i], fmt->sizes[i]);
        printf("\n");
    }
}
template<typename T> void structmem_print(struct struct_fmt *fmt, void *structure, int index, T& val)
{
    printf("%s:\n", fmt->struct_name);
    printf("\t%s:%s: %Iu %Iu \n", fmt->types[index], fmt->names[index], fmt->offsets[index], fmt->sizes[index]);
    memcpy(&val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
}
void print_struct_elem_type(struct struct_fmt *fmt, void *structure, int index){printf("%s", fmt->types[index]);}
void print_struct_elem_name(struct struct_fmt *fmt, void *structure, int index){printf("%s", fmt->names[index]);}
template<typename T> void print_struct_elem_val(T init_val)
{
    template_structs<T> _struct = {init_val};
    //std::cout << typeid(_struct.struct_val).name() << " : "
    std::cout << _struct.struct_val;
    //return _struct;
}
void print_struct_elem(struct struct_fmt *fmt, void *structure, int index)
{
    //std::cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
	//char* struct_elem_name = print_struct_elem_name(fmt, structure, index);
    //printf("\t%s = ", struct_elem_name);
    //printf("\t%s = ", fmt->names[index]);
    printf("fmt->values[%d] %s = ", index, fmt->values[index]);
    //get_struct_elem_values
    printf("(");
    print_struct_elem_type(fmt, structure, index);
    printf(")");
    print_struct_elem_name(fmt, structure, index);
    printf(" = ");

    if(fmt->types[index] == "int")
    {//    int int_val;
        memcpy(&return_vals.int_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.int_val);
        //auto _struct = get_struct_elem_val(return_vals.int_val);
        printf("\n");
        //return _struct;
	}
	else if(fmt->types[index] == "unsigned int")
    {//    unsigned int uint_val;
        memcpy(&return_vals.uint_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.uint_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "long")
    {//   long long_val;
        memcpy(&return_vals.long_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.long_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "unsigned long")
    {//    unsigned long ul_val;
        memcpy(&return_vals.ul_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.ul_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "long long")
    {//    long long ll_val;
        memcpy(&return_vals.ll_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.ll_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "unsigned long long")
    {//    unsigned long long ull_val;
        memcpy(&return_vals.ull_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.ull_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "float")
    {//    float float_val;
        memcpy(&return_vals.float_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.float_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "double")
    {//    double double_val;
        memcpy(&return_vals.double_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.double_val);
        printf("\n");
        //return _struct;
    }
    else if(fmt->types[index] == "char")
    {//    char char_val;
        memcpy(&return_vals.char_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.char_val);
        printf("\n");
        //return _struct;
    }
	else if(fmt->types[index] == "char*")
    {//    char* char_ptr_val;
        memcpy(&return_vals.char_ptr_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.char_ptr_val);
        printf("\n");
        //return _struct;
    }
    else if(fmt->types[index] == "string" || fmt->types[index] == "std::string")
    {//    std::string string_val;
        memcpy(&return_vals.char_ptr_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        print_struct_elem_val(return_vals.char_ptr_val);
        printf("\n");
        //return _struct;
    }
}
void print_struct_elements(struct struct_fmt *fmt, void *structure)
{
    for (size_t index = 0; index < fmt->num_members; index++)
    {
        print_struct_elem(fmt, structure, index);
    }
}
const char* get_struct_elem_type(struct struct_fmt *fmt, void *structure, int index){struct_types.push_back(fmt->types[index]); return fmt->types[index];}
const char* get_struct_elem_name(struct struct_fmt *fmt, void *structure, int index){struct_names.push_back(fmt->names[index]); return fmt->names[index];}
const char* get_struct_elem_values(struct struct_fmt *fmt, void *structure, int index){struct_values.push_back(fmt->values[index]); return fmt->values[index];}
template<typename T> template_structs<T> get_struct_elem_val(T init_val)
{
    template_structs<T> _struct = {init_val};
    std::string str = std::to_string(_struct.struct_val);
    struct_vals.push_back(str.c_str());
    return _struct;
}
template<typename T> template_structs<T> get_struct_elem_strval(T init_val)
{
    template_structs<T> _struct = {init_val};
    std::string str = std::string(_struct.struct_val);
    struct_vals.push_back(str.c_str());
    return _struct;
}
void get_struct_elem(struct struct_fmt *fmt, void *structure, int index)
{
    std::cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
    printf("%s = ", fmt->names[index]);
    if(fmt->types[index] == "int")
    {//    int int_val;
        memcpy(&return_vals.int_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.int_val);
        std::cout << _struct.struct_val << std::endl;
	}
	else if(fmt->types[index] == "unsigned int")
    {//    unsigned int uint_val;
        memcpy(&return_vals.uint_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.uint_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "long")
    {//   long long_val;
        memcpy(&return_vals.long_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.long_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "unsigned long")
    {//    unsigned long ul_val;
        memcpy(&return_vals.ul_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.ul_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "long long")
    {//    long long ll_val;
        memcpy(&return_vals.ll_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.ll_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "unsigned long long")
    {//    unsigned long long ull_val;
        memcpy(&return_vals.ull_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.ull_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "float")
    {//    float float_val;
        memcpy(&return_vals.float_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.float_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "double")
    {//    double double_val;
        memcpy(&return_vals.double_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.double_val);
        std::cout << _struct.struct_val << std::endl;
    }
    else if(fmt->types[index] == "char")
    {//    char char_val;
        memcpy(&return_vals.char_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_val(return_vals.char_val);
        std::cout << _struct.struct_val << std::endl;
    }
	else if(fmt->types[index] == "char*")
    {//    char* char_ptr_val;
        memcpy(&return_vals.char_ptr_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_strval(return_vals.char_ptr_val);
        std::cout << _struct.struct_val << std::endl;
    }
    else if(fmt->types[index] == "string" || fmt->types[index] == "std::string")
    {//    std::string string_val;
        memcpy(&return_vals.char_ptr_val, ((unsigned char*)structure)+fmt->offsets[index], fmt->sizes[index]);
        auto _struct = get_struct_elem_strval(return_vals.char_ptr_val);
        std::cout << _struct.struct_val << std::endl;
    }
}
void get_struct_elements(struct struct_fmt *fmt, void *structure)
{
    for (size_t index = 0; index < fmt->num_members; index++)
    {
        get_struct_elem(fmt, structure, index);
        //std::cout << _struct.struct_val << ",\n";
    }
}
void structdef_manual_access(char* tbase)
{
    //char * tbase = (char *)tstptr;
    int a_cpy;
    int a_memcpy;
    float b_cpy;
    float b_memcpy;
    float* b_ptr = (float *)(tbase+4);
    //std::copy(&tbase[0], &tbase[0]+4, &a_cpy);
    //std::copy(&tbase[8], &tbase[11], &b_cpy);
    //std::copy(&tbase+8, &tbase+12, &b_cpy);
    memcpy ( &a_memcpy, &tbase[0], 4 );
    memcpy ( &b_memcpy, &tbase[4], 4);
    //printf("a_cpy = %d\n", a_cpy);
    //printf("b_cpy = %d\n", b_cpy);
    printf("a_memcpy = %d\n", a_memcpy);
    //printf("a_cpy = %d, a_memcpy = %d\n", a_cpy, a_memcpy);
    //printf("b(cpy) = %f\n", b_cpy);
    printf("b(memcpy) = %f\n", b_memcpy);
    printf("b(*ptr) = %f\n", *b_ptr);
    //printf("b(memcpy) = %f, b(*ptr) = %f\n", b_memcpy, *b_ptr);
    //printf("b = %f, b(memcpy) = %f, b(*ptr) = %f\n", tbase->pCTb, b_memcpy, *b_ptr);

    int acpy2;
    float bcpy2;
    structmem_print(&t_fmt, tbase, 0, acpy2);
    structmem_print(&t_fmt, tbase, 1, bcpy2);
    printf("acpy2 = %d\n", acpy2);
    printf("bcpyb2 = %f\n", bcpy2);

}
void structdef_testing()
{
    struct t rst = {.pCTa = 1, .pCTb = 1.0, .pCTc = 'a'};
    struct t tst = {.pCTa = 5, .pCTb = 6.0, .pCTc = 'c'};
    struct s sst = {.pCTl = 1024, .pCTg = 0.0, .pCTf = 2048};

    unsigned char tbuff[t_fmt.packed_size];
    struct_pack(&t_fmt, &tst, tbuff);
    printf("t packed:\n\t");
    print_buffer(tbuff, sizeof(tbuff));
    printf("\n");

    unsigned char rbuff[t_fmt.packed_size];
    struct_pack(&t_fmt, &rst, rbuff);
    printf("r packed:\n\t");
    print_buffer(rbuff, sizeof(rbuff));
    printf("\n");

    unsigned char sbuff[s_fmt.packed_size];
    struct_pack(&s_fmt, &sst, sbuff);
    printf("s packed:\n\t");
    print_buffer(sbuff, sizeof(tbuff));
    printf("\n");

    struct_print(&t_fmt, &tst);
    struct_print(&t_fmt, &rst);
    struct_print(&s_fmt, &sst);
//
//    std::cout << "<get,print>_struct_elements " << std::endl;
//    char * tbase = (char *)&tst;
//    structdef_manual_access(tbase);
//    print_struct_elements(&t_fmt, &tst);
//    get_struct_elements(&t_fmt, &tst);
//
//    tst.print_pCTa(tst); std::cout << "out = " << tst.get_pCTa(tst) << std::endl;
//    tst.print_pCTb(tst); std::cout << "out2 = " << tst.get_pCTb(tst) << std::endl;
//
//    t_ENUM_PTR t_subenum0 = t_subenum_ptr(0);
//    t::ENUM_PTR t_subenum1 = tst.subenum_ptr(1);
//    ENUM_INDEX(t,2) //t_subenum2
//    PRINT_ENUM(t,t_subenum0)
//    PRINT_ENUM(t,t_subenum1)
//    PRINT_ENUM(t,t_subenum2)
//    tst.ENUMS_MAP.emplace("First Value", t::epCTa);
//    tst.ENUMS_MAP.emplace("Second Value", t::epCTb);
//    tst.ENUMS_MAP.emplace("Third Value", t::epCTc);
//    VARPRINT(tst.ENUMS_MAP["Second Value"])
//    VARPRINT(tst.ENUMS_MAP["Third Value"])
//    VARPRINT(tst.ENUMS_MAP["First Value"])
//    VARPRINT(ENUM_ACCESS(t,pCTa))
//    VARPRINT(t::epCTa)
//    VARPRINT(tst.epCTb)
//    VARPRINT(tst.epCTc)

    std::cout << std::endl << "PRINT_FUNCTION testing" << std::endl;
    std::cout << "\tt_runit() + funcout(tst) = \n";
    t_fill_fmap();
    //tst.print_fmap.push_back(print_pCTa);
    //t_print_fmap.push_back(t_print_pCTb);
    //t_PRINT_FUNCTION t_funcout = t_print_fmap[0];
    //t::PRINT_FUNCTION tst_funcout = tst.print_fmap[0];
    t_PRINT_FUNCTION t_funcout0 = t_print_fmap[t::epCTa];
    t::PRINT_FUNCTION t_funcout1 = t_print_fmap[1];
    t::PRINT_FUNCTION t_funcout2 = t_print_fmap[2];
    t_funcout0(tst);
    t_funcout1(tst);
    t_funcout2(tst);
}
