#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstace() 
	{
		if (Instance == NULL)
			Instance = new SceneManager;
		return Instance;
	}

private:
	Scene* SceneState;

public:
	void SetScene(SCENEID _SceneId);

	void Update();
	void Render();
	void Release();

public:
	SceneManager();
	~SceneManager();
};

