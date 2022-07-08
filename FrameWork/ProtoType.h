#pragma once
#include "Headers.h"

class Object;
class ProtoType
{
private:
	static ProtoType* Instance;
public:
	static ProtoType* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ProtoType();
		return Instance;
	}
private:
	map<string, Object*> ProtoTypeList;

public:
	void Initialize();

	Object* ProtoTypeObject(string _Key);
private:
	ProtoType();
public:
	~ProtoType();

};