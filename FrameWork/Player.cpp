#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Player::Player() : pBullet(nullptr){  }

Player::Player(Transform _Info) : Object(_Info){}
Player::~Player() {  }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;
	attackspeed = 0.0f;
	as = 1.0f;

	Buffer[0] = (char*)"  ��  ";
	Buffer[1] = (char*)"���ܣ�";
	Buffer[2] = (char*)"  ��  ";
	

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
		if (attackspeed >= 10)
		{
			attackspeed = 0.0f;
			ObjectManager::GetInstance()->AddObject("Bullet");
		}
	}
	return 0;
}

void Player::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x , 
			TransInfo.Position.y + i, 
			Buffer[i], Color
		);
	}
	
}

void Player::Release()
{
}
