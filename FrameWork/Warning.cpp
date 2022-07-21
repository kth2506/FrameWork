
#include "Warning.h"
#include "CursorManager.h"
#include "InputManager.h"
Warning::Warning() {}
Warning::Warning(Transform _Info) {}
Warning::~Warning() {}

void Warning::Initialize()
{
	count = 0;

	strKey = "Warning";
	TextureList.emplace_back((char*)"██");

	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"...");
	//
	//TextureList.emplace_back((char*)"");
	//TextureList.emplace_back((char*)"");
	//TextureList.emplace_back((char*)"");
	//TextureList.emplace_back((char*)"...");
	//TextureList.emplace_back((char*)"...");
	//
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"..");
	//TextureList.emplace_back((char*)"...");


}

int Warning::Update()
{
	if (count < (int)TextureList.size() * 3 + 2)
		count++;

	return 0;
}

void Warning::Render()
{
	
	CursorManager::GetInstance()->WriteBuffer(
		50.0f,10.0f,TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		50.0f, 11.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		50.0f, 12.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		50.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);

	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 10.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 11.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 12.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		52.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	
	CursorManager::GetInstance()->WriteBuffer(
		54.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);

	CursorManager::GetInstance()->WriteBuffer(
		56.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		56.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);

	CursorManager::GetInstance()->WriteBuffer(
		58.0f, 12.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		58.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	
	CursorManager::GetInstance()->WriteBuffer(
		60.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		60.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	
	CursorManager::GetInstance()->WriteBuffer(
		62.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);

	CursorManager::GetInstance()->WriteBuffer(
		64.0f, 10.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		64.0f, 11.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		64.0f, 12.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		64.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		64.0f, 14.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	
	CursorManager::GetInstance()->WriteBuffer(
		66.0f, 10.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		66.0f, 11.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		66.0f, 12.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);
	CursorManager::GetInstance()->WriteBuffer(
		66.0f, 13.0f, TextureList[0], LIGHTRED + LIGHTRED * 16);

}

void Warning::Release()
{
}
