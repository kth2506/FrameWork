#pragma once
#include "UserInterface.h"

class Score : public UserInterface
{
public:
	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Score();
	Score(Transform _Info);
	virtual ~Score();
};

