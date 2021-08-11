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
	GETSINGLETON(SceneManager)->SetScene(SCENEID_STAGE);
}

void MainUpdate::Update()
{
	GETSINGLETON(InputManager)->Checkkey();
	GETSINGLETON(SceneManager)->Update();

	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();
}

void MainUpdate::Render()
{
	GETSINGLETON(SceneManager)->Render();
}

void MainUpdate::Release()
{
	GETSINGLETON(SceneManager)->Release();
	DoubleBuffer::GetInstance()->DestroyBuffer();
}
