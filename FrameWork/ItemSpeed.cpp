#include "ItemSpeed.h"
#include "CursorManager.h"
#include "Object.h"
ItemSpeed::ItemSpeed() {}
ItemSpeed::~ItemSpeed() {}


void ItemSpeed::Initialize()
{
	Type = SPEEDUP;
}

int ItemSpeed::Update(Transform& Info)
{
	return 0;
}

void ItemSpeed::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¨ß", 5
	);
}

void ItemSpeed::Release()
{
}

