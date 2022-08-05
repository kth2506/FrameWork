#pragma once
#include "BulletBridge.h"

class BulletFire : public BulletBridge
{
private:
	bool Check;
	int Grade;
	int count;
public:

	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BulletFire();
	virtual ~BulletFire();
};

