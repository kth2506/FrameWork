#pragma once
#include "Object.h"

class Background : public Object
{
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual Object* Clone() override { return new Background(*this); }

public:
	Background();
	Background(Transform _Info);

	virtual ~Background();
};

