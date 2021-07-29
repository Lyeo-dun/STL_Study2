#pragma once
#include "Object.h"

template <typename T>
class ObjectFactory 
{
public:
	static Object* CreateObject()
	{
		Object* _obj = new T;
		_obj->Initialize();

		return _obj;
	}
};