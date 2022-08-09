#pragma once
#include "Bridge.h"

class Object;
class EnemyBridge : public Bridge
{
protected:
	// ** Enemy 의 데이터만 넣음.
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