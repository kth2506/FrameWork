#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "NormalBullet.h"
Player::Player() : pBullet(nullptr){  }

Player::Player(Transform _Info) : Object(_Info){}
Player::~Player() {  }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;
	attackspeed = 0.0f;
	as = 1.0f;

	Buffer[0] = (char*)"  ¡ü  ";
	Buffer[1] = (char*)"£¼¡Ü£¾";
	Buffer[2] = (char*)"  ¡ý  ";
	

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 3.0f);
	Color = 15;

	return this;
}

int Player::Update()
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	
	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;

	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;

	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1;

	if (dwKey & KEY_CTRL)
		as += 0.1f;
		
	attackspeed += as;

	if (dwKey & KEY_SPACE)
	{
		if (attackspeed >= 5.0f)
		{
			attackspeed = 0.0f;
			Bridge* pBridge = new NormalBullet;
			ObjectManager::GetInstance()->AddBullet("Bullet", pBridge);
		}
	}
	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 3; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f, 
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i], Color
		);
}

void Player::Release()
{
}
