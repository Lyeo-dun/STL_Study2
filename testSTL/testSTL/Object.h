#pragma once
#include "Headers.h"

class Object
{
protected:
	map<string, list<char*>> Texture;
	Transform TransInfo;
	bool Active;
	
	string m_pKey;
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	string GetKey() { return m_pKey; }
	bool isActive() { return Active; }

public:
public:
	Object();
	virtual ~Object();
};

