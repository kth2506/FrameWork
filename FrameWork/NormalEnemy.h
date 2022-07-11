#pragma once
#include "EnemyBridge.h"

class NormalEnemy : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	NormalEnemy();
	virtual ~NormalEnemy();
};

