#pragma once
#include "Object.h"

class Player : public Object
{
	//jump���� ����
	float m_Power;
		 
	bool m_Jumping;	
	bool m_Drop;
		 
	float m_OldJumpY;
	float m_MaximumY;

	//���� ����
	MOTION_DIRECTION m_Left;

	//�÷��̾� �̵� ����
	ULONGLONG FrameTime;
	float Speed;

	//�÷��̾� �ִϸ��̼� ����
	ULONGLONG AniTime;
	MOTION_KINDS MotionState;
	int Motion;
	float AniFrame;

public:
	void Jump();
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

