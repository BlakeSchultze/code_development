#include "code_development.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
enum DATA_FORMATS			{ OLD_FORMAT, VERSION_0, VERSION_1, CONTINUOUS	};				// Define the data formats that are supported
enum DATA_ORDER				{ HISTORY, TYPE									};				// Define the data formats that are supported
enum SCAN_TYPES				{ EXPERIMENTAL, SIMULATED_G, SIMULATED_T		};				// Experimental or simulated (GEANT4 or TOPAS) data
enum FILE_TYPES				{ TEXT, BINARY									};				// Experimental or simulated data
enum RAND_GENERATORS		{ DEFAULT_RAND, MINSTD_RAND, MINSTD_RAND0, MT19937,				// Defines the available random number generator engines
                              MT19937_64, RANLUX24, RANLUX48, KNUTH_B		};					//
enum IMAGE_BASES			{ VOXELS, BLOBS									};				// Defines whether images are formed using voxels or blobs as the basis elements
enum STRUCTURAL_ELEMENTS	{ SQUARE, DISK									};				// Defines the structural elements available to the morphological operators
enum MORPHOLOGICAL_OPS		{ EROSION, DILATION, OPENING, CLOSING			};				// Defines the mathematical morphology operators available for image processing
enum BIN_ANALYSIS_TYPE		{ MEANS, COUNTS, MEMBERS						};				// Choices for what information about the binned data is desired
enum BIN_ANALYSIS_FOR		{ ALL_BINS, SPECIFIC_BINS						};				// Choices for which bins the desired data should come from
enum BIN_ORGANIZATION		{ BY_BIN, BY_HISTORY							};				// Binned data is either organized in order by bin or by history w/ bin # specified separately
enum BIN_ANALYSIS_OF		{ WEPLS, ANGLES, POSITIONS, BIN_NUMS			};				// Choices for which type of binned data is desired
enum FILTER_TYPES			{ RAM_LAK, SHEPP_LOGAN, NONE					};				// Define the types of filters that are available for use in FBP
enum HULL_TYPES				{ SC_HULL, MSC_HULL, SM_HULL, FBP_HULL			};				// Define valid choices for which hull to use in MLP calculations
enum INITIAL_ITERATE		{ X_HULL, FBP_IMAGE, HYBRID, ZEROS, IMPORT		};				// Define valid choices for which hull to use in MLP calculations
enum TX_OPTIONS				{ FULL_TX, PARTIAL_TX, PARTIAL_TX_PREALLOCATED	};				// Define valid choices for the host->GPU data transfer method
enum ENDPOINTS_ALGORITHMS	{ YES_BOOL, NO_BOOL								};				// Define the method used to identify protons that miss/hit the hull in MLP endpoints calculations
enum MLP_ALGORITHMS			{ STANDARD, TABULATED							};				// Define whether standard explicit calculations or lookup tables are used in MLP calculations
enum PROJECTION_ALGORITHMS	{ ART, SART, BIP, BICAV, DROP, OSSART, SAP, CARP,				// Define valid choices for iterative projection algorithm to use
							  SABICAV, SADROP, SAOSSART, ROBUST_A, ROBUST_B };				//
enum RECON_SCHEMES			{ REPEAT_ALG, INTERLEAVE_ALGS, DETERMINE_ALG, LISTOF_ALGS};		// Defines possible schemes for selecting the projection algorithm used each iteration, which needn't be the same
enum ROBUST_METHODS			{ OLS, TLS, TIKHONOV, RIDGE, MINMIN, MINMAX, ADDITIVE_UPDATE};	// Defines the robust regression methods available for robust image reconstruction
enum LAMBDA_K_TYPES			{ CONSTANT, LINEAR_K							};				// Define valid choices for setting the relaxation parameter lambda as a function of iteration k
enum SABIP_CONFIGS			{ SABIP_NUM_STRINGS, SABIP_STRING_SIZE			};				// Define valid choices for determining # of BIP algorithm blocks per SAP string in hybrid SAP/BIP algorithm
enum BLOCK_ORDERING			{ CYCLIC, ROTATE_LEFT, ROTATE_RIGHT, RAND_SHUFFLE, PRIME_CYCLE};// Define options for setting the order in which BIP blocks are being used in reconstruction
enum S_CURVES				{ SIGMOID, TANH, ATAN, ERF, LIN_OVER_ROOT		};				// Define valid choices for iterative projection algorithm to use
enum LOG_ENTRIES			{ OBJECT_L, SCAN_TYPE_L, RUN_DATE_L, RUN_NUMBER_L,				// Define the headings of each column in the execution log
                              ACQUIRED_BY_L, PROJECTION_DATA_DATE_L, CALIBRATED_BY_L, 		//
                              PREPROCESS_DATE_L, PREPROCESSED_BY_L, RECONSTRUCTION_DATE_L,	//
							RECONSTRUCTED_BY_L, COMMENTS_L					};				//
