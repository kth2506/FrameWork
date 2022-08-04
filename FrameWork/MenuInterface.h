#pragma once
#include "UserInterface.h"

class Object;
class MenuInterface : public UserInterface
{
private:
	DWORD dwKey;
	int Select;
	int Color;
	Object* pPlayer;
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	MenuInterface();
	MenuInterface(Transform _Info);
	virtual ~MenuInterface();
};

