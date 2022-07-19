#include "Stage.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "NormalEnemy.h"
#include "ItemPower.h"
#include "ItemSpeed.h"
#include "ItemChange.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "InputManager.h"
#include "ScrollBox.h"
#include "Time.h"
#include "ObjectPool.h"
#include "CollisionManager.h"
#include "NormalBullet.h"
#include "NormalPlayer.h"
#include "SceneManager.h"
#include "Outtro.h"
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
}

void Stage::Update()
{
	CursorManager::GetInstance()->WriteBuffer(1.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().x);
	CursorManager::GetInstance()->WriteBuffer(6.0f, 43.0f, (int)CursorManager::GetInstance()->GetVector().y);
	

	// 이동반경
	{
		if (pPlayer->GetPosition().x < 10)
			pPlayer->SetPosition(10, pPlayer->GetPosition().y);
		if (pPlayer->GetPosition().x > 170)
			pPlayer->SetPosition(170, pPlayer->GetPosition().y);
		if (pPlayer->GetPosition().y < 11)
			pPlayer->SetPosition(pPlayer->GetPosition().x, 11);
		if (pPlayer->GetPosition().y > 43)
			pPlayer->SetPosition(pPlayer->GetPosition().x, 43);
	}


	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<Object*>* pItemList = ObjectManager::GetInstance()->GetObjectList("Item");

	count++;
	
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (Check)
	{
		if (count % 18 == 0)
		{
			Bridge* bEnemy = new NormalEnemy;
			ObjectManager::GetInstance()->AddEnemy(bEnemy);
		}
		pTime->Update();
		ObjectManager::GetInstance()->Update();
	}
	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}
	if (dwKey & KEY_TAB)
		Enable_UI();


	// 충돌시
	{
			// Bullet 이동반경
		if (pBulletList != nullptr)
		{
			for (list<Object*>::iterator iter = pBulletList->begin();
				iter != pBulletList->end(); )
			{
				if (((*iter)->GetPosition().x >= Console_Width || (*iter)->GetPosition().x < 0.0f ||
					(*iter)->GetPosition().y >= Console_Height || (*iter)->GetPosition().y < 8.0f) && pBulletList->size())
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
							if (CollisionManager::RectCollision(*Bulletiter, *Enemyiter))
							{
								int damage = (*Bulletiter)->GetBridge()->GetDamage() + pPlayer->GetBridge()->GetDamage();
								(*Enemyiter)->GetBridge()->SetHp(damage);
								Bulletiter = ObjectManager::GetInstance()->ThrowObject(Bulletiter, (*Bulletiter));
							}
							else
								++Bulletiter;
						}
					}

					if ((*Enemyiter)->GetBridge()->GetHp() <= 0)
					{
						srand((unsigned int)time(NULL));
						int num = rand() % 10;
						Bridge* bItem;
						switch (num)
						{
						case 1:
							bItem = new ItemPower;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
						case 2:
							bItem = new ItemSpeed;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
						case 3:
							bItem = new ItemChange;
							ObjectManager::GetInstance()->AddItem(bItem, Enemyiter);
							break;
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
				Check = 0;
				UserInterface* pOuttro = new Outtro;
				pOuttro->Initialize();

				//
				//SceneManager::GetInstance()->SetScene(ENDING);
			}
		}
	}
}

void Stage::Render()
{
	
	ObjectManager::GetInstance()->Render();
	pTime->Render();

}

void Stage::Enable_UI()
{
	Check = !Check;
}

void Stage::Release()
{
}

