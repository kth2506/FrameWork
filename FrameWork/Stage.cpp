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
#include "ObjectPool.h"
#include "ProtoType.h"

Stage::Stage() : Check(0){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front()->Clone();
	//for (int i = 0; i < 5; ++i)
	//{
	//	ObjectManager::GetInstance()->AddObject("Enemy");
	//	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	//	pEnemyList->front()->SetPosition(10.0f + i, 2.0f + i);
	//}
	pUI = new ScrollBox;
	pUI->Initialize();

}

void Stage::Update()
{
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	//pPlayer = pPlayerList->front();
	pPlayer->Update();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	//Enable_UI();
	if (dwKey & KEY_TAB)
	{
		if (pBulletList->size())
		{
			ObjectPool::GetInstance()->CatchObject(pBulletList->back());
			pBulletList->pop_back();
		}
	}

	if (dwKey & KEY_ESCAPE)
	{
		if (Check == 0)
		{
			if (pPlayerList->size())
			{
				ObjectPool::GetInstance()->CatchObject(pPlayerList->back());
				pPlayerList->pop_back();
			}
			Check = 1;
		}
		else if( Check == 1)
		{
			ObjectManager::GetInstance()->AddObject("Player");
			Check = 0;
		}
	}

	ObjectManager::GetInstance()->Update();


	{
		if (pBulletList != nullptr)
		{
			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); )
			{
				if ((*iter)->GetPosition().x >= 120.0f)
					iter = pBulletList->erase(iter);
				else
					++iter;
			}
		}

		if (pPlayerList != nullptr)
		{
			if (pEnemyList != nullptr)
			{
				for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
					Enemyiter != pEnemyList->end();)
				{
					//if (CollisionManager::RectCollision(pPlayer, *Enemyiter))
					//{
					//	ObjectPool::GetInstance()->CatchObject(pPlayerList->back());
					//
					//
					//	continue;
					//}


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
						Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					else
						++Enemyiter;
				}
			}
		}
	}


}

void Stage::Render()
{

	ObjectManager::GetInstance()->Render();
	pPlayer->Render();

	//if (Check)
	//pUI->Render();

}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}



void Stage::Enable_UI()
{
	//Check = !Check;
}
