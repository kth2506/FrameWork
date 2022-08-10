#pragma once
#include "Die.h"

class Object;
class DiePlayer : public Die
{
private:
	Object* pPlayer;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	DiePlayer();
	DiePlayer(Transform _Info);
	virtual ~DiePlayer();
};

