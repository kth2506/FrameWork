#pragma once
#include "Bridge.h"

class Object;
class BulletBridge : public Bridge
{
protected:
	// ** Bullet 의 데이터만 넣음.
	Object* pPlayer;
	int Type;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	int GetType() { return Type; }
public:
	BulletBridge() : Type(0) , pPlayer(nullptr){};
	virtual ~BulletBridge() {};
};