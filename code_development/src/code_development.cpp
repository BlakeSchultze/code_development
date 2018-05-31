#include "../include/code_development.h"
#include "../include/AKS_development.h"
#include "../include/pCT_development.h"
#include "../include/ReminderWalker.h"

#define pCT_test			ON
const bool pCT_printing_test = ON;
const bool preprocessing_test = OFF;
const bool pCT_general_test = OFF;
const bool pCT_stringops_test = OFF;
const bool TVS_beta_sequence_test = OFF;
const bool TVS_ell_assign_test = OFF;
const bool block_ordering_test = OFF;
const bool slice_merging_test = OFF;

#define AKS_test			OFF
#define ReminderWalker_test OFF

int main(int argc, char * argv[])
{
	pCT_development(pCT_test);
	AKS_development(AKS_test);		
	ReminderWalker(ReminderWalker_test);
	exit_program();	
	return 0;
}
