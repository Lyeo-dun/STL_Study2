#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}

void Object::AddTexture(MOTION_DIRECTION _Dir, MOTION_KINDS _MotionKinds, int _MotionOrder, vector<char*> _Texture)
{
	map<int, vector<char*>>::iterator iter = Texture[_Dir][_MotionKinds].find(_MotionOrder);

	if (iter == Texture[_Dir][_MotionKinds].end())
	{
		Texture[_Dir][_MotionKinds].insert(make_pair(_MotionOrder, _Texture));
	}
	else
	{
		iter->second = _Texture;
	}
}
