#include "ItemPower.h"
#include "CursorManager.h"
#include "Object.h"
ItemPower::ItemPower(){}
ItemPower::~ItemPower(){}


void ItemPower::Initialize()
{
	Type = POWERUP;
	Count = 0;

}

int ItemPower::Update(Transform& Info)
{

	++Count;
	if (Count > 100)
		return BUFFER_OVER;
	return 0;
}

void ItemPower::Render()
{
	
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"��", 9
	);
	
}

void ItemPower::Release()
{
}

