#pragma once
#include "Bridge.h"

class EnemyBridge : public Bridge
{
protected:
	// ** Enemy �� �����͸� ����.
	int Hp;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	EnemyBridge() {};
	virtual ~EnemyBridge() {};
};