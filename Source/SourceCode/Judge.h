#pragma once

VECTOR2 sub_vector(VECTOR2 a, VECTOR2 b);
float Length(VECTOR2 a, VECTOR2 b);
VECTOR2 NorVector(VECTOR2 a, VECTOR2 b);
VECTOR2 NorVector(VECTOR2 a);

BOOL LineHitCheck(VECTOR2 v1, VECTOR2 v2, VECTOR2 t, float r1, float r2);
BOOL circleHitCheck(VECTOR2 v1, float r1, VECTOR2 v2, float r2);
BOOL SquareHitCheck(VECTOR2 v1, VECTOR2 v2, VECTOR2 v3, VECTOR2 v4, VECTOR2 t, float r);
VECTOR2 rotate(VECTOR2 vec, float angle);