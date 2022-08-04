#pragma once
#include "UserInterface.h"

class Object;
class Level : public UserInterface
{
private:
	Object* pPlayer;
	int level;
	int exp;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Level();
	Level(Transform _Info);
	virtual ~Level();
};

