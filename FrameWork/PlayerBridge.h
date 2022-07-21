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
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void IncresePower(int _Value) { Damage += _Value; }
	void IncreseAttackSpeed() { as += 0.3f; }
	void IncreseBoom() { ++BoomCount;  }
	void ChangeBullet()
	{
		int num = 0;

		while (num == Bulletid)
		{
			srand((unsigned int)time(NULL));
			num = rand() % BULLETMAX;
		}

		switch (num)
		{
		case BULLETNORMAL:
			Bulletid = BULLETNORMAL;
			break;
		case BULLETNORMAL2:
			Bulletid = BULLETNORMAL2;
			break;
		//case BULLETBOOM:
		//	Bulletid = BULLETBOOM;
		//	break;
		}
	};
	
public:
	PlayerBridge() {};
	virtual ~PlayerBridge() {};
};
