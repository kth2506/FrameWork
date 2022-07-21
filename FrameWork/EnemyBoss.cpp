#include "EnemyBoss.h"
#include "CursorManager.h"
#include "Object.h"
#include "MathManager.h"
#include "Player.h"
#include "ObjectManager.h"

EnemyBoss::EnemyBoss() {}

EnemyBoss::~EnemyBoss() {}

void EnemyBoss::Initialize()
{
	Hp = 100;
	Damage = 5;
	//pObject->SetPosition(100.0f, 20.0f);
}

int EnemyBoss::Update(Transform& Info)
{

	return 0;
}

void EnemyBoss::Render()
{
	pObject->SetScale(20.0f, 5.0f);

	for (int i = 0; i < 5; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y +i ,
			(char*)"�̢̢̢̢̢̢̢̢̢�", 12
		);
	}
	

}

void EnemyBoss::Release()
{
}
