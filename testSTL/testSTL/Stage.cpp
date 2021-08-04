#include "Stage.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Enemy.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	ObjectManager::GetInstance()->Initialize();
	EnemySpawnTime = GetTickCount64();
}

void Stage::Update()
{
	if (EnemySpawnTime + 1000 < GetTickCount64())
	{
		int EnemyCount = ObjectManager::GetInstance()->GetEnemyCount();
		if (EnemyCount < 8)
		{
			list<Object*> EnemyList= *ObjectManager::GetInstance()->GetList("Enemy");

			for (list<Object*>::iterator iter = EnemyList.begin(); iter != EnemyList.end(); ++iter)
			{
				if (!(*iter)->isActive())
				{
					(*iter)->SetActive(true);

					int EnemyX = rand() % 2;
					float EnemyY = rand() % 10 + 3;

					switch (EnemyX)
					{
					case 0:
						EnemyX = (*iter)->GetScale().x;
						break;
					case 1:
						EnemyX = 120 - (*iter)->GetScale().x;
						break;
					}
					(*iter)->SetPosition(Vector3(EnemyX, EnemyY));

					break;
				}
			}

			ObjectManager::GetInstance()->SetEnemyCount(EnemyCount + 1);

			EnemySpawnTime = GetTickCount64();
		}
	}

	if (ObjectManager::GetInstance()->GetEnemyCount() >= 128)
	{
		ObjectManager::GetInstance()->SetEnemyCount(128);
	}
	
	ObjectManager::GetInstance()->Update();

	if (ObjectManager::GetInstance()->GetMoveScene())
	{
		Sleep(300);
		SceneManager::GetInstace()->SetScene(SCENEID_ENDING);
	}

}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	ObjectManager::GetInstance()->Release();
}
