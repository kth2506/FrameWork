#pragma once
#include "Object.h"

class Bridge;
class Object;
class Player : public Object
{
private:
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual Object* Clone() override{ return new Player(*this);	}

private:
	Object* pBullet;
public:

public:
	Player();
	Player(Transform _Info);

	virtual ~Player();
};
