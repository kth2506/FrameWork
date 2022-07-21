#pragma once

#include "NormalPlayer.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "BulletNormal.h"
#include "BulletNormal2.h"
#include "BulletBoom.h"
#include "Player.h"
#include "ObjectManager.h"

NormalPlayer::NormalPlayer(){}

NormalPlayer::~NormalPlayer(){}

void NormalPlayer::Initialize()
{
	Hp = 10;
	Damage = 0;
	attackSpeed = 0.0f;
	BoomCount = 10000;
	as = 1.0f;
	
}

int NormalPlayer::Update(Transform& Info)
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	attackSpeed += as;
	if (dwKey & KEY_SPACE)
	{
		if (attackSpeed >= 10.0f)
		{
			Bridge* bBullet;
			switch (Bulletid)
			{
			case BULLETNORMAL:
				bBullet = new BulletNormal;
				ObjectManager::GetInstance()->AddBullet(bBullet);
				break;
			case BULLETNORMAL2:
				bBullet = new BulletNormal2;
				ObjectManager::GetInstance()->AddBullet(bBullet);
				break;
			}

			attackSpeed = 0.0f;
		}
	}

	if ((dwKey & KEY_CTRL) && BoomCount)
	{
		Bridge* bBullet;
		bBullet = new BulletBoom;
		ObjectManager::GetInstance()->AddBullet(bBullet);
		--BoomCount;
	}



	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f,
		Info.Position.y - Info.Scale.y * 0.5f,
		(char*)"  ¡ü  ", 11
	);
	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f,
		Info.Position.y - Info.Scale.y * 0.5f + 1,
		(char*)"£¼¡Ü£¾", 11
	);
	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f,
		Info.Position.y - Info.Scale.y * 0.5f + 2,
		(char*)"  ¡ý  ", 11
	);
	return 0;
}

void NormalPlayer::Render()
{

	
}

void NormalPlayer::Release()
{
}

