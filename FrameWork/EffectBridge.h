#pragma once
#include "Bridge.h"

class EffectBridge : public Bridge
{
protected:
	// ** Effect �� �����͸� ����.
	int Count;
	vector<char*> TextureList;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:

public:
	EffectBridge() {};
	virtual ~EffectBridge() {};
};