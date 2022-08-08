
#include "Level.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Bridge.h"
#include "PlayerBridge.h"
Level::Level() {}
Level::Level(Transform _Info) {}
Level::~Level() {}

void Level::Initialize()
{
	count = 0;
	level = 0;
	exp = 0;
	strKey = "Level";
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	TextureList.emplace_back((char*)" ");
	TextureList.emplace_back((char*)" ");

	TransInfo.Position = Vector3(4.0f, 2.0f);
}

int Level::Update()
{
	level = ((PlayerBridge*)pPlayer->GetBridge())->GetLevel();
	exp = ((PlayerBridge*)pPlayer->GetBridge())->GetExp();

	if (exp >= 60)
	{
	}
	return 0;
}

void Level::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			if (j < exp)
				CursorManager::GetInstance()->WriteBuffer(
					Console_Width / 2 - 30+ j, 2.0f + i,
					TextureList[i], KHAKI * 4);
			else
				CursorManager::GetInstance()->WriteBuffer(
					Console_Width / 2 - 30+ j, 2.0f + i,
					TextureList[i], 4+11 * 4);
		}
	}

	CursorManager::GetInstance()->WriteBuffer(
		Console_Width / 2 - 25, 1.0f,
		level , LIGHTGRAY | (LIGHTGRAY * 4));
	CursorManager::GetInstance()->WriteBuffer(
		Console_Width / 2 - 30, 1.0f,
		(char*)"LEVEL", LIGHTGRAY | (LIGHTGRAY * 4));

}

void Level::Release()
{
}
