#include "InputManager.h"
#include "DoubleBuffer.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Checkkey()
{
	m_ulKey = 0;

	if (GetAsyncKeyState('A'))
	{
		m_ulKey |= KEYID_LEFT;
	}
	if (GetAsyncKeyState('D'))
	{
		m_ulKey |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		m_ulKey |= KEYID_RETURN;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_ulKey |= KEYID_SPACE;
	}

}
