#include "Cloud.h"

Cloud::Cloud(){}
Cloud::Cloud(Transform _Info){}
Cloud::~Cloud(){}

void Cloud::Initialize()
{
	strKey = "Cloud";


	TransInfo.Position = Vector3(80.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
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

