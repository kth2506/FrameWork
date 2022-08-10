#include "PlayerEffect.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
PlayerEffect::PlayerEffect(){}

PlayerEffect::~PlayerEffect(){}

void PlayerEffect::Initialize()
{
	Count = 0;
	TextureList.emplace_back((char*)"¡Ú¡Ø");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ø");
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
	for (int i = 0; i < (int)TextureList.size(); ++i)
		CursorManager::GetInstance()->WriteBuffer
		(pPlayer->GetPosition().x, pPlayer->GetPosition().y + i, TextureList[i]);

}

void PlayerEffect::Release()
{
}

