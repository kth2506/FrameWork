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
	//TextureList.emplace_back((char*)"			                                 ΓΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΔ");
	//TextureList.emplace_back((char*)"			                                 Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	//TextureList.emplace_back((char*)"			                                 Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	//TextureList.emplace_back((char*)"			                                 Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	//TextureList.emplace_back((char*)"			                                 ΖΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΕ");

	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");
	TextureList.emplace_back((char*)"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　");

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
	TextureList.emplace_back((char*)"			                ΓΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΔ");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                Β　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　Β");
	TextureList.emplace_back((char*)"			                ΖΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΑΕ");


	TextureListTemp.emplace_back((char*)"POWER UP");
	TextureListTemp.emplace_back((char*)"SPEED UP");
	TextureListTemp.emplace_back((char*)"CHANGE BULLET");
	TextureListTemp.emplace_back((char*)"VITALITY");
	TextureListTemp.emplace_back((char*)"FIRE UP");


	TextureListExplain.emplace_back((char*)"Power Up");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"Bullet Damage + 2");
	TextureListExplain.emplace_back((char*)"Boom + 1");
	TextureListExplain.emplace_back((char*)"");

	TextureListExplain.emplace_back((char*)"Speed Up");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"Reload Rate + 2");
	TextureListExplain.emplace_back((char*)"Move Speed + 1");
	TextureListExplain.emplace_back((char*)"");

	TextureListExplain.emplace_back((char*)"Change Weapon");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"Change Random Bullet");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"");


	TextureListExplain.emplace_back((char*)"Vitality");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"MaxHp + 1");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"");


	TextureListExplain.emplace_back((char*)"Fire Upgrade");
	TextureListExplain.emplace_back((char*)"");
	TextureListExplain.emplace_back((char*)"Fire Reload Rate + 1");
	TextureListExplain.emplace_back((char*)"Fire Damage + 2");
	TextureListExplain.emplace_back((char*)"");

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
			((PlayerBridge*)pPlayer->GetBridge())->IncreasePower(2);
			break;
		case 1:
			((PlayerBridge*)pPlayer->GetBridge())->IncreaseAttackSpeed(0.2f);
			((PlayerBridge*)pPlayer->GetBridge())->IncreaseSpeed(0.08f);
			break;
		case 2:
			((PlayerBridge*)pPlayer->GetBridge())->ChangeBullet();
			break;
		case 3:
			((PlayerBridge*)pPlayer->GetBridge())->IncreaseMaxHp();
			break;
		case 4:
			((PlayerBridge*)pPlayer->GetBridge())->FireUpgrade();
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
			TextureList[i], 8);
	}

	for (int i = 0; i < 5; ++i)
	{
		if (i == Select)
			Color = RED;
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x + 183 / 5 * i + 11, TransInfo.Position.y + 12,
			TextureListTemp[i], Color);
		Color = 15;
	}


	CursorManager::GetInstance()->WriteBuffer(70, 10, (char*)"け       けけけけ   け    け   けけけけ   け       け け");
	CursorManager::GetInstance()->WriteBuffer(70, 11, (char*)"け       け         け    け   け         け       け け");
	CursorManager::GetInstance()->WriteBuffer(70, 12, (char*)"け       けけけ     け    け   けけけ     け       け け");
	CursorManager::GetInstance()->WriteBuffer(70, 13, (char*)"け       け          け  け    け         け");
	CursorManager::GetInstance()->WriteBuffer(70, 14, (char*)"けけけ   けけけけ      け      けけけけ   けけけ   け け");

	for (int i = 0; i < 5; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer((float)58, (float)32 + i, TextureListExplain[i + Select * 5]);
	}

}

void MenuInterface::Release()
{
}
