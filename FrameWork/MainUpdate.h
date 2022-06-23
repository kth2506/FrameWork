#pragma once
class MainUpdate
{
private:
	int Count = 0;
	SCENEID state;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();

public:
	MainUpdate();
	~MainUpdate();

};

