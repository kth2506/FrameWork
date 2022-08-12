#include "ItemBoom.h"
#include "CursorManager.h"
#include "Object.h"
ItemBoom::ItemBoom() {}
ItemBoom::~ItemBoom() {}


void ItemBoom::Initialize()
{
	Type = BOOM;
	Count = 0;
}

int ItemBoom::Update(Transform& Info)
{

	++Count;
	if (Count > 100)
		return BUFFER_OVER;
	return 0;
}

void ItemBoom::Render()
{

	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¨Î", LIGHTBLUE
	);
}

void ItemBoom::Release()
{
}

