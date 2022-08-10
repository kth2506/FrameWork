
#include "Outtro.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Outtro::Outtro() {}
Outtro::Outtro(Transform _Info) {}
Outtro::~Outtro() {}

void Outtro::Initialize()
{
	count = 0;

	strKey = "Outtro";
	TextureList.emplace_back((char*)" ######      ###    ##     ## ########     #######  ##     ## ######## ########  ");
	TextureList.emplace_back((char*)"##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ## ");
	TextureList.emplace_back((char*)"##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ## ");
	TextureList.emplace_back((char*)"##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########  ");
	TextureList.emplace_back((char*)"##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##   ");
	TextureList.emplace_back((char*)"##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##  ");
	TextureList.emplace_back((char*)" ######   ##     ## ##     ## ########     #######     ###    ######## ##     ## ");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	TextureList.emplace_back((char*)"");
	                                                  
                  
	TransInfo.Position = Vector3(Console_Width / 2 - 32.5f, 12.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(34.0f, 17.0f); 
}

int Outtro::Update()
{
	count++;

	if (count > (int)TextureList.size() * 3)
		return BUFFER_OVER;
	return 0;
}

void Outtro::Render()
{

	for (int i = 0; i <  int(count / 3); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			TextureList[i] , RED);
	}

	
}

void Outtro::Release()
{
}
