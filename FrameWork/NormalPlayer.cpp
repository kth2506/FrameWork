#include "NormalPlayer.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "NormalBullet.h"
#include "NormalBullet2.h"
#include "Player.h"
#include "ObjectManager.h"

NormalPlayer::NormalPlayer(){}

NormalPlayer::~NormalPlayer(){}

void NormalPlayer::Initialize()
{
	Hp = 30;
	Damage = 0;
	attackSpeed = 0.0f;
	as = 1.0f;
}

int NormalPlayer::Update(Transform& Info)
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_CTRL)
		as += 0.1f;

	attackSpeed += as;
	if (dwKey & KEY_SPACE)
	{
		if (attackSpeed >= 10.0f)
		{
			Bridge* bBullet;
			switch (Bulletid)
			{
			case NORMALBULLET:
				bBullet = new NormalBullet;
				ObjectManager::GetInstance()->AddBullet(bBullet);
				break;
			case NORMALBULLET2:
				bBullet = new NormalBullet2;
				ObjectManager::GetInstance()->AddBullet(bBullet);
				break;
			default:
				break;
			}
			attackSpeed = 0.0f;
		}
	}

	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f + 2,
		Info.Position.y - Info.Scale.y * 0.5f,
		(char*)"¡ü", 11
	);
	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f,
		Info.Position.y - Info.Scale.y * 0.5f + 1,
		(char*)"£¼¡Ü£¾", 11
	);
	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x - Info.Scale.x * 0.5f + 2,
		Info.Position.y - Info.Scale.y * 0.5f + 2,
		(char*)"¡ý", 11
	);
	return 0;
}

void NormalPlayer::Render()
{

	
}

void NormalPlayer::Release()
{
}

