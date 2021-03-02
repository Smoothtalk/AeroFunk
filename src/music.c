#include <osbind.h>
#include "music.h"

unsigned int timeLastCalled = 0;
unsigned int current_duration = 0;
unsigned int currentNote = 0; /* note that is being played */

/*{key,duration,volume} */
/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/
struct Note notes[23] = 
{
	{A_SHARP_4,5,STD_VOL},
	{F_5,5,STD_VOL},
	{C_5,5,STD_VOL},
	{F_5,5,STD_VOL},
	{C_SHARP_5,5,STD_VOL},
	{D_SHARP_5,9,STD_VOL},
	{F_5,9,STD_VOL},
	{D_SHARP_5,15,STD_VOL},
	{G_5,5,STD_VOL},
	{A_SHARP_5,5,STD_VOL},
	/* {F_5,5,STD_VOL}, */
	{F_5,5,STD_VOL},
	/* {C_SHARP_5,5,STD_VOL}, */
	{C_6,5,STD_VOL},
	/* {G_SHARP_5,5,STD_VOL}, */
	{C_SHARP_6,5,STD_VOL},
	/* {A_SHARP_5,5,STD_VOL}, */
	{C_6,5,STD_VOL},
	/* {G_SHARP_5,5,STD_VOL}, */
	{C_SHARP_6,5,STD_VOL},
	/* {A_SHARP_5,5,STD_VOL}, */
	{C_6,3,STD_VOL},
	/* {G_SHARP_5,5,STD_VOL}, */
	{A_SHARP_5,3,STD_VOL},
	/* {C_SHARP_5,3,STD_VOL}, */
	{G_SHARP_5,5,STD_VOL},
	/* {C_SHARP_5,3,STD_VOL}, */
	{F_5,5,STD_VOL},
	/* {C_SHARP_5,3,STD_VOL}, */
	{G_SHARP_5,5,STD_VOL},
	/* {F_SHARP_5,3,STD_VOL}, */
	{D_SHARP_5,5,STD_VOL},
	/* {C_SHARP_5,3,STD_VOL}, */
	{F_5,5,STD_VOL},
	/* {C_SHARP_5,3,STD_VOL}, */
	{C_SHARP_6,2,STD_VOL}
	/* {A_SHARP_5,3,STD_VOL} */
};
 
/*
	/* {F_5,12,STD_VOL}, */
	/* {C_SHARP_5,12,STD_VOL}, */
	/* {G_SHARP_5,12,STD_VOL}, */
	/* {A_SHARP_5,12,STD_VOL}, */
	/* {G_SHARP_5,12,STD_VOL}, */
	/* {A_SHARP_5,12,STD_VOL}, */
	/* {G_SHARP_5,12,STD_VOL},*/
	/* {C_SHARP_5,3,STD_VOL}, */
	/* {C_SHARP_5,3,STD_VOL}, */
	/* {C_SHARP_5,3,STD_VOL}, */
	/* {F_SHARP_5,3,STD_VOL}, */
	/* {C_SHARP_5,3,STD_VOL}, */
	/* {C_SHARP_5,3,STD_VOL}, */
	/* {A_SHARP_5,3,STD_VOL} */	
	
int currNote = 0;
int currTime = 0;
/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/
void start_music() {
	
	UINT8 theNote = notes[currNote].key;
	int theVolume = notes[currNote].volume;
	
	currNote = 0;
	currTime = 0;
 
 	set_tone(0, theNote); 
	enable_channel(0, 1, 0); 
	set_volume(0,theVolume); 
}
/******************************************************************************
*
*
*
*
*
*
*
*
*
*
******************************************************************************/
void update_music() {

	if (currTime > notes[currNote].duration) {
		currNote++;
		
		set_tone(0,(UINT8) notes[currNote].key); 
		enable_channel(0, 1, 0); 
		set_volume(0,notes[currNote].volume); 
		currTime = 0; 
	} 
	else 
	{
		currTime++;
	}
	
 	if (currNote == 22) {
		currNote = 0;
	}  
}  