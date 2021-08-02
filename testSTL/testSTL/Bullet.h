#pragma once
#include "Object.h"

class Bullet : public Object
{
	float Speed;

	ULONGLONG FrameTime;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Bullet();
	virtual ~Bullet()override;
};

