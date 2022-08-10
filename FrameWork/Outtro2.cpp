
#include "Outtro2.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Outtro2::Outtro2() {}
Outtro2::Outtro2(Transform _Info) {}
Outtro2::~Outtro2() {}

void Outtro2::Initialize()
{
	count = 0;

	strKey = "Outtro2";


	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	//TransInfo.Position = Vector3(float(180 / 2) - 32.5f, 10.0f);
	//TransInfo.Rotation = Vector3(0.0f, 0.0f);
	//TransInfo.Scale = Vector3(34.0f, 17.0f);
}

int Outtro2::Update()
{
	count++;

	return 0;
}

void Outtro2::Render()
{
	for(int i = 0 ; i < 20; ++i)
	CursorManager::GetInstance()->WriteBuffer(
		2.0f, i + 1, (char*)"                                                                                                                                                                                                   " 
	);

	for (int i = 0; i < int(count / 3); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
		2.0f, i+1, 
			TextureList[i]);
	}


}

void Outtro2::Release()
{
}
