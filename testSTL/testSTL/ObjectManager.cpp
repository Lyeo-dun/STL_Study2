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


void ObjectManager::Initialize()
{
	AddObject(ObjectFactory<Player>::CreateObject());
}

void ObjectManager::Update()
{

}

void ObjectManager::Render()
{
}

void ObjectManager::Release()
{
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
