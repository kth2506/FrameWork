#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	int Damage;
	int Type;
	Object* pObject;
public:
	virtual void Initialize()PURE;	
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetObject(Object* _Object) {pObject = _Object;}
	int GetDamage() { return Damage; }
	int GetType() { return Type; }
public:
	Bridge() : pObject(nullptr) {};
	virtual ~Bridge() {};

};

