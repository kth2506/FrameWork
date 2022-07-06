#pragma once
#include "Object.h"
class Bullet : public Object
{
private:
	Object* pEnemy;
	POINT p;
public:

	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual Object* Clone() {return new Bullet(*this);}
	
public:
	Bullet();
	Bullet(Transform _Info);

	virtual ~Bullet();
};

