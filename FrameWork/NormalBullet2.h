#pragma once
#include "BulletBridge.h"

class NormalBullet2 : public BulletBridge
{
public:

	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	NormalBullet2();
	virtual ~NormalBullet2();
};

