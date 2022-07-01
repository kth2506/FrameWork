#pragma once
#include "Object.h"
class Player : public Object
{
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual Object* Clone() override{ return new Player(*this);	}

public:
	Player();
	Player(Transform _Info);

	virtual ~Player();
};

