#include "MainUpdate.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

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

}

void MainUpdate::Update()
{
}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}
