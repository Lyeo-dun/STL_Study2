#pragma once
#include "Scene.h"

class EndScene : public Scene
{
	int Choice;
	vector<char*> Text;
	Transform TextTrans;

	ULONGLONG KeyInputStartTime;
	ULONGLONG FrameTime;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	EndScene();
	virtual ~EndScene()override;
};

