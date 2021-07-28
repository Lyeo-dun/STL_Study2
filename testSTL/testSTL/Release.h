#pragma once
template <typename T>
void Safe_Release(T& _obj)
{
	if (_obj != NULL)
	{
		delete _obj;
		_obj = NULL;
	}
}

#define SAFE_RELEASE(_obj) Safe_Release(_obj)