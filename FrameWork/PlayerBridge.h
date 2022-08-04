#pragma once
#include "Bridge.h"

class Object;
class PlayerBridge : public Bridge
{
protected:
	// ** Player 의 데이터만 넣음.
	float as;
	float attackSpeed;
	int BoomCount;
	BULLETID Bulletid = BULLETNORMAL;
	int Level;
	int Exp;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void IncreasePower(int _Value) { Damage += _Value; }
	void IncreaseAttackSpeed() { as += 0.3f; }
	void IncreaseBoom() { ++BoomCount;  }
	void IncreaseHp() { ++Hp;  }
	void IncreaseExp() { Exp +=2; }
	int GetLevel() { return Level; }
	int GetExp() { return Exp; }
	void SetLevel() { Level++; }
	void SetExp() { Exp = 0; }
	void ChangeBullet()
	{
		int num = 0;

		srand((unsigned int)time(NULL));
		num = rand() % 2;

		switch (num)
		{
		case BULLETNORMAL:
			Bulletid = BULLETNORMAL;
			break;
		case BULLETNORMAL2:
			Bulletid = BULLETNORMAL2;
			break;
		}
	};
	
public:
	PlayerBridge() {};
	virtual ~PlayerBridge() {};
};
