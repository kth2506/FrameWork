#define _CRT_SECURE_NO_WARNINGS
#include "Bullet.h"
#include "CursorManager.h"
#include "Player.h"
#include "ObjectManager.h"
#include "MathManager.h"

Bullet::Bullet(){}

Bullet::Bullet(Transform _Info) : Object(_Info){}

Bullet::~Bullet() {  }

Object* Bullet::Initialize(string _Key)
{
	strKey = _Key;

	Buffer[0] = (char*)"¢´";
	Buffer[1] = (char*)"";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);

	return this;
}

int Bullet::Update()
{
	
	TransInfo.Direction = MathManager::GetCursorDirection(TransInfo.Position);

	//TransInfo.Direction = MathManager::GetDirection(
	//	TransInfo.Position, Vector3(60.0f, 15.0f));
	//
	//TransInfo.Position += TransInfo.Direction;
	

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i], 13
		);
	}
	TransInfo.Position += TransInfo.Direction;

}

void Bullet::Release()
{

}
