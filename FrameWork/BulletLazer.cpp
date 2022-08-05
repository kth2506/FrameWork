#include "BulletLazer.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

BulletLazer::BulletLazer() {}
BulletLazer::~BulletLazer() {}


void BulletLazer::Initialize()
{
	// Bullet 의 데이터 초기화
	Check = false;
	Damage = 5;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

}

int BulletLazer::Update(Transform& Info)
{
	Info.Scale = Vector3(4.0f, 1.0f);
	Info.Position += Info.Direction * 1.2f;

	if (Info.Direction.y > -0.45f && Info.Direction.y < 0.45f)
		Check = true;

	return 0;
}

void BulletLazer::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"= =", 2);
}

void BulletLazer::Release()
{
}
