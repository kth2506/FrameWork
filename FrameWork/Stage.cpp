#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
Stage::Stage() : pPlayer(nullptr){  }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// ** 1. ��ȯ ���°� Object* && list<Objcet*>
	// ** 2. Key �� ���޵Ǿ�� �Ѵ�
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObjectList("Player");
	
	if(pPlayerList != nullptr)
		pPlayer = pPlayerList->front();

	//list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("��");

}

void Stage::Update()
{

	ObjectManager::GetInstance()->Update();

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObjectList("��");

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

}

void Stage::Render()
{


	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}
