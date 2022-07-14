#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	// ** Bullet 의 데이터만 넣음.
	int Damage;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	int GetDamage() { return Damage; }
public:
	BulletBridge() {};
	virtual ~BulletBridge() {};
};