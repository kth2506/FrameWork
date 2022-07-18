#define _CRT_SECURE_NO_WARNINGS
#include "Bullet.h"
#include "CursorManager.h"
#include "Player.h"
#include "ObjectManager.h"
#include "MathManager.h"
#include "NormalBullet.h"

Bullet::Bullet(){}

Bullet::Bullet(Transform _Info) : Object(_Info){}

Bullet::~Bullet() { Release(); }

Object* Bullet::Initialize(string _Key)
{
	strKey = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);

	if (pBridge)
		pBridge->Initialize();
	return this;
}

int Bullet::Update()
{

	if (pBridge)
		pBridge->Update(TransInfo);
	return 0;
}

void Bullet::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Bullet::Release()
{
	delete pBridge;
	pBridge = nullptr;

}
