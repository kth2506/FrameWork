#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
NormalBullet::NormalBullet(){}
NormalBullet::~NormalBullet(){}


void NormalBullet::Initialize()
{
	// Bullet 의 데이터 초기화
}

int NormalBullet::Update(Transform& Info)
{
	if (Info.Direction.y > 0)
	{
		Info.Position.x += Info.Direction.x / (Info.Direction.y * 1);
		Info.Position.y += Info.Direction.y / (Info.Direction.y * 1);
	}
	else
	{
		Info.Position.x -= Info.Direction.x / (Info.Direction.y * 1);
		Info.Position.y -= Info.Direction.y / (Info.Direction.y * 1);
	}

	
	return 0;
}

void NormalBullet::Render()
{
	//CursorManager::GetInstance()->WriteBuffer(
	//	pObject->GetPosition().x,
	//	pObject->GetPosition().y,
	//	(char*)"¤", 13);

	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(float)pObject->GetDirection().y);
}

void NormalBullet::Release()
{
}
