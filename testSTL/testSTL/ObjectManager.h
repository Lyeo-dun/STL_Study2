#pragma once
#include "Headers.h"
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

public:
	~ObjectManager();
private:
	ObjectManager();
};

