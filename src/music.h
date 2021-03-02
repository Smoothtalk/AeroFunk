#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"
#include "psg.h"

#define A_4 0x0FE
#define A_SHARP_4 0x7F0
#define A_SHARP_5 0x078
#define B_4 0x0E2
#define C_4 0x1AC
#define C_5 0x0D6
#define C_6 0x06B
#define C_SHARP_4 0x194
#define C_SHARP_5 0x0CA
#define C_SHARP_6 0x065
#define D_4 0x17D
#define D_SHARP_4 0x168
#define D_SHARP_5 0x0B4
#define E_4 0x153
#define F_4 0x140
#define F_5 0x0A0
#define F_SHARP_4 0x12E
#define F_SHARP_5 0x097
#define G_4 0x11D
#define G_5 0x08F
#define G_SHARP_4 0x10D
#define G_SHARP_5 0x087

#define STD_VOL 4

typedef struct Note
{
	UINT8 key;
	int duration;
	int volume;

} note;

void start_music();
void update_music();

#endif