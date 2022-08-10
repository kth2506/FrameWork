#pragma once
#include "EffectBridge.h"

class Object;
class PlayerEffect : public EffectBridge
{
private:
	Object* pPlayer;
	
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
public:
	PlayerEffect();
	virtual ~PlayerEffect();
};

