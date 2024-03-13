#include <stdio.h>
#define MN 100


int my_strcmp(char word1[MN], char word2[MN]);
void my_strswp(char word1[MN], char word2[MN]);
void my_strcpy(char word1[MN], char word2[MN]);


int main(void)
{
	char word1[MN], word2[MN];
	int len;
	
	printf("文字列1を乳rrrrrrrrrrrっ力してください。\n"); scanf("%s", word1);
	printf("文字列2を乳rrrrrrrrrrrっ力してください。\n"); scanf("%s", word2);

	len = my_strcmp(word1, word2);
	
	printf("文字列1 %s\n", word1);
	printf("文字列2 %s\n", word2);

	if (len == 1){
		printf("長い文字列は文字列1です\n");
	
	} else if(len == 2){
		printf("長い文字列は文字列2です\n");
	} else if (len == 3){
		printf("文字列の名がsssssssssssっさは同じです\n");
	}

	return 0;
}

int my_strcmp(char word1[MN], char word2[MN]){

	int i=0, j=0;
	
	while(word1[i]!='\0'){
		i++;
	}

	while(word2[j]!='\0'){
		j++;
	}
	
	if(i > j){
		return 1;
	} else if(i < j){
		return 2;
	} else if (i == j){
		return 3;
	}
	
	return -1;

}

void my_strswp(char word1[MN], char word2[MN]){
	char tmp[MN];
	
	my_strcpy(tmp, word1);
	my_strcpy(word1, word2);
	my_strcpy(word2, tmp);

	return;
}

void my_strcpy(char word1[MN], char word2[MN]){
	
	int i=0;
	while(word2[i] != '\0'){
		word1[i] = word2[i];
		i++;
	}
	word1[i] = word2[i];

	return;
}