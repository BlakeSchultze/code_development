#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#endif // COMMON_H_INCLUDED
//------------------------------------------------------------------------------------------------//
//------------------------------ Detect Operating System environment -----------------------------//
//------------------------------------------------------------------------------------------------//
enum OS_ENVIRONMENTS{LINUX, WIN_32, WIN_64, APPLE, ANDROID, AKAROS, NACL, ASMJC, FUSCHIA};
enum COMPILERS{GCC, MSVC, MINGW32, MINGW32W, MINGW64, CLANG, EMSCRIPTEN};
//enum PROCESSOR_ARCHITECTURES{};

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

char __print_statement[512];
char __system_command[512];
char __ls_cmd_win[] = "dir -/b /a:d";
char __ls_cmd_linux[] = "find -maxdepth 1 -type d -printf \"%f\n\"";
char __folder[512];
char __filename[512];
char __csvfile[512];
char __textfile[512];
int __i = 0;
std::ifstream __input_file;
std::ofstream __output_file;
std::string __termout;
std::string		__line__input;
std::string __input_value;
std::string __string;
std::string __outstring;
std::stringstream  __line_sstream;
std::vector<std::string> strcat_elements;

//-------------------------------------------------------------------------//
//--------------------------------- common --------------------------------//
//-------------------------------------------------------------------------//
TEST_CONTROL		test_controls;
TEST_CONTROL_MAP	test_control_map;

//-------------------------------------------------------------------------//
//---------------------------------- pCT ----------------------------------//
//-------------------------------------------------------------------------//
struct configurations;
extern configurations parameter_container;
extern configurations *configurations_h; //= &parameter_container;
extern configurations *configurations_d;
extern void construct_pCT_params();
typedef std::tuple<configurations, std::string, PARAM_TYPES> PCT_PARAMS;
//std::vector<PCT_PARAMS> pct_params;
//std::vector<PCT_PARAMS> pct_params_vec;
//struct configurations;
//typedef std::tuple<configurations, std::string, PARAM_TYPES> PCT_PARAMS;
//std::vector<PCT_PARAMS> pct_params;
//std::vector<PCT_PARAMS> pct_params_vec;
//extern std::vector<PCT_PARAMS> pct_params;
//extern std::vector<PCT_PARAMS> pct_params_vec;
UINT DROP_BLOCK_SIZE = 3200;
UINT reconstruction_histories , DROP_last_block_size, num_DROP_blocks;
const BLOCK_ORDERING		DROP_BLOCK_ORDER		= CYCLIC;
BLOCK_ORDERING block_order	= BLOCK_ORDERING(0);
//BLOCK_ORDERING block_order	= BLOCK_ORDERING{0};
//BLOCK_ORDERING block_order	= BLOCK_ORDERING[0];
std::vector<UINT> DROP_block_sizes;
std::vector<UINT> DROP_block_order;
std::vector<UINT> DROP_block_start_positions;
UINT k = 4, ELL = 10, N = 5, K = 12;
bool OVERWRITE=false;
const char BASH_ECHO_CMD[]			= "echo -e";										// Command to secure copy data/directories between clusters/nodes
const char WIN_ECHO_CMD[]			= "echo";											// Command to secure copy data/directories between clusters/nodes
const bool SAMP_PROC3= true;
int ITERATIONS = 0, SLICES = 20, COLUMNS = 200, ROWS = 200;
//const char PCT_DATA_DIR[] = "D:\\pCT\\pCT_data\\reconstruction_data\\CTP404_Sensitom\\Experimental\\B_25600\\";//B_25600_L_0.000100_TV_1
const char PCT_DATA_DIR[] = "D:\\pCT\\pCT_data\\reconstruction_data\\CTP404_Sensitom\\Experimental\\B_25600\\TV=1\\";//B_25600_L_0.000100_TV_1
const char X_BASENAME[] = "x_";
const char TV_CALCULATED[] = "TV_calculated.csv";
const char TV_MEASUREMENTS[] = "TV_measurements.txt";
const char* C_CONST_CHAR = "c";
const char* CONTINUE_PROMPT ="Enter 'c' to continue execution, any other character exits program";
