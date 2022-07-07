#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"

ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;

ObjectPool::ObjectPool() {}
ObjectPool::~ObjectPool() {}


void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter =
		DisableList.find(_Object->GetKey());
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
		return pObject;
	}

	return nullptr;
}

void ObjectPool::Update()
{

	CursorManager::GetInstance()->WriteBuffer(85.0f, 0.0f, (char*)"DisableBullet : ");
	CursorManager::GetInstance()->WriteBuffer(100.0f, 0.0f, (int)DisableList["Bullet"].size());
	CursorManager::GetInstance()->WriteBuffer(85.0f, 1.0f, (char*)"EnableBullet : ");
	CursorManager::GetInstance()->WriteBuffer(99.0f, 1.0f, (int)EnableList["Bullet"].size());


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
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (Disableiter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back((*iter2));
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));

				(*iter).second.erase(iter2);
			}

			default:
				++iter2;
			}
		}
	}


}
