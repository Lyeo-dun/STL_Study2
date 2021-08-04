#pragma once
#include "Headers.h"

class ColliderManager
{
public:
	static bool CollisionRact(const Transform& _Temp, const Transform& _Dest)
	{
		if (((_Temp.Position.x + (_Temp.Scale.x / 2)) > (_Dest.Position.x - (_Dest.Scale.x / 2))) &&
			((_Temp.Position.y + (_Temp.Scale.y / 2)) > (_Dest.Position.y - (_Dest.Scale.y / 2))) &&
			((_Dest.Position.x + (_Dest.Scale.x / 2)) > (_Temp.Position.x - (_Temp.Scale.x / 2))) &&
			((_Dest.Position.y + (_Dest.Scale.y / 2)) > (_Temp.Position.y - (_Temp.Scale.y / 2))))
			return true;

		return false;
	}
};