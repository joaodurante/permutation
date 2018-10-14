#include <stdio.h>
#include <string.h>

#define STRING "abcd"
#define STRING_SIZE 5

void permute(char string[], int start, int end);
void swap(char string[], int i, int j);

int main(){
	char string[STRING_SIZE] = STRING;
	int stringSize = STRING_SIZE - 2; //STRING_SIZE - "\0" - last char
	permute(string, 0, stringSize);
	getchar();
}

void permute(char string[], int start, int end){
	if(start == end){
		for(int i = 0; i <= end; i++)
			printf("%c ", string[i]);
		printf("\n");
	}
	else{
		for(int i = start; i <= end; i++){
			swap(string, start, i);
			permute(string, start + 1, end);
			swap(string, start, i);
		}
	}
}

void swap(char string[], int i, int j){
	char temp = string[i];
	string[i] = string[j];
	string[j] = temp;
}

