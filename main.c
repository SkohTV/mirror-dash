// Includes from ...
#include "interfaces/mainMenu.h"



int main(){
	menuState();
	return EXIT_SUCCESS;
}




//!Finalized version doesn't have access to tests
/*
//int main(int argc, char *argv[]){
	// CLI ARGUMENTS
	for (int i = 0 ; i < argc ; i++){
		switch (argv[i][0]){
			case 't':
				printf("Executing test : %d\n", argv[i][1] - 48);
				testsRun(argv[i][1] - 48) ; break ;
		}
	}

	// DEFAULT RUN WITHOUT ARGUMENTS
	if (argc == 1){ }
}
*/