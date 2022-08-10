#pragma once
#include "Object.h"

class Effect : public Object
{

public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual Object* Clone() override { return new Effect(*this); }

public:
	Effect();
	Effect(Transform _Info);

	virtual ~Effect();
};

