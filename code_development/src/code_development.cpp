#include "../include/code_development.h"
#include "../include/common.h"
//#include "common.cpp"
//#include "../include/AKS_development.h"
//#include "../include/pCT_development.h"
//#include "../include/walker_development.h"

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


int main(int argc, char * argv[])
{
	init_test_control();
	test_of(structdefs);
	test_of(pCT);
	test_of(AKS);
	test_of(walker);
	exit_program();
}
