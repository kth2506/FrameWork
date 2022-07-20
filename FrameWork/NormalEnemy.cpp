#include "NormalEnemy.h"
#include "CursorManager.h"
#include "Object.h"
#include "MathManager.h"
#include "Player.h"
#include "ObjectManager.h"

NormalEnemy::NormalEnemy(){}

NormalEnemy::~NormalEnemy(){}

void NormalEnemy::Initialize()
{
	Hp = 30;
	Damage = 1;
}

int NormalEnemy::Update(Transform& Info)
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	Info.Direction = MathManager::GetDirection(Info.Position, pPlayer->GetPosition());
	Info.Position += Info.Direction * 0.5f;

	return 0;
}

void NormalEnemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¢Ì¢Ì", 12
	);

}

void NormalEnemy::Release()
{
}
