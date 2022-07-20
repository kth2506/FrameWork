#include "Intro.h"
#include "CursorManager.h"

Intro::Intro() : check(true){}
Intro::Intro(Transform _Info){}
Intro::~Intro(){}

void Intro::Initialize()
{
	strKey = "Intro";

	TextureList.emplace_back((char*)"....##.....#####......##.....##.####.##....##.##.....##.########.########..######.");
	TextureList.emplace_back((char*)"..####....##...##.....###...###..##..###...##.##.....##....##....##.......##....##");
	TextureList.emplace_back((char*)"....##...##.....##....####.####..##..####..##.##.....##....##....##.......##......");
	TextureList.emplace_back((char*)"....##...##.....##....##.###.##..##..##.##.##.##.....##....##....######....######.");
	TextureList.emplace_back((char*)"....##...##.....##....##.....##..##..##..####.##.....##....##....##.............##");
	TextureList.emplace_back((char*)"....##....##...##.....##.....##..##..##...###.##.....##....##....##.......##....##");
	TextureList.emplace_back((char*)"..######...#####......##.....##.####.##....##..#######.....##....########..######.");
	
	for(int i = 0 ; i < 16; ++i)
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"				Press To Enter");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");



	TransInfo.Position = Vector3(float(180 / 2) - 41, 5.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(14.0f, 6.0f);
}

int Intro::Update()
{

	if (count < (int)TextureList.size() * 3 + 2)
		count++;

	return 0;
}

void Intro::Render()
{
	
	for (int i = 0; i < int(count / 3); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			TextureList[i] , 12);
		if(count == (int)TextureList.size() * 3 + 2)
		count -= 10;
	}
}

void Intro::Release()
{
}

