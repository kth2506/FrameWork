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
#include "BulletBoom2.h"
#include "BulletFire.h"
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
	Maxhp = Hp;
	FireSpeed = 0.0f;
	Fs = 0.3f;
	FireGrade = false;
}

int NormalPlayer::Update(Transform& Info)
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	attackSpeed += as;
	FireSpeed += Fs;
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
		for (int i = 0; i < 20; ++i)
		{
			Bridge* bBullet;
			bBullet = new BulletBoom2;
			Vector3 vec = Vector3(float(rand() % 160) + 10, float(rand() % 30) + 10);
			ObjectManager::GetInstance()->AddBullet(bBullet, vec);
		}
		--BoomCount;
	}

	if (FireGrade && (FireSpeed > 20.0f))
	{
		Bridge* bBullet;
		bBullet = new BulletFire;
		ObjectManager::GetInstance()->AddBullet(bBullet);
		FireSpeed = 0.0;
	}

	return 0;
}

void NormalPlayer::Render()
{

	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - pObject->GetScale().x * 0.5f,
		pObject->GetPosition().y - pObject->GetScale().y * 0.5f,
		(char*)"���ܣ�", CYAN
	);
	
}

void NormalPlayer::Release()
{
}

