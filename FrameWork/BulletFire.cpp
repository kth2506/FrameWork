#include "BulletFire.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Object.h"
#include "Player.h"
#include "ObjectManager.h"

BulletFire::BulletFire() {}
BulletFire::~BulletFire() {}


void BulletFire::Initialize()
{
	// Bullet 의 데이터 초기화
	Check = false;
	Damage = 7;
	count = 0;
}

int BulletFire::Update(Transform& Info)
{
	count++;
	Vector3 vec = Vector3(ObjectManager::GetInstance()->GetObjectList("Player")->front()->GetPosition());
	switch (count)
	{
	case 0:
	case 1:
		Info.Position = Vector3(vec.x - 1.0f, vec.y - 4.0f);
		break;
	case 2:
	case 3:
		Info.Position = Vector3(vec.x - 0.0f, vec.y - 4.0f);
		break;
	case 4:
	case 5:
		Info.Position = Vector3(vec.x + 1.0f, vec.y - 4.0f);
		break;
	case 6:
	case 7:
		Info.Position = Vector3(vec.x + 2.0f, vec.y - 4.0f);
		break;
	case 8:
	case 9:
		Info.Position = Vector3(vec.x + 3.0f, vec.y - 4.0f);
		break;
	case 10:
	case 11:
		Info.Position = Vector3(vec.x + 3.0f, vec.y - 3.0f);
		break;
	case 12:
	case 13:
		Info.Position = Vector3(vec.x + 3.0f, vec.y - 2.0f);
		break;
	case 14:
	case 15:
		Info.Position = Vector3(vec.x + 2.0f, vec.y - 2.0f);
		break;
	case 16:
	case 17:
		Info.Position = Vector3(vec.x + 1.0f, vec.y - 2.0f);
		break;
	case 18:
	case 19:
		Info.Position = Vector3(vec.x + 0.0f, vec.y - 2.0f);
		break;
	case 20:
	case 21:
		Info.Position = Vector3(vec.x - 1.0f, vec.y - 1.0f);
		break;
	case 22:
	case 23:
		Info.Position = Vector3(vec.x - 2.0f, vec.y - 1.0f);
		break;
	case 24:
	case 25:
		Info.Position = Vector3(vec.x - 3.0f, vec.y - 1.0f);
		break;
	case 26:
	case 27:
		Info.Position = Vector3(vec.x - 4.0f, vec.y - 1.0f);
		break;
	case 28:
	case 29:
		Info.Position = Vector3(vec.x - 5.0f, vec.y - 1.0f);
		break;
	case 30:
	case 31:
		Info.Position = Vector3(vec.x - 5.0f, vec.y - 2.0f);
		break;
	case 32:
	case 33:
		Info.Position = Vector3(vec.x - 5.0f, vec.y - 3.0f);
		break;
	case 34:
	case 35:
		Info.Position = Vector3(vec.x - 4.0f, vec.y - 3.0f);
		break;
	case 36:
	case 37:
		Info.Position = Vector3(vec.x - 3.0f, vec.y - 3.0f);
		break;
	case 38:
	case 39:
		Info.Position = Vector3(vec.x - 2.0f, vec.y - 3.0f);
		break;
	//case 40:
	//case 41:
	//case 42:
	//case 43:
	//case 44:
	//case 45:
	//case 46:
	//case 47:
	//case 48:
	//case 49:
	//case 50:
	//case 51:
	//case 52:
	//case 53:
	//case 54:
	//case 55:
	//case 56:
	//case 57:
	//case 58:
	//case 59:
	default:
		count = 0;
		break;
	}

	


	return 0;
}

void BulletFire::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition().x,
		pObject->GetPosition().y,
		(char*)"＊", 2);
}

void BulletFire::Release()
{
}
