#include "ItemSpeed.h"
#include "CursorManager.h"
#include "Object.h"
ItemSpeed::ItemSpeed() {}
ItemSpeed::~ItemSpeed() {}


void ItemSpeed::Initialize()
{
	Type = 2;
}

int ItemSpeed::Update(Transform& Info)
{
	return 0;
}

void ItemSpeed::Render()
{
	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			pObject->GetPosition().x,
			pObject->GetPosition().y,
			(char*)"¨ß", 15
		);
	}
}

void ItemSpeed::Release()
{
}

