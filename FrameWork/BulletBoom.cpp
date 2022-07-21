#pragma once

#include "BulletBoom.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"


BulletBoom::BulletBoom() {}
BulletBoom::~BulletBoom() {}


void BulletBoom::Initialize()
{
	// Bullet 税 汽戚斗 段奄鉢
	Type = BULLETBOOM;
	Damage = 50;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	Count = 0;
	List.push_back((char*)"『");
	List.push_back((char*)"『『『");
	List.push_back((char*)"『『『『『");
	List.push_back((char*)"『『『『『『『");
	List.push_back((char*)"『『『『『");
	List.push_back((char*)"『『『");
	List.push_back((char*)"『");
}

int BulletBoom::Update(Transform& Info)
{
	//if (Count > 50)
	//	return BUFFER_OVER;
	if (Count < 20)
	Info.Position += Info.Direction * 2.0f;

	Count++;

	return 0;
}

void BulletBoom::Render()
{
	if (Count > 20)
		Boom();
	else if (Count < 20)
	{
		switch (Count % 3)
		{
		case 0:
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x,
				pObject->GetPosition().y,
				(char*)"『", 2);
			break;
		case 1:
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x,
				pObject->GetPosition().y,
				(char*)"【", 2);
			break;
		case 2:
			CursorManager::GetInstance()->WriteBuffer(
				pObject->GetPosition().x,
				pObject->GetPosition().y,
				(char*)"』", 2);
			break;
		default:
			break;
		}
	}
	

}

void BulletBoom::Release()
{
}


void BulletBoom::Boom()
{
	pObject->SetScale(9.0f, 7.0f);

	CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y - 3,
			List[0], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 2,
		pObject->GetPosition().y - 2,
		List[1], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 4,
		pObject->GetPosition().y - 1,
		List[2], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 6,
		pObject->GetPosition().y,
		List[3], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 4,
		pObject->GetPosition().y + 1,
		List[4], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 2,
		pObject->GetPosition().y + 2,
		List[5], 2);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y + 3,
		List[6], 2);
}