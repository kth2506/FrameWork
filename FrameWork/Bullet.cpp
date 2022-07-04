#include "Bullet.h"
#include "CursorManager.h"


Bullet::Bullet(){}

Bullet::Bullet(Transform _Info) : Object(_Info){}

Bullet::~Bullet() {  }

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"==@";
	Buffer[1] = (char*)"==@";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 2.0f);


	
}


int Bullet::Update()
{
	Vector3 Target = Vector3(60.0f, 15.0f);

	float Width = Target.x - TransInfo.Position.x;
	float Height = Target.y - TransInfo.Position.y;

	float Distance = sqrt((Width * Width) + (Height * Height));

	TransInfo.Direction = Vector3(Width / Distance, Height / Distance);

	TransInfo.Position += TransInfo.Direction;



	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position.x, TransInfo.Position.y, (char*)"BBB", Color
	);
}

void Bullet::Release()
{

}
