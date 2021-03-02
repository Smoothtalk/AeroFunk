#include<osbind.h>
#include<stdlib.h>
#include <string.h>
#include"GAME.H"

#define SCREEN_SIZE 0x8100L

long *timer = (long *)0x462;
UINT8 buffer[32256];
UINT8 background[32256];


int main(){
	
	long *frontScreen;
	long *backScreen;
	long *backgroundSave;
	
	struct Model model = {
	{
		{
		{400,640,0,0},				/*LEVEL ONE*/
		false,
		{
		{16, 16, 6, 0},
		6,0,1,3,6,0,16,
		false,
		true,
		false,
		true
		},
		{
		{
		{32, 32, 200, 50},
		1, 200, 50, 200, 50, 
		false,
		0
		}
		,
		{
		{32, 32, 424, 200},
		1, 424, 200, 426, 200, 
		false,
		2
		}
		,		
		},
		{
		{{16, 64, 0, 20},
		0,51},
		{{16, 64, 100, 90},
		100,121},
		{{16, 64, 200, 50},
		200,81},
		{{16, 64, 350, 25},
		350,56},
		{{16, 64, 424, 200},
		424,231},
		{{16, 64, 576, 169},
		576,200}
		},
		6,0,
		624,200,
		20
		},
		{
		{400,640,0,0},				/*LEVEL TWO*/
		false,
		{
		{16, 16, 6, 50},
		6,50,1,3,6,50,16,
		false,
		true,
		false,
		true
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20, 
		false,
		0
		}
		,
		{
		{32, 32, 428, 50},
		1, 428, 50, 428, 50, 
		false,
		2
		}
		,		
		},
		{
		{{16, 64, 0, 169},
		0,200},						
		{{16, 64, 164, 130},
		164,161},
		{{16, 64, 226, 20},
		226,51},
		{{16, 64, 328, 89},
		328,120},
		{{16, 64, 428, 50},
		428,81},
		{{16, 64, 576, 25},
		576,56}
		},
		6,50,
		624,56,
		30
		},
		{
		{400,640,0,0},				/*LEVEL THREE*/
		false,
		{
		{16, 16, 6, 120},
		6,120,1,3,6,120,16,
		false,
		true,
		false,
		true
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20, 
		false,
		0
		}
		,
		{
		{32, 32, 430, 160},
		1, 430, 160, 430, 160, 
		false,
		2
		}
		,		
		},
		{
		{{16, 64, 0, 169},
		0,200},						
		{{16, 64, 164, 130},
		164,161},
		{{16, 64, 226, 20},
		226,51},
		{{16, 64, 328, 89},
		328,120},
		{{16, 64, 430, 160},
		430,191},
		{{16, 64, 576, 133},
		576,164}
		},
		6,50,
		624,164,
		27
		},
		{
		{400,640,0,0},				/*LEVEL FOUR*/
		false,
		{
		{16, 16, 6, 180},
		6,180,1,3,6,180,16,
		false,
		true,
		false,
		true
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20, 
		false,
		0
		}
		,
		{
		{32, 32, 430, 160},
		1, 430, 160, 430, 160, 
		false,
		2
		}
		,		
		},
		{
		{{16, 64, 0, 169},
		0,200},						
		{{16, 64, 126, 169},
		126,200},
		{{16, 64, 220, 169},
		226,200},
		{{16, 64, 330, 169},
		330,200},
		{{16, 64, 450, 146},
		450,177},
		{{16, 64, 576, 133},
		576,164}
		},
		6,50,
		624,164,
		15
		},	
	},
	0,
	0,
	0,
	0,
	0,
	false,
	false,
	false
	};
	
	struct ModelSaves frontSave = {
		6,
		0,
		{
		202,
		426
		},
		{
		50,
		200
		},
	};
	
	struct ModelSaves backSave = {
		6,
		0,
		{
		202,
		426,
		},
		{
		50,
		200,
		},
	};
	
	
	long in;
	long * temp;
	UINT32 timeThen = 0L, timeNow = 0L, timeElapsed = 0L;

	frontScreen = Physbase();
	
	temp = frontScreen;

	backScreen = (long []) buffer;	
	backScreen = (long *)((long)(backScreen + 256) & 0xffffff00L);
	
	backgroundSave = (long [])background;
	backgroundSave = (long *)((long)(backgroundSave + 256) & 0xffffff00L);
	
		
	menu((UINT32 *) frontScreen);
	
	if(model.endReached == false){
		render_Background(&model,(UINT32 *)backgroundSave);
	}


	render(&model, (UINT32 *) frontScreen);
	render(&model, (UINT32 *) backScreen);

	timeThen = get_time();
	start_music();
	
	while (model.gameOver == false)
	{
		
		if(Cconis()){
			in = Cnecin();
			/*Async Events*/
			switch (in)
			{	
			case LEFT_ARROW:
			
				event_Left(&model);

				break;
			case RIGHT_ARROW:
				
				event_Right(&model);
				
				break;
				
			case SPACE:
				
				event_Jump(&model);
				
				break;
				
			case RETURN:
				model.gameOver = true;
				stop_sound();
				break;
				
			default:   		
				break;
			}
		}	
		
		timeNow = get_time();
		timeElapsed = timeNow - timeThen;
		
		if(timeElapsed > 0){
			
			erase((UINT32 *) backScreen, &model, &backSave);
			
			saveLocation(&model,&frontSave);
			
			event_UpdateWorld(&model);
			
			if(model.endReached == true){
				render_Background(&model,(UINT32 *)backgroundSave);
				model.endReached = false;
			}
			update_music();
			memcpy(backScreen,backgroundSave,32256);
						
			render_Updates(&model,(UINT32 *) backScreen);
			
			saveLocation(&model,&backSave);
			
			flip_Screen((long *)&frontScreen,(long *)&backScreen);

			erase((UINT32 *) backScreen, &model, &frontSave);
					
			timeThen = timeNow;
			Vsync();	
		}


	}		
	
	
	
	if (temp != frontScreen)
	{
		flip_Screen((long *)&frontScreen,(long *)&backScreen);
	}
	Vsync();
	
	end_Result((UINT32 *) frontScreen,&model);
	
	return 0;
}


