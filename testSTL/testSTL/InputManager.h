#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* m_pInstance;
public:
	static InputManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new InputManager;
		
		return m_pInstance;
	}

private:
	ULONG m_ulKey;
public:
	ULONG GetKey() { return m_ulKey; }
	void Checkkey();

private:
	InputManager();
public:
	~InputManager();
};

