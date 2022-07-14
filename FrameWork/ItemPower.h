#pragma once
#include "ItemBridge.h"

class ItemPower : public ItemBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

public:
	ItemPower();
	virtual ~ItemPower();
};

