#include "BulletNormal2.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

BulletNormal2::BulletNormal2() {}
BulletNormal2::~BulletNormal2() {}


void BulletNormal2::Initialize()
{
	// Bullet 의 데이터 초기화
	Check = false;
	Damage = 20;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	
}

int BulletNormal2::Update(Transform& Info)
{
	Info.Scale = Vector3(4.0f, 1.0f);
	Info.Position += Info.Direction * 1.2f;

	if (Info.Direction.y > -0.45f && Info.Direction.y < 0.45f)
		Check = true;
	
	return 0;
}

void BulletNormal2::Render()
{
	if (Check)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"¤", 2);
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y+1,
			(char*)"¤", 2);
	}
	else
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¤¤", 2);
}

void BulletNormal2::Release()
{
}
