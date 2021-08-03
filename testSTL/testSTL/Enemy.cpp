#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	m_Key = "Enemy";
	TransInfo.Position = Vector3(0, 0);

	vector<char*> _texture;

	_texture.push_back((char*)"(====)");
	AddTexture(DIR_LEFT, BULLET, 0, _texture);
	_texture.clear();

	Active = false;
}

void Enemy::Update()
{
}

void Enemy::Render()
{
}

void Enemy::Release()
{
}

