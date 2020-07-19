#include "func.h"

int main(int argc, char *argv[]) {
	if(argc == 3) run(argv[1], argv[2]);
	else {
		printf("[ ! ] Usage : %s <filename1> <filename2>\n", argv[0]);
		return 0;
	}

	return 0;
}

