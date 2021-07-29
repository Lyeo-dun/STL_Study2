#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	Object();
	virtual ~Object();
};

