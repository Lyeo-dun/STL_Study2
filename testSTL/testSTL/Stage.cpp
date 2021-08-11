#include "Stage.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "Enemy.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release(); 
	/*
	* 씬을 없앨 때 만들었던 데이터를 삭제하지 않은 채 Initialize를 하기 때문에 데이터가
	* 두배로 생겨난다. 하지만 그정도의 데이터 양까지는 필요없고, 현재는 간단한 프로젝트 이므로
	* 임시적으로 씬이 소멸할 때 release를 해주었다.
	*/
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
		GETSINGLETON(SceneManager)->SetScene(SCENEID_ENDING);
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
