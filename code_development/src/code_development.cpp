#include "../include/code_development.h"
#include "../include/AKS_development.h"
#include "../include/pCT_development.h"

int main(int argc, char * argv[])
{
	//print_colored_text("hello", RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	//echo_statement<const char*>("hello", RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	//echo_statement<std::string>(std::string("hello"), RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	//echo_statement("hello", RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	//echo_statement(std::string("hello"), RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	cout<< "colorless hello " << endl;
	print_colored_text("hello", RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	print_colored_text(std::string("hello"), RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	sprintf_s( print_statement, "Performing testing of functions currently in development");
	print_section_header( print_statement, MAJOR_SECTION_SEPARATOR, RED_TEXT, RED_TEXT, WHITE_BACKGROUND, DONT_UNDERLINE_TEXT );
	print_section_exit( "Finished input data verification", SECTION_EXIT_CSTRING, RED_TEXT, RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );	
	int x = 4;
	//std::string num(x);
	print_labeled_value("COLUMNS =", 200, GREEN_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
		print_labeled_value("COLUMNS =", 3.5698, RED_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
		print_labeled_value("COLUMNS =", "clm", BLUE_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
		print_labeled_value("COLUMNS =", 'a', BLUE_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	print_multiline_bash_results("dir /b", LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, false);
exit_program();		
	change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, true);
return 0;
//	#define ON						(0==0)									// [T/F] Definition of boolean "ON" as equivalent to 'true'
//#define OFF						(!ON)									// [T/F] Definition of boolean "OFF" as equivalent to 'false' (technically 'not true')
//#define START					true									// [T/F] Used as an alias for true for starting timer
//#define STOP					false									// [T/F] Used as an alias for false for stopping timer
//#define SAMP_PROC				ON
//	#define SAMP_PROC2				OFF
//const bool SAMP_PROC3= true;
//
//recon_DROP_initializations();
//
////char FBP_FILTER_CSTRING[32];
////char HULL_FILTER_CSTRING[32];
////char X_0_FILTER_CSTRING[32];
//
//tuple_mapping();
//	
//	//set_procedure_on_off_string(SAMP_PROC, FBP_FILTER_CSTRING);
//	//set_procedure_on_off_string(SAMP_PROC3, HULL_FILTER_CSTRING);
//	//printf("%s\n", FBP_FILTER_CSTRING);
//	//printf("%s\n", HULL_FILTER_CSTRING);
//	std::string FBP_FILTER_STRING= set_procedure_on_off_string(SAMP_PROC3);
//	std::string HULL_FILTER_STRING= set_procedure_on_off_string(SAMP_PROC2);
//	cout << FBP_FILTER_STRING << endl;
//	cout << HULL_FILTER_STRING << endl;
//	if(exit_prompt( "Enter 'c' to continue execution, any other character exits program", 'c'))
//		exit_program();
//	
//	// AKS
//// n=11701, r=11699, q=5849, s=2923
//// n=1000000007, r=57287, q=28643, s=14311
////
//// Bernstein
//// n=349, r=347, q=173, s=140
//// n=1000000007, r=3623, q=1811, s=1785
//	bool prime_test_result = false;
//	unsigned int n0;
//	while(true)
//	{
//		//cout << "n ? ";
//		//cin >> n0;
//
//		//unsigned int n = n0;
//		prime_test_result = is_prime_Bernstein();
//		printf("prime_test_result = %d\n", prime_test_result);
//		//exit_program_if( true);
//		//exit_program_if( "Enter 'c' to continue execution, any other character exits program", 'c');
//		if(exit_prompt( "Enter 'c' to continue execution, any other character exits program", 'c'))
//			break;
//	}
	size_t file_size = 11379018252;
	ULL file_size2 = 11379018252;
	float fileFraction = 1.0;
	size_t sizeToUse = int(fileFraction*float(file_size));
	size_t sizeToUse2 = static_cast<size_t>(fileFraction*file_size);
	unsigned long long sizeToUse3 = static_cast<unsigned long long>(fileFraction*file_size2);
	size_t sizeToUse4 = fileFraction*file_size;
	cout << file_size << " " << static_cast<int>(file_size) << endl;
	cout << file_size2 << endl;
	cout << sizeToUse << endl;
	cout << sizeToUse2 << endl;
	cout << sizeToUse3 << endl;
	cout << sizeToUse4 << endl;
	cout << (static_cast<size_t>(fileFraction*file_size2)) << endl;
	printf("file_size = %Iu\n", (unsigned long)file_size);
	printf("file_size2 = %lu\n", file_size2);
	printf("fileFraction = %f\n", fileFraction);
	printf("sizeToUse = %ld\n", sizeToUse);
	printf("sizeToUse2 = %zu\n", sizeToUse2);
	
	int num = 2;
	int num2 = 3;
	double roottwo = sqrt(num^2 + num2^2);
	unsigned int roottwoint = static_cast<unsigned int>(sqrt(num^2 + num2^2));
	printf("roottwo = %6.6lf\n", roottwo );
	printf("roottwoint = %d\n", roottwoint );
	
	//enum BLOCK_ORDERING			{ CYCLIC, ROTATE_LEFT, ROTATE_RIGHT, RANDOMLY_SHUFFLE, END_BLOCK_ORDERING					};				// Define the data formats that are supported
	//const BLOCK_ORDERING		DROP_BLOCK_ORDER		= CYCLIC;
	//BLOCK_ORDERING block_order	= BLOCK_ORDERING{0};
	//BLOCK_ORDERING block_order	= BLOCK_ORDERING(0);
	//cout << ( block_order == ROTATE_LEFT) << endl;
	int			RGBLCDshield_menuLevelsV[][6]   =
                                                {
                                                    {1,2,3},
                                                    {4,5,6,7},
                                                    {8,9}, {10,11},{12,13},
                                                    {10,13,14,15,16,17}
                                                };
	int         RGBLCDshield_menuLevelsC[][3][2][6]   =
                                                {
                                                    {
														{{3}},
														{{2,3,4},{2,3,4}},
														{{1,2},{2,3,4,5,6,7}}
													},
                                                    {
														{{3}},
														{{2,3,4},{2,3,4}},
														{{1,2},{2,3,4,5,6,7}}
													}
                                                };

int         RGBLCDshield_menuLevelsDD[4][3][7];
	
int         RGBLCDshield_menuLevelsD[][4][3][7]   =
                                                {
                                                    {3},
                                                    {
                                                        {3}, 
                                                        {
                                                            {-1}, 
                                                            {1,3}
                                                        },
                                                        {
                                                            {-2},
                                                            {3,2,3,4},
                                                            {3, 2,3,4}
                                                        },
                                                        {
                                                            {-2},
                                                            {2, 1,2},
                                                            {6, 2,3,4,5,6,7}
                                                        }
                                                    },
                                                    {
                                                        {3}, 
                                                        {
                                                            {-1}, 
                                                            {1,3}
                                                        },
                                                        {
                                                            {-2},
                                                            {3,2,3,4},
                                                            {3, 2,3,4}
                                                        },
                                                        {
                                                            {-2},
                                                            {2, 1,2},
                                                            {6, 2,3,4,5,6,7}
                                                        }
                                                    },
                                                    {
                                                        {3}, 
                                                        {
                                                            {-1}, 
                                                            {1,3}
                                                        },
                                                        {
                                                            {-2},
                                                            {3,2,3,4},
                                                            {3, 2,3,4}
                                                        },
                                                        {
                                                            {-2},
                                                            {2, 1,2},
                                                            {6, 2,3,4,5,6,7}
                                                        }
                                                    }
                                                };
	cout << RGBLCDshield_menuLevelsV[0][0] << endl;
	cout << RGBLCDshield_menuLevelsV[1][0] << endl;
	cout << RGBLCDshield_menuLevelsV[1][1] << endl;
	cout << RGBLCDshield_menuLevelsV[1][2] << endl;
	cout << RGBLCDshield_menuLevelsV[0][1] << endl;
	cout << RGBLCDshield_menuLevelsV[2][1] << endl;
	cout << RGBLCDshield_menuLevelsV[2][2] << endl;
	cout << RGBLCDshield_menuLevelsV[2][3] << endl;
	cout << RGBLCDshield_menuLevelsV[2][4] << endl;
	cout << RGBLCDshield_menuLevelsV[3][0] << endl;

	//int         RGBLCDshield_menuLevelsDDD[4][3][7] = {RGBLCDshield_menuLevelsD[2]};	
	int         RGBLCDshield_menuLevelsDDD[] = {*(*RGBLCDshield_menuLevelsD[1][1])};	
	cout << "[0][0][0][0] : " << RGBLCDshield_menuLevelsD[0][0][0][0] << endl;
	cout << "[1][0][0][0] : "<< RGBLCDshield_menuLevelsD[1][0][0][0] << endl; 
	cout << "[1][1][0][0] : "<< RGBLCDshield_menuLevelsD[1][1][0][0] << endl;
	cout << "[1][2][0][0] : "<< RGBLCDshield_menuLevelsD[1][2][0][0] << endl;
	cout << "[1][3][0][0] : "<< RGBLCDshield_menuLevelsD[1][3][0][0] << endl;
	cout << "[0][1][0][0] : "<< RGBLCDshield_menuLevelsD[0][1][0][0] << endl;
	cout << "[2][1][0][0] : "<< RGBLCDshield_menuLevelsD[2][1][0][0] << endl;
	cout << "[2][2][0][0] : "<< RGBLCDshield_menuLevelsD[2][2][0][0] << endl;
	cout << "[2][3][0][0] : "<< RGBLCDshield_menuLevelsD[2][3][0][0] << endl;
	cout << "[2][4][0][0] : "<< RGBLCDshield_menuLevelsD[2][4][0][0] << endl;
	cout << "[3][0][0][0] : "<< RGBLCDshield_menuLevelsD[3][0][0][0] << endl;
		
	cout << "[0][0][1][0] : "<< RGBLCDshield_menuLevelsD[0][0][1][0] << endl;
	cout << "[1][0][1][0] : "<< RGBLCDshield_menuLevelsD[1][0][1][0] << endl;
	cout << "[1][1][1][0] : "<< RGBLCDshield_menuLevelsD[1][1][1][0] << endl;
	cout << "[1][2][1][0] : "<< RGBLCDshield_menuLevelsD[1][2][1][0] << endl;
	cout << "[1][3][1][0] : "<< RGBLCDshield_menuLevelsD[1][3][1][0] << endl;
	cout << "[0][1][1][0] : "<< RGBLCDshield_menuLevelsD[0][1][1][0] << endl;
	cout << "[2][1][1][0] : "<< RGBLCDshield_menuLevelsD[2][1][1][0] << endl;
	cout << "[2][2][1][0] : "<< RGBLCDshield_menuLevelsD[2][2][1][0] << endl;
	cout << "[2][3][1][0] : "<< RGBLCDshield_menuLevelsD[2][3][1][0] << endl;
	cout << "[2][4][1][0] : "<< RGBLCDshield_menuLevelsD[2][4][1][0] << endl;
	cout << "[3][0][1][0] : "<< RGBLCDshield_menuLevelsD[3][0][1][0] << endl;

	cout << "[0][0][1][1] : "<< RGBLCDshield_menuLevelsD[0][0][1][1] << endl;
	cout << "[1][0][1][1] : "<< RGBLCDshield_menuLevelsD[1][0][1][1] << endl;
	cout << "[1][1][1][1] : "<< RGBLCDshield_menuLevelsD[1][1][1][1] << endl;
	cout << "[1][2][1][1] : "<< RGBLCDshield_menuLevelsD[1][2][1][1] << endl;
	cout << "[1][3][1][1] : "<< RGBLCDshield_menuLevelsD[1][3][1][1] << endl;
	cout << "[0][1][1][1] : "<< RGBLCDshield_menuLevelsD[0][1][1][1] << endl;
	cout << "[2][1][1][1] : "<< RGBLCDshield_menuLevelsD[2][1][1][1] << endl;
	cout << "[2][2][1][1] : "<< RGBLCDshield_menuLevelsD[2][2][1][1] << endl;
	cout << "[2][3][1][1] : "<< RGBLCDshield_menuLevelsD[2][3][1][1] << endl;
	cout << "[2][4][1][1] : "<< RGBLCDshield_menuLevelsD[2][4][1][1] << endl;
	cout << "[3][0][1][1] : "<< RGBLCDshield_menuLevelsD[3][0][1][1] << endl;
	
int         RGBLCDshield_menuLevelsE[][4][3][7]   =
                                                {
                                                    {3},//0000
                                                    {
                                                        {3},//1000 
                                                        {
                                                            {-1}, //1100
                                                            {1,1111}//1110,1111
                                                        },
                                                        {
                                                            {-2},//1200
                                                            {3,1211,1212,1213},//1210-3
                                                            {3, 1221,1222,1223}//1220-3
                                                        },
                                                        {
                                                            {-2},//1300
                                                            {2, 1311,1312},//1310-2
                                                            {6, 1321,1322,1323,1324,1325,1326}//1320-6
                                                        }
                                                    },
                                                    {
                                                        {3}, //2000
                                                        {
                                                            {-1}, //2100
                                                            {1,2111}//2110/1
                                                        },
                                                        {
                                                            {-2},//2200
                                                            {3,2211,2212,2213},//2210-3
                                                            {3, 2221,2222,2223}//2220-3
                                                        },
                                                        {
                                                            {-2},//2300
                                                            {2, 2311,2312},//2310-2
                                                            {6, 2321,2322,2323,2324,2325,2326}//2320-6
                                                        }
                                                    },
                                                    {
                                                        {3}, //3000
                                                        {
                                                            {-1}, //3100
                                                            {1,3111}//3110/1
                                                        },
                                                        {
                                                            {-2},//3200
                                                            {3,3211,3212,3213},//3210-3
                                                            {3,3221,3222,3223}//3220-3
                                                        },
                                                        {
                                                            {-2},//3300
                                                            {2,3311,3312},//3310-2
                                                            {6,3321,3322,3323,3324,3325,3326}//3320-6
                                                        }
                                                    }
                                                };
	
	cout << "RGBLCDshield_menuLevelsE[][4][3][7] " << endl<< endl;
	cout << "[0][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[0][0][0][0] << endl;
	cout << "[1][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[1][0][0][0] << endl;
	cout << "[1][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[1][1][0][0] << endl;
	cout << "[1][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[1][2][0][0] << endl;
	cout << "[1][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[1][3][0][0] << endl;

	
	cout << "[1][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[1][1][1][0] << endl;
	cout << "[1][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[1][2][1][0] << endl;
	cout << "[1][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[1][2][2][0] << endl;
	cout << "[1][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[1][3][1][0] << endl;
	cout << "[1][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[1][3][2][0] << endl;
	
	cout << "[1][1][1][1] : "<< RGBLCDshield_menuLevelsE[1][1][1][1] << endl;
	cout << "[1][2][1][1] : "<< RGBLCDshield_menuLevelsE[1][2][1][1] << endl;
	cout << "[1][2][1][2] : "<< RGBLCDshield_menuLevelsE[1][2][1][2] << endl;
	cout << "[1][2][1][3] : "<< RGBLCDshield_menuLevelsE[1][2][1][3] << endl;
	cout << "[1][2][2][1] : "<< RGBLCDshield_menuLevelsE[1][2][2][1] << endl;
	cout << "[1][2][2][2] : "<< RGBLCDshield_menuLevelsE[1][2][2][2] << endl;
	cout << "[1][2][2][3] : "<< RGBLCDshield_menuLevelsE[1][2][2][3] << endl;
	cout << "[1][3][1][1] : "<< RGBLCDshield_menuLevelsE[1][3][1][1] << endl;
	cout << "[1][3][1][2] : "<< RGBLCDshield_menuLevelsE[1][3][1][2] << endl;
	cout << "[1][3][2][1] : "<< RGBLCDshield_menuLevelsE[1][3][2][1] << endl;
	cout << "[1][3][2][2] : "<< RGBLCDshield_menuLevelsE[1][3][2][2] << endl;
	cout << "[1][3][2][3] : "<< RGBLCDshield_menuLevelsE[1][3][2][3] << endl;
	cout << "[1][3][2][4] : "<< RGBLCDshield_menuLevelsE[1][3][2][4] << endl;
	cout << "[1][3][2][5] : "<< RGBLCDshield_menuLevelsE[1][3][2][5] << endl;
	cout << "[1][3][2][6] : "<< RGBLCDshield_menuLevelsE[1][3][2][6] << endl;

	cout << "[2][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[2][0][0][0] << endl;
	cout << "[2][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[2][1][0][0] << endl;
	cout << "[2][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[2][2][0][0] << endl;
	cout << "[2][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[2][3][0][0] << endl;

	cout << "[2][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[2][1][1][0] << endl;
	cout << "[2][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[2][2][1][0] << endl;
	cout << "[2][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[2][2][2][0] << endl;
	cout << "[2][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[2][3][1][0] << endl;
	cout << "[2][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[2][3][2][0] << endl;

	
	cout << "[2][1][1][1] : "<< RGBLCDshield_menuLevelsE[2][1][1][1] << endl;
	cout << "[2][2][1][1] : "<< RGBLCDshield_menuLevelsE[2][2][1][1] << endl;
	cout << "[2][2][1][2] : "<< RGBLCDshield_menuLevelsE[2][2][1][2] << endl;
	cout << "[2][2][1][3] : "<< RGBLCDshield_menuLevelsE[2][2][1][3] << endl;
	cout << "[2][2][2][1] : "<< RGBLCDshield_menuLevelsE[2][2][2][1] << endl;
	cout << "[2][2][2][2] : "<< RGBLCDshield_menuLevelsE[2][2][2][2] << endl;
	cout << "[2][2][2][3] : "<< RGBLCDshield_menuLevelsE[2][2][2][3] << endl;
	cout << "[2][3][1][1] : "<< RGBLCDshield_menuLevelsE[2][3][1][1] << endl;
	cout << "[2][3][1][2] : "<< RGBLCDshield_menuLevelsE[2][3][1][2] << endl;
	cout << "[2][3][2][1] : "<< RGBLCDshield_menuLevelsE[2][3][2][1] << endl;
	cout << "[2][3][2][2] : "<< RGBLCDshield_menuLevelsE[2][3][2][2] << endl;
	cout << "[2][3][2][3] : "<< RGBLCDshield_menuLevelsE[2][3][2][3] << endl;
	cout << "[2][3][2][4] : "<< RGBLCDshield_menuLevelsE[2][3][2][4] << endl;
	cout << "[2][3][2][5] : "<< RGBLCDshield_menuLevelsE[2][3][2][5] << endl;
	cout << "[2][3][2][6] : "<< RGBLCDshield_menuLevelsE[2][3][2][6] << endl;

	cout << "[3][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[3][0][0][0] << endl;
	cout << "[3][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[3][1][0][0] << endl;
	cout << "[3][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[3][2][0][0] << endl;
	cout << "[3][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[3][3][0][0] << endl;

	cout << "[3][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[3][1][1][0] << endl;
	cout << "[3][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[3][2][1][0] << endl;
	cout << "[3][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[3][2][2][0] << endl;
	cout << "[3][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[3][3][1][0] << endl;
	cout << "[3][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[3][3][2][0] << endl;
	
	cout << "[3][1][1][1] : "<< RGBLCDshield_menuLevelsE[3][1][1][1] << endl;
	cout << "[3][2][1][1] : "<< RGBLCDshield_menuLevelsE[3][2][1][1] << endl;
	cout << "[3][2][1][2] : "<< RGBLCDshield_menuLevelsE[3][2][1][2] << endl;
	cout << "[3][2][1][3] : "<< RGBLCDshield_menuLevelsE[3][2][1][3] << endl;
	cout << "[3][2][2][1] : "<< RGBLCDshield_menuLevelsE[3][2][2][1] << endl;
	cout << "[3][2][2][2] : "<< RGBLCDshield_menuLevelsE[3][2][2][2] << endl;
	cout << "[3][2][2][3] : "<< RGBLCDshield_menuLevelsE[3][2][2][3] << endl;
	cout << "[3][3][1][1] : "<< RGBLCDshield_menuLevelsE[3][3][1][1] << endl;
	cout << "[3][3][1][2] : "<< RGBLCDshield_menuLevelsE[3][3][1][2] << endl;
	cout << "[3][3][2][1] : "<< RGBLCDshield_menuLevelsE[3][3][2][1] << endl;
	cout << "[3][3][2][2] : "<< RGBLCDshield_menuLevelsE[3][3][2][2] << endl;
	cout << "[3][3][2][3] : "<< RGBLCDshield_menuLevelsE[3][3][2][3] << endl;
	cout << "[3][3][2][4] : "<< RGBLCDshield_menuLevelsE[3][3][2][4] << endl;
	cout << "[3][3][2][5] : "<< RGBLCDshield_menuLevelsE[3][3][2][5] << endl;
	cout << "[3][3][2][6] : "<< RGBLCDshield_menuLevelsE[3][3][2][6] << endl;

	int path[] = {2,2,0,0};
	int sublvls = LCDshield_num_sublevels(RGBLCDshield_menuLevelsE, path, 1);
	cout << "sublvls = "<< sublvls << endl;
	
	//cout << "0 : "<< RGBLCDshield_menuLevelsDDD[0] << endl;
	//cout << "1 : "<< RGBLCDshield_menuLevelsDDD[1] << endl;
	//cout << "2 : "<< RGBLCDshield_menuLevelsDDD[2] << endl;
	cout << ((-1 + 50) % 50 ) << endl;
	cout << ((49 + 50) % 50 ) << endl;
	cout << ((48 + 50) % 50 ) << endl;
	unsigned int p = 3;
	unsigned int bound = 50;
	unsigned int umaxval = std::numeric_limits<unsigned int>::max();
	int maxval = std::numeric_limits<int>::max() - std::numeric_limits<int>::min()-1;
	cout << (min(p-- + umaxval, bound)) << endl;
	cout << (min((p-- + umaxval),bound)) << endl;
	cout << (min((p-- + umaxval),bound)) << endl;
	cout << (min((p-- + umaxval),bound)) << endl;
	cout << (umaxval) << endl;
	

	int t = 4;
	int* t_point = &t;
	cout << (*t_point) << endl;
	t--;
	cout << (*t_point) << endl;

	int k = 4, ELL = 10, N = 5, K = 12;

	//ELL = randi(k-1, ELL);										// Randomly choose integer in [k,ELL] using default engine, resulting in a larger perturbation factor
	//printf("ELL = %d\n", ELL );
	
	int min = ELL, max = k;
	    if( ELL > k )
        {
        	min = k;
		max = ELL;
	}
	for(int i = 0; i < 10; i++)
		{
			ELL = min + ( rand() % static_cast<int>( max - min + 1 ) );                       // Randomly choose integer in [k,ELL] using specified engine, resulting in a larger perturbation factor
		printf(" = %d %d\n", max,min  );
		printf(" = %d\n",rand()  );
		printf(" = %d\n",static_cast<int>( max - min + 1 ) );
		printf(" = %d\n", rand() % static_cast<int>( max - min + 1 ) );
		printf("ELL = %d\n", ELL );
	}
	if( min == 0) cout << 0 << endl;
	else if ( min == 1) cout << 1 << endl;
	else if ( min == 2) cout << 2 << endl;
	else if ( min == 3) cout << 33 << endl;
	else if ( min == 4) cout << 4 << endl;
	else puts("WRONG MODE");
	//return 0;
	/*
	int TVS_ETA_SEQUENCE_LENGTH = log(TVS_MIN_ETA)/log(ALPHA);
	printf("TVS_ETA_SEQUENCE_LENGTH = %d\n", TVS_ETA_SEQUENCE_LENGTH );
	float* TVS_eta_sequence_h = (float*)calloc( TVS_ETA_SEQUENCE_LENGTH - ELL_0 + 1, sizeof(float));
	for( int exponent = ELL_0, element = 0; exponent < TVS_ETA_SEQUENCE_LENGTH; exponent++, element++ )
		TVS_eta_sequence_h[element] = powf(ALPHA, exponent);
	for( int exponent = ELL_0, element = 0; exponent < TVS_ETA_SEQUENCE_LENGTH; exponent++, element++ )
		printf("TVS_eta_sequence_h[%d]  = %6.12lf\n", element, TVS_eta_sequence_h[element]  );
	*/
	//TVS_BETA_SEQUENCE_LENGTH = log(TVS_MIN_BETA)/log(ALPHA);
	unsigned int TVS_BETA_SEQUENCE_LENGTH = ELL_0 + 1 + N * K;
	float* TVS_beta_sequence_h = (float*)calloc( TVS_BETA_SEQUENCE_LENGTH, sizeof(float));
	for( int exponent = 0; exponent < TVS_BETA_SEQUENCE_LENGTH; exponent++ )
		TVS_beta_sequence_h[exponent] = powf(ALPHA, exponent);
	for( int exponent = ELL_0; exponent < TVS_BETA_SEQUENCE_LENGTH; exponent++ )
		printf("TVS_beta_sequence_h[%d]  = %6.12lf\n", exponent, TVS_beta_sequence_h[exponent]  );

	printf("TVS_beta_sequence_h[%d]  = %6.12lf\n", ELL, TVS_beta_sequence_h[ELL]  );

	print_colored_text("hello", RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
			
			int iterations = 12;
			int slices = 20;
			int columns = 200;
			int rows = 200;
			char basename[] = "x_";
			char bdir[] = "D:\\pCT\\pCT_data\\reconstruction_data\\CTP404_Sensitom\\Experimental\\";
			//combine_set_x_n_slices( filename_base, directory, iterations, x_max, y_max, z_max );
			//combine_set_x_n_slices<float>( basename, bdir, iterations, columns, rows, slices, false );
			
			//int i = 1;
			//char fname[256];
			//char folder[256];
			//char exec_command[512];
			//char mkdir_command[] = "dir -/b";
			//sprintf_s( exec_command, "%s %s", mkdir_command, bdir);
			//std::stringstream  lineStream(exec(exec_command));
			//std::string termout;
			//while(lineStream >> termout)
			//{
			//	//char indir[]="D:\\pCT\\pCT_data\\reconstruction_data\\CTP404_Sensitom\\Experimental\\B_3200_L_0.000100_TV_0_A_0.500000_L0_0_Nk_1\\";
			//	sprintf_s(folder, "%s\\", termout.c_str());
			//	cout<< i++ << ": " << termout << endl;
			//	cout<< folder << endl;
			//	for( int iteration = 0; iteration <= iterations; iteration++)
			//	{
			//		sprintf_s(fname, "%s%d", basename, iteration);
			//		combine_x_slices<float>( fname, bdir, folder, columns, rows, slices );
			//	}
			//}
	exit_program();	return 0;
}
