#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ScrollBox.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Stage::Stage() : Check(0){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;
	
	pPlayer = new Player;
	pPlayer->Initialize();

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();

	pUI = new ScrollBox;
	pUI->Initialize();


	for (int i = 0; i < 10; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(float(rand() % 118) , float(rand() % 26) + pEnemy->GetScale().y * 2);

		//ObjectManager::GetInstance()->AddObject("Enemy");

	}
	

}

void Stage::Update()
{


	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	if (dwKey & KEY_ESCAPE)
	{
		if (pBulletList->size())
		{
			ObjectPool::GetInstance()->CatchObject(pBulletList->back());
			pBulletList->pop_back();
		}
	}

	pPlayer->Update();
	ObjectManager::GetInstance()->Update();

	//Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	//Object* pEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->front();
	//if (dwKey & KEY_ESCAPE)
	//{
	//	ObjectManager::GetInstance()->AddObject("Bullet");
	//}

	{
		if (pBulletList != nullptr)
		{

			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); )
			{
				if ((*iter)->GetPosition().x >= 120.0f)								
					iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
				else
					++iter;
			}
		}

		if (pPlayer != nullptr)
		{
			if (pEnemyList != nullptr)
			{
				for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
					Enemyiter != pEnemyList->end(); ++Enemyiter)
				{
					/*if (CollisionManager::RectCollision(pPlayer, *Enemyiter))
					{
						continue;
					}*/


					if (pBulletList != nullptr)
					{
						for (list<Object*>::iterator Bulletiter = pBulletList->begin();
							Bulletiter != pBulletList->end(); )
						{
							if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
							{
								Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
								(*Enemyiter)->SetHp();
							}
							else
								++Bulletiter;
						}
					}

					//if ((*Enemyiter)->GetHp() <= 0)
					//	Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					//else
					//	++Enemyiter;
				}
			}
		}
	}

	if (Check)
		pUI->Update();

}

void Stage::Render()
{
	pPlayer->Render();

	ObjectManager::GetInstance()->Render();

	if (Check)
	pUI->Render();

}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}



void Stage::Enable_UI()
{
	Check = !Check;
}
