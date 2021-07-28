#pragma once
class Scene
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

public:
	Scene();
	virtual ~Scene();
};

