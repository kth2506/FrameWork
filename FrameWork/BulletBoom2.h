#pragma once
#include "BulletBridge.h"

class BulletBoom2 : public BulletBridge
{
private:
	int Count;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BulletBoom2();
	virtual ~BulletBoom2();
};

