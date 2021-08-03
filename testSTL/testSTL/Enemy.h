#pragma once
#include "Object.h"

class Enemy : public Object
{
	Vector3 TargetPos;

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:

public:
	Enemy();
	virtual ~Enemy()override;
};

