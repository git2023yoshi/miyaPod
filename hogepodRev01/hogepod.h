#include <stdio.h>

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
	struct PLAYLIT playlist1;
};