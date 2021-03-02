#include <stdio.h>
#include "RENDER.H"

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

void render_Hero(const struct Hero *hero, UINT16 *base){

	if(hero->isFacingForwards == false && (hero->isJumping == true && hero->isFalling == false)){
		plot_bitmap16(base,LEFT_HERO_JUMP,hero->deltaX,hero->deltaY,HERO_SIZE);
	}
	else if(hero->isFacingForwards == true && (hero->isJumping == true && hero->isFalling == false)){
		plot_bitmap16(base,RIGHT_HERO_JUMP,hero->deltaX,hero->deltaY,HERO_SIZE);
	}
	else if(hero->isFacingForwards == false && (hero->isFalling == true && hero->isJumping == false)){
		plot_bitmap16(base,LEFT_HERO_FALL,hero->deltaX,hero->deltaY,HERO_SIZE);
	}
	else if(hero->isFacingForwards == true && (hero->isFalling == true && hero->isJumping == false)){
		plot_bitmap16(base,RIGHT_HERO_FALL,hero->deltaX,hero->deltaY,HERO_SIZE);
	}

	else if(hero->isFacingForwards == false && (hero->isFalling == false && hero->isJumping == false)){
		plot_bitmap16(base,LEFT_HERO_1,hero->deltaX,hero->deltaY,HERO_SIZE);
	}
	
	else if(hero->isFacingForwards == true && (hero->isFalling == false && hero->isJumping == false)){
		plot_bitmap16(base,RIGHT_HERO_1,hero->deltaX,hero->deltaY,HERO_SIZE);
	}
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

void render_SawBlade(const struct SawBlade *sawBlade, UINT32 *base){
		
		plot_bitmap32( (UINT32 *)base,SAWBLADE,sawBlade->x,sawBlade->y,SAWBLADE_SIZE);


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


void render(const struct Model *model, UINT32 *base){


	int numSawblade = 0;
	
	clearScreen((UINT32 *)base);
	for(numSawblade = 0; numSawblade < 2; numSawblade++){
		render_SawBlade(&model->levelScreens[model->currentScreen].sawBlades[numSawblade],(UINT32 *)base);
	}
	
	render_Hero(&model->levelScreens[model->currentScreen].hero, (UINT16 *)base);
	
	render_Health(&model->levelScreens[model->currentScreen].hero, (UINT32 *)base);

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

void render_Updates(const struct Model *model, UINT32 *base){

	int numSawblade = 0;
	
	for(numSawblade = 0; numSawblade < 2; numSawblade++){
		render_SawBlade(&model->levelScreens[model->currentScreen].sawBlades[numSawblade],(UINT32 *)base);
	}
	render_Hero(&model->levelScreens[model->currentScreen].hero, (UINT16 *)base);
	render_Health(&model->levelScreens[model->currentScreen].hero, (UINT32 *)base);
	
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

void render_Health(const struct Hero *hero, UINT32 *base){

	if(hero->health == 3)
		plot_bitmap32(base, HEARTS_3, 608, 0, 32);
	else if(hero->health == 2)
		plot_bitmap32(base, HEARTS_2, 608, 0, 32);		
	else if(hero->health == 1)
		plot_bitmap32(base, HEARTS_1, 608, 0, 32);
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

void render_ClearHero(UINT16 *base, int heroX, int heroY){

	clear16X16(base,CLEAR_16X16,heroX,heroY,HERO_SIZE);	
	
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

void render_ClearSawblade(UINT32 *base, int sawBladeX, int sawBladeY){

	clear32X32((UINT32 *)base,CLEAR_32X32,sawBladeX,sawBladeY,SAWBLADE_SIZE);
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

void render_ClearHeart(UINT32 *base){

	clear32X32((UINT32 *)base,CLEAR_32X32,605,40,SAWBLADE_SIZE);
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

void erase(UINT32 *base, const struct Model *model, const struct ModelSaves* backSave){
	
	int numSawblade = 0;
	
	render_ClearHeart(base);
	render_ClearHero((UINT16 *) base, backSave->heroX,backSave->heroY);

	for(numSawblade = 0; numSawblade < 2; numSawblade++){
		render_ClearSawblade(base, backSave->sawBladeX[numSawblade], backSave->sawBladeY[numSawblade]);
	}

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

void render_GameOver(UINT32 *base){
	
	clearScreen((UINT32 *)base);
	plot_Background((UINT32*)base,LOSE_SCREEN,0,0,8000);

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

void render_Menu(UINT32 *base){
	
	clearScreen((UINT32 *)base);
	plot_Background((UINT32*)base,START_SCREEN,0,0,8000);

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

void render_Background(const struct Model *model,UINT32 *base){
	
	int numPlatform = 0;
	clearScreen((UINT32 *)base);
	
 	if(model->currentScreen == 0){
	
		plot_Background((UINT32*)base,BACKGROUND_LEVEL_1,0,0,8000);
	}
	if(model->currentScreen == 1){
	
		plot_Background((UINT32*)base,BACKGROUND_LEVEL_2,0,0,8000);
	}
	if(model->currentScreen == 2){
	
		plot_Background((UINT32*)base,BACKGROUND_LEVEL_3,0,0,8000);
	}
	if(model->currentScreen == 3){
	
		plot_Background((UINT32*)base,BACKGROUND_LEVEL_4,0,0,8000);
	}
	

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

void render_ArrowPositionOne(UINT32 *base){
	
	render_ClearHero((UINT16 *) base, 200,220);
	plot_bitmap16((UINT16 *)base,SELECTION_ARROW,200,190,HERO_SIZE);

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

void render_ArrowPositionTwo(UINT32 *base){
	
	render_ClearHero((UINT16 *) base, 200,190);
	plot_bitmap16((UINT16 *)base,SELECTION_ARROW,200,220,HERO_SIZE);

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

void render_GameWon(UINT32 *base){
	
	clearScreen((UINT32 *)base);
	plot_Background((UINT32*)base,WINNER_SCREEN,0,0,8000);

}