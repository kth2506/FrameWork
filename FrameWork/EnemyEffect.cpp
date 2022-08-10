#include "EnemyEffect.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
EnemyEffect::EnemyEffect() {}

EnemyEffect::~EnemyEffect() {}

void EnemyEffect::Initialize()
{
	Count = 0;
	TextureList.emplace_back((char*)"¡Ü");
	TextureList.emplace_back((char*)"¡Û");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
}

int EnemyEffect::Update(Transform& Info)
{
	Count++;
	if (Count > 3)
		return BUFFER_OVER;
	return 0;
}

void EnemyEffect::Render()
{
	CursorManager::GetInstance()->WriteBuffer	(
		pObject->GetPosition().x - 2,
		pObject->GetPosition().y, 
		TextureList[Count]);

}

void EnemyEffect::Release()
{
}

