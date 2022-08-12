#pragma once
#include "Headers.h"

class Object;
class Bridge;

class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager();
		return Instance;
	}
private:
	map<string, list<Object*>>* EnableList;
public:
	void AddEnemy(Bridge* _Bridge);
	void AddEnemyBoss(Bridge* _Bridge);
	void AddEnemyBoss(Bridge* _Bridge , Vector3 _Position);
	void AddItem(Bridge* _Bridge, list<Object*>::iterator _Iter);
	void AddEffect(Bridge* _Bridge, list<Object*>::iterator _Iter);
	void AddBullet(Bridge* _Bridge);
	void AddBullet(Bridge* _Bridge, Vector3 _Position);
	void AddPlayer(Bridge* _Bridge);
	void AddObject(string _Key);
	list<Object*>* GetObjectList(string _strKey);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where, Object* _Object);
	void Update();
	void Render();


private:
	ObjectManager();
public:
	~ObjectManager();

};

