#include "UserInterfaceManager.h"
#include "Time.h"
#include "ScrollBox.h"
#include "Outtro.h"
#include "HpBar.h"
#include "Warning.h"
#include "Level.h"
#include "BulletUI.h"
UserInterfaceManager* UserInterfaceManager::Instance = nullptr;

UserInterfaceManager::UserInterfaceManager(){}
UserInterfaceManager::~UserInterfaceManager() {}


void UserInterfaceManager::Initialize()
{
	pTime = new Time;
	pTime->Initialize();
	pHpBar = new HpBar;
	pHpBar->Initialize();
	pLevel = new Level;
	pLevel->Initialize();
	pBulletUI = new BulletUI;
	pBulletUI->Initialize();
}

void UserInterfaceManager::Update()
{
	//pWarning = new Warning;
	//pWarning->Initialize();	
	
	pHpBar->Update();
	pTime->Update();
	pLevel->Update();
	pBulletUI->Update();

}


void UserInterfaceManager::Render()
{
	pHpBar->Render();
	pTime->Render();
	pLevel->Render();
	pBulletUI->Render();

}

void UserInterfaceManager::Release()
{
}






