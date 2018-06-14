//#ifndef EXTERNS_H_INCLUDED
//#define EXTERNS_H_INCLUDED

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef COMMON_TEM_H
    #define COMMON_TEM_H
	template<typename T> std::stringstream  ls (T);
	template<typename T> std::string stringify(T string_input);
	template<typename T> char* charify(T string_input);
    #include "..//src//common.tem"  // Include the implementation
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef PCT_TEM_H  // Prevent duplicate definition
#define PCT_TEM_H
	template<typename T> std::string echo_cmd(T);
	template<typename T> std::string colored_text(T, const char*, const char*, const char* );
	template<typename T> std::string echo_statement(T, const char*, const char*, const char* );
	template<typename T> void print_colored_text(T, const char*, const char*, const char* );
	template<typename T> void print_labeled_value(const char*, T, const char*, const char*, const char*, const char* );
    #include "..//src//pCT_development.tem"  // Include the implementation
#endif
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
extern const bool           structdef_test;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
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
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
extern char __print_statement[512];
extern char __system_command[512];
extern char __ls_cmd_linux[];
extern char __ls_cmd_win[];
extern char __folder[512];
extern char __filename[512];
extern char __csvfile[512];
extern char __textfile[512];
extern char* __str;
extern int __i;
extern std::ifstream __input_file;
extern std::ofstream __output_file;
extern std::string __termout;
extern std::string	__line__input;
extern std::string __input_value;
extern std::string __string;
extern std::string __outstring;
extern std::stringstream  __line_sstream;
extern std::vector<std::string> strcat_elements;
extern const char* C_CONST_CHAR;
extern const char* CONTINUE_PROMPT;
extern const char BASH_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
extern const char WIN_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
extern std::string exec(const char*) ;
extern void exit_program();
extern void exit_program_if( bool);
extern void exit_program_if( const char*, char);
extern bool exit_prompt( const char*, char);
extern std::string color_encoding_statement(const char*, const char*, const char* );
extern std::string change_text_color_cmd(const char*, const char*, const char*, bool);
extern void change_text_color(const char*, const char*, const char*, bool);
extern void print_section_separator(const char, const char*, const char*, const char* );
extern void print_section_header( const char*, const char, const char*, const char*, const char*, const char* );
extern void print_section_exit( const char*, const char*, const char*, const char*, const char*, const char* );
extern void print_multiline_bash_results(const char*, const char*, const char*, const char* );
extern void test_routine( void (*TEST_FUNCTION)(), bool );
extern void init_test_control();
extern void test_of(const std::string);
extern void construct_pCT_params();
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
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
