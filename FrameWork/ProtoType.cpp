#include "ProtoType.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"

ProtoType* ProtoType::Instance = nullptr;

ProtoType::ProtoType(){}

ProtoType::~ProtoType(){}

void ProtoType::Initialize()
{
	Transform Info;

	string Key;

	Key = "Player";
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "Enemy";	
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);

	Key = "Item";
	ProtoTypeList[Key] = (new Item(Info))->Initialize(Key);

}

Object* ProtoType::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;

	return iter->second;
}

