#include "Bullet.h"
#include "CursorManager.h"
#include "Player.h"
#include "ObjectManager.h"

Bullet::Bullet(){}

Bullet::Bullet(Transform _Info) : Object(_Info){}

Bullet::~Bullet() {  }

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"¢´";
	Buffer[1] = (char*)"";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);

	
}




int Bullet::Update()
{
	pEnemy = ObjectManager::GetInstance()->GetObjectList("Enemy")->front();
	Vector3 Target = pEnemy->GetPosition();

	float Width = Target.x - TransInfo.Position.x;
	float Height = Target.y - TransInfo.Position.y;

	float Distance = sqrt((Width * Width) + (Height * Height));

	TransInfo.Direction = Vector3(Width / Distance, Height / Distance);

	TransInfo.Position += TransInfo.Direction;



	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < 1; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
			TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
			Buffer[i], Color
		);
	}
}

void Bullet::Release()
{

}
