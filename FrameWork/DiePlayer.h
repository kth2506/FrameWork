#pragma once
#include "UserInterface.h"

class Object;
class DiePlayer : public UserInterface
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

