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

#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>

#define LEFT -1
#define RIGHT +1

typedef int bool;
#define true -1
#define false 0
#define MAX_PLATFORM 6
#define MAX_SAWBLADE 2



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
struct BoundingBox{

	unsigned int height;
	unsigned int length;
	unsigned int hotSpotX;
	unsigned int hotSpotY; /*default*/ 
};
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
struct SawBlade{
	struct BoundingBox bBox;

	unsigned int speed, initialX, initialY, x, y;
	bool forward;
	int timer;
	
};
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
struct Hero{
	struct BoundingBox bBox;
	signed int deltaX, deltaY;
	unsigned int speed, health, initialX, initialY, spriteHeight;
	bool isJumping, isFacingForwards, isInvincible, isFalling;
};
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
struct Platform{
	/*bounding box property here*/
	struct BoundingBox bBox;
	
	unsigned int x, y;
};
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
struct Screen{
	struct BoundingBox bBox;	
	bool isPlayerDead;
	struct Hero hero;
	struct SawBlade sawBlades[MAX_SAWBLADE]; /*temp numbers*/
	struct Platform platForms[MAX_PLATFORM];
	unsigned int entranceX, entranceY, exitX, exitY;
	signed int jumpCounter;
};
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
struct Model{
	struct Screen levelScreens[4];
	unsigned int time;
	int currentScreen;
	signed int direction;
 	signed int jumpCounter;
	int invincCounter;
	bool gameOver;
	bool gameWon;
	bool endReached;
};

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
struct ModelSaves{
	int heroX,
		heroY;
	int	sawBladeX[MAX_SAWBLADE];
	int sawBladeY[MAX_SAWBLADE];
	
};
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
void move_Hero(struct Hero *hero, int direction);
void hero_Hit(struct Hero *hero);
void hero_Jump(struct Hero *hero);
void hero_Fall(struct Hero *hero);

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
void move_SawBlade(struct SawBlade *sawBlade, struct Platform *platform);
void check_SawBlade_Collision(struct Hero *hero, struct SawBlade *sawBlade);
void check_Platform_Collision(struct Hero *hero, struct Platform *platform);
void move_Screen(struct Hero *hero,const struct Model *model);

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
void incrementJumpCounter(struct Model *model);

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
void set_Hero_Direction(struct Model *model, int direction);

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
void move_Screen(struct Hero *hero,struct Model *model);


#endif
