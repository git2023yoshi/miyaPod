#include <stdio.h>
#include <stdlib.h>

#define MN 100

struct ALBUM{
	int year;
	char name[MN];
	char musician[MN];
	char genre[MN];
	struct ALBUM *next, *playlistlink;
};

struct PLAYLIST {
	int max;
	char name[MN];
	struct ALBUM *start;
};

struct PLAYBUFFER {
	int max;
	char name[MN];
	struct ALBUM *start;
};

struct HOGEPOD{
	struct ALBUM *start;
	struct PLAYBUFFER playbuffer;
	struct PLAYLIST playlist1;
};

//プロトタイプ

void hogepod_main_menu();
int my_scanf_integer();
int my_strcmp( char word1[MN], char word2[MN]);
int hogepod_album_count_index( struct ALBUM *start, struct ALBUM *count);
void hogepod_album_print( struct ALBUM *start, int rule );
struct ALBUM *hogepod_album_select( struct ALBUM *start, int type );
void hogepod_album_select_menu();


void hogepod_edit_original( struct HOGEPOD *pt_hogepod );
void hogepod_edit_original_menu();
void hogepod_edit_playlist( struct HOGEPOD *pt_hogepod );
void hogepod_edit_playlist_menu();
void hogepod_edit_original_delete( struct HOGEPOD *pt_hogepod );
void hogepod_edit_playlist_delete( struct HOGEPOD *pt_hogepod );
void hogepod_edit_original_add( struct HOGEPOD *pt_hogepod );
void hogepod_edit_playlist_add( struct HOGEPOD *pt_hogepod );
void hogepod_edit_swap( struct ALBUM *start);
void hogepod_swap_otonari( struct ALBUM *start, int num1, int num2 );
void hogepod_swap_no_otonari( struct ALBUM *start, int num1, int num2 );

void hogepod_load( struct HOGEPOD *pt_hogepod );
void hogepod_load_original( struct HOGEPOD *pt_hogepod );
void hogepod_load_playlist( struct HOGEPOD *pt_hogepod );
void hogepod_save_original( struct HOGEPOD *pt_hogepod );
void hogepod_save_playlist( struct HOGEPOD *pt_hogepod );

void hogepod_play( struct HOGEPOD *pt_hogepod );
void hogepod_play_menu();
void hogepod_makebuffer_original( struct HOGEPOD *pt_hogepod, int rule );
void hogepod_makebuffer_playlist( struct HOGEPOD *pt_hogepod );
void hogepod_playing( struct HOGEPOD *pt_hogepod, int type);
void hogepod_playing_menu();


