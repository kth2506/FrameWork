#pragma once
#include "EffectBridge.h"

class BossEffect : public EffectBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
public:
	BossEffect();
	virtual ~BossEffect();
};

