#pragma once
#include "Headers.h"

class Object
{
protected:
	map<int, vector<char*>> Texture[MOTION_MAX][KINDS_MAX];

	Transform TransInfo;
	MOTION_DIRECTION m_Left;

	bool Active;

	string m_Key;
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	//�� ������Ʈ Ű��
	string GetKey() { return m_Key; }
	
	//�ؽ��� ����
	void AddTexture(MOTION_DIRECTION _Dir, MOTION_KINDS _MotionKinds, int _MotionOrder, vector<char*> _texture);

	//transform�� ���� getter & setter
	Transform GetTransform()const { return TransInfo; }
	void SetPosition(Vector3 _pos) { TransInfo.Position = _pos; }
	Vector3 GetPosition()const { return TransInfo.Position; }
	void SetScale(Vector3 _scale) { TransInfo.Scale = _scale; }
	Vector3 GetScale()const { return TransInfo.Scale; }

	//active�� ���� ��Ʈ��
	void SetActive(const bool& _Active) { Active = _Active; }
	bool isActive() { return Active; }

	void SetDirection(MOTION_DIRECTION _Dir) { m_Left = _Dir; }
	MOTION_DIRECTION GetDirection()const { return m_Left; }

public:
public:
	Object();
	virtual ~Object();
};

