#pragma once
#include "EnemyBridge.h"

class EnemyBoss : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	EnemyBoss();
	virtual ~EnemyBoss();
};

