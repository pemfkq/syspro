#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	char c;

	int copyType = atoi(argv[1]);
	fp1 = fopen(argv[2], "r");
	fp2 = fopen(argv[3], "w");
	
	if(copyType == 0){
		while((c = fgetc(fp1)) != EOF)
			fputc(c,fp2);
	}else if(copyType == 1){
		while((c = fgetc(fp1)) != EOF){
			c = tolower(c);
			fputc(c,fp2);
		}
	}else{
		while((c = fgetc(fp1)) != EOF){
			c = toupper(c);
			fputc(c,fp2);
		}

	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}
