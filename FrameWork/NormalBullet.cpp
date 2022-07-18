#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

NormalBullet::NormalBullet(){}
NormalBullet::~NormalBullet(){}


void NormalBullet::Initialize()
{
	// Bullet 의 데이터 초기화
	Damage = 10;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
}

int NormalBullet::Update(Transform& Info)
{
	Info.Position += Info.Direction;
	
	return 0;
}

void NormalBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¤", 13);
}

void NormalBullet::Release()
{
}
