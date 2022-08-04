
#include "BulletUI.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Bridge.h"
#include "PlayerBridge.h"
BulletUI::BulletUI() {}
BulletUI::BulletUI(Transform _Info) {}
BulletUI::~BulletUI() {}

void BulletUI::Initialize()
{
	strKey = "BulletUI";
	BoomCount = 0;
	AttackSpeed = 0.0f;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	TextureList.emplace_back((char*)"  ");
	TextureList.emplace_back((char*)"  ");

	TransInfo.Position = Vector3(4.0f, 2.0f);
}

int BulletUI::Update()
{
	BoomCount = ((PlayerBridge*)pPlayer->GetBridge())->GetBoomCount();
	AttackSpeed = ((PlayerBridge*)pPlayer->GetBridge())->GetAttackSpeed();

	return 0;
}

void BulletUI::Render()
{
	for (int i = 0; i < BoomCount; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			4.0f + i * 3, 5.0f,
			(char*)"¡Ø");
	}
}

void BulletUI::Release()
{
}
