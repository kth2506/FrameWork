#include "ItemPotion.h"
#include "CursorManager.h"
#include "Object.h"
ItemPotion::ItemPotion() {}
ItemPotion::~ItemPotion() {}


void ItemPotion::Initialize()
{
	Type = POTION;
	Count = 0;
}

int ItemPotion::Update(Transform& Info)
{
	++Count;
	if (Count > 100)
		return BUFFER_OVER;

	return 0;
}

void ItemPotion::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¨Ô", 9
	);
}

void ItemPotion::Release()
{
}

