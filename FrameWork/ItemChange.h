#pragma once
#include "ItemBridge.h"

class ItemChange : public ItemBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	ItemChange();
	virtual ~ItemChange();
};

