#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
Player::Player(){  }

Player::Player(Transform _Info) : Object(_Info){}
Player::~Player() {  }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(Console_Width / 2, Console_Height / 2);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 3.0f);
	Color = 15;

	if (pBridge)
		pBridge->Initialize();
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
	{
		if (TransInfo.Position.x < 10)
			TransInfo.Position.x = 10;
		if (TransInfo.Position.x > Console_Width - 10.0f)
			TransInfo.Position.x = Console_Width - 10.0f;
		if (TransInfo.Position.y < 10)
			TransInfo.Position.y = 10;
		if (TransInfo.Position.y > Console_Height - 5.0f)
			TransInfo.Position.y = Console_Height - 5.0f;
	}
	if (pBridge)
		pBridge->Update(TransInfo);
	return 0;
}

void Player::Render()
{
	if (pBridge)
		pBridge->Render();

}

void Player::Release()
{
	delete pBridge;
	pBridge = nullptr;
}
