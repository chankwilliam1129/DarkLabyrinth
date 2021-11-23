#include "All.h"

using namespace GameLib;
void CAMERA::update()
{
	using namespace input;
	if (angle >= 360)angle -= 360.0f;
	if (angle < 0)angle += 360.0f;
}

void CAMERA::object_update(DRAW_OBJECT* it)
{
	if (magnification <= 0)magnification = 0.1f;

	VECTOR2 temppos = it->position - position;

	it->drawPosition.x = temppos.x * cosf(ToRadian(angle)) - temppos.y * sinf(ToRadian(angle));
	it->drawPosition.y = temppos.x * sinf(ToRadian(angle)) + temppos.y * cosf(ToRadian(angle));

	it->drawPosition *= magnification;

	it->drawPosition.x += system::SCREEN_WIDTH / 2;
	it->drawPosition.y += system::SCREEN_HEIGHT / 2;

	it->drawPosition.y *= ratio;

	it->drawPosition.y += 350;
}