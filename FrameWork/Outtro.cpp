
#include "Outtro.h"
#include "CursorManager.h"
#include "InputManager.h"
Outtro::Outtro() {}
Outtro::Outtro(Transform _Info) {}
Outtro::~Outtro() {}

void Outtro::Initialize()
{
	count = 0;

	strKey = "Outtro";
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	TextureList.emplace_back((char*)"gggggggggggggg");
	                                                  
                  
	TransInfo.Position = Vector3(float(180 / 2) - 32.5f, 10.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(34.0f, 17.0f); 
}

int Outtro::Update()
{
	if (count < (int)TextureList.size() * 3 + 2)
		count++;

	return 0;
}

void Outtro::Render()
{

	for (int i = 0; i <  int(count / 3); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			TextureList[i]);
	}


}

void Outtro::Release()
{
}
