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
	Info.Direction = MathManager::GetCursorDirection(Info.Position);
	Info.Position += Info.Direction;

	return 0;
}

void NormalBullet::Render()
{
	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y + i,
			(char*)"¤", 13
		);
	}

}

void NormalBullet::Release()
{
}
