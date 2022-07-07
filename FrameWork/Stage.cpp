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

Stage::Stage() : Check(false){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = false;
	

	pUI = new ScrollBox;
	pUI->Initialize();

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();

	for (int i = 0; i < 10; ++i)
	{
		srand(DWORD(GetTickCount64() * (i + 1)));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->SetPosition(float(rand() % 118) , float(rand() % 26) + pEnemy->GetScale().y * 2);

		ObjectManager::GetInstance()->AddObject(pEnemy);

	}
	

}

void Stage::Update()
{


	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_TAB)
	{
		Enable_UI();
	}

	//if (dwKey & KEY_ESCAPE)
	//{
	//	exit(0);
	//}

	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	Object* pEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->front();
	if (dwKey & KEY_ESCAPE)
	{
		map<string, list <Object*>>::iterator iter;
		ObjectManager::GetInstance()->TakeObject(iter, "Bullet");
	}
	{
		if (pBulletList != nullptr)
		{

			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); ++iter)
			{
				//if ((*iter)->GetPosition().x >= 120.0f)
				//	iter = pBulletList->erase(iter);
				//else
				//	++iter;
			}
		}

		if (pPlayer != nullptr)
		{
			if (pEnemyList != nullptr)
			{
				for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
					Enemyiter != pEnemyList->end(); )
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

					if ((*Enemyiter)->GetHp() <= 0)
					{
						Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					}
					else
						++Enemyiter;
				
				}
			}


			//if (pEnemyList != nullptr && pPlayer != nullptr)
			//{
			//	for (list<Object*>::iterator Playeriter = pEnemyList->begin();
			//		Playeriter != pEnemyList->end(); ++Playeriter)
			//	{
			//		if (CollisionManager::CircleCollision(pPlayer, *Playeriter))
			//		{
			//			CursorManager::GetInstance()->WriteBuffer(
			//				60, 1.5, (char*)"맞았습니다", 15
			//			);
			//		}
			//	}
			//}
			//
			//if (pEnemyList != nullptr && pBulletList != nullptr)
			//{
			//	for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
			//		Enemyiter != pEnemyList->end(); )
			//	{
			//		for (list<Object*>::iterator Bulletiter = pBulletList->begin();
			//			Bulletiter != pBulletList->end();)
			//		{
			//			if (CollisionManager::CircleCollision(*Bulletiter, *Enemyiter))
			//			{
			//				ObjectManager::GetInstance()->ThrowObject((*Enemyiter));
			//
			//				//Bulletiter = pBulletList->erase(Bulletiter);
			//				//
			//				//(*Enemyiter)->SetHp();
			//				//CursorManager::GetInstance()->WriteBuffer(
			//				//	60, 1.5, (*Enemyiter)->GetHp(), 15
			//				//);
			//			}
			//			else
			//				++Bulletiter;
			//		}
			//
			//
			//		if ((*Enemyiter)->GetHp() <= 0)
			//		{
			//			Enemyiter = pEnemyList->erase(Enemyiter);
			//		}
			//		else
			//			++Enemyiter;
			//
			//	}
			//}

		}

		if (Check)
			pUI->Update();

	
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
	pUI->Render();

}

void Stage::Release()
{
}



void Stage::Enable_UI()
{
	Check = !Check;
}
