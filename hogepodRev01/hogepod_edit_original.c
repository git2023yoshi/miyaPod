#include "hogepod.h"



void hogepod_edit_original( struct HOGEPOD *pt_hogepod )
{
	int num;

	hogepod_edit_original_menu();
	num = my_scanf_integer();

	switch( num )
	{
		case 1:
		case 2:
		case 3:
		case 4:
			hogepod_album_select(pt_hogepod, num);

		case 5:
			hogepod_edit_original_delete(pt_hogepod);

		case 6:
			hogepod_edit_original_add(pt_hogepod);
		
		case 7:
			hogepod_edit_swap(pt_hogepod);

		default : break;
	}
	
	
	return;
}

void hogepod_edit_original_menu()
{
	printf("==オリジナルアルバム編集menu==\n");
	printf("1... 年の変更\n");
	printf("2... アルバム名の変更\n");
	printf("3... 音楽家名の変更\n");
	printf("4... ジャンル名の変更\n");
	printf("5... アルバムの1件削除\n");
	printf("6... アルバムの1件追加\n");
	printf("7... アルバムの順序の入れ替え\n");
	printf("0... メインメニューに戻る\n");
	printf("番号を入力 >");

return;
}


void hogepod_edit_original_delete( struct HOGEPOD *pt_hogepod )
{
	return;
}

void hogepod_edit_original_add( struct HOGEPOD *pt_hogepod )
{
	return;
}
