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
	printf("==�I���W�i���A���o���ҏWmenu==\n");
	printf("1... �N�̕ύX\n");
	printf("2... �A���o�����̕ύX\n");
	printf("3... ���y�Ɩ��̕ύX\n");
	printf("4... �W���������̕ύX\n");
	printf("5... �A���o����1���폜\n");
	printf("6... �A���o����1���ǉ�\n");
	printf("7... �A���o���̏����̓���ւ�\n");
	printf("0... ���C�����j���[�ɖ߂�\n");
	printf("�ԍ������ >");

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
