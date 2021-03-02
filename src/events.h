/*############################################################################*/
#ifndef EVENTS_H
#define EVENTS_H

#include <stdio.h>
#include "MODEL.H"
#include"effects.h"
#include"psg.h"

#define UP_ARROW 0x00480000L
#define DOWN_ARROW 0x00500000L
#define LEFT_ARROW 0x004B0000L
#define RIGHT_ARROW 0x004D0000L
#define RETURN	0x001C000DL
#define SPACE 0x00390020L
/*############################################################################*/

/*############################################################################*/

void event_UpdateWorld(struct Model *model);

/*############################################################################*/
void event_Left(struct Model *model);

/*############################################################################*/
void event_Right(struct Model *model);

/*############################################################################*/
void event_Jump(struct Model *model);

#endif