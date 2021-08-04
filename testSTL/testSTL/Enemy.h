#pragma once
#include "Object.h"

class Enemy : public Object
{

	Vector3 TargetPos;
	bool TargetCheck;

	MOTION_KINDS MotionState;
	int Motion;

	Vector3 Direction;
	float Speed;

	ULONGLONG FrameTime;

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

