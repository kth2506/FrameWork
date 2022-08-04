#pragma once
#include "UserInterface.h"

class Object;
class BulletUI : public UserInterface
{
private:
	int BoomCount;
	float AttackSpeed;
	Object* pPlayer;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BulletUI();
	BulletUI(Transform _Info);
	virtual ~BulletUI();
};

