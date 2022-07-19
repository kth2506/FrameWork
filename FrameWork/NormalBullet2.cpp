#include "NormalBullet2.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

NormalBullet2::NormalBullet2() {}
NormalBullet2::~NormalBullet2() {}


void NormalBullet2::Initialize()
{
	// Bullet �� ������ �ʱ�ȭ
	Damage = 20;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

}

int NormalBullet2::Update(Transform& Info)
{
	Info.Scale = Vector3(4.0f, 1.0f);
	Info.Position += Info.Direction;

	return 0;
}

void NormalBullet2::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"����", 2);
}

void NormalBullet2::Release()
{
}
