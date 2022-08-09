#pragma once
#include "Bridge.h"

class Object;
class EnemyBridge : public Bridge
{
protected:
	// ** Enemy �� �����͸� ����.
	vector<char*> TextureEnemy;
	int Color;
	int Stage;
	Object* pPlayer;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	void StageUp(int _Value) { Stage+= _Value; }
	void DamageUp(int _Value) { Damage+= _Value; }
public:
	EnemyBridge() {};
	virtual ~EnemyBridge() {};
};