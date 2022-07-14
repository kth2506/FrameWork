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
	Hp = 10;
}

int NormalEnemy::Update(Transform& Info)
{
	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	Info.Direction = MathManager::GetDirection(Info.Position, pPlayer->GetPosition());
	Info.Position += Info.Direction;

	return 0;
}

void NormalEnemy::Render()
{

	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"¢Ì", 15
		);
	}
}

void NormalEnemy::Release()
{
}
