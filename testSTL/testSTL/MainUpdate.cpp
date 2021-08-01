#include "MainUpdate.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "InputManager.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	DoubleBuffer::GetInstance()->CreateBuffer(CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);
	SceneManager::GetInstace()->SetScene(SCENEID_STAGE);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->Checkkey();
	SceneManager::GetInstace()->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();
}

void MainUpdate::Render()
{
	SceneManager::GetInstace()->Render();
}

void MainUpdate::Release()
{
	SceneManager::GetInstace()->Release();
	DoubleBuffer::GetInstance()->DestroyBuffer();
}
