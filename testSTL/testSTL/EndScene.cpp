#include "EndScene.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
	Choice = 0;
	Text.push_back((char*)"다시 시작");
	Text.push_back((char*)"게임 종료");

	TextTrans.Position = Vector3(CONSOL_MAX_WIDTH / 2, 30 / 2);
	TextTrans.Scale = Vector3(strlen(Text.front()), Text.size());

	KeyInputStartTime = GetTickCount64();
	FrameTime = GetTickCount64();
}

void EndScene::Update()
{
	if (KeyInputStartTime + 500 < GetTickCount64())
	{
		if (FrameTime + 50 < GetTickCount64())
		{
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (Choice < 1)
					Choice++;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (Choice > 0)
					Choice--;
			}

			if (GetAsyncKeyState(VK_RETURN))
			{
				switch (Choice)
				{
				case 0:
					SceneManager::GetInstace()->SetScene(SCENEID_STAGE);
					break;
				case 1:
					Sleep(300);

					exit(NULL);
					break;
				}
			}
		}
	}
}

void EndScene::Render()
{
	{
		int y = 0;
		for (vector<char*>::iterator iter = Text.begin(); iter != Text.end(); ++iter)
		{
			DoubleBuffer::GetInstance()->WriteBuffer((int)(TextTrans.Position.x - (TextTrans.Scale.x / 2)),
				(int)(TextTrans.Position.y - (TextTrans.Scale.y / 2)) + y, (*iter), 8);
			if (Choice == y)
			{
				DoubleBuffer::GetInstance()->WriteBuffer((int)(TextTrans.Position.x - (TextTrans.Scale.x / 2)),
					(int)(TextTrans.Position.y - (TextTrans.Scale.y / 2)) + y, (*iter), 15);
			}
			y++;	
		}
	}
}

void EndScene::Release()
{
}