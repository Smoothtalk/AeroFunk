#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#include "RASTER.H"
#include "MODEL.H"
#include "BITMAPS.H"
#include "back1.h"
#include "back2.h"
#include "ONESS.H"
#include "TWOSS.H"


#define HERO_SIZE 16
#define SAWBLADE_SIZE 32
#define PLATFORM_NORMAL_SIZE 200
#define BACKGROUND_SIZE 8000


void render(const struct Model *model, UINT32 *base);

void render_Platform(const struct Platform *platform, UINT32 *base);

void render_Hero(const struct Hero *hero, UINT16* base);

void render_SawBlade(const struct SawBlade *sawBlade, UINT32 *base);

void render_Health(const struct Hero *hero, UINT32 *base);

void render_Updates(const struct Model *model, UINT32 *base);

void render_ClearHero(UINT16 *base, int heroX, int heroY);

void render_ClearSawblade(UINT32 *base, int sawBladeX, int sawBladeY);

void render_ClearHeart(UINT32 *base);

void erase(UINT32 *base, const struct Model *model, const struct ModelSaves* backSave);

void render_GameOver(UINT32 *base);

void render_Menu(UINT32 *base);

void render_Background(const struct Model *model,UINT32 *base);

void render_ArrowPositionOne(UINT32 *base);

void render_ArrowPositionTwo(UINT32 *base);


#endif