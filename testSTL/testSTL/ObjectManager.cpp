#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Player.h"
#include "Bullet.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Initialize()
{
	AddObject(ObjectFactory<Player>::CreateObject());
}

void ObjectManager::Update()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			if ((*iter2)->isActive())
			{
				(*iter2)->Update();
			}
		}
	}
}

void ObjectManager::Render()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			if ((*iter2)->isActive())
			{
				(*iter2)->Render();
			}
		}
	}
}

void ObjectManager::Release()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			SAFE_RELEASE(*iter2);
		}
	}

	ObjectList.clear();
}

void ObjectManager::AddObject(Object* _pObj)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObj->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> TmpList;
		TmpList.push_back(_pObj);

		ObjectList.insert(make_pair(_pObj->GetKey(), TmpList));
	}
	else
	{
		iter->second.push_back(_pObj);
	}
}
