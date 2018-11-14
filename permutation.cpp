#include <stdio.h>
#include <string.h>

#define STRING "abcd"
#define STRING_SIZE 5

void permute(char string[], int start, int end);
void swap(char string[], int i, int j);
char* getString();

int main(){
	char fullString[11];
	printf("Enter the characters (1-10): ");
	scanf("%s", &fullString);
	printf("\n\n-----RESULT-----\n\n");
	
	int stringLength = strlen(fullString);
	char string[stringLength];
	strcpy(string, fullString);
	
	permute(string, 0, stringLength);
}

void permute(char string[], int start, int end){
	if(start == end){
		for(int i = 0; i < end; i++)
			printf("%c ", string[i]);
		printf("\n");
	}
	else{
		for(int i = start; i < end; i++){
			swap(string, i, start);
			permute(string, start + 1, end);
			swap(string, i, start);
		}
	}
}

void swap(char string[], int i, int j){
	char temp = string[j];
	string[j] = string[i];
	string[i] = temp;
}

