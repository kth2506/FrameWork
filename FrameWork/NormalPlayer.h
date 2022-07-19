#pragma once
#include "PlayerBridge.h"


class NormalPlayer : public PlayerBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

public:
	NormalPlayer();
	virtual ~NormalPlayer();
};

