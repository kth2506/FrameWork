#pragma once
#include "Bridge.h"

class Object;
class EnemyBridge : public Bridge
{
protected:
	// ** Enemy 의 데이터만 넣음.
	vector<char*> TextureEnemy;
	float Speed;
	int Color;
	int Stage = 0;
	int Exp;
	Object* pPlayer;
	int Type;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	int GetType() { return Type; }
	void StageUp(int _Value) 
	{ Stage+= _Value;	Hp += Stage * 10;	Speed += Stage * 0.1;}
	void DamageUp(int _Value) { Damage+= _Value; }
	int GetExp() { return Exp; }
public:
	EnemyBridge() {};
	virtual ~EnemyBridge() {};
};