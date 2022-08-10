#include "Enemy.h"
#include "CursorManager.h"
#include "ProtoType.h"
#include "BulletNormal.h"
#include "BulletNormal2.h"
#include "BulletBoom.h"

Enemy::Enemy() {}
Enemy::Enemy(Transform _Info) : Object(_Info){}
Enemy::~Enemy() {}

Object* Enemy::Initialize(string _Key)
{
	strKey = _Key;
	
	TransInfo.Position = Vector3(10.0f, 10.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);

	if (pBridge)
		pBridge->Initialize();

	return this;

}

int Enemy::Update()
{
	if (pBridge)
		pBridge->Update(TransInfo);
	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	delete pBridge;
	pBridge = nullptr;
}
