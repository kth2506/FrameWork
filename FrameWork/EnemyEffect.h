#pragma once
#include "EffectBridge.h"

class EnemyEffect : public EffectBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
public:
	EnemyEffect();
	virtual ~EnemyEffect();
};

