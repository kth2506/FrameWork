
#include "HpBar.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Bridge.h"

HpBar::HpBar() {}
HpBar::HpBar(Transform _Info) {}
HpBar::~HpBar() {}

void HpBar::Initialize()
{
	count = 0;
	hp = 0;
	strKey = "HpBar";
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	TextureList.emplace_back((char*)"  ");
	TextureList.emplace_back((char*)"  ");

	TransInfo.Position = Vector3(4.0f, 2.0f);
}

int HpBar::Update()
{
	hp = pPlayer->GetBridge()->GetHp();

	return 0;
}

void HpBar::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j < hp)
				CursorManager::GetInstance()->WriteBuffer(
					4.0f + j * 2, 2.0f + i,
					TextureList[i], LIGHTRED + LIGHTRED * 16);
			else
				CursorManager::GetInstance()->WriteBuffer(
					4.0f+ j * 2, 2.0f + i,
					TextureList[i], RED + RED * 16);
		}
	}

	CursorManager::GetInstance()->WriteBuffer(
		4.0f, 1.0f,
		(char*)" HP  ", WHITE + LIGHTGRAY * 16);
}

void HpBar::Release()
{
}
