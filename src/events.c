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

#include "EVENTS.H"
 
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
void event_UpdateWorld(struct Model *model)
{	
	int numPlatform = 0;
	int numSawblade = 0;
	bool noHeroOnPlateform = true;
	int sawBladeTimer = 0;
	
	if(model->levelScreens[model->currentScreen].hero.isInvincible == true && model->invincCounter <= 7)
	{
		model->invincCounter++;
	}
	
	if(model->invincCounter >= 7)
	{
		model->levelScreens[model->currentScreen].hero.isInvincible = false;
		model->invincCounter = 0;
	}

	for(numPlatform = 0; (numPlatform < 6 && noHeroOnPlateform == true);numPlatform++){
		
		check_Platform_Collision(&model->levelScreens[model->currentScreen].hero, &model->levelScreens[model->currentScreen].platForms[numPlatform]);
		
		if(model->levelScreens[model->currentScreen].hero.isFalling == false){
			noHeroOnPlateform = false;
		}
		
	}

	if(model->levelScreens[model->currentScreen].hero.isJumping == true && model->jumpCounter <  model->levelScreens[model->currentScreen].jumpCounter){
		hero_Jump(&model->levelScreens[model->currentScreen].hero);
		incrementJumpCounter(model);
		noHeroOnPlateform = true;
	}
	
	if(model->jumpCounter >= model->levelScreens[model->currentScreen].jumpCounter && model->levelScreens[model->currentScreen].hero.isJumping == true){
			
		model->jumpCounter = 0;
		model->levelScreens[model->currentScreen].hero.isFalling = true;
		model->levelScreens[model->currentScreen].hero.isJumping = false;
		noHeroOnPlateform =true;
	}
				
	if(model->levelScreens[model->currentScreen].hero.isFalling == true){
			
		hero_Fall(&model->levelScreens[model->currentScreen].hero);
		noHeroOnPlateform =true;
	}
		
	move_Hero(&model->levelScreens[model->currentScreen].hero, model->direction);	

	move_SawBlade(&model->levelScreens[model->currentScreen].sawBlades[0], &model->levelScreens[model->currentScreen].platForms[2]);
	move_SawBlade(&model->levelScreens[model->currentScreen].sawBlades[1], &model->levelScreens[model->currentScreen].platForms[4]);
		
	for(numSawblade = 0; numSawblade < 2; numSawblade++){
		check_SawBlade_Collision(&model->levelScreens[model->currentScreen].hero, &model->levelScreens[model->currentScreen].sawBlades[numSawblade]);
	}

	/*reset the values back to default*/
	model->direction = 0;
	
	move_Screen(&model->levelScreens[model->currentScreen].hero,model);
	
	if(model->endReached == true)
		play_nextLevel();
	
	if(model->levelScreens[model->currentScreen].hero.isInvincible == true)
		ding();
	
	if(model->levelScreens[model->currentScreen].hero.health <= 0){
		stop_sound();
		/* Exit out of loop go to the dead screen*/
		model->gameOver = true;
		/*ToDo the splash screens for either fail or winner*/
	}
	model->time++;
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

void event_Left(struct Model *model){
			
	set_Hero_Direction(model,LEFT);
	
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
void event_Right(struct Model *model){
			
	set_Hero_Direction(model,RIGHT);
	
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
void event_Jump(struct Model *model){

	if(model->levelScreens[model->currentScreen].hero.isJumping == false && model->levelScreens[model->currentScreen].hero.isFalling == false){
		model->levelScreens[model->currentScreen].hero.isJumping = true;
		model->jumpCounter = 0;
		play_gunshot();
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