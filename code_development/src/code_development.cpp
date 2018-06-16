#include "../include/code_development.h"
#include "../include/common.h"
//#include "common.cpp"
//#include "../include/AKS_development.h"
//#include "../include/pCT_development.h"
//#include "../include/walker_development.h"

int main(int argc, char * argv[])
{
	init_test_control();
	test_of(structdefs);
	test_of(pCT);
	test_of(AKS);
	test_of(walker);
	exit_program();
}
