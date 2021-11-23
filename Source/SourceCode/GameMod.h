#pragma once
class MOD
{
public:
	enum type
	{
		mNONE,
		mCritial_Chance,
		mCritial_Mag,
		mDamage_Mag,
		mMultishot,
		mReflection,
		mAttackSpeed_Mag,
		mTOTLE,
	};
public:
	int	level = 0;
	int type = 0;
};

class MODOBJECT :public MOVEALG
{
public:
	enum iWork
	{
		mLevel,
		mType,
	};
	enum fWork
	{
		mHeight_Speed,
	};
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MODOBJECT modObject;

class MODDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN MODDRAW modDraw;