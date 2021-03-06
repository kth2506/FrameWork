#pragma once
#include "Object.h"

class Cloud : public Object
{
public:
	virtual Object* Initialize(string _Key) override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual Object* Clone() override { return new Cloud(*this); }

public:
	Cloud();
	Cloud(Transform _Info);

	virtual ~Cloud();
};

