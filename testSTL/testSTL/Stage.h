#pragma once
#include "Scene.h"

class Stage :public Scene
{
private:
	ULONGLONG EnemySpawnTime;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Stage();
	virtual ~Stage()override;
};

