#include "InputManager.h"
#include "DoubleBuffer.h"


InputManager* InputManager::m_pInstance = NULL;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Checkkey()
{
	m_ulKey = 0;

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_ulKey |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_ulKey |= KEYID_RIGHT;
	}

}
