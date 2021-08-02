#pragma once
#include "Object.h"

class Player : public Object
{
	//jump���� ����
	float m_Power;		 
	bool m_Jump;			 
	float m_OldY;
	float m_Time;

	//�÷��̾� �̵� ����
	ULONGLONG FrameTime;
	float Speed;

	//�÷��̾� �ִϸ��̼� ����
	ULONGLONG AniTime;
	MOTION_KINDS MotionState;
	int Motion;
	float AniFrame;

	//�����
	ULONGLONG BulletTime;
	float RateOfFire;

public:
	void Jump();
	void CheckJump();
	void CheckKey();

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Player();
	virtual ~Player()override;
};

