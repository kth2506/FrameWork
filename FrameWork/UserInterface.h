#pragma once
#include "Headers.h"

class UserInterface
{
protected:
	Transform TransInfo;
	string strKey;
	int count;

	vector<char*> TextureList;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	string GetKey() const { return strKey; }

public:
	UserInterface();
	UserInterface(Transform _Info);
	virtual ~UserInterface();
};

