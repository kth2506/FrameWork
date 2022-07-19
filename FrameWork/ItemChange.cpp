#include "ItemChange.h"
#include "CursorManager.h"
#include "Object.h"

ItemChange::ItemChange(){}

ItemChange::~ItemChange(){}

void ItemChange::Initialize()
{
	Type = CHANGE;
}

int ItemChange::Update(Transform& Info)
{
	return 0;
}

void ItemChange::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"¨Ï", 2
	);
}

void ItemChange::Release()
{
}

