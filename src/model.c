#include "MODEL.H"

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
void move_SawBlade(struct SawBlade *sawBlade, struct Platform *platform)
{
 	if(sawBlade->timer > 2){

	if(sawBlade->forward == true){
				
		if(sawBlade->bBox.hotSpotX >= (platform->x + platform->bBox.length)){
			sawBlade->forward = false;
		}
		else{
			sawBlade->x+=2;
			sawBlade->bBox.hotSpotX = sawBlade->x + sawBlade->bBox.length;
		}	
	}
	else{
		
		if(sawBlade->x <= platform->x){
			sawBlade->forward = true;
		}
		else{
			sawBlade->x-=2;
			sawBlade->bBox.hotSpotX = sawBlade->x;
		}	
	}
	
 	sawBlade->timer =0;
	}
	else{
		sawBlade->timer+=1;
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
void move_Hero(struct Hero *hero, int direction)
{

	
	/*direction is positive or negative */
		if(hero->isFalling == false){
			hero->deltaX += direction * 5;
		}
		else{
			hero->deltaX += direction * 2;
		}
		
		if(hero->deltaX < 0)
		{
			hero->deltaX = 0;
		}
		
		if(direction == RIGHT){
			
			hero->bBox.hotSpotX = hero->deltaX + hero->bBox.length;

			
		}
		else{
			hero->bBox.hotSpotX = hero->deltaX;

		}
		
		/*take out later*/
		
		if(hero->bBox.hotSpotX > 640){

			
			if(hero->isFalling == false){
				hero->deltaX-=5;
			}
			else{
				hero->deltaX-=2;
			}
			hero->bBox.hotSpotX = hero->deltaX + hero->bBox.length;
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
void hero_Hit(struct Hero *hero)
{
	if(hero->isInvincible == false)
	{
		hero->isInvincible = true;
		
  		hero->health -= 1;
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

void unInvincile(struct Hero *hero){
	
	if(hero->isInvincible == true){
		hero->isInvincible == false;
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

void hero_Jump(struct Hero *hero){
	
	if(hero->isFacingForwards == true){
	
		hero->deltaY -= 3;
	
		hero->bBox.hotSpotX = hero->deltaX + hero->bBox.length;
		hero->bBox.hotSpotY = hero->deltaY;
	}
	else{
	
		hero->deltaY -= 3;
		hero->bBox.hotSpotX = hero->deltaX;
		hero->bBox.hotSpotY = hero->deltaY;
	
	}
	
	if(hero->deltaY < 0){
		hero->deltaY +=3;
		hero->bBox.hotSpotY = hero->deltaY;
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

void hero_Fall(struct Hero *hero){
		
	if(hero->isFacingForwards == true){
		
		hero->deltaY += 1;
		hero->bBox.hotSpotX = hero->deltaX + hero->bBox.length;
		hero->bBox.hotSpotY = hero->deltaY + hero->bBox.height;

	}
	else{
		
		hero->deltaY += 1;
		hero->bBox.hotSpotX = hero->deltaX;
		hero->bBox.hotSpotY = hero->deltaY+ hero->bBox.height;
	
	}
	
	if(hero->deltaY > 240){
		hero->deltaX = hero->initialX;
		hero->bBox.hotSpotX = hero->deltaX + hero->bBox.length;
		hero->deltaY = hero->initialY;
		hero->bBox.hotSpotY = hero->deltaY; + hero->bBox.height;
		hero_Hit(hero);
	
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
void move_Screen(struct Hero *hero,struct Model *model)
{
	if(hero->bBox.hotSpotX >= model->levelScreens[model->currentScreen].exitX && hero->bBox.hotSpotY == model->levelScreens[model->currentScreen].exitY){

		if(model->currentScreen == 3){
			model->gameOver = true;
			model->gameWon = true;
		}
		model->endReached = true;
		model->currentScreen++;
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
void check_SawBlade_Collision(struct Hero *hero, struct SawBlade *sawBlade)
{
	if(hero->isInvincible == false)
	{
		if(hero->bBox.hotSpotY >= sawBlade->bBox.hotSpotY && hero->bBox.hotSpotY <= (sawBlade->bBox.hotSpotY + sawBlade->bBox.height))
		{
			if((hero->bBox.hotSpotX >= sawBlade->x) && (hero->bBox.hotSpotX <= sawBlade->x + sawBlade->bBox.length))
			{
				hero_Hit(hero);
			}		 
		}
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
void check_Platform_Collision(struct Hero *hero, struct Platform *platform)
{
	if(hero->bBox.hotSpotY == platform->y){
	
		if((hero->bBox.hotSpotX >= platform->x 
		 && hero->bBox.hotSpotX <= platform->x + platform->bBox.length)){
			hero->isFalling = false;
		 }
	}
	
	if((hero->bBox.hotSpotX < platform->x 
		|| hero->bBox.hotSpotX > platform->x + platform->bBox.length) && hero->isJumping == false){
		hero->isFalling = true;
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
void incrementJumpCounter(struct Model *model){
	model->jumpCounter++;
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

void set_Hero_Direction(struct Model *model, int direction){

	if(direction == LEFT){
		model->levelScreens[model->currentScreen].hero.isFacingForwards = false;
	}
	else{
		model->levelScreens[model->currentScreen].hero.isFacingForwards = true;
	}
	
	model->direction =  direction;
	
}