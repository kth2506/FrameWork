#pragma once
#include "Bridge.h"

class ItemBridge : public Bridge
{
protected:
	// ** Item 의 데이터만 넣음.
	int Type;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:	
	int GetType() { return Type; }

public:
	ItemBridge() {};
	virtual ~ItemBridge() {};
};