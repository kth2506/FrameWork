#include "ItemPower.h"
#include "CursorManager.h"
#include "Object.h"
ItemPower::ItemPower(){}
ItemPower::~ItemPower(){}


void ItemPower::Initialize()
{
	Type = 1;
}

int ItemPower::Update(Transform& Info)
{
	return 0;
}

void ItemPower::Render()
{
	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"¨Ü", 15
		);
	}
}

void ItemPower::Release()
{
}

