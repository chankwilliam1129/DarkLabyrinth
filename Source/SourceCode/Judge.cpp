#include "All.h"

float vector2LengthSq(VECTOR2 v)
{
	return v.x * v.x + v.y * v.y;
}
float vector2Length(VECTOR2 v)
{
	return sqrtf(vector2LengthSq(v));
}
VECTOR2 sub_vector(VECTOR2 a, VECTOR2 b)
{
	VECTOR2 ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return ret;
}
float Length(VECTOR2 a, VECTOR2 b)
{
	return vector2Length(sub_vector(a, b));
}
VECTOR2 NorVector(VECTOR2 a, VECTOR2 b) {

	VECTOR2 t;
	t.x = a.x - b.x;
	t.y = a.y - b.y;

	float l;
	l = sqrtf((t.x * t.x) + (t.y * t.y));
	if (l) {
		t.x /= l;
		t.y /= l;
		return VECTOR2(t.x, t.y);
	}
	else return VECTOR2(1, 1);
}
VECTOR2 NorVector(VECTOR2 a) {
	return NorVector(a, VECTOR2(0, 0));
}
float cross(VECTOR2 a, VECTOR2 b, VECTOR2 p)
{
	VECTOR2 ab = sub_vector(a, b);
	VECTOR2 ap = sub_vector(a, p);

	return (ab.x * ap.y - ab.y * ap.x);
}
float dot(VECTOR2 a, VECTOR2 b, VECTOR2 p)
{
	VECTOR2 ap = sub_vector(a, p);
	VECTOR2 ab = sub_vector(a, b);

	return(ab.x * ap.x + ab.y * ap.y);
}
float dot2(VECTOR2 a, VECTOR2 b, VECTOR2 p)
{
	VECTOR2 bp = sub_vector(b, p);
	VECTOR2 ab = sub_vector(a, b);

	return(bp.x * ab.x + bp.y * ab.y);
}
BOOL LineHitCheck(VECTOR2 v1, VECTOR2 v2, VECTOR2 t, float r1, float r2)
{
	if (sqrtf(cross(v1, v2, t) * cross(v1, v2, t)) / Length(v1, v2) <= r1 + r2)
	{
		return TRUE;
	}

	return FALSE;

}
BOOL circleHitCheck(VECTOR2 v1, float r1, VECTOR2 v2, float r2)
{
	VECTOR2 v = v2 - v1;
	float lenSq = vector2LengthSq(v);
	if (lenSq <= (r1 + r2) * (r1 + r2))
	{
		return TRUE;
	}
	return FALSE;
}
BOOL TriangleHitCheck(VECTOR2 v1, VECTOR2 v2, VECTOR2 v3, VECTOR2 t, float r)
{
	if (sqrtf(cross(v1, v2, t) * cross(v1, v2, t)) / Length(v1, v2) <= r)
	{
		if (dot(v1, v2, t) * dot2(v1, v2, t) <= 0)return TRUE;

	}
	if (sqrtf(cross(v2, v3, t) * cross(v2, v3, t)) / Length(v2, v3) <= r)
	{
		if (dot(v2, v3, t) * dot2(v2, v3, t) <= 0)return TRUE;

	}
	if (sqrtf(cross(v3, v1, t) * cross(v3, v1, t)) / Length(v3, v1) <= r)
	{
		if (dot(v3, v1, t) * dot2(v3, v1, t) <= 0)return TRUE;

	}
	if ((cross(v1, v2, t) > 0 && cross(v2, v3, t) > 0 && cross(v3, v1, t) > 0) || (cross(v1, v2, t) < 0 && cross(v2, v3, t) < 0 && cross(v3, v1, t) < 0)) {

		return TRUE;
	}
	return FALSE;

}
BOOL SquareHitCheck(VECTOR2 v1, VECTOR2 v2, VECTOR2 v3, VECTOR2 v4, VECTOR2 t, float r)
{

	if (t.x + r < v1.x) return false;
	if (t.y + r < v1.y) return false;
	if (t.x - r > v3.x) return false;
	if (t.y - r > v3.y) return false;
	return true;
}
VECTOR2 rotate(VECTOR2 vec, float angle)
{
	VECTOR2 temp = vec;

	vec.x = temp.x * cosf(ToRadian(angle)) - temp.y * sinf(ToRadian(angle));
	vec.y = temp.x * sinf(ToRadian(angle)) + temp.y * cosf(ToRadian(angle));

	return vec;
}