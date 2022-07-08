#include "Cloud.h"

Cloud::Cloud(){}
Cloud::Cloud(Transform _Info){}
Cloud::~Cloud(){}

Object* Cloud::Initialize(string _Key)
{
	strKey = _Key;


	TransInfo.Position = Vector3(80.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	return this;
}

int Cloud::Update()
{
	return 0;
}

void Cloud::Render()
{
}

void Cloud::Release()
{
}

