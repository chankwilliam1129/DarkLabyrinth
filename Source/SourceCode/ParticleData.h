#pragma once
class PARTICLE_DATA
{
public:
	GameLib::Sprite* pData = SPRITELOAD::spr["Partial"];
	VECTOR2	pTexPos = { 0.0f,0.0f };
	VECTOR2	pTexSize = { 4,4 };

	DRAWALG* pDrawAlg = &paritcleDraw;

	float pSpeed = 1;
	float pSpeed_Mag = 1;
	float pSpeed_Cor = .0f;

	VECTOR2 pVector = { 1, 1 };
	float pVector_Cor = 0.0f;

	VECTOR2 pScale = { 1,1 };
	VECTOR2 pScale_Mag = { 1,1 };
	VECTOR2 pScale_Cor = { 0,0 };

	float pHeight = 32.0f;
	float pHeight_Speed = 0.0f;
	float pHeight_Speed_Cor = 0.0f;

	VECTOR4 pColor = { 0.6f,0.3f,0.2f,1 };
	float pColor_Mag = 1;

	int pLife = 300;

public:
	GAME_OBJECT* create();
	GAME_OBJECT* create(VECTOR2 pVector);
};
EXTERN PARTICLE_DATA particle_data;

class PARTICLE_RAIN:public PARTICLE_DATA
{
public:
	PARTICLE_RAIN();
};
EXTERN PARTICLE_RAIN particle_rain;

class PARTICLE_SPARK :public PARTICLE_DATA
{
public:
	PARTICLE_SPARK();
};
EXTERN PARTICLE_SPARK particle_spark;