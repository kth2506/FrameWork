﻿#include "Enemy.h"
#include "CursorManager.h"
Enemy::Enemy() {}
Enemy::Enemy(Transform _Info) : Object(_Info){}
Enemy::~Enemy() {}

Object* Enemy::Initialize(string _Key)
{
	strKey = _Key;
	
	Buffer[0] = (char*)"호";
	Buffer[1] = (char*)"ㅅ";
	Hp = 10;
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	return this;

}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0; 
}

void Enemy::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i], 15
		);
	}
}

void Enemy::Release()
{
}
