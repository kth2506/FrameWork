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
ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager(){}


void ObjectManager::AddObject(string _Key)
{
	Object* pObject = ObjectPool::GetInstance()->ThrowObject(_Key);

	if (pObject == nullptr)
		pObject = ProtoType::GetInstance()->ProtoTypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	//if (_Key == "Bullet")
	//{
	//	list<Object*>* TempList;
	//	TempList = GetObjectList("Player");
	//	pObject->SetPosition(TempList->front()->GetPosition());
	//	pObject->SetDirection(MathManager::GetCursorDirection(pObject->GetPosition()));
	//}
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






