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
#include "NormalEnemy.h"
#include "Time.h"
Stage::Stage() : Check(0) , count(0){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;
	count = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	
	pUI = new ScrollBox;
	pUI->Initialize();
	pTime = new Time;
	pTime->Initialize();

}

void Stage::Update()
{
	CursorManager::GetInstance()->WriteBuffer(1.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().x);
	CursorManager::GetInstance()->WriteBuffer(6.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().y);

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	//pPlayer = pPlayerList->front();

	count++;

	//if (count % 14 == 0)
	//{
	//	Bridge* pBridge = new NormalEnemy;
	//	ObjectManager::GetInstance()->AddEnemy("Enemy", pBridge);
	//}
	DWORD dwKey = InputManager::GetInstance()->GetKey();

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
		Enable_UI();
	}

	ObjectManager::GetInstance()->Update();
	if (Check)
		pUI->Render();
	pTime->Update();

	{
		if (pBulletList != nullptr)
		{
			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); )
			{
				if (((*iter)->GetPosition().x >= Console_Width || (*iter)->GetPosition().x < 0.0f ||
					(*iter)->GetPosition().y >= Console_Height || (*iter)->GetPosition().y < 0.0f) && pBulletList->size())
				{
					iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));

				}
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

	pTime->Render();

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
