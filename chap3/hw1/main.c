#include <stdio.h>
#include <string.h>
#include "copy.h"
char line[50][MAXLINE];
char Str[50][MAXLINE];
void copy(char from[], char to[]);

int main()
{
	int len = 0; // length of input text
	int textlen[50]; // save each text length

	int longestTextLen; // save the longest text's length
	int longest = 0; // save the longest text's array number
	int i = 0;

	while (fgets(line[i],MAXLINE,stdin) != NULL) {
		len = strlen(line[i]) - 1;
		if(len == 0)   // I dot't know why, but NULL check is not working
			break;  
		textlen[i]=len;
		copy(line[i], Str[i]);
		i++;

	}

	for(int n=0;n<i;n++){
		longestTextLen = 0;
		for(int m=0;m<i;m++){
			if(longestTextLen < textlen[m]){
				longest = m;
				longestTextLen = textlen[m];
			}
		}
		printf("%s", Str[longest]);
		textlen[longest] = -1;
	}
	return 0;
}
