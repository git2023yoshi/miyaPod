#include <stdio.h>
#define MN 100


void my_strswp(char word1[MN], char word2[MN]);
void my_strcpy(char word1[MN], char word2[MN]);

int main(void)
{
	char word1[MN], word2[MN];
	
	printf("������1���rrrrrrrrrrr���͂��Ă��������B\n"); scanf("%s", word1);
	printf("������2���rrrrrrrrrrr���͂��Ă��������B\n"); scanf("%s", word2);

	my_strswp(word1, word2);
	
	printf("������1 %s\n", word1);
	printf("������2 %s\n", word2);

	return 0;
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