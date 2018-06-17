///*************************************************************************************************************************//
///*-----------------------------------------------------------------------------------------------------------------------*//
///*----------------------- externs.h: Forward declarations of externally defined variables/functions ---------------------*//
///*-----------------------------------------------------------------------------------------------------------------------*//
///*************************************************************************************************************************//
//-------------------------------------------------------------------------//
//------------------------------ common.tem -------------------------------//
//-------------------------------------------------------------------------//
#ifndef COMMON_TEM_H
    #define COMMON_TEM_H
	template<typename T> std::stringstream  ls(T);
	//template<typename T> std::stringstream  lsB (T directory);
    //template<typename T, typename S> std::stringstream  lsB (T directory);
    //template<typename T, typename S> std::stringstream  lsB (T directory, S optargs...);
    //template<typename T, typename S> std::stringstream  lsB (T directory);
    //template<typename T> std::stringstream  lsC (T, std::string = std::string(""));
    template<typename T> std::string stringify(T);
	template<typename T> char* charify(T);
    template<typename T> std::string string_cat(T);
    template<typename T, typename... Args> std::string string_cat(T, Args...); // recursive variadic function
    template<typename... Args> void control_lkill( void (*f)(Args... ),unsigned int , Args... );
    #include "..//src//common.tem"  // Include the implementation
#endif
//-------------------------------------------------------------------------//
//-------------------------- pCT_development.tem --------------------------//
//-------------------------------------------------------------------------//
#ifndef PCT_TEM_H  // Prevent duplicate definition
#define PCT_TEM_H
	template<typename T> std::string quote_text(T text ){ return std::string("\"") + std::string(text) + std::string("\""); }
    template<typename T> std::string echo_cmd(T);
	template<typename T> std::string colored_text(T, const char*, const char*, const char* );
	template<typename T> std::string echo_statement(T, const char*, const char*, const char* );
	template<typename T> void print_colored_text(T, const char*, const char*, const char* );
	template<typename T> void print_labeled_value(const char*, T, const char*, const char*, const char*, const char* );
    template<typename T> void vector_2_disk( const char*, const char*, const char*, std::vector<T>, const int, const int, const int, bool );
    template<typename T> void combine_x_slices( const char*, const char*, const char*, const int, const int, const int, bool );
    template<typename B, typename D, typename F> void concat_x_slices( B, D, F, const int, const int, const int, bool );
    template<typename B, typename D, typename F> void combine_x_n_slices( B, D, F, const int, const int, const int, const int, bool );
    //template<typename D> void combine_x_n_slices( const char*, D, const char*, const int, const int, const int, const int, bool  );
    template<typename B, typename D> void combine_set_x_n_slices( B, D, const int, const int, const int, const int, bool );
    #include "..//src//pCT_development.tem"  // Include the implementation
#endif
//-------------------------------------------------------------------------//
//-------------------------------- common.h -------------------------------//
//-------------------------------------------------------------------------//
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
extern const bool           structdef_test;
//-------------------------------------------------------------------------//
//-------------------------------- common.h -------------------------------//
//-------------------------------------------------------------------------//
extern char __print_statement[512];
extern char __system_command[512];
extern char __ls_cmd_linux[];
extern char __ls_cmd_win[];
extern char __folder[512];
extern char __filename[512];
extern char __csvfile[512];
extern char __textfile[512];
extern char* __str;
extern int __i, __j, __k;
extern unsigned int __loop_index, __KILL_LOOP_INDEX;
extern unsigned int __fcall_index, __KILL_FCALL_INDEX;
extern std::ifstream __input_file;
extern std::ofstream __output_file;
extern std::string __termout;
extern std::string	__line__input;
extern std::string __input_value;
extern std::string __string;
extern std::string __outstring;
extern std::stringstream  __line_sstream;
extern std::vector<std::string> strcat_elements;
extern bool OVERWRITE;
extern const char* C_CONST_CHAR;
extern const char* CONTINUE_PROMPT;
extern const char BASH_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
extern const char WIN_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
//-------------------------------------------------------------------------//
//------------------------------ common.cpp -------------------------------//
//-------------------------------------------------------------------------//
extern bool fileExists(const std::string&);
extern bool statFileExistence(const std::string&);
extern std::string exec(const char*);
extern void test_routine( void (*TEST_FUNCTION)(), bool );
extern void init_test_control();
extern void test_of(const std::string);
//-------------------------------------------------------------------------//
//-------------------------- pCT_development.cpp --------------------------//
//-------------------------------------------------------------------------//
extern void exit_program();
extern void exit_program_if( bool);
extern void exit_program_if( const char*, char);
extern bool exit_prompt( const char*, char);
extern void generate_history_sequence(ULL, ULL, ULL* );
extern void verify_history_sequence(ULL, ULL, ULL* );
extern void print_history_sequence(ULL*, ULL, ULL );
//extern void apply_history_sequence(ULL, ULL, ULL*);
extern void shuffle_blocks();
extern void rotate_blocks_left();
extern void rotate_blocks_right();
extern void print_DROP_block_info();
extern void recon_DROP_initializations();
extern std::string set_procedure_on_off_string(const bool);
extern void tuple_mapping();
extern int randi(int, int);
extern std::string color_encoding_statement(const char*, const char*, const char* );
extern std::string change_text_color_cmd(const char*, const char*, const char*, bool);
extern void change_text_color(const char*, const char*, const char*, bool);
extern void print_section_separator(const char, const char*, const char*, const char* );
extern void print_section_header( const char*, const char, const char*, const char*, const char*, const char* );
extern void print_section_exit( const char*, const char*, const char*, const char*, const char*, const char* );
extern void print_multiline_bash_results(const char*, const char*, const char*, const char* );
//-------------------------------------------------------------------------//
//----------------------------- pCT_params.cpp ----------------------------//
//-------------------------------------------------------------------------//
extern void construct_pCT_params();
//-------------------------------------------------------------------------//
//-------------------------- code_development.cpp -------------------------//
//-------------------------------------------------------------------------//
// Project test routine control
extern void pCT_development();
extern void AKS_development();
extern void walker_development();
extern void structdef_testing();

// Project test subtest routine control
extern const bool preprocessing_test;
extern const bool pCT_general_test;
extern const bool pCT_stringops_test;
extern const bool pCT_printing_test;
extern const bool TVS_beta_sequence_test;
extern const bool TVS_ell_assign_test;
extern const bool block_ordering_test;
extern const bool slice_merging_test;

extern void preprocessing_testing();
extern void pCT_general_testing();
extern void pCT_stringops_testing();
extern void pCT_printing_testing();
extern void TVS_beta_sequence_testing();
extern void TVS_ell_assign_testing();
extern void block_ordering_testing();
extern void slice_merging_testing();
extern void TV_measurements_testing();
//#endif // EXTERNS_H_INCLUDED
