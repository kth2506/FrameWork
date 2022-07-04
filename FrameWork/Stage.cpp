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

	if (dwKey & KEY_ESCAPE)
	{
		exit(0);
	}

	ObjectManager::GetInstance()->Update();

	
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	Object* pEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->front();
	
	{
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



		if (pEnemyList != nullptr && pPlayer != nullptr)
		{
			for (list<Object*>::iterator Playeriter = pEnemyList->begin();
				Playeriter != pEnemyList->end(); ++Playeriter)
			{
				if (CollisionManager::Collision(pPlayer, *Playeriter))
				{
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

						(*Enemyiter)->SetHp();
						cout << " Enemy : " << (*Enemyiter)->GetHp() << endl;

					}
					else
						++Bulletiter;
				}
			}
		}



		if (pEnemyList != nullptr)
		{
			for (auto iter = pEnemyList->begin();
				iter != pEnemyList->end(); )
			{
				if ((*iter)->GetHp() <= 0)
				{
					iter = pEnemyList->erase(iter);
				}
				else
					++iter;
			}
		}

	}
	
	if(Check)
	pUI->Update();

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
