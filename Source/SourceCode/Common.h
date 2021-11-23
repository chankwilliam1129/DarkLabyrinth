#pragma once

template<typename MANAGER>
class SINGLETON
{
public:
	static std::shared_ptr<MANAGER> getInstance()
	{
		static std::shared_ptr<MANAGER> instance = std::shared_ptr<MANAGER>(new MANAGER);
		return instance;
	}
};

static float(* const ToRadian)(float) = DirectX::XMConvertToRadians;
static float(* const ToDegree)(float) = DirectX::XMConvertToDegrees;

#define CLICK_ENTER		(TRG(0) & PAD_START)
#define HOLD_UP			(STATE(0) & PAD_UP)
#define HOLD_DOWN		(STATE(0) & PAD_DOWN)
#define HOLD_LEFT		(STATE(0) & PAD_LEFT)
#define HOLD_RIGHT		(STATE(0) & PAD_RIGHT)

#define CLICK_MOUSE_LEFT	(TRG(0) & PAD_L1)
#define CLICK_MOUSE_RIGHT	(TRG(0) & PAD_L2)
#define CLICK_MOUSE_MIDDLE	(TRG(0) & PAD_L3)

#define OUT_MOUSE_LEFT	(TRG_RELEASE(0) & PAD_L1)

#define HOLD_Z			(STATE(0) & PAD_TRG1)
#define HOLD_X			(STATE(0) & PAD_TRG2)
#define HOLD_C			(STATE(0) & PAD_TRG3)

