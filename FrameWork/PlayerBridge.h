#pragma once
#include "Bridge.h"

class Object;
class PlayerBridge : public Bridge
{
protected:
	// ** Player 의 데이터만 넣음.
	float as;
	float attackSpeed;
	BULLETID Bulletid = NORMALBULLET;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void IncresePower(int _Value) { Damage += _Value; }
	void IncreseAttackSpeed() { as += 0.3f; }
	void ChangeBullet() { Bulletid = NORMALBULLET2; }
public:
	PlayerBridge() {};
	virtual ~PlayerBridge() {};
};