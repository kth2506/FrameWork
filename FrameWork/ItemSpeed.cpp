#include "ItemSpeed.h"
#include "CursorManager.h"
#include "Object.h"
ItemSpeed::ItemSpeed() {}
ItemSpeed::~ItemSpeed() {}


void ItemSpeed::Initialize()
{
	Type = SPEEDUP;
	Count = 0;
}

int ItemSpeed::Update(Transform& Info)
{
	++Count;
	if (Count > 100)
		return BUFFER_OVER;

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

