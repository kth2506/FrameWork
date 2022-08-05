#pragma once

#include "NormalPlayer.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "BulletNormal.h"
#include "BulletNormal2.h"
#include "BulletBoom.h"
#include "Player.h"
#include "ObjectManager.h"
#include "BulletLazer.h"
NormalPlayer::NormalPlayer(){}

NormalPlayer::~NormalPlayer(){}

void NormalPlayer::Initialize()
{
	Hp = 5;
	Damage = 0;
	attackSpeed = 0.0f;
	BoomCount = 5;
	as = 1.0f;
	Level = 1;
	Exp = 0;

	
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
			case BULLETLAZER:
				bBullet = new BulletLazer;
				ObjectManager::GetInstance()->AddBullet(bBullet);
				break;
			}

			attackSpeed = 0.0f;
		}
	}

	if ((dwKey & KEY_CTRL) && BoomCount && ( attackSpeed >= 10.0f))
	{
		attackSpeed = 0.0f;
		Bridge* bBullet;
		bBullet = new BulletBoom;
		ObjectManager::GetInstance()->AddBullet(bBullet);
		--BoomCount;
	}


	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f,
		Info.Position.y - Info.Scale.y * 0.5f + 1,
		(char*)"£¼¡Ü£¾", 9
	);
	return 0;
}

void NormalPlayer::Render()
{

	
}

void NormalPlayer::Release()
{
}

