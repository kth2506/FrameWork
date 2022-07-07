#include "ObjectManager.h"
#include "CollisionManager.h"
#include "ObjectPool.h"

#include "Object.h"
#include "Player.h"
#include "Enemy.h"
ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager(){}


void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		EnableList->insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);

}

void ObjectManager::Render()
{
	for(map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		(*iter2)->Render();
}

void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}

list<Object*>* ObjectManager::GetObjectList(string _strKey)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_strKey);

	if(iter == EnableList->end())
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

void ObjectManager::TakeObject(string _strKey)
{
	map<string, list<Object*>>::iterator iter = DisableList->find(_strKey);

	if (iter == DisableList->end())
	{

	}
	else
	{
		list<Object*>* TempList;
		TempList = GetObjectList(_strKey);
		

	}

}
