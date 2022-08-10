#pragma once
#include "Bridge.h"

class Object;
class PlayerBridge : public Bridge
{
protected:
	// ** Player 의 데이터만 넣음.
	float as;
	float attackSpeed;
	float FireSpeed;
	float Fs;
	BULLETID Bulletid = BULLETNORMAL;
	int BoomCount;
	int Level;
	int Exp;
	int Maxhp;
	bool FireGrade;
	
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void IncreasePower() { Damage *= 1.2; }
	void IncreaseAttackSpeed() { as *= (float)1.2; }
	void IncreaseBoom() { if (BoomCount < 5) ++BoomCount;  }
	void IncreaseHp() { if(Maxhp != Hp ) ++Hp;  }
	void IncreaseExp() { Exp +=6; }
	void IncreaseMaxHp() { ++Hp; ++Maxhp; }
	void FireUpgrade() { FireGrade = true; Fs *= 1.2f; }
	int GetLevel() { return Level; }
	int GetMaxhp() { return Maxhp; }
	int GetExp() { return Exp; }
	int GetBoomCount() { return BoomCount; }
	float GetAttackSpeed() { return as; }
	void SetLevel() { Level++; }
	void SetExp() { Exp = 0; }
	void ChangeBullet()
	{
		int num = 0;

		srand((unsigned int)time(NULL));
		num = rand() % 3;

		switch (num)
		{
		case BULLETNORMAL:
			Bulletid = BULLETNORMAL;
			break;
		case BULLETNORMAL2:
			Bulletid = BULLETNORMAL2;
			break;
		case BULLETLAZER:
			Bulletid = BULLETLAZER;
			break;
		}
	};
	
public:
	PlayerBridge() {};
	virtual ~PlayerBridge() {};
};
