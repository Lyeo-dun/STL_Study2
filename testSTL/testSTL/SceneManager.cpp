#include "SceneManager.h"
#include "Stage.h"
#include "EndScene.h"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}


void SceneManager::SetScene(SCENEID _SceneId)
{
	SAFE_RELEASE(SceneState);

	switch (_SceneId)
	{
	case SCENEID_STAGE:
		SceneState = new Stage;
		break;
	case SCENEID_ENDING:
		SceneState = new EndScene;
		break;
	}

	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	SAFE_RELEASE(SceneState);
}
