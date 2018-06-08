#include "../include/code_development.h"
#include "../include/AKS_development.h"
#include "../include/pCT_development.h"
#include "../include/walker_development.h"

const bool pCT_test						=	OFF;
	const bool pCT_printing_test		=	ON;
	const bool preprocessing_test		=	OFF;
	const bool pCT_general_test			=	OFF;
	const bool pCT_stringops_test		=	OFF;
	const bool TVS_beta_sequence_test	=	OFF;
	const bool TVS_ell_assign_test		=	OFF;
	const bool block_ordering_test		=	OFF;
	const bool slice_merging_test		=	OFF;
	const bool TV_CSV_to_TXT_test		=	OFF;
const bool AKS_test						=	OFF;
const bool walker_test					=	OFF;

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
std::stringstream  __line_sstream;
std::vector<std::string> strcat_elements;

int main(int argc, char * argv[])
{
	init_test_control();
	structdef_testing();
	test_of(pCT);
	test_of(AKS);
	test_of(walker);
	exit_program();
}
