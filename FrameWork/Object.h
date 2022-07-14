#pragma once
#include "Headers.h"

class Bridge;
class ItemBridge;
class Object
{
protected:
	Transform TransInfo;
	string strKey;
	char* Buffer[3];
	int Color = 15;
	int Hp;
	float as;
	float attackSpeed;
	Bridge* pBridge;
public:
	virtual Object* Initialize(string _Key)PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;
	
public:
	int GetHp() { return Hp; }
	void SetHp() { --Hp; }
	string GetKey() const { return strKey; }

	Vector3 GetPosition() const	{ return TransInfo.Position; }
	void SetPosition(float _x, float _y)	{ TransInfo.Position = Vector3(_x, _y); }
	void SetPosition(Vector3 _Position)	{ TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetScale(float _x, float _y)	{ TransInfo.Scale = Vector3(_x, _y); }	
	void SetScale(Vector3 _Scale) { TransInfo.Scale = _Scale; }

	Vector3 GetDirection() const { return TransInfo.Direction; }
	void SetDirection(float _x, float _y) { TransInfo.Direction = Vector3(_x, _y); }
	void SetDirection(Vector3 _Direction) { TransInfo.Direction = _Direction; }

	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
	Bridge* GetBridge() { return pBridge; }
	void IncreseAttackSpeed() { as += 0.1f; }

public:
	Object();
	Object(Transform _Info);
	virtual ~Object();
};

