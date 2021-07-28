#include "SceneManager.h"
#include "Stage.h"


SceneManager* SceneManager::Instance = NULL;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}


void SceneManager::SetScene(SCENEID _SceneId)
{
	SAFE_RELEASE(SceneState);

	switch (_SceneId)
	{
	case SCENEID_STAGE:
		SceneState = new Stage;
		break;
	}

	SceneState->Initialize();
}

void SceneManager::Update()
{
}

void SceneManager::Render()
{
}

void SceneManager::Release()
{
}
