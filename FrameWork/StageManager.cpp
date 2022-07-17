#include "StageManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalEnemy.h"
#include "ItemPower.h"
#include "ItemSpeed.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "InputManager.h"
#include "ScrollBox.h"
#include "Time.h"
#include "ObjectPool.h"
#include "CollisionManager.h"
#include "NormalBullet.h"
StageManager* StageManager::Instance = nullptr;
StageManager::StageManager()
	: Check(0), count(0), pPlayer(), pTime(), pUI(){}

StageManager::~StageManager(){}

void StageManager::Initialize()
{
	Check = 0;
	count = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	pUI = new ScrollBox;
	pUI->Initialize();
	pTime = new Time;
	pTime->Initialize();
}

void StageManager::Update()
{

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	list<Object*>* pItemList = ObjectManager::GetInstance()->GetObjectList("Item");
	count++;
	pPlayer = pPlayerList->front();

	if (count % 14 == 0)
	{
		Bridge* pBridge = new NormalEnemy;
		ObjectManager::GetInstance()->AddEnemy("Enemy", pBridge);
	}
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
					{
						srand((unsigned int)time(NULL));
						int num = rand() % 10;
						if (num < 3)
						{
							Bridge* pBridge = new ItemPower;
							ObjectManager::GetInstance()->AddItem("Item", pBridge, Enemyiter);
						}
						else if (num == 4)
						{
							Bridge* pBridge = new ItemSpeed;
							ObjectManager::GetInstance()->AddItem("Item", pBridge, Enemyiter);

						}
						Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					}
					else
						++Enemyiter;
				}
			}
		}

		if (pItemList != nullptr)
		{
			if (pPlayerList != nullptr)
			{
				for (auto Itemiter = pItemList->begin();
					Itemiter != pItemList->end();)
				{
					if (CollisionManager::RectCollision(*Itemiter, pPlayerList->front()))
					{
						int a = (*Itemiter)->GetBridge()->GetType();
						switch (a)
						{
						case 1:
							pPlayer->IncreseAttackSpeed();
							break;
						case 2:
							pPlayer->IncresePower();
							break;
						default:
							break;
						}

						Itemiter = ObjectManager::GetInstance()->ThrowObject(Itemiter, (*Itemiter));
					}
					else
						++Itemiter;
				}
			}
		}
	}

}

void StageManager::Render()
{
	ObjectManager::GetInstance()->Render();
	pTime->Render();
}

void StageManager::Enable_UI()
{
	Check = !Check;
}

void StageManager::Release()
{

}

