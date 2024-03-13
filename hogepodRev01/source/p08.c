#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

struct ALBUM{
	int year;
	char name[M], musician[M], genre[100];
	struct ALBUM *next;
};



void menu_main();
int my_scanf_integer();

void album_load1( struct ALBUM album[100]);

void album_print_all( struct ALBUM *start);
int album_count(struct ALBUM *start);
void album_print_one(struct ALBUM *start);

void album_change(struct ALBUM *start);

void album_change_otonari(struct ALBUM *start, int num1, int num2);
void album_change_no_otonari(struct ALBUM *start, int num1, int num2);

int main(void)
{
	int ans = -1;
	struct ALBUM album[N], *start;
	
	album_load1( album );
	
	start = &album[0];
	
	while (ans != 0){
		menu_main();
		ans = my_scanf_integer();
		
		switch(ans){
			case 0:
				printf("========================\n");
				printf("   ����ꂳ�܂ł���, \n");
				printf("   �v���O�������I�����܂� \n");
				printf("========================\n");
				break;
			case 1:
				album_print_all(start);
				printf("������\n"); break;
			case 2:
				album_print_one(start);
				//printf("������\n"); 
				break;
			case 3:
				printf("%d �����o�^����Ă��܂�. \n", album_count(start));
				break;
			case 4:
				album_change(start);
				//printf("������\n");
				break;
			case 5:
				// album_save(start);
				//printf("������\n");
				break;
			default:
				printf("0-5 �̒l����͂��Ă�������\n");
		
		}
	}
	
	return 0;
}

void menu_main(){
	printf("=== MAIN MENU === \n");
	printf("1... �ꗗ \n");
	printf("2... 1���̂� \n");
	printf("3... �v�f���̃J�E���g\n");
	printf("4... �w�肵�ĕ��ёւ�\n");
	printf("5... �f-�^�̕ۑ�\n");
	printf("0... �I������\n");
	printf("�I�����Ă�������\n");
	
	return;

}


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
		
		printf("�����l����͂��Ă������� ");
	
	}

	return -1;
}

void album_load1( struct ALBUM album[100]){
	int i, number;
	FILE *fp;
	
	fp = fopen("data08.dat", "r");
	
	album[0].next = &album[1];
	
	fscanf(fp, "%d", &number);
	
	for (i=1; i<number+1; i++){
		fscanf(fp, "%d", &album[i].year );
		fscanf(fp, "%s", &album[i].name[0] );
		fscanf(fp, "%s", &album[i].musician[0] );
		fscanf(fp, "%s", &album[i].genre[0] );
		
		album[i].next = &album[i+1];

	}
	
	fclose(fp);
	
	album[i].next = NULL;
	return;

}


void album_print_all( struct ALBUM *start){
	struct ALBUM *index;
	int i = 0;
	
	index = start;
	index = index->next;
	
	printf("=======�����Ă���A���o���ꗗ=========\n");
	
	while( index->next != NULL){
		
		printf("%d) ", i+1);
		printf("%d ", index->year);
		printf("%s ", &index->name[0]);
		printf("%s ", &index->musician[0]);
		printf("%s\n", &index->genre[0]);
		
		index = index->next;
		i++;
	}
	printf("=========================\n");
	return;
}

int album_count(struct ALBUM *start){
	
	struct ALBUM *index;
	int count;
	count = 0;
	
	index = start;
	index = index->next;
	
	while(index->next != NULL){
		count++;
		index = index->next;
	}
	
	return count;

}

void album_print_one(struct ALBUM *start){
	struct ALBUM *index;
	int i, ans;
	
	printf("���Ԗڂ̃A���o���H\n");
	ans = my_scanf_integer();
	
	if (1 > ans || ans > album_count(start)){
		printf("�Y������A���o���͂���܂���\n");
		return;
	}
	
	index = start;
	for (i=0; i<ans; i++){
		index = index->next;
	}
	
	printf("---------------------------\n");
	printf("����-�X�N       : %d\n", index->year);
	printf("�A���o����      : %s\n", &index->name[0]);
	printf("���            : %d\n", &index->musician[0]);
	printf("�W������        : %d\n", &index->genre[0]);


	printf("---------------------------\n");


	return;

}

void album_change(struct ALBUM *start){
	int num1, num2;
	
	printf("���ԖڂƉ��Ԗڂ����ꂩ����H\n"); num1 = my_scanf_integer();
	printf("��?\n"); num2 = my_scanf_integer();
	
	if (num1 - num2 == 0) {
		printf("�����v�f�Ȃ̂œ���ւ���K�v�͂���܂���\n"); return;
	}
	
	if (num1 < 1 || album_count(start) < num2 ){
		printf("����ȗv�f�͂���܂���\n"); return;
	}
	
	if (num1 - num2 == 1 || num1 - num2 == -1){
		printf("�׍����v�f�����ւ��܂�\n");
		//printf("������\n");
		album_change_otonari(start, num1, num2);
	} else {
		printf("�׍���Ȃ��v�f�����ւ��܂�\n");
		album_change_no_otonari(start, num1, num2);
	}

}



void album_change_no_otonari(struct ALBUM *start, int num1, int num2){
	
	struct ALBUM *index;
	struct ALBUM *A, *Amae, *Aato;
	struct ALBUM *B, *Bmae, *Bato;
	
	int i;
	
	
	index = start;
	
	for(i=0; i<num1 - 1; i++){
		index = index -> next;
	}
	
	Amae = index;
	A = index->next;
	Aato = index->next->next;
	
	index = start;
	
	for (i = 0; i < num2 - 1; i++){
		index = index -> next;
	}
	
	Bmae = index;
	B = index->next;
	Bato = index->next->next;
	
	A->next = Bato;
	B->next = Aato;
	Amae->next = B;
	Bmae->next = A;
	
	printf("�A���o�� %s �� %s �����ւ��܂���\n", &A->name[0], &B->name[0]);

	return;
}


void album_change_otonari(struct ALBUM *start, int num1, int num2){
	
	struct ALBUM *index;
	struct ALBUM *A, *Amae, *Aato;
	struct ALBUM *B, *Bmae, *Bato;
	
	int tmp, i, k;
	
	if(num1 > num2){
		k = num1;
		num1 = num2;
		num2 = k;
	}
	
	index = start;
	for(i=0; i<num1-1; i++){
		index = index->next;
	}
	Amae = index;
	A = index->next;
	
	index = start;
	for (i=0; i<num2; i++){
		index = index->next;
		
	}
	
	B = index;
	Bato = index->next;
	
	Amae -> next = B;
	B -> next = A;
	A -> next = Bato;
	
	printf("�A���o�� %s �� %s �����ւ��܂���\n", &A->name[0], &B->name[0]);

	return;
}
