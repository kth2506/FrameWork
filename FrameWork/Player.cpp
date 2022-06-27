#include "Player.h"
#include "InputManager.h"
Player::Player()
	: Horizontal(0), Vertical(0) {  }

Player::Player(Transform _Info) : Object(_Info) , Horizontal(0), Vertical(0){}
Player::~Player() {  }

void Player::Initialize()
{
	strKey = "Player";
	Horizontal = 0;
	Vertical = 0;

	TransInfo.Position = Vector3(Horizontal, Vertical);
}

void Player::Update()
{

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	
	if (dwKey & KEY_UP)
		TransInfo.Position.x += 1;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.x -= 1;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.y -= 1;
	if (dwKey & KEY_RIGHT)
		TransInfo.Position.y += 1;


}

void Player::Render()
{
	cout << strKey << endl;
	cout << "X : " << TransInfo.Position.x << endl;
	cout << "Y : " << TransInfo.Position.y << endl << endl;
}

void Player::Release()
{
}
