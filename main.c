// Includes from ...
#include "primitives/core.h"
#include "primitives/linkedList.h"

#include "interfaces/gameLoop.h"

#include "tests/tests.h"


int main(int argc, char *argv[]){
	printf("%d\n", 0 + (0<<1));
	printf("%d\n", 0 + (1<<1));
	printf("%d\n", 1 + (0<<1));
	printf("%d\n", 1 + (1<<1));


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

	// EXIT
	return EXIT_SUCCESS;
}