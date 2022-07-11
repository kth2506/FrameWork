#include "Intro.h"
#include "CursorManager.h"

Intro::Intro() : count(0) , check(true){}
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
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"					Press To Enter");



	TransInfo.Position = Vector3(float(180 / 2) - 31, 5.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(14.0f, 6.0f);
}

int Intro::Update()
{

	if (count < (int)TextureList.size() * 3)
		count++;
	else
		check = !check;

	return 0;
}

void Intro::Render()
{
	//(int)TextureList.size();
	
	if (check)
	{
		for (int i = 0; i < int(count / 3); ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(
				TransInfo.Position.x - TransInfo.Scale.x * 0.5f,
				TransInfo.Position.y - TransInfo.Scale.y * 0.5f + i,
				TextureList[i]);
		}
	}
}

void Intro::Release()
{
}

