#include "Player.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	m_pKey = "Player";

	Active = true;

	TransInfo.Position = Vector3(30, 28);
	TransInfo.Scale = Vector3(strlen("(|-)>"), 3);
	

	//플레이어 텍스쳐 작업
	{//왼쪽 애니메이션
		vector<char*> Left;

		//대기 모션
		Left.push_back((char*)"   o");
		Left.push_back((char*)"<(-|)");
		Left.push_back((char*)"  / ＼");

		AddTexture(DIR_LEFT, IDLE, 0, Left);
		Left.clear();

		//걷기
		Left.push_back((char*)"   o");
		Left.push_back((char*)"<(-|)");
		Left.push_back((char*)"  / <");
		
		AddTexture(DIR_LEFT, WALK, 0, Left);
		Left.clear();

		Left.push_back((char*)"   o");
		Left.push_back((char*)"<(-|)");
		Left.push_back((char*)"  / ＼");

		AddTexture(DIR_LEFT, WALK, 1, Left);
		Left.clear();

		Left.push_back((char*)"   o");
		Left.push_back((char*)"<(-|)");
		Left.push_back((char*)"  < ＼");

		AddTexture(DIR_LEFT, WALK, 2, Left);
		Left.clear();

		Left.push_back((char*)"   o");
		Left.push_back((char*)"<(-|)");
		Left.push_back((char*)"  / ＼");
	
		AddTexture(DIR_LEFT, WALK, 3, Left);
		Left.clear();
	}

	{//오른쪽 애니메이션
		vector<char*> Right;

		//대기
		Right.push_back((char*)" o");
		Right.push_back((char*)"(|-)>");
		Right.push_back((char*)"/ ＼");

		AddTexture(DIR_RIGHT, IDLE, 0, Right);
		Right.clear();

		//걷기
		Right.push_back((char*)" o");
		Right.push_back((char*)"(|-)>");
		Right.push_back((char*)"/ >");

		AddTexture(DIR_RIGHT, WALK, 0, Right);
		Right.clear();

		Right.push_back((char*)" o");
		Right.push_back((char*)"(|-)>");
		Right.push_back((char*)"/ ＼");

		AddTexture(DIR_RIGHT, WALK, 1, Right);
		Right.clear();

		Right.push_back((char*)" o");
		Right.push_back((char*)"(|-)>");
		Right.push_back((char*)" >＼");

		AddTexture(DIR_RIGHT, WALK, 2, Right);
		Right.clear();

		Right.push_back((char*)" o");
		Right.push_back((char*)"(|-)>");
		Right.push_back((char*)"/ ＼");

		AddTexture(DIR_RIGHT, WALK, 3, Right);
		Right.clear();
	}
	
	m_Left = DIR_LEFT;
	Motion = 0;
	MotionState = IDLE;
	
	AniFrame = 85;
	Speed = 1.2f;

	FrameTime = GetTickCount64();
	AniTime = GetTickCount64();
}

void Player::Update()
{
	if (AniTime + AniFrame < GetTickCount64())
	{
		if (MotionState != IDLE)
		{
			Motion++;

			if (Motion > Texture[m_Left][MotionState].size() - 1)
			{
				Motion = 0;
			}
			
			AniTime = GetTickCount64();
		}
	}

	if (FrameTime + 50 < GetTickCount64())
	{
		CheckKey();

		FrameTime = GetTickCount64();
	}
}

void Player::Render()
{
	map<int, vector<char*>>::iterator Map = Texture[m_Left][MotionState].find(Motion);

	int y = 0;
	for (vector<char*>::iterator iter = Map->second.begin(); iter != Map->second.end(); ++iter)
	{
		DoubleBuffer::GetInstance()->WriteBuffer((int)(TransInfo.Position.x - TransInfo.Scale.x / 2),
			(int)(TransInfo.Position.y - TransInfo.Scale.y / 2) + y, (*iter), 15);
			y++;
	}
}

void Player::Release()
{
}

void Player::Jump()
{

}

void Player::CheckKey()
{
	ULONG ulKey = InputManager::GetInstance()->GetKey();

	if (ulKey & KEYID_LEFT)
	{
		TransInfo.Position.x -= Speed;
		MotionState = WALK;
		m_Left = DIR_LEFT;
	}
	if (ulKey & KEYID_RIGHT)
	{
		TransInfo.Position.x += Speed;
		MotionState = WALK;
		m_Left = DIR_RIGHT;
	}
	if (ulKey == 0)
	{
		MotionState = IDLE;
		Motion = 0;
	}
}
