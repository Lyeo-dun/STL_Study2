#include "Bullet.h"
#include "DoubleBuffer.h"


Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	m_pKey = "Bullet";
	TransInfo.Position = Vector3(0, 0);

	vector<char*> _texture;

	_texture.push_back((char*)"<--");
	AddTexture(DIR_LEFT, BULLET, 0, _texture);
	_texture.clear();

	_texture.push_back((char*)"-->");
	AddTexture(DIR_RIGHT, BULLET, 0, _texture);

	TransInfo.Scale = Vector3(strlen((char*)"-->"), 1);
	m_Left = DIR_LEFT;
	Speed = 2.5f;
	Active = false;

	FrameTime = GetTickCount64();
}

void Bullet::Update()
{
	if (FrameTime + 50 < GetTickCount64())
	{
		switch (m_Left)
		{
		case DIR_LEFT:
			TransInfo.Position.x -= Speed;
			break;
		case DIR_RIGHT:
			TransInfo.Position.x += Speed;
			break;
		}

		if ((TransInfo.Position.x < (TransInfo.Scale.x/2)) || (TransInfo.Position.x > (120 - (TransInfo.Scale.x / 2))))
		{
			Active = false;
		}
		FrameTime = GetTickCount64();
	}
}

void Bullet::Render()
{
	map<int, vector<char*>>::iterator Map = Texture[m_Left][BULLET].begin();

	int y = 0;
	for (vector<char*>::iterator iter = Map->second.begin(); iter != Map->second.end(); ++iter)
	{
		DoubleBuffer::GetInstance()->WriteBuffer((int)(TransInfo.Position.x - TransInfo.Scale.x / 2),
			(int)(TransInfo.Position.y - TransInfo.Scale.y / 2) + y, (*iter), 15);
		y++;
	}
}

void Bullet::Release()
{
}
