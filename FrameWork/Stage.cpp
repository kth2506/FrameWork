#pragma once

#include "Stage.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ItemPower.h"
#include "ItemSpeed.h"
#include "ItemChange.h"
#include "ItemBoom.h"
#include "NormalEnemy.h"
#include "NormalPlayer.h"
#include "ObjectManager.h"
#include "ObjectPool.h"
#include "BulletBoom.h"
#include "Time.h"
#include "ScrollBox.h"
#include "Outtro.h"
#include "HpBar.h"
#include "EnemyBoss.h"
#include "Warning.h"
Stage::Stage() {  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 1;
	count = 0;
	Bridge* bPlayer = new NormalPlayer;
	ObjectManager::GetInstance()->AddPlayer(bPlayer);
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	pPlayer = pPlayerList->front();

	pTime = new Time;
	pTime->Initialize();
	pHpBar = new HpBar;
	pHpBar->Initialize();
	pOuttro = new Outtro;
	pOuttro->Initialize();
	pWarning = new Warning;
	pWarning->Initialize();
}

void Stage::Update()
{
	CursorManager::GetInstance()->WriteBuffer(1.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().x);
	CursorManager::GetInstance()->WriteBuffer(6.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().y);
	


	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pItemList = ObjectManager::GetInstance()->GetObjectList("Item");

	count++;
	
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	//if (count % 18 == 0)
	//{
	//	Bridge* bEnemy = new NormalEnemy;
	//	ObjectManager::GetInstance()->AddEnemy(bEnemy);
	//}
	if (count % (14 * 60) == 0)
	{
		Bridge* bEnemy = new EnemyBoss;
		ObjectManager::GetInstance()->AddEnemyBoss(bEnemy);
	}
	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
	if (dwKey & KEY_TAB)
		Enable_UI();

	pHpBar->Update();
	pTime->Update();
	pWarning->Update();
	ObjectManager::GetInstance()->Update();

	// 이동반경
	{
		if (pPlayer->GetPosition().x < 10)
			pPlayer->SetPosition(pPlayer->GetPosition().x + 1.0f, pPlayer->GetPosition().y);
		if (pPlayer->GetPosition().x > Console_Width - 10.0f)
			pPlayer->SetPosition(pPlayer->GetPosition().x - 1.0f, pPlayer->GetPosition().y);
		if (pPlayer->GetPosition().y < 10)
			pPlayer->SetPosition(pPlayer->GetPosition().x, pPlayer->GetPosition().y + 1.0f);
		if (pPlayer->GetPosition().y > Console_Height - 3.0f)
			pPlayer->SetPosition(pPlayer->GetPosition().x, pPlayer->GetPosition().y - 1.0f);
	}
	// 충돌시
	{
			// Bullet 이동반경
		if (pBulletList != nullptr)
		{
			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); )
			{
				if (((*iter)->GetPosition().x >= Console_Width - 2.0f || (*iter)->GetPosition().x < 0.0f ||
					(*iter)->GetPosition().y >= Console_Height - 2.0f|| (*iter)->GetPosition().y < 8.0f) && pBulletList->size())
				{
					iter = ObjectManager::GetInstance()->ThrowObject(iter, (*iter));
				}
				else
					++iter;
			}
		}


		if (pPlayer != nullptr)
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
							if (((BulletBridge*)(*Bulletiter)->GetBridge())->GetType() == BULLETBOOM)
							{
								if (CollisionManager::CircleCollision(*Bulletiter, *Enemyiter))
								{
									(*Enemyiter)->GetBridge()->SetHp((*Bulletiter)->GetBridge()->GetDamage()
										+ pPlayer->GetBridge()->GetDamage());

									Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
								}
								else
									++Bulletiter;
							}
							else
							{
								if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
								{
									(*Enemyiter)->GetBridge()->SetHp((*Bulletiter)->GetBridge()->GetDamage()
										+ pPlayer->GetBridge()->GetDamage());

									Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
								}
								else
									++Bulletiter;
							}
						}
					}

					if ((*Enemyiter)->GetBridge()->GetHp() <= 0)
					{
						srand((unsigned int)time(NULL));
						int num = rand() % 20;
						Bridge* bItem;
						switch (num)
						{
						case 1:
							bItem = new ItemPower;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
							bItem = new ItemSpeed;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
						case 7:
							bItem = new ItemChange;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
						case 8:
						case 9:
							bItem = new ItemBoom;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
						default:
							break;
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
			if (pPlayer != nullptr)
			{
				for (auto Itemiter = pItemList->begin();
					Itemiter != pItemList->end();)
				{
					if (CollisionManager::RectCollision(*Itemiter, pPlayer))
					{

						switch (((ItemBridge*)(*Itemiter)->GetBridge())->GetType())
						{
						case SPEEDUP:
							((PlayerBridge*)pPlayer->GetBridge())->IncreseAttackSpeed();
							break;
						case POWERUP:
							((PlayerBridge*)pPlayer->GetBridge())->IncresePower(5);
							break;
						case CHANGE:
							((PlayerBridge*)pPlayer->GetBridge())->ChangeBullet();
							break;
						case BOOM:
							((PlayerBridge*)pPlayer->GetBridge())->IncreseBoom();
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

		// Player 
		if (pPlayer != nullptr)
		{
			if (pEnemyList != nullptr)
			{
				for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
					Enemyiter != pEnemyList->end();)
				{

					if (CollisionManager::RectCollision(*Enemyiter, pPlayer))
					{
						pPlayer->GetBridge()->SetHp((*Enemyiter)->GetBridge()->GetDamage());
						Enemyiter = ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));
					}
					else
						++Enemyiter;
				}
			}
			if (pPlayer->GetBridge()->GetHp() <= 0)
			{
				Check = false;
				
				//
				//SceneManager::GetInstance()->SetScene(ENDING);
			}
		}
	}

}

void Stage::Render()
{
	pHpBar->Render();
	ObjectManager::GetInstance()->Render();
	pTime->Render();
	pWarning->Render();
}

void Stage::Enable_UI()
{
	Check = !Check;
}

void Stage::Release()
{
}

