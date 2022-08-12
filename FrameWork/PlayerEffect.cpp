#include "PlayerEffect.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
PlayerEffect::PlayerEffect(){}

PlayerEffect::~PlayerEffect(){}

void PlayerEffect::Initialize()
{
	Count = 0;
	TextureList.emplace_back((char*)"��");
	TextureList.emplace_back((char*)"��");
	TextureList.emplace_back((char*)"�١ڡ١�");
	TextureList.emplace_back((char*)"�ڡ١ڡ�");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

}

int PlayerEffect::Update(Transform& Info)
{
	Count++;
	if (Count > 100)
		return BUFFER_OVER;
	return 0;
}

void PlayerEffect::Render()
{
	if(Count < 4)
	CursorManager::GetInstance()->WriteBuffer
	(pPlayer->GetPosition().x, pPlayer->GetPosition().y, (char*)"��");
	if(Count > 5 && Count < 8)
	CursorManager::GetInstance()->WriteBuffer
	(pPlayer->GetPosition().x, pPlayer->GetPosition().y, (char*)"��");

}

void PlayerEffect::Release()
{
}

