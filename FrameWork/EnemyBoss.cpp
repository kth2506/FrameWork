#include "EnemyBoss.h"
#include "CursorManager.h"
#include "Object.h"
#include "MathManager.h"
#include "Player.h"
#include "ObjectManager.h"
#include "NormalEnemy.h"
EnemyBoss::EnemyBoss() {}

EnemyBoss::~EnemyBoss() {}

void EnemyBoss::Initialize()
{
	count = 0;
	Hp = 100000000000;
	Damage = 3;
	Type = BOSS;
	Exp = 30;

	TextureEnemy.emplace_back((char*)"¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"     ¢Ì¢Ì¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"    ¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"¢Ì¢Ì");
	TextureEnemy.emplace_back((char*)"¢Ì¢Ì");



	//pObject->SetPosition(100.0f, 20.0f);
}

int EnemyBoss::Update(Transform& Info)
{
	count++;
	if (count > 0 && count < 70)
		Info.Position += Vector3(0.0, 0.2);
	if (count > 70 && count < 140)
		Info.Position -= Vector3(0.0, 0.2);
	if (count >= 140)
		count = 0;
	if (count % 13 == 0)
	{
		Bridge* bEnemy = new NormalEnemy;
		ObjectManager::GetInstance()->AddEnemyBoss(bEnemy , Vector3(Info.Position.x - 3, Info.Position.y + 5));
	}
	return 0;
}

void EnemyBoss::Render()
{
	pObject->SetScale(19.0f, 15);

	for (int i = 0; i < TextureEnemy.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y +i ,
			TextureEnemy[i], 12
		);
	}
	

}

void EnemyBoss::Release()
{
}
