#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"
#include "ObjectManager.h"
ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;

ObjectPool::ObjectPool() {}
ObjectPool::~ObjectPool() {}


void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Object->GetKey());
	if (Disableiter == DisableList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		Disableiter->second.push_back(_Object);

}

Object* ObjectPool::ThrowObject(string _Key)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		Object* pObject = Disableiter->second.front();
		Disableiter->second.pop_front();

		pObject->Initialize(_Key);
		return pObject;
	}

	return nullptr;
}

void ObjectPool::Update()
{

	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); )
		{
		
			int result = (*iter2)->Update();

			switch (result)
			{
			case BUFFER_OVER:
			{
				iter2 = ObjectManager::GetInstance()->ThrowObject(iter2, (*iter2));
				//map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());
				//
				//if (Disableiter == DisableList.end())
				//{
				//	list<Object*> TempList;
				//	TempList.push_back((*iter2));
				//	DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				//}
				//else
				//	Disableiter->second.push_back((*iter2));
				//
				//(*iter).second.erase(iter2);
			}
			break;
			default:
				++iter2;
			}
		}
	}


}
