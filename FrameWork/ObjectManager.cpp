#include "ObjectManager.h"
#include "CollisionManager.h"
#include "ObjectPool.h"
#include "ObjectFactory.h"
#include "ProtoType.h"
#include "Bullet.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "MathManager.h"
#include "Bridge.h"
ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager(){}

void ObjectManager::AddEnemy(Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject("Enemy");


	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject("Enemy")->Clone();


	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);
	pObject->SetPosition(float(rand() % 180), float((rand() % 30) +7));
	pObject->SetDirection(MathManager::GetCursorDirection(pObject->GetPosition()));

	map<string, list<Object*>>::iterator iter = EnableList->find("Enemy");

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddEnemyBoss(Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject("Enemy");

	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject("Enemy")->Clone();

	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);
	pObject->SetPosition(100.0f, 20.0f);

	map<string, list<Object*>>::iterator iter = EnableList->find("Enemy");

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddItem(Bridge* _Bridge, list<Object*>::iterator _Iter)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject("Item");


	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject("Item")->Clone();


	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);
	pObject->SetPosition((*_Iter)->GetPosition());

	map<string, list<Object*>>::iterator iter = EnableList->find("Item");

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddBullet(Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject("Bullet");


	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject("Bullet")->Clone();

	
	_Bridge->Initialize();
	_Bridge->SetObject(pObject);
	
	Object* pPlayer = GetObjectList("Player")->front();
	pObject->SetBridge(_Bridge);
	pObject->SetPosition(pPlayer->GetPosition().x - pPlayer->GetScale().x * 0.5f,
		pPlayer->GetPosition().y - pPlayer->GetScale().y * 0.5f );
	pObject->SetDirection(MathManager::GetCursorDirection(pObject->GetPosition()));

	map<string, list<Object*>>::iterator iter = EnableList->find("Bullet");

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddPlayer(Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject("Player");


	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject("Player")->Clone();


	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);

	map<string, list<Object*>>::iterator iter = EnableList->find("Player");

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddObject(string _Key)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject(_Key);


	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}



list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	if (iter == EnableList->end())
		return nullptr;

	return &iter->second;
}


list<Object*>::iterator ObjectManager::ThrowObject(list<Object*>::iterator _Where, Object* _Object)
{
	map<string, list<Object*>>::iterator iter =
		EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
		return _Where;

	ObjectPool::GetInstance()->CatchObject(_Object);
	return iter->second.erase(_Where);


}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}


void ObjectManager::Render()
{
	for(map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		(*iter2)->Render();
}






