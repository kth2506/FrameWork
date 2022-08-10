#include "Intro2.h"
#include "CursorManager.h"

Intro2::Intro2() : check(true) {}
Intro2::Intro2(Transform _Info) {}
Intro2::~Intro2() {}

void Intro2::Initialize()
{
	strKey = "Intro2";

	Count = 0;


}

int Intro2::Update()
{
	if(Count < 15)
	Count++;
		
	return 0;
}

void Intro2::Render()
{

	for(int i = 0 ; i < Console_Height; ++i)
	CursorManager::GetInstance()->WriteBuffer(Vector3(0, i), (char*)"                                                                                                                                                                                                        " , Count << 4);
}

void Intro2::Release()
{
}

