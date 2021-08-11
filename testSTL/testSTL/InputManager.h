#pragma once
#include "Headers.h"

class InputManager
{
public:
	DECLARE_SINGLETON(InputManager)

private:
	ULONG m_ulKey;
public:
	ULONG GetKey() { return m_ulKey; }
	void Checkkey();

public:
	InputManager();
	~InputManager();
};

