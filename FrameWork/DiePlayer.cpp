#include "DiePlayer.h"
#include "Player.h"
#include "ObjectManager.h"
#include "CursorManager.h"
DiePlayer::DiePlayer(){}
DiePlayer::DiePlayer(Transform _Info){}
DiePlayer::~DiePlayer(){}

void DiePlayer::Initialize()
{
	count = 0;
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ø");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ø");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ø");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	TextureList.emplace_back((char*)"¡Ø");
	TextureList.emplace_back((char*)"¡Ú");
	TextureList.emplace_back((char*)"¡Ù");
	
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();

	//TransInfo.Position = Vector3(15.0f, 15.0f);




}

int DiePlayer::Update()
{
	count++;
	if (count > 100)
		return BUFFER_OVER;


	return 0;
}

void DiePlayer::Render()
{
	for (int i = 0; i < TextureList.size(); ++i)
		CursorManager::GetInstance()->WriteBuffer
		(pPlayer->GetPosition().x , pPlayer->GetPosition().y + i, TextureList[i]);
}

void DiePlayer::Release()
{
}

