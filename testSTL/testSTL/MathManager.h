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

	static Vector3 GetDirection(const Vector3& _Obj, const Vector3& _Target)
	{
		float Width = _Target.x - _Obj.x;
		float Height = _Target.y - _Obj.y;

		float Distance = sqrt((Width * Width) + (Height * Height));

		Vector3 Result = Vector3((Width / Distance), (Height / Distance));

		return Result;
	}
};