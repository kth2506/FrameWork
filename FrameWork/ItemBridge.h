#pragma once
#include "Bridge.h"

class ItemBridge : public Bridge
{
protected:
	// ** Item �� �����͸� ����.

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
public:
	ItemBridge() {};
	virtual ~ItemBridge() {};
};