#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	// ** Enemy 의 데이터만 넣음.
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	EnemyBridge() {};
	virtual ~EnemyBridge() {};
};