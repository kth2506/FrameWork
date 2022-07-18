#include "ItemPower.h"
#include "CursorManager.h"
#include "Object.h"
ItemPower::ItemPower(){}
ItemPower::~ItemPower(){}


void ItemPower::Initialize()
{
	Type = POWERUP;
}

int ItemPower::Update(Transform& Info)
{
	return 0;
}

void ItemPower::Render()
{
	
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¨Ü", 9
	);
	
}

void ItemPower::Release()
{
}

