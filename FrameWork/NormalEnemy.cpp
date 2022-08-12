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

	Type = NORMALENEMY;
	Stage = 0;
	Color = 1;
	Damage = 1;
	Speed = 0.5f;
	Exp = 10;
	TextureEnemy.emplace_back((char*)"¡ë");
	TextureEnemy.emplace_back((char*)"¢Ê");
	TextureEnemy.emplace_back((char*)"¢È");
	TextureEnemy.emplace_back((char*)"¢Ç");
	TextureEnemy.emplace_back((char*)"¢É");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
	TextureEnemy.emplace_back((char*)"IoI");
}

int NormalEnemy::Update(Transform& Info)
{
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	Info.Direction = MathManager::GetDirection(Info.Position, pPlayer->GetPosition());
	Info.Position += Info.Direction * Speed;

	return 0;
}

void NormalEnemy::Render()
{
	
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		
		TextureEnemy[Stage], RED
	);
}

void NormalEnemy::Release()
{
}
