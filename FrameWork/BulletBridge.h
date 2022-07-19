#pragma once
#include "Bridge.h"

class Object;
class BulletBridge : public Bridge
{
protected:
	// ** Bullet 의 데이터만 넣음.
	Object* pPlayer;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	BulletBridge() {};
	virtual ~BulletBridge() {};
};