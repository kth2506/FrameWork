#include "Item.h"
#include "CursorManager.h"
#include "ItemPower.h"
Item::Item(){}
Item::Item(Transform _Info){}
Item::~Item(){}

Object* Item::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
	if (pBridge)
		pBridge->Initialize();
	return this;
}

int Item::Update()
{
	if (pBridge)
		pBridge->Update(TransInfo);
	return 0;
}

void Item::Render()
{
	if (pBridge)
		pBridge->Render();
	
}

void Item::Release()
{
	delete pBridge;
	pBridge = nullptr;
}
