#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	int Damage;
	int Type;
	int Power;
	int Hp;
	Object* pObject;
public:
	virtual void Initialize()PURE;	
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	void SetObject(Object* _Object) {pObject = _Object;}
	void SetPower(int _Power) { Power = _Power; }
	void SetHp(int _Damage) { Hp -= _Damage; }
	int GetDamage() { return Damage; }
	int GetHp() { return Hp; }
	int GetType() { return Type; }
public:
	Bridge() : pObject(nullptr) {};
	virtual ~Bridge() {};

};

