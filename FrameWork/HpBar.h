#pragma once
#include "UserInterface.h"

class Object;
class HpBar : public UserInterface
{
private:
	Object* pPlayer;
	int hp;
	int Maxhp;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	int SetHp(int _Value) { hp = _Value; }
public:
	HpBar();
	HpBar(Transform _Info);
	virtual ~HpBar();
};

