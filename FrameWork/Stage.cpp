#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "Bullet.h"
Stage::Stage(){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Object* pEnemyProto = new Enemy;
	pEnemyProto->Initialize();


	for (int i = 0; i < 10; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(float(rand() % 118) , float(rand() % 30));

		ObjectManager::GetInstance()->AddObject(pEnemy);

	}
	

}

void Stage::Update()
{

	ObjectManager::GetInstance()->Update();

	
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("＊");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("★★");

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("●")->front();

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin();
			iter != pBulletList->end();)
		{
			if ((*iter)->GetPosition().x >= 120.0f)
				iter = pBulletList->erase(iter);
			else
				++iter;
		}
	}



	if (pEnemyList != nullptr && pPlayer!= nullptr)
	{
		for (list<Object*>::iterator Playeriter = pEnemyList->begin();
			Playeriter != pEnemyList->end(); ++Playeriter)
		{
			if (CollisionManager::Collision(pPlayer, *Playeriter))
			{
				CursorManager::Draw(50.0f, 1.0f, "충돌입니다");
			}

		}
	}

	if (pEnemyList != nullptr && pBulletList != nullptr)
	{
		for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
			Enemyiter != pEnemyList->end(); ++Enemyiter)
		{
			for (list<Object*>::iterator Bulletiter = pBulletList->begin();
				Bulletiter != pBulletList->end();)
			{
				if (CollisionManager::Collision(*Bulletiter, *Enemyiter))
				{
					Bulletiter = pBulletList->erase(Bulletiter);
					CursorManager::Draw(50.0f, 1.0f, "맞았습니다");
				}
				else
					++Bulletiter;
			}
		}
	}

}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
}
