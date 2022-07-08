#include "Item.h"
#include "CursorManager.h"

Item::Item(){}
Item::Item(Transform _Info){}
Item::~Item(){}

Object* Item::Initialize(string _Key)
{
	strKey = _Key;

	Buffer[0] = (char*)"¨Ü";
	Buffer[1] = (char*)"¨Í";
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);

	return this;
}

int Item::Update()
{
	
	return 0;
}

void Item::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i], 15
		);
	}
}

void Item::Release()
{
}
