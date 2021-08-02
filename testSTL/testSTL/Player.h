#pragma once
#include "Object.h"

class Player : public Object
{
	//jump관련 변수
	float m_Power; //점프 뛸 때 힘
	bool m_Jump; //점프 상태인지 아닌지
	float m_OldY; //점프 뛰기 전의 높이
	float m_Time; //점프를 하는 중에 흐른 시간

	//플레이어 이동 제어
	ULONGLONG FrameTime;
	float Speed;

	//플레이어 애니메이션 제어
	ULONGLONG AniTime;
	MOTION_KINDS MotionState;
	int Motion;
	float AniFrame;

	//연사력
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

