#pragma once
#include "Headers.h"

class Bridge;
class BridgeManager
{
private:
	static BridgeManager* Instance;
public:
	static BridgeManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new BridgeManager();
		return Instance;
	}
private:
	Bridge* pBridge;
public:
	Bridge* GetBridge() { return pBridge; }
private:
	BridgeManager();
public:
	~BridgeManager();

};

