#pragma once
class PARTICLE :public MOVEALG
{
public:
	enum iWORK
	{
		pLife = 0,
	};

	enum fWORK
	{
		pSpeed,
		pSpeed_Mag,
		pSpeed_Cor,
		pVector_Cor,
		pColor_Mag,
		pHeight,
		pHeight_Speed,
		pHeight_Speed_Cor,
	};

	enum vWORK
	{
		pVector,
		pScale,
		pScale_Mag,
		pScale_Cor,
		pColorXY,
		pColorZW,
	};

public:
	void move(GAME_OBJECT* obj);
};
EXTERN PARTICLE partical_mvAlg;