void flip_Screen(long *front, long *back)
{
	long *tmp;
	tmp = (long *)*front;
	*front = *back;
	*back = (long *)tmp;
	
	Setscreen(-1L,*front,-1L);
	
}


UINT32 get_time(){
	long timeNow;
	long old_ssp;
	
	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	
	return timeNow;
}

void saveLocation(const struct Model* model, struct ModelSaves *modelSave){
			
	modelSave->heroX = model->levelScreens[0].hero.deltaX;
	modelSave->heroY = model->levelScreens[0].hero.deltaY;
	modelSave->sawBladeX[0] = model->levelScreens[model->currentScreen].sawBlades[0].x;
	modelSave->sawBladeY[0] = model->levelScreens[model->currentScreen].sawBlades[0].y;
	modelSave->sawBladeX[1] = model->levelScreens[model->currentScreen].sawBlades[1].x;
	modelSave->sawBladeY[1] = model->levelScreens[model->currentScreen].sawBlades[1].y;
}

void menu(UINT32 *base){
	
	bool selection = false;
	long in;
	
	render_Menu((UINT32 *)base);
	Setscreen(-1L,base,-1L);
	Vsync();
	
	while(selection == false){
		if(Cconis()){
				in = Cnecin();
				/*Async Events*/
				switch (in)
				{	
				case UP_ARROW:
				
					render_ArrowPositionOne((UINT32 *)base);
					break;
				
				case DOWN_ARROW:
					render_ArrowPositionTwo((UINT32 *)base);
					break;
				
				case RETURN:
					selection = true;
					break;
				
			default:   		
				break;
			}
		}
		Vsync();
	}

}

void end_Result(UINT32 *base, const struct Model *model){

	if(model->gameWon == true){
		render_GameWon((UINT32 *) base);
	}
	else{
	
		render_GameOver((UINT32 *) base);
	
	}
	Vsync();
}