#pragma once
#include "BulletBridge.h"

class BulletBoom : public BulletBridge
{
private:
	int Count;
	vector<char*> List;
public:

	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void Boom();
public:
	BulletBoom();
	virtual ~BulletBoom();
};

