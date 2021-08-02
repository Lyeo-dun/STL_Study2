#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;

public:
	static ObjectManager* GetInstance() 
	{
		if (Instance == NULL)
			Instance = new ObjectManager;
		return Instance;
	}

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	map<string, list<Object*>> ObjectList;

public:
	void AddObject(Object* _pObj);

	list<Object*>* GetList(string _strKey) {
		map<string, list<Object*>>::iterator iter = ObjectList.find(_strKey);

		if (iter == ObjectList.end())
			return NULL;

		return &iter->second;
	}


public:
	~ObjectManager();
private:
	ObjectManager();
};