enum PARAM_TYPES			{ ENUM, BOOLEAN, ALPHANUMERIC					};				// Define the data formats that are supported
//enum BLOCK_ORDERING			{ CYCLIC, ROTATE_LEFT, ROTATE_RIGHT, RANDOMLY_SHUFFLE, END_BLOCK_ORDERING					};				// Define the data formats that are supported

struct configurations;
extern configurations parameter_container;
extern configurations *configurations_h; //= &parameter_container;
extern configurations *configurations_d;

typedef std::vector<UINT>::iterator block_iterator;
extern void construct_pCT_params();
//cfgdef_enum_parameter(configurations_h->rand_engine, "rand_engine" , cfgdef_optname );	// 1

extern UINT DROP_BLOCK_SIZE;
extern UINT reconstruction_histories , DROP_last_block_size, num_DROP_blocks;
extern const BLOCK_ORDERING		DROP_BLOCK_ORDER;
extern BLOCK_ORDERING block_order;
//extern BLOCK_ORDERING block_order;
//extern BLOCK_ORDERING block_order;
extern std::vector<UINT> DROP_block_sizes;
extern std::vector<UINT> DROP_block_order;
extern std::vector<UINT> DROP_block_start_positions;
extern UINT k, ELL, N, K;
extern const char BASH_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
extern const char WIN_ECHO_CMD[];											// Command to secure copy data/directories between clusters/nodes
extern char print_statement[512];
extern char system_command[512];
extern const bool SAMP_PROC3;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#define SAMP_PROC				ON
#define SAMP_PROC2				OFF
#define TVS_MIN_ETA				1E-40									// Specify minimum perturbation coefficient to include in precalculated coefficient array
#define TV_THRESHOLD			(1/10000)								// [#] Value of TV difference ratio |TV_y - TV_y_previous| / TV_y between successive betas where beta is not decreased more
#define ALPHA					0.75									// Perturbation coefficient generation kernel value: BETA_K_N = ALPHA^ELL
#define ELL_0					0										// Initial value of L used in calculating the perturbation coefficient: ALPHA^ELL
#define CONSOLE_WINDOW_WIDTH	80										// [#] Specifies character width of stdout console window
#define SPACE_CHAR				' '										// [character] Specifies character to use in major section separator
#define SPACE_STRING			" "										// [character] Specifies character to use in major section separator
#define EMPTY_STRING			" "										// [character] Specifies character to use in major section separator
#define MAJOR_SECTION_SEPARATOR	'*'										// [character] Specifies character to use in major section separator
#define MINOR_SECTION_SEPARATOR	'-'										// [character] Specifies character to use in minor section separator
#define SECTION_EXIT_CSTRING	"-----)"								// [string] String prefix of task completion console text notifications using section_exit function
#define DARK					0										// [#] Integer encoding of 'dark' text color shading option used in printing colored text to stdout (console window)
#define LIGHT					1										// [#] Integer encoding of 'light' text color shading option used in printing colored text to stdout (console window) 	
#define BLACK					30										// [#] Integer encoding of 'black' text color used in printing colored text to stdout (console window)
#define RED						31										// [#] Integer encoding of 'red' text color used in printing colored text to stdout (console window)
#define GREEN					32										// [#] Integer encoding of 'green' text color used in printing colored text to stdout (console window)
#define BROWN					33										// [#] Integer encoding of 'brown' text color used in printing colored text to stdout (console window)
#define BLUE					34										// [#] Integer encoding of 'blue' text color used in printing colored text to stdout (console window)
#define PURPLE					35										// [#] Integer encoding of 'purple' text color used in printing colored text to stdout (console window)
#define CYAN					36										// [#] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define BLACK_TEXT				"0;30"									// [string] Integer encoding of 'black' text color used in printing colored text to stdout (console window)
#define GRAY_TEXT				"1;30"									// [string] Integer encoding of 'black' text color used in printing colored text to stdout (console window)
#define RED_TEXT				"0;31"									// [string] Integer encoding of 'red' text color used in printing colored text to stdout (console window)
#define LIGHT_RED_TEXT			"1;31"									// [string] Integer encoding of 'red' text color used in printing colored text to stdout (console window)
#define GREEN_TEXT				"0;32"									// [string] Integer encoding of 'green' text color used in printing colored text to stdout (console window)
#define LIGHT_GREEN_TEXT		"1;32"									// [string] Integer encoding of 'green' text color used in printing colored text to stdout (console window)
#define BROWN_TEXT				"0;33"									// [string] Integer encoding of 'brown' text color used in printing colored text to stdout (console window)
#define YELLOW_TEXT				"1;33"									// [string] Integer encoding of 'brown' text color used in printing colored text to stdout (console window)
#define BLUE_TEXT				"0;34"									// [string] Integer encoding of 'blue' text color used in printing colored text to stdout (console window)
#define LIGHT_BLUE_TEXT			"1;34"									// [string] Integer encoding of 'blue' text color used in printing colored text to stdout (console window)
#define PURPLE_TEXT				"0;35"									// [string] Integer encoding of 'purple' text color used in printing colored text to stdout (console window)
#define LIGHT_PURPLE_TEXT		"1;35"									// [string] Integer encoding of 'purple' text color used in printing colored text to stdout (console window)
#define CYAN_TEXT				"0;36"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define LIGHT_CYAN_TEXT			"1;36"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define LIGHT_GRAY_TEXT			"0;37"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define WHITE_TEXT				"1;37"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define GRAY_BACKGROUND			"5;40"									// [string] Integer encoding of 'black' text color used in printing colored text to stdout (console window)
#define BLACK_BACKGROUND		"40"									// [string] Integer encoding of 'black' text color used in printing colored text to stdout (console window)
#define LIGHT_RED_BACKGROUND	"5;41"									// [string] Integer encoding of 'red' text color used in printing colored text to stdout (console window)
#define RED_BACKGROUND			"6;41"									// [string] Integer encoding of 'red' text color used in printing colored text to stdout (console window)
#define LIGHT_GREEN_BACKGROUND	"5;42"									// [string] Integer encoding of 'green' text color used in printing colored text to stdout (console window)
#define GREEN_BACKGROUND		"6;42"									// [string] Integer encoding of 'green' text color used in printing colored text to stdout (console window)
#define BROWN_BACKGROUND		"5;43"									// [string] Integer encoding of 'brown' text color used in printing colored text to stdout (console window)
#define YELLOW_BACKGROUND		"6;43"									// [string] Integer encoding of 'brown' text color used in printing colored text to stdout (console window)
#define LIGHT_BLUE_BACKGROUND	"5;44"									// [string] Integer encoding of 'blue' text color used in printing colored text to stdout (console window)
#define BLUE_BACKGROUND			"6;44"									// [string] Integer encoding of 'blue' text color used in printing colored text to stdout (console window)
#define LIGHT_PURPLE_BACKGROUND	"5;45"									// [string] Integer encoding of 'purple' text color used in printing colored text to stdout (console window)
#define PURPLE_BACKGROUND		"6;45"									// [string] Integer encoding of 'purple' text color used in printing colored text to stdout (console window)
#define LIGHT_CYAN_BACKGROUND	"5;46"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define CYAN_BACKGROUND			"6;46"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define WHITE_BACKGROUND		"5;47"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define LIGHT_GRAY_BACKGROUND	"6;47"									// [string] Integer encoding of 'cyan' text color used in printing colored text to stdout (console window)
#define UNDERLINE_TEXT			";4"									// [string] Integer encoding specifying text be underlined when printing colored text to stdout (console window)
#define DONT_UNDERLINE_TEXT		""										// [string] Empty encoding specifying text NOT be underlined when printing colored text to stdout (console window)
#define OPEN_COLOR_ESCAPE_SEQ	"\033["								// [string] Escape sequence setting removing color from subsequent console output text
#define CLOSE_COLOR_ESCAPE_SEQ	"\033[m"								// [string] Escape sequence setting removing color from subsequent console output text
#define NOCOLOR					"\033[0m"								// [string] Escape sequence setting removing color from subsequent console output text
//#define BLACK					"\033[0;30m"							// [string] Escape sequence setting the color of subsequent console output text to black
#define DARKGRAY				"\033[1;30m"							// [string] Escape sequence setting the color of subsequent console output text to dark gray
//#define RED					"\033[0;31m"							// [string] Escape sequence setting the color of subsequent console output text to red
#define LIGHTRED				"\033[1;31m"							// [string] Escape sequence setting the color of subsequent console output text to light red
//#define GREEN					"\033[0;32m"							// [string] Escape sequence setting the color of subsequent console output text to green
#define LIGHTGREEN				"\033[1;32m"							// [string] Escape sequence setting the color of subsequent console output text to light green
//#define BROWN					"\033[1;33m"							// [string] Escape sequence setting the color of subsequent console output text to brown
//#define YELLOW				"\033[0;33m"							// [string] Escape sequence setting the color of subsequent console output text to yellow
//#define BLUE					"\033[0;34m"							// [string] Escape sequence setting the color of subsequent console output text to blue
#define LIGHTBLUE				"\033[1;34m"							// [string] Escape sequence setting the color of subsequent console output text to light blue
//#define PURPLE				"\033[0;35m"							// [string] Escape sequence setting the color of subsequent console output text to purple
#define LIGHTPURPLE				"\033[1;35m"							// [string] Escape sequence setting the color of subsequent console output text to light purple
//#define CYAN					"\033[0;36m"							// [string] Escape sequence setting the color of subsequent console output text to cyan
#define LIGHTCYAN				"\033[1;36m"							// [string] Escape sequence setting the color of subsequent console output text to light cyan
#define LIGHTGRAY				"\033[0;37m"							// [string] Escape sequence setting the color of subsequent console output text to light gray
//#define WHITE					"\033[1;37m"							// [string] Escape sequence setting the color of subsequent console output text to white
#define X_INCREASING_DIRECTION	RIGHT									// [#] specifies direction (LEFT/RIGHT) along x-axis in which voxel #s increase
#define Y_INCREASING_DIRECTION	DOWN									// [#] specifies direction (UP/DOWN) along y-axis in which voxel #s increase
#define Z_INCREASING_DIRECTION	DOWN									// [#] specifies direction (UP/DOWN) along z-axis in which voxel #s increase
#define X_ZERO_COORDINATE		-RECON_CYL_RADIUS						// [cm] x-coordinate corresponding to front edge of 1st voxel (i.e. column) in image space
#define Y_ZERO_COORDINATE		RECON_CYL_RADIUS						// [cm] y-coordinate corresponding to front edge of 1st voxel (i.e. row) in image space
#define Z_ZERO_COORDINATE		RECON_CYL_HEIGHT/2						// [cm] z-coordinate corresponding to front edge of 1st voxel (i.e. slice) in image space
#define PRINT_TV				true									// [bool] Print total variation measurement
#define DONT_PRINT_TV			false									// [bool] Dont print total variation measurement
#define CHAR_ID_CHAR			'c'
#define BOOL_ID_CHAR			'b'
#define INT_ID_CHAR				'i'
#define UINT_ID_CHAR			'j'
#define STRING_ID_CHAR			's'
#define FLOAT_ID_CHAR			'f'
#define DOUBLE_ID_CHAR			'd'
#define BOOL_FORMAT				"%d"									// [string] Specifies format to use for writing/printing boolean data using {s/sn/f/v/vn}printf statements
#define CHAR_FORMAT				"%c"									// [string] Specifies format to use for writing/printing character data using {s/sn/f/v/vn}printf statements
#define INT_FORMAT				"%d"									// [string] Specifies format to use for writing/printing integer data using {s/sn/f/v/vn}printf statements
#define FLOAT_FORMAT			"%6.6lf"								// [string] Specifies format to use for writing/printing floating point data using {s/sn/f/v/vn}printf statements
#define STRING_FORMAT			"%s"									// [string] Specifies format to use for writing/printing strings data using {s/sn/f/v/vn}printf statements
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef ITEMTOOL_H  // Prevent duplicate definition
#define ITEMTOOL_H
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
extern const bool preprocessing_test;
extern const bool pCT_general_test;
extern const bool pCT_stringops_test;
extern const bool pCT_printing_test;
extern const bool TVS_beta_sequence_test;
extern const bool TVS_ell_assign_test;
extern const bool block_ordering_test;
extern const bool slice_merging_test;
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
extern void preprocessing_testing();
extern void pCT_general_testing();
extern void pCT_stringops_testing();
extern void pCT_printing_testing();
extern void TVS_beta_sequence_testing();
extern void TVS_ell_assign_testing();
extern void block_ordering_testing();
extern void slice_merging_testing();
extern void TV_measurements_testing();
	//extern void pCT_development();

