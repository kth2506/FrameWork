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
	TransInfo.Direction = Vector3(0.1f, -0.06f);


	
}


int Bullet::Update()
{

	Vector3 Target = Vector3(60.0f, 15.0f);

	Vector3 Result = Target - TransInfo.Position;
	float distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));

	cout << TransInfo.Direction.x << endl;
	cout << TransInfo.Direction.y << endl;

	TransInfo.Direction /= distance;



	TransInfo.Position += TransInfo.Direction;



	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.y * 0.5f) + i,
			Buffer[i]);
	}
}

void Bullet::Release()
{

}
