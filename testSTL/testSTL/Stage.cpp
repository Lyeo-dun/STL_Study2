#include "Stage.h"
#include "ObjectManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	ObjectManager::GetInstance()->Initialize();
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	ObjectManager::GetInstance()->Release();
}
