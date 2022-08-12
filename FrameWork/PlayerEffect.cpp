#include "PlayerEffect.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
PlayerEffect::PlayerEffect(){}

PlayerEffect::~PlayerEffect(){}

void PlayerEffect::Initialize()
{
	Count = 0;
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù¡Ú¡Ù¡Ú");
	TextureList.emplace_back((char*)"¡Ú¡Ù¡Ú¡Ù");
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
	(pPlayer->GetPosition().x, pPlayer->GetPosition().y, (char*)"¡Ù");
	if(Count > 5 && Count < 8)
	CursorManager::GetInstance()->WriteBuffer
	(pPlayer->GetPosition().x, pPlayer->GetPosition().y, (char*)"¡Ú");

}

void PlayerEffect::Release()
{
}

