#pragma once
#include "Headers.h"

class Object;
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
	void AddObject(Object* _Object);
	list<Object*>* GetObjectList(string _strKey);

	void Render();
	void Update();
private:
	ObjectManager();
public:
	~ObjectManager();

};