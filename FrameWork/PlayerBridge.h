#pragma once
#include "Bridge.h"

class PlayerBridge : public Bridge
{
protected:
	// ** Player �� �����͸� ����.

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	PlayerBridge() {};
	virtual ~PlayerBridge() {};
};