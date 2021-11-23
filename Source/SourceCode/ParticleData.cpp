#include "All.h"
GAME_OBJECT* PARTICLE_DATA::create()
{
	GAME_OBJECT* obj = new GAME_OBJECT;
	obj->exist = true;
	obj->mvAlg = &partical_mvAlg;
	obj->iWork[PARTICLE::pLife] = pLife;
	obj->fWork[PARTICLE::pSpeed] = pSpeed;
	obj->fWork[PARTICLE::pSpeed_Mag] = pSpeed_Mag;
	obj->fWork[PARTICLE::pSpeed_Cor] = pSpeed_Cor;
	obj->fWork[PARTICLE::pVector_Cor] = pVector_Cor;
	obj->fWork[PARTICLE::pColor_Mag] = pColor_Mag;
	obj->fWork[PARTICLE::pHeight] = pHeight;
	obj->fWork[PARTICLE::pHeight_Speed] = pHeight_Speed;
	obj->fWork[PARTICLE::pHeight_Speed_Cor] = pHeight_Speed_Cor;
	obj->vWork[PARTICLE::pVector] = pVector;
	obj->vWork[PARTICLE::pScale] = pScale;
	obj->vWork[PARTICLE::pScale_Mag] = pScale_Mag;
	obj->vWork[PARTICLE::pScale_Cor] = pScale_Cor;
	obj->vWork[PARTICLE::pColorXY] = VECTOR2(pColor.x, pColor.y);
	obj->vWork[PARTICLE::pColorZW] = VECTOR2(pColor.z, pColor.w);
	obj->zcode = DRAW_LIST::zObject;
	return obj;
}

GAME_OBJECT* PARTICLE_DATA::create(VECTOR2 p)
{
	GAME_OBJECT* obj = new GAME_OBJECT;
	obj->exist = true;
	obj->mvAlg = &partical_mvAlg;
	obj->iWork[PARTICLE::pLife] = pLife;
	obj->fWork[PARTICLE::pSpeed] = pSpeed;
	obj->fWork[PARTICLE::pSpeed_Mag] = pSpeed_Mag;
	obj->fWork[PARTICLE::pSpeed_Cor] = pSpeed_Cor;
	obj->fWork[PARTICLE::pVector_Cor] = pVector_Cor;
	obj->fWork[PARTICLE::pColor_Mag] = pColor_Mag;
	obj->fWork[PARTICLE::pHeight] = pHeight;
	obj->fWork[PARTICLE::pHeight_Speed] = pHeight_Speed;
	obj->fWork[PARTICLE::pHeight_Speed_Cor] = pHeight_Speed_Cor;
	obj->vWork[PARTICLE::pVector] = p;
	obj->vWork[PARTICLE::pScale] = pScale;
	obj->vWork[PARTICLE::pScale_Mag] = pScale_Mag;
	obj->vWork[PARTICLE::pScale_Cor] = pScale_Cor;
	obj->vWork[PARTICLE::pColorXY] = VECTOR2(pColor.x, pColor.y);
	obj->vWork[PARTICLE::pColorZW] = VECTOR2(pColor.z, pColor.w);
	obj->zcode = DRAW_LIST::zObject;
	return obj;
}

PARTICLE_RAIN::PARTICLE_RAIN()
{
	pData = SPRITELOAD::spr["Partial"];
	pTexPos = { 0.0f,0.0f };
	pTexSize = { 4,4 };
	pDrawAlg = &paritcleDraw;
	pSpeed = 0.3f;
	pSpeed_Mag = 1;
	pSpeed_Cor = .0f;
	pVector = { 1, 1 };
	pVector_Cor = 0.0f;
	pScale = { 0.2f,0.2f };
	pScale_Mag = { 1,1 };
	pScale_Cor = { 0,0 };
	pHeight = 0.0f;
	pHeight_Speed = 1.2f;
	pHeight_Speed_Cor = -0.3f;
	pColor = { 0.0f,0.1f,0.3f,0.7f };
	pColor_Mag = 0.8f;
	pLife = 30;
}

PARTICLE_SPARK::PARTICLE_SPARK()
{
	pData = SPRITELOAD::spr["Partial"];
	pTexPos = { 0.0f,0.0f };
	pTexSize = { 4,4 };
	pDrawAlg = &paritcleDraw;
	pSpeed = rand() % 3 + 3.0f;
	pSpeed_Mag = 0.92f;
	pSpeed_Cor = 0.0f;
	pVector = { 1, 1 };
	pVector_Cor = 0.0f;
	pScale = { 0.5f,0.5f };
	pScale_Mag = { 0.98f,0.98f };
	pScale_Cor = { 0,0 };
	pHeight = 32.0f;
	pHeight_Speed = (rand()%20 - 10) * 0.1f;
	pHeight_Speed_Cor = -0.02f;
	pColor = { 1.0f,0.1f,0.0f,1.0f };
	pColor_Mag = 0.92f;
	pLife = 80;
}