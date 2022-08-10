#include "Effect.h"
#include "CursorManager.h"
#include "EffectBridge.h"
Effect::Effect() {}
Effect::Effect(Transform _Info) {}
Effect::~Effect() {}

Object* Effect::Initialize(string _Key)
{
	strKey = _Key;
	
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);
	if (pBridge)
		pBridge->Initialize();
	return this;
}

int Effect::Update()
{
	if (pBridge)
		return pBridge->Update(TransInfo);
	return 0;
}

void Effect::Render()
{
	if (pBridge)
		pBridge->Render();

}

void Effect::Release()
{
	delete pBridge;
	pBridge = nullptr;
}
