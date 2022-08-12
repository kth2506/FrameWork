#include "BossEffect.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
BossEffect::BossEffect() {}

BossEffect::~BossEffect() {}

void BossEffect::Initialize()
{
	Count = 0;
	TextureList.emplace_back((char*)"�ܡۡܡۡܡۡܡۡܡۡܡۡܡۡܡ�");
	TextureList.emplace_back((char*)"�ۡܡۡܡۡܡۡܡۡܡۡܡۡܡۡ�");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
}

int BossEffect::Update(Transform& Info)
{
	Count++;
	if (Count > 3)
		return BUFFER_OVER;
	return 0;
}

void BossEffect::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x - 2,
		pObject->GetPosition().y,
		TextureList[Count]);

}

void BossEffect::Release()
{
}

