#include "Intro.h"

Intro::Intro(){}
Intro::Intro(Transform _Info){}
Intro::~Intro(){}

void Intro::Initialize()
{
	strKey = "Intro";

	TextureList.push_back("忙式式式式式式式式式式式式式式式忖");
	for (int i = 0; i < 22; ++i)
		TextureList.push_back("弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛");
	TextureList.push_back("戌式式式式式式式式式式式式式式式戎");

	TransInfo.Position = Vector3(float(120 / 2), 5.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(14.0f, 6.0f);
}

int Intro::Update()
{
	return 0;
}

void Intro::Render()
{
}

void Intro::Release()
{
}

