#pragma once
#include "BulletBridge.h"

class BulletLazer : public BulletBridge
{
private:
	bool Check;
public:

	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BulletLazer();
	virtual ~BulletLazer();
};

