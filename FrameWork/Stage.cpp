#pragma once

#include "Stage.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "Congraturation.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ItemPower.h"
#include "ItemSpeed.h"
#include "ItemChange.h"
#include "ItemBoom.h"
#include "ItemPotion.h"
#include "NormalEnemy.h"
#include "NormalPlayer.h"
#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Outtro.h"
#include "BulletBoom.h"
#include "BulletBoom2.h"
#include "PlayerEffect.h"
#include "EnemyBoss.h"
#include "EnemyEffect.h"
#include "UserInterfaceManager.h"
#include "MenuInterface.h"

Stage::Stage() {  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = true;
	count = 0;
	Clear = false;
	GameOver = false;
	Bridge* bPlayer = new NormalPlayer;
	ObjectManager::GetInstance()->AddPlayer(bPlayer);
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	pPlayer = pPlayerList->front();

	pMenuInterface = new MenuInterface;
	pMenuInterface->Initialize();

	UserInterfaceManager::GetInstance()->Initialize();
}

void Stage::Update()
{
	CursorManager::GetInstance()->WriteBuffer(CursorManager::GetInstance()->GetVector().x, CursorManager::GetInstance()->GetVector().y,
																(char*)"¢Á" );
	

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pItemList = ObjectManager::GetInstance()->GetObjectList("Item");

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	
	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
	if (dwKey & KEY_TAB)
		Enable_UI();


	if (Check)
	{
		count++;

		CursorManager::GetInstance()->WriteBuffer(Console_Width / 2 - 30.0f, Console_Height - 2.0f
			, (char*)"WASD - Move   SPACE - Shoot   CTRL - Boom");
		if (count % 25 == 0)
		{
			Bridge* bEnemy = new NormalEnemy;
			ObjectManager::GetInstance()->AddEnemy(bEnemy);
			
			((NormalEnemy*)bEnemy)->StageUp(count / 300 + 1);
		}
		else if (count == (14 * 20))
		{
			Bridge* bEnemy = new EnemyBoss;
			ObjectManager::GetInstance()->AddEnemyBoss(bEnemy);
		}

		ObjectManager::GetInstance()->Update();
		UserInterfaceManager::GetInstance()->Update();

		// Ãæµ¹½Ã
		{
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
										Bridge* bBullet;
										bBullet = new BulletBoom2;
										ObjectManager::GetInstance()->AddBullet(bBullet, (*Bulletiter)->GetPosition());
										
										(*Enemyiter)->GetBridge()->SetHp((*Bulletiter)->GetBridge()->GetDamage()
											+ pPlayer->GetBridge()->GetDamage());


										Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
										++Bulletiter;
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
							
							Bridge* bEffect;
							bEffect = new EnemyEffect;
							ObjectManager::GetInstance()->AddEffect(bEffect, Enemyiter);


							srand((unsigned int)time(NULL));
							int num = rand() % 10;							
							((PlayerBridge*)pPlayer->GetBridge())->IncreaseExp
							(((EnemyBridge*)(*Enemyiter)->GetBridge())->GetExp());
							
						
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
								bItem = new ItemPotion;
								ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
								break;
							case 7:
							case 8:
								bItem = new ItemSpeed;
								ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
								break;
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
								((PlayerBridge*)pPlayer->GetBridge())->IncreaseAttackSpeed(0.1f);
								break;
							case POWERUP:
								((PlayerBridge*)pPlayer->GetBridge())->IncreasePower(1);
								break;
							case CHANGE:
								break;
							case BOOM:	
								((PlayerBridge*)pPlayer->GetBridge())->IncreaseBoom();
								break;
							case POTION:
								((PlayerBridge*)pPlayer->GetBridge())->IncreaseHp();

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
				//if (pPlayer->GetBridge()->GetHp() <= 0)
				//{
				//	Check = false;
				//	GameOver = true;
				//	
				//	pOuttro = new Outtro;
				//	pOuttro->Initialize();
				//}
			}
		}


		if (count > 14 * 60)
		{
			Check = false;
			Clear = true; 
		
			pCongraturation = new Congraturation;
			pCongraturation->Initialize();
		}
	}

	if (((PlayerBridge*)pPlayer->GetBridge())->GetExp() >= 52)
	{
		((PlayerBridge*)pPlayer->GetBridge())->SetLevel();
		((PlayerBridge*)pPlayer->GetBridge())->SetExp();
		Enable_UI();
	}


	if(!Check)
	{
		if (Clear)
		{
			pCongraturation->Update();
			if (pCongraturation->Update() == BUFFER_OVER && dwKey & KEY_ENTER)
			{
				SceneManager::GetInstance()->SetScene(EXIT);
			}
		}
		else
		{
			if (!GameOver)
			{

				CursorManager::GetInstance()->WriteBuffer(Console_Width / 2 - 15.0f, Console_Height - 2.0f
					, (char*)"ENTER - Select");
				pMenuInterface->Update();
				if (dwKey & KEY_ENTER)
				{
					Enable_UI();
				}
			}
			else
			{
				pOuttro->Update();
				if (pOuttro->Update() == BUFFER_OVER && dwKey & KEY_ENTER)
				{

					SceneManager::GetInstance()->SetScene(EXIT);

				}
			}
		}
	
	}


}

void Stage::Render()
{
		ObjectManager::GetInstance()->Render();
		UserInterfaceManager::GetInstance()->Render();
		if (!Check)
		{
			if(Clear)
				pCongraturation->Render();
			else
			{
				if (!GameOver)
					pMenuInterface->Render();
				else
					pOuttro->Render();
			}
			

		}

}

void Stage::Enable_UI()
{
	Check = !Check;
}

void Stage::Release()
{
}

