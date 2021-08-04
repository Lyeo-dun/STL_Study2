#include "Enemy.h"
#include "ObjectManager.h"
#include "DoubleBuffer.h"
#include "MathManager.h"
#include "ColliderManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}


void Enemy::Initialize()
{
	m_Key = "Enemy";
	TransInfo.Position = Vector3(0, 0);

	vector<char*> _texture;

	_texture.push_back((char*)"(====)");
	_texture.push_back((char*)"(====)");
	_texture.push_back((char*)"(====)");

	AddTexture(DIR_CENTER, ENEMY, 0, _texture);
	TransInfo.Scale = Vector3(strlen((char*)"(====)"), _texture.size());

	_texture.clear();

	Direction = Vector3(0, 0);
	Speed = 0.8f;

	m_Left = DIR_CENTER;
	MotionState = ENEMY;
	Motion = 0;
	
	Active = false;
	TargetCheck = false;
	
	FrameTime = GetTickCount64();
}

void Enemy::Update()
{
	if (FrameTime + 50 < GetTickCount64())
	{
		if (!TargetCheck)
		{
			TargetChecking();
		}	
		TransInfo.Position.x += Direction.x * Speed;
		TransInfo.Position.y += Direction.y * Speed;

		FrameTime = GetTickCount64();
	}

	{
		list<Object*> &BulletList = *ObjectManager::GetInstance()->GetList("Bullet");
		for (list<Object*>::iterator iter = BulletList.begin(); iter != BulletList.end();++iter)
		{
			if((*iter)->isActive())
				if (ColliderManager::CollisionRact(TransInfo, (*iter)->GetTransform()))
				{
					SetActiveFalse();
					(*iter)->SetActive(false);

					break;
				}
		}
	}

	if (TransInfo.Position.y > 28 || TransInfo.Position.x >= 120 - TransInfo.Scale.x || TransInfo.Position.x <= TransInfo.Scale.x)
	{
		SetActiveFalse();
	}
}

void Enemy::Render()
{
	map<int, vector<char*>>::iterator Map = Texture[m_Left][MotionState].find(Motion);

	int y = 0;
	for (vector<char*>::iterator iter = Map->second.begin(); iter != Map->second.end(); ++iter)
	{
		DoubleBuffer::GetInstance()->WriteBuffer((int)(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			(int)(TransInfo.Position.y - (TransInfo.Scale.y / 2)) + y, (*iter), 15);
		y++;
	}
}


void Enemy::Release()
{
}


void Enemy::SetActiveFalse()
{
	TargetCheck = false;
	Active = false;
	ObjectManager::GetInstance()->SetEnemyCount(ObjectManager::GetInstance()->GetEnemyCount() - 1);
}

void Enemy::TargetChecking()
{
	list<Object*> PlayerList = *ObjectManager::GetInstance()->GetList("Player");
	TargetPos = PlayerList.front()->GetPosition();
	Direction = MathManager::GetDirection(TransInfo.Position, TargetPos);

	TargetCheck = true;
}
