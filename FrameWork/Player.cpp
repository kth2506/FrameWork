#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Player::Player()
	: Horizontal(0), Vertical(0) {  }

Player::Player(Transform _Info) : Object(_Info) , Horizontal(0), Vertical(0){}
Player::~Player() {  }

void Player::Initialize()
{
	strKey = "Player";

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";
	

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
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

	if (dwKey & KEY_SPACE)
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Bullet>::CreateObject(TransInfo.Position));

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.y * 0.5f) + i,
			Buffer[i]);
	}

	
}

void Player::Release()
{
}