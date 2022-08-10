#pragma once

#include "BulletBoom2.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

BulletBoom2::BulletBoom2() {}
BulletBoom2::~BulletBoom2() {}


void BulletBoom2::Initialize()
{
	// Bullet 税 汽戚斗 段奄鉢
	Type = BULLETBOOM2;
	Damage = 50;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	Count = 0;
}

int BulletBoom2::Update(Transform& Info)
{
	Count++;
	if (Count > 28)
		return BUFFER_OVER;
	pObject->SetPosition(Info.Position);

	
	return 0;
}

void BulletBoom2::Render()
{

	pObject->SetScale((float)Count / 5 * 2, (float)Count/ 5); 

	if (Count / 5 == 0)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"『", LIGHTMAGENTA);
	}
	else if (Count / 5 == 1)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y - 1,
			(char*)"『", LIGHTMAGENTA);

		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 2,
			pObject->GetPosition().y,
			(char*)"『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + 1,
			(char*)"『", LIGHTMAGENTA);
	}
	else if (Count / 5 == 2)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y - 2,
			(char*)"『", LIGHTMAGENTA);

		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 2,
			pObject->GetPosition().y - 1,
			(char*)"『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 4,
			pObject->GetPosition().y,
			(char*)"『『『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 2,
			pObject->GetPosition().y + 1,
			(char*)"『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + 2,
			(char*)"『", LIGHTMAGENTA);
	}
	else
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y - 3,
			(char*)"『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 2,
			pObject->GetPosition().y - 2,
			(char*)"『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 4,
			pObject->GetPosition().y - 1,
			(char*)"『『『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 6,
			pObject->GetPosition().y,
			(char*)"『『『『『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 4,
			pObject->GetPosition().y + 1,
			(char*)"『『『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x - 2,
			pObject->GetPosition().y + 2,
			(char*)"『『『", LIGHTMAGENTA);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + 3,
			(char*)"『", LIGHTMAGENTA);
	}

	

}

void BulletBoom2::Release()
{
}

