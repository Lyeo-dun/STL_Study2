#pragma once
#include "Headers.h"

class MathManager
{	
public:
	static float GetDistance(const Vector3& _Obj, const Vector3& _Target)
	{
		float Width = _Target.x - _Obj.x;
		float Height = _Target.y - _Obj.y;

		return sqrt((Width * Width) + (Height * Height));
	}
};