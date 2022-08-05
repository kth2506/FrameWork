#define _CRT_SECURE_NO_WARNINGS

#include "MenuInterface.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "PlayerBridge.h"
#include "ObjectManager.h"
#include "Player.h"
#include "BulletFire.h"
MenuInterface::MenuInterface() {}
MenuInterface::MenuInterface(Transform _Info) {}
MenuInterface::~MenuInterface() {}

void MenuInterface::Initialize()
{

	strKey = "MenuInterface";
	Select = 0;
	Color = 15;
	count = 0;
	pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	TextureList.emplace_back((char*)"ΓΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΘΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΘΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΘΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΘΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΔ");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"ΖΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΚΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΚΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΚΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΚΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΕ");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"			                ΓΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΔ");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                ΖΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΕ");


	TextureListTemp.emplace_back((char*)"POWER UP!!");
	TextureListTemp.emplace_back((char*)"ATTACKSPEED UP!!");
	TextureListTemp.emplace_back((char*)"CHANGE BULLET!!");
	TextureListTemp.emplace_back((char*)"MAXHP UP!!");
	TextureListTemp.emplace_back((char*)"FIRE UP!!");

	TransInfo.Position = Vector3(12.0f, 10.0f);
}

int MenuInterface::Update()
{
	count++;
	dwKey = InputManager::GetInstance()->GetKey();

	if ((dwKey & KEY_LEFT )&& count > 4)
	{
		--Select;
		if (Select < 0)
			Select = 4;
		count = 0;
	}

	if ((dwKey & KEY_RIGHT )&& count > 4)
	{
		++Select;
		if (Select > 4)
			Select = 0;
		count = 0;
	}


	if (dwKey & KEY_ENTER)
	{
		switch (Select)
		{
		case 0:
			((PlayerBridge*)pPlayer->GetBridge())->IncreasePower(5);
			break;
		case 1:
			((PlayerBridge*)pPlayer->GetBridge())->IncreaseAttackSpeed();
			break;
		case 2:
			((PlayerBridge*)pPlayer->GetBridge())->ChangeBullet();
			break;
		case 3:
			((PlayerBridge*)pPlayer->GetBridge())->IncreaseMaxHp();
			break;
		case 4:
			Bridge* bBullet;
			bBullet = new BulletFire;
			ObjectManager::GetInstance()->AddBullet(bBullet,
				Vector3(pPlayer->GetPosition().x - 3.0f, pPlayer->GetPosition().y - 3.0f));
			break;
		default:
			break;
		}
	}
	return 0;
}

void MenuInterface::Render()
{

	for (int i = 0; i < (int)TextureList.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			TextureList[i], 11);
	}

	for (int i = 0; i < 5; ++i)
	{
		if (i == Select)
			Color = RED;
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x + 183 / 5 * i + 11, TransInfo.Position.y + 4,
			TextureListTemp[i], Color);
		Color = 15;
	}




}

void MenuInterface::Release()
{
}
