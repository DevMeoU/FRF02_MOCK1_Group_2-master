#include "hal.h"



void main(int argc, char* argv[]){
    const char *filePath = "floppy.img";
	// const char *path = argv[1];
	uint32_t numberOfElements = 0;	
	uint32_t input = 0;
	int32_t run = 0;
	uint32_t u_32checkFAT;
	printf("\n\n");
	u_32checkFAT = checkFatTypes(filePath);
	if(u_32checkFAT == 0)
	{
		printf("\t\t\t\t[INFO]Check file is: FAT12");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n\n");
		printf("\t\t\t\t[INFO]Begin read file: FAT12");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n");
		do {
			/* Open root directory when run program */
			if (run == 0) {
				system("cls");
				numberOfElements = openRoot(filePath);
				printf("\n\n\t0. Exit");
				run++;
			}
			/* The user will input a number from 0 to numberOfElements */
			input = inputNumberByUser(numberOfElements);
			/* If the user inputs 0, open the previous folder */
			if (input == 0) {
				if (run > 1){
					system("cls");
					numberOfElements = closeDirectory(filePath); 
				}
				run--;
			}
			else {
				system("cls");
				numberOfElements = openDirectory(filePath, input);
				run++;
			}
			if (run > 1) {
				printf("\n\n\t0. Back");
			}
			if (run == 1) {
				printf("\t\n\n\t0. Exit");
			}
		} while (run);
	}
	else if(u_32checkFAT == 1)	
	{
		printf("\t\t\t\tINFO]Check file is: FAT16");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n\n");
		printf("\t\t\tINFO]Begin read file: FAT16");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n");
	}
	else if(u_32checkFAT == 2)	
	{
		printf("\t\t\t\t[INFO]Check file is: FAT32");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n\n");
		printf("\t\t[INFO]Begin read file: FAT32");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n");
	}
	else	
	{
		printf("\t\t\t\t[ERROR]This file is not FAT");
		printf("\n");
		printf("\t------------------------------------------------------------------------");
		printf("\n");
	}
}


