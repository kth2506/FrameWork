
#include "Congraturation.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Congraturation::Congraturation() {}
Congraturation::Congraturation(Transform _Info) {}
Congraturation::~Congraturation() {}

void Congraturation::Initialize()
{
	count = 0;

	strKey = "Congraturation";


	TextureList.emplace_back((char*)"                               ######   #######  ##    ##  ######   ########     ###    ######## ##     ## ########     ###    ######## ####  #######  ##    ##    #### #### ");
	TextureList.emplace_back((char*)"                              ##    ## ##     ## ###   ## ##    ##  ##     ##   ## ##      ##    ##     ## ##     ##   ## ##      ##     ##  ##     ## ###   ##    #### #### ");
	TextureList.emplace_back((char*)"                              ##       ##     ## ####  ## ##        ##     ##  ##   ##     ##    ##     ## ##     ##  ##   ##     ##     ##  ##     ## ####  ##    #### #### ");
	TextureList.emplace_back((char*)"                              ##       ##     ## ## ## ## ##   #### ########  ##     ##    ##    ##     ## ########  ##     ##    ##     ##  ##     ## ## ## ##     ##   ##  ");
	TextureList.emplace_back((char*)"                              ##       ##     ## ##  #### ##    ##  ##   ##   #########    ##    ##     ## ##   ##   #########    ##     ##  ##     ## ##  ####       ");
	TextureList.emplace_back((char*)"                              ##    ## ##     ## ##   ### ##    ##  ##    ##  ##     ##    ##    ##     ## ##    ##  ##     ##    ##     ##  ##     ## ##   ###    #### #### ");
	TextureList.emplace_back((char*)"                               ######   #######  ##    ##  ######   ##     ## ##     ##    ##     #######  ##     ## ##     ##    ##    ####  #######  ##    ##    #### #### ");
	
	
	
	TextureList.emplace_back((char*)" ");
	TextureList.emplace_back((char*)" ");
	TextureList.emplace_back((char*)" ");
	
	TextureList.emplace_back((char*)"                                              ######  ##       ########    ###    ########     #### #### ");
	TextureList.emplace_back((char*)"                                              ##    ## ##       ##         ## ##   ##     ##    #### ####  ");
	TextureList.emplace_back((char*)"                                              ##       ##       ##        ##   ##  ##     ##    #### ####  ");
	TextureList.emplace_back((char*)"                                              ##       ##       ######   ##     ## ########      ##   ##   ");
	TextureList.emplace_back((char*)"                                              ##       ##       ##       ######### ##   ##                 ");
	TextureList.emplace_back((char*)"                                              ##    ## ##       ##       ##     ## ##    ##     #### ####  ");
	TextureList.emplace_back((char*)"                                               ######  ######## ######## ##     ## ##     ##    #### #### ");
	TransInfo.Position = Vector3(float(180 / 2) - 32.5f, 10.0f);
	//TransInfo.Rotation = Vector3(0.0f, 0.0f);
	//TransInfo.Scale = Vector3(34.0f, 17.0f);
}

int Congraturation::Update()
{
	if (count < (int)TextureList.size() * 3)
		count++;

	if (count == (int)TextureList.size() * 3)
		return BUFFER_OVER;
	return 0;
}

void Congraturation::Render()
{

	for (int i = 0; i < int(count / 3); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			10.0f, i + 15,
			TextureList[i]);
	}

	
}

void Congraturation::Release()
{
}
