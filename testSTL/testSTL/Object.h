#pragma once
#include "Headers.h"

class Object
{
protected:
	map<int, vector<char*>> Texture[MOTION_MAX][KINDS_MAX];

	Transform TransInfo;
	bool Active;
	
	string m_pKey;
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	void AddTexture(MOTION_DIRECTION _Dir, MOTION_KINDS _MotionKinds, int _MotionOrder, vector<char*> _texture);

	string GetKey() { return m_pKey; }
	bool isActive() { return Active; }

public:
public:
	Object();
	virtual ~Object();
};

