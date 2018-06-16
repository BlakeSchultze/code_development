#include "../include/pCT_development.h"

//UINT DROP_BLOCK_SIZE = 3200;
//UINT reconstruction_histories , DROP_last_block_size, num_DROP_blocks;
//const BLOCK_ORDERING		DROP_BLOCK_ORDER		= CYCLIC;
//BLOCK_ORDERING block_order	= BLOCK_ORDERING(0);
////BLOCK_ORDERING block_order	= BLOCK_ORDERING{0};
////BLOCK_ORDERING block_order	= BLOCK_ORDERING[0];
//std::vector<UINT> DROP_block_sizes;
//std::vector<UINT> DROP_block_order;
//std::vector<UINT> DROP_block_start_positions;
//UINT k = 4, ELL = 10, N = 5, K = 12;
//const char BASH_ECHO_CMD[]			= "echo -e";										// Command to secure copy data/directories between clusters/nodes
//const char WIN_ECHO_CMD[]			= "echo";											// Command to secure copy data/directories between clusters/nodes
//const bool SAMP_PROC3= true;
//int ITERATIONS = 12, SLICES = 20, COLUMNS = 200, ROWS = 200;
//const char PCT_DATA_DIR[] = "D:\\pCT\\pCT_data\\reconstruction_data\\CTP404_Sensitom\\Experimental\\B_25600\\";
//const char X_BASENAME[] = "x_";
//const char TV_CALCULATED[] = "TV_calculated.csv";
//const char TV_MEASUREMENTS[] = "TV_measurements.txt";
//const char* C_CONST_CHAR = "c";
//const char* CONTINUE_PROMPT ="Enter 'c' to continue execution, any other character exits program";
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void exit_program()
{
	//char user_response[20];
	//timer( STOP );
	change_text_color( YELLOW_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, false);std::cin.clear();
	puts("Hit enter to stop...");
	 //Clean the stream and ask for input
	change_text_color( GREEN_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, false);std::cin.clear();
		//ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cin.get();
	exit(1);
}
void exit_program_if( bool early_exit)
{
	if( early_exit )
	{
		//char user_response[20];
		//timer( STOP );
		puts("Hit enter to stop...");
		//fgets(user_response, sizeof(user_response), stdin);
		 //Clean the stream and ask for input
		std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
		std::cin.get();
		exit(1);
	}
}
void exit_program_if( const char* exit_statement, char continue_character)
{
	puts(exit_statement);
	char user_response;
	std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cin.get(user_response);
	//while( user_response != continue_character )
	if( user_response != static_cast<int>(continue_character) )
	//if( user_response != continue_character )
		exit(1);
}
bool exit_prompt( const char* exit_statement, char continue_character)
{
	puts(exit_statement);
	//char user_response[256];
	char user_response;
	std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
	std::cin.get(user_response);
	//while( user_response != continue_character )
	if( user_response != static_cast<int>(continue_character) )
	//if( user_response != continue_character )
		return true;
		//	exit(1);
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void generate_history_sequence(ULL N, ULL offset_prime, ULL* sequence )
{
    sequence = (ULL*) calloc( N, sizeof(ULL));
	for( ULL i = 1; i < N; i++ )
        sequence[i] = ( sequence[i-1] + offset_prime ) % N;
}
void verify_history_sequence(ULL N, ULL offset_prime, ULL* sequence )
{
	for( ULL i = 1; i < N; i++ )
    {
        if(sequence[i] == 1)
        {
            printf("repeats at i = %llu\n", i);
            printf("history_sequence[i] = %llu\n", sequence[i]);
            break;
        }
        if(sequence[i] > N)
        {
            printf("exceeds at i = %llu\n", i);
            printf("history_sequence[i] = %llu\n", sequence[i]);
            break;
        }
    }
}
void print_history_sequence(ULL* sequence, ULL print_start, ULL print_end )
{
    for( ULL i = print_start; i < print_end; i++ )
		printf("history_sequence[i] = %llu\n", sequence[i]);
}
//void apply_history_sequence(ULL N, ULL offset_prime, ULL* sequence)
//{
//	if(RECON_HISTORY_ORDERING == PRIME_PERMUTATION)
//	{
//		//
//		bin_num_vector_reconstruction.reserve(N);
//		//gantry_angle_vector.reserve(gantry_angle_vector);
//		WEPL_vector_reconstruction.reserve(N);
//		x_entry_vector_reconstruction.reserve(N);
//		y_entry_vector_reconstruction.reserve(N);
//		z_entry_vector_reconstruction.reserve(N);
//		x_exit_vector_reconstruction.reserve(N);
//		y_exit_vector_reconstruction.reserve(N);
//		z_exit_vector_reconstruction.reserve(N);
//		xy_entry_angle_vector_reconstruction.reserve(N);
//		xz_entry_angle_vector_reconstruction.reserve(N);
//		xy_exit_angle_vector_reconstruction.reserve(N);
//		xz_exit_angle_vector_reconstruction.reserve(N);
//		first_MLP_voxel_vector_reconstruction.reserve(N);
//
//		//
//		generate_history_sequence(N, offset_prime, sequence );
//
//		for(int i = 0; i < N; i++ )
//		{
//			read_index = sequence[i];
//			bin_num_vector_reconstruction.push_back(bin_num_vector[read_index]);
//			//gantry_angle_vector.push_back(gantry_angle_vector[read_index]);
//			WEPL_vector_reconstruction.push_back(WEPL_vector[read_index]);
//			x_entry_vector_reconstruction.push_back(x_entry_vector[read_index]);
//			y_entry_vector_reconstruction.push_back(y_entry_vector[read_index]);
//			z_entry_vector_reconstruction.push_back(z_entry_vector[read_index]);
//			x_exit_vector_reconstruction.push_back(x_exit_vector[read_index]);
//			y_exit_vector_reconstruction.push_back(y_exit_vector[read_index]);
//			z_exit_vector_reconstruction.push_back(z_exit_vector[read_index]);
//			xy_entry_angle_vector_reconstruction.push_back(xy_entry_angle_vector[read_index]);
//			xz_entry_angle_vector_reconstruction.push_back(xz_entry_angle_vector[read_index]);
//			xy_exit_angle_vector_reconstruction.push_back(xy_exit_angle_vector[read_index]);
//			xz_exit_angle_vector_reconstruction.push_back(xz_exit_angle_vector[read_index]);
//			first_MLP_voxel_vector_reconstruction.push_back(first_MLP_voxel_vector[read_index]);
//		}
//	}
//	else if(RECON_HISTORY_ORDERING == SEQUENTIAL)
//	{
//		bin_num_vector_reconstruction = bin_num_vector;
//		//gantry_angle_vector = gantry_angle_vector;
//		WEPL_vector_reconstruction = WEPL_vector;
//		x_entry_vector_reconstruction = x_entry_vector;
//		y_entry_vector_reconstruction = y_entry_vector;
//		z_entry_vector_reconstruction = z_entry_vector;
//		x_exit_vector_reconstruction = x_exit_vector;
//		y_exit_vector_reconstruction = y_exit_vector;
//		z_exit_vector_reconstruction = z_exit_vector;
//		xy_entry_angle_vector_reconstruction = xy_entry_angle_vector;
//		xz_entry_angle_vector_reconstruction = xz_entry_angle_vector;
//		xy_exit_angle_vector_reconstruction = xy_exit_angle_vector;
//		xz_exit_angle_vector_reconstruction = xz_exit_angle_vector;
//		first_MLP_voxel_vector_reconstruction = first_MLP_voxel_vector;
//	}
////	bin_num_vector_ordered = ;
////		gantry_angle_vector_ordered;
////		WEPL_vector_ordered;
////		x_entry_vector_ordered;
////		y_entry_vector_ordered;
////		z_entry_vector_ordered;
////		x_exit_vector_ordered;
////		y_exit_vector_ordered;
////		z_exit_vector_ordered;
////		xy_entry_angle_vector_ordered;
////		xz_entry_angle_vector_ordered;
////		xy_exit_angle_vector_ordered;
////		xz_exit_angle_vector_ordered;
////		first_MLP_voxel_vector_ordered;
////		voxel_x_vector_ordered;
////		voxel_y_vector_ordered;
////		voxel_z_vector_ordered;
//}
void shuffle_blocks()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle (DROP_block_order.begin(),				DROP_block_order.end(),				std::default_random_engine(seed));
	std::shuffle (DROP_block_sizes.begin(),				DROP_block_sizes.end(),				std::default_random_engine(seed));
	std::shuffle (DROP_block_start_positions.begin(),	DROP_block_start_positions.end(),	std::default_random_engine(seed));
	/*std::srand ( seed );
	std::random_shuffle ( DROP_block_order.begin(), DROP_block_order.end() );
	std::srand ( seed );
	std::random_shuffle ( DROP_block_sizes.begin(), DROP_block_sizes.end() );
	std::srand ( seed );
	std::random_shuffle ( DROP_block_start_positions.begin(), DROP_block_start_positions.end() );
	*/
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//std::shuffle (DROP_block_order.begin(), DROP_block_order.end(), std::default_random_engine(seed));
	//std::shuffle (DROP_block_sizes.begin(), DROP_block_sizes.end(), std::default_random_engine(seed));
	//std::shuffle (DROP_block_start_positions.begin(), DROP_block_start_positions.end(), std::default_random_engine(seed));
}
void rotate_blocks_left()
{
	 std::rotate(DROP_block_order.begin(),				DROP_block_order.begin() + 1,			DROP_block_order.end());
	 std::rotate(DROP_block_sizes.begin(),				DROP_block_sizes.begin() + 1,			DROP_block_sizes.end());
	 std::rotate(DROP_block_start_positions.begin(),	DROP_block_start_positions.begin() + 1, DROP_block_start_positions.end());
}
void rotate_blocks_right()
{
	std::rotate(DROP_block_order.rbegin(),				DROP_block_order.rbegin() + 1,				DROP_block_order.rend());
	std::rotate(DROP_block_sizes.rbegin(),				DROP_block_sizes.rbegin() + 1,				DROP_block_sizes.rend());
	std::rotate(DROP_block_start_positions.rbegin(),	DROP_block_start_positions.rbegin() + 1,	DROP_block_start_positions.rend());
}
void print_DROP_block_info()
{
	for(uint i = 0; i < num_DROP_blocks; i++)
	{
		cout << "i = " << i << ": " << DROP_block_order[i] << std::endl;
	}
	cout << endl;
	for(uint i = 0; i < num_DROP_blocks; i++)
	{
		cout << "i = " << i << ": " << DROP_block_sizes[i] << std::endl;
	}
	cout << endl;
	for(uint i = 0; i < num_DROP_blocks; i++)
	{
		cout << "i = " << i << ": " << DROP_block_start_positions[i] << std::endl;
	}
	cout << endl;
}
void recon_DROP_initializations()
{
	reconstruction_histories = 232546;
	DROP_last_block_size = reconstruction_histories % DROP_BLOCK_SIZE;
	num_DROP_blocks = static_cast<UINT>(ceil(reconstruction_histories / DROP_BLOCK_SIZE));

	std::vector<UINT> DROP_block_sizes_constructor( num_DROP_blocks, DROP_BLOCK_SIZE);
	std::vector<UINT> DROP_block_order_constructor( num_DROP_blocks);
	std::vector<UINT> DROP_block_start_positions_constructor( num_DROP_blocks, DROP_BLOCK_SIZE);

	DROP_block_sizes_constructor.back() = DROP_last_block_size;
	std::iota (DROP_block_order_constructor.begin(), DROP_block_order_constructor.end(), 0);
	DROP_block_start_positions_constructor.front() = 0;
	for(uint i = 1; i < num_DROP_blocks; i++)
		DROP_block_start_positions_constructor[i] += DROP_block_start_positions_constructor[i - 1];

	DROP_block_sizes = DROP_block_sizes_constructor;
	DROP_block_order = DROP_block_order_constructor;
	DROP_block_start_positions = DROP_block_start_positions_constructor;

	std::cout << "Initial block info construction" << std::endl;
	print_DROP_block_info();


	std::cout << "Rotate left block info" << std::endl;
	rotate_blocks_left();
	print_DROP_block_info();
	if(exit_prompt( CONTINUE_PROMPT, CHAR_ID_CHAR))
		exit_program();

	std::cout << "Rotate right block info" << std::endl;
	rotate_blocks_right();
	print_DROP_block_info();
	if(exit_prompt( CONTINUE_PROMPT, CHAR_ID_CHAR))
		exit_program();

	std::cout << "Shuffled block info" << std::endl;
	shuffle_blocks();
	print_DROP_block_info();
	if(exit_prompt( CONTINUE_PROMPT, CHAR_ID_CHAR))
		exit_program();

	//switch{DROP_BLOCK_ORDER}
	//{
	//case CYCLIC:			break;
	//case ROTATE_LEFT:			break;
	//case ROTATE_RIGHT:		break;
	//case RANDOMLY_SHUFFLE:		break;
	//}

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
std::string set_procedure_on_off_string(const bool procedure_on)
{

	std::string ON_STRING("ON");
	std::string OFF_STRING("OFF");
	if(procedure_on)
		return ON_STRING;
	else
		return OFF_STRING;
}
void tuple_mapping()
{
	std::multimap<std::string, unsigned int> EXECUTION_LOG_SWITCHMAP;

	EXECUTION_LOG_SWITCHMAP.insert( std::pair<std::string,unsigned int>(std::string("OUTPUT_DIRECTORY"), 2));
	EXECUTION_LOG_SWITCHMAP.insert( std::pair<std::string,double>(std::string("INPUT_DIRECTORY"), 1));
	EXECUTION_LOG_SWITCHMAP.insert( std::pair<std::string,unsigned int>(std::string("INPUT_FOLDER"), 3));
	for( std::multimap<std::string, unsigned int>::iterator it=EXECUTION_LOG_SWITCHMAP.begin(); it != EXECUTION_LOG_SWITCHMAP.end(); it++)
	{
		cout << it->first << it->second << endl;
	}
}
int randi(int min_value, int max_value)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::uniform_int_distribution<int> distribution(min_value, max_value);
	std::default_random_engine generator(seed);
	return distribution(generator);
}
std::string color_encoding_statement(const char* text_color_code, const char* background_color_code, const char* underlining_coding )
{
	std::string out_statement = std::string(OPEN_COLOR_ESCAPE_SEQ) + std::string(text_color_code) + std::string(";") + std::string(background_color_code) + std::string(underlining_coding)+ std::string("m") ;
	return out_statement;
}
std::string change_text_color_cmd(const char* text_color_code, const char* background_color_code, const char* underlining_coding, bool reset)
{
	std::string color_encoding;
	if( !reset ) color_encoding = color_encoding_statement(text_color_code, background_color_code, underlining_coding );
	else color_encoding = std::string(CLOSE_COLOR_ESCAPE_SEQ);
	return echo_cmd(color_encoding);
}
void change_text_color(const char* text_color_code, const char* background_color_code, const char* underlining_coding, bool reset)
{
	std::string color_encoding = change_text_color_cmd(text_color_code, background_color_code, underlining_coding, reset);
	system(color_encoding.c_str());
}
void print_section_separator(const char separation_char, const char* text_color_code, const char* background_color_code, const char* underlining_coding )
{
	std::string section_separator_str(CONSOLE_WINDOW_WIDTH, separation_char);
	print_colored_text(section_separator_str, text_color_code, background_color_code, underlining_coding );
	if(separation_char == MAJOR_SECTION_SEPARATOR)
		print_colored_text(section_separator_str, text_color_code, background_color_code, underlining_coding );
}
void print_section_header( const char* statement, const char separation_char, const char* separator_text_color_code, const char* text_color_code, const char* background_color_code, const char* underlining_coding )
{
	//char header_output[256];
	std::string header_str(statement);
	size_t length = strlen(statement), index = 0, max_line_length = 70, num_dashes, leading_dashes, trailing_dashes, line_length;
	print_section_separator(separation_char, separator_text_color_code, background_color_code, underlining_coding );
	while( index < length )
	{
		//i = 0;
		line_length = std::min(static_cast<int>(length - index), static_cast<int>(max_line_length));
		if( line_length < length - index )
			while( statement[index + line_length] != SPACE_CHAR )
				line_length--;
		num_dashes = CONSOLE_WINDOW_WIDTH - line_length - 2;
		leading_dashes = num_dashes / 2;
		trailing_dashes = num_dashes - leading_dashes;

		std::string leading_dashes_str(leading_dashes, separation_char);
		std::string trailing_dashes_str(trailing_dashes, separation_char);
		leading_dashes_str.append(SPACE_STRING);
		trailing_dashes_str.insert(0, SPACE_STRING);
		std::string leading_dashes_str_colored = colored_text(leading_dashes_str, separator_text_color_code, background_color_code, underlining_coding );
		std::string trailing_dashes_str_colored = colored_text(trailing_dashes_str, separator_text_color_code, background_color_code, underlining_coding );
		std::string header_substr = header_str.substr (index, line_length);
		std::string header_substr_colored = colored_text(header_substr, text_color_code, background_color_code, underlining_coding );
		std::string header_str = leading_dashes_str_colored + header_substr_colored + trailing_dashes_str_colored;
		std::string echo_statement = echo_cmd(header_str);
		system(echo_statement.c_str());
		index += line_length;
	}
	print_section_separator(separation_char, separator_text_color_code, background_color_code, underlining_coding );
}
void print_section_exit( const char* statement, const char* leading_statement_chars, const char* separator_text_color_code, const char* text_color_code, const char* background_color_code, const char* underlining_coding )
{
	//char section_exit_output[256];
	size_t length = strlen(statement);
	size_t num_leading_chars = strlen(leading_statement_chars);
	size_t index = 0, line_length, max_line_length = CONSOLE_WINDOW_WIDTH - 10;
	std::string section_exit_str(statement);
	std::string leading_spaces(num_leading_chars, SPACE_CHAR);
	std::string leading_chars_str(leading_statement_chars);
	leading_chars_str.append(SPACE_STRING);
	std::string leading_chars_str_colored = colored_text(leading_chars_str, separator_text_color_code, background_color_code, underlining_coding );
	while( index < length )
	{
		line_length = std::min(static_cast<int>(length - index), static_cast<int>(max_line_length));
		if( line_length < length - index )
			while( statement[index + line_length] != SPACE_CHAR )
				line_length--;
		std::string section_exit_substr = section_exit_str.substr (index, line_length);
		std::string section_exit_substr_colored = colored_text(section_exit_substr, text_color_code, background_color_code, underlining_coding );
		std::string section_exit_output = leading_chars_str_colored + section_exit_substr_colored;
		std::string echo_statement = echo_cmd(section_exit_output);
		system(echo_statement.c_str());
		leading_chars_str_colored = colored_text(leading_spaces, separator_text_color_code, background_color_code, underlining_coding );
		index += line_length;
	}
	puts(EMPTY_STRING);
}
void print_multiline_bash_results(const char* command, const char* text_color_code, const char* background_color_code, const char* underlining_coding )
{
	std::string echo_command = echo_statement("${i}", text_color_code, background_color_code, underlining_coding );
	#if defined(_WIN32) || defined(_WIN64)
		sprintf(__system_command, "%s %s", command, echo_command.c_str());
		change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, false);
		system(__system_command);
		change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, true);
	#else
		sprintf(__system_command, "OIFS=$IFS; IFS=$'\\n'; for i in $(%s); do %s; done; IFS=$OIFS", command, echo_command.c_str());
		system(__system_command);
	#endif
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------- Header for pCT reconstruction program -------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void preprocessing_testing()
{
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
	printf("file_size2 = %llu\n", file_size2);
	printf("fileFraction = %f\n", fileFraction);
	printf("sizeToUse = %ud\n", sizeToUse);
	printf("sizeToUse2 = %ud\n", sizeToUse2);

}
void pCT_general_testing()
{
	//tuple_mapping();
	int num = 2;
	int num2 = 3;
	double roottwo = sqrt(((num)^2) + ((num2)^2));
	unsigned int roottwoint = static_cast<unsigned int>(sqrt((num^2) +(num2^2)));
	printf("roottwo = %6.6lf\n", roottwo );
	printf("roottwoint = %d\n", roottwoint );

	int t = 4;
	int* t_point = &t;
	cout << (*t_point) << endl;
	t--;
	cout << (*t_point) << endl;
}
void pCT_stringops_testing()
{
	//char FBP_FILTER_CSTRING[32];
	//char HULL_FILTER_CSTRING[32];
	//char X_0_FILTER_CSTRING[32];
		//set_procedure_on_off_string(SAMP_PROC, FBP_FILTER_CSTRING);
		//set_procedure_on_off_string(SAMP_PROC3, HULL_FILTER_CSTRING);
		//printf("%s\n", FBP_FILTER_CSTRING);
		//printf("%s\n", HULL_FILTER_CSTRING);
		std::string FBP_FILTER_STRING= set_procedure_on_off_string(SAMP_PROC3);
		std::string HULL_FILTER_STRING= set_procedure_on_off_string(SAMP_PROC2);
		cout << FBP_FILTER_STRING << endl;
		cout << HULL_FILTER_STRING << endl;
		if(exit_prompt( CONTINUE_PROMPT, CHAR_ID_CHAR))
			exit_program();
}
void pCT_printing_testing()
{
    //char __ls_cmd_win[] = "dir -/b /a:d";
    //char __ls_cmd_linux[] = "find -maxdepth 1 -type d -printf \"%f\n\"";
	cout<< "colorless hello " << endl;
	print_colored_text("hello", RED_TEXT, BLACK_BACKGROUND, UNDERLINE_TEXT );
	print_colored_text(std::string("hello"), GREEN_TEXT, BLACK_BACKGROUND, UNDERLINE_TEXT );
	sprintf( __print_statement, "Performing testing of functions currently in development");
	print_section_header( __print_statement, MAJOR_SECTION_SEPARATOR, RED_TEXT, RED_TEXT, WHITE_BACKGROUND, DONT_UNDERLINE_TEXT );
	print_section_exit( "Finished input data verification", SECTION_EXIT_CSTRING, GREEN_TEXT, RED_TEXT, BLACK_BACKGROUND, DONT_UNDERLINE_TEXT );
	print_labeled_value("COLUMNS =", 200, GREEN_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	print_labeled_value("COLUMNS =", 3.5698, RED_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	print_labeled_value("COLUMNS =", "clm", BLUE_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	print_labeled_value("COLUMNS =", 'a', YELLOW_TEXT, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	print_multiline_bash_results(__ls_cmd_win, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	//print_multiline_bash_results(__ls_cmd_linux, LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT);
	change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, false);
	change_text_color( LIGHT_PURPLE_TEXT, GRAY_BACKGROUND, DONT_UNDERLINE_TEXT, true);
}
void TVS_beta_sequence_testing()
{
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
	for( uint exponent = 0; exponent < TVS_BETA_SEQUENCE_LENGTH; exponent++ )
		TVS_beta_sequence_h[exponent] = powf(ALPHA, exponent);
	for( uint exponent = ELL_0; exponent < TVS_BETA_SEQUENCE_LENGTH; exponent++ )
		printf("TVS_beta_sequence_h[%d]  = %6.12lf\n", exponent, TVS_beta_sequence_h[exponent]  );

	printf("TVS_beta_sequence_h[%d]  = %6.12lf\n", ELL, TVS_beta_sequence_h[ELL]  );

}
void TVS_ell_assign_testing()
{
	k = 4, ELL = 10, N = 5, K = 12;
	ELL = randi(k-1, ELL);										// Randomly choose integer in [k,ELL] using default engine, resulting in a larger perturbation factor
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
}
void block_ordering_testing()
{
	recon_DROP_initializations();
	BLOCK_ORDERING block_order	= BLOCK_ORDERING(0);
	cout << ( block_order == ROTATE_LEFT) << endl;
}
void slice_merging_testing(){ combine_set_x_n_slices( X_BASENAME, PCT_DATA_DIR, ITERATIONS, COLUMNS, ROWS, SLICES, OVERWRITE ); }
void TV_measurements( const char* directory, const int iterations, bool overwrite )
{
	__line_sstream = ls(std::string(PCT_DATA_DIR));
	while(__line_sstream >> __termout)
	{
		sprintf(__csvfile, "%s\\%s\\%s", directory, __termout.c_str(), TV_CALCULATED);
		sprintf(__textfile, "%s\\%s\\%s", directory, __termout.c_str(), TV_MEASUREMENTS);
		cout<< "dir: " << __termout << endl;
		__input_file.open(__csvfile ); // declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
		__output_file.open(__textfile ); // declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
		__i = 0;
		while ( __input_file.good() )
		{
			std::getline ( __input_file, __input_value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
			if( __i >= CSV_SKIP_2_TV )
			{
				__output_file.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
				__output_file.precision(6);
				__output_file << std::stod(__input_value) << endl <<std::stod(__input_value) << endl;
	//			cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
	//			cout.precision(6);
	//			cout << std::stod(__input_value) << endl <<std::stod(__input_value) << endl;
			}
			__i++;
        //	if(__i > 1 ) return;
		}
		__input_file.close();
		__output_file.close();
	}
}
void TV_measurements_testing(){TV_measurements( PCT_DATA_DIR, ITERATIONS, true );}
void pCT_development()
{
	//construct_pCT_params();
	__string = string_cat("Hello", 16, " World!! ", " Please ", " work ");
	cout << __string << endl;
	__string = string_cat("Hello ", "World!! ", "Please ", "work ");
	cout << __string << endl;
	//sprintf( __system_command, "%s %s", __ls_cmd_win, PCT_DATA_DIR);
	test_of(TV_CSV_to_TXT);
	test_of(pCT_general);
	test_of(pCT_stringops);
	test_of(pCT_printing);
	test_of(TVS_beta_sequence);
	test_of(TVS_ell_assign);
	test_of(pCT_block_ordering);
	test_of(pCT_slice_merging);
}
