#include "All.h"

void MOVE_WAIT::move(GAME_OBJECT* obj) {
}

void MOVE_TRACKING::move(GAME_OBJECT* obj) {
	const float MOVE = 0.7f;
	if (Length(PL->obj->position, obj->position) > 140.0f)
	{
		obj->speed = NorVector(PL->obj->position, obj->position) * MOVE;
	}
	else
	{
		obj->speed = rotate(NorVector(PL->obj->position, obj->position),90.0f) * MOVE;
	}
}

void MOVE_PROACTIVE::move(GAME_OBJECT* obj) {
	const float MOVE = 1.1f;
	float vr = Length(PL->obj->speed, obj->speed);
	float sr = Length(PL->obj->position, obj->position);
	float tc = 0.0f;
	if (vr)tc = sr / vr;
	VECTOR2 point = PL->obj->position + PL->obj->speed * tc;
	VECTOR2 speed = NorVector(point - obj->position);
	obj->speed = speed * MOVE;
}

void MOVE_ESCAPE::move(GAME_OBJECT* obj) {
	const float MOVE = 0.7f;
	obj->speed = NorVector(obj->position, PL->obj->position) * MOVE;
}

void MOVE_NORMAL::move(GAME_OBJECT* obj) {
	const float MOVE = 0.7f;
	float angle = atan2f(obj->position.y - PL->obj->position.y, obj->position.x - PL->obj->position.x);
	angle += DirectX::XMConvertToRadians(90);
	obj->speed.x = cosf(angle) * MOVE;
	obj->speed.y = sinf(angle) * MOVE;
}