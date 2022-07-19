#pragma once
#include "Bridge.h"

class Object;
class EnemyBridge : public Bridge
{
protected:
	// ** Enemy �� �����͸� ����.
	Object* pPlayer;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	EnemyBridge() {};
	virtual ~EnemyBridge() {};
};