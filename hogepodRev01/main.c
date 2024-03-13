#include "hogepod.h"

int main(void)
{
	struct ALBUM *album;


	hogepod_main_menu();

return 0;

}


/* ================ îƒópä÷êî=================== */
int my_scanf_integer(){
	
	int i, chk;
	char buffer[100];
	
	while (1) {
		scanf("%99s", buffer); i = 0; chk = 1;
		while (buffer[i] != '\0'){
			if ( buffer[i] < '0' || '9' < buffer[i]) chk = 0;
			i++;
		}
		if( chk ) return atoi( buffer );
		
		printf("êÆêîílÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢ ");
	
	}

	return -1;
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

