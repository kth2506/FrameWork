#pragma once

#include "BulletBoom.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"
#include "BulletBoom2.h"

BulletBoom::BulletBoom() {}
BulletBoom::~BulletBoom() {}


void BulletBoom::Initialize()
{
	// Bullet 의 데이터 초기화
	Type = BULLETBOOM;
	Damage = 50;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	Count = 0;
}

int BulletBoom::Update(Transform& Info)
{
	if (Count >= 20)
	{
		Bridge* bBullet;
		bBullet = new BulletBoom2;
		ObjectManager::GetInstance()->AddBullet(bBullet, Info.Position);
		return BUFFER_OVER;
	}
	if (Count < 20)
	Info.Position += Info.Direction * 2.0f;

	Count++;

	return 0;
}

void BulletBoom::Render()
{
	switch (Count % 3)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"※", 2);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"★", 2);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"☆", 2);
		break;
	default:
		break;
	}
}

void BulletBoom::Release()
{
}

