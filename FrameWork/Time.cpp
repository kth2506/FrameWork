#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"
#include "CursorManager.h"
#include "InputManager.h"
Time::Time() : Minutes(0), Second(0) , count(0) {}
Time::Time(Transform _Info) {}
Time::~Time() {}

void Time::Initialize()
{

	strKey = "Time";

	Minutes = 10;
	Second = 0;
	count = 0;
	
	vector<char*> Zero;
	Zero.push_back((char*)"   _|   ");
	Zero.push_back((char*)" _|  _| ");
	Zero.push_back((char*)" _|  _| ");
	Zero.push_back((char*)" _|  _| ");
	Zero.push_back((char*)"   _|   ");
	vector<char*> One;
	One.push_back((char*)"   _|  ");
	One.push_back((char*)" _|_|  ");
	One.push_back((char*)"   _|  ");
	One.push_back((char*)"   _|  ");
	One.push_back((char*)"   _|  ");
	vector<char*> Two;
	Two.push_back((char*)"   _|_|  ");
	Two.push_back((char*)" _|    _|");
	Two.push_back((char*)"     _|  ");
	Two.push_back((char*)"   _|    ");
	Two.push_back((char*)" _|_|_|_|");
	vector<char*> Three;
	Three.push_back((char*)"  _|_|_| ");
	Three.push_back((char*)"       _|");
	Three.push_back((char*)"   _|_|  ");
	Three.push_back((char*)"       _|");
	Three.push_back((char*)"  _|_|_| ");
	vector<char*> Four;
	Four.push_back((char*)" _|  _|  ");
	Four.push_back((char*)" _|  _|  ");
	Four.push_back((char*)" _|_|_|_|");
	Four.push_back((char*)"     _|  ");
	Four.push_back((char*)"     _|  ");
	vector<char*> Five;
	Five.push_back((char*)"  _|_|_| ");
	Five.push_back((char*)" _|      ");
	Five.push_back((char*)" _|_|_|  ");
	Five.push_back((char*)"       _|");
	Five.push_back((char*)" _|_|_|  ");
	vector<char*> Six;
	Six.push_back((char*)"  _|_|_| ");
	Six.push_back((char*)" _|      ");
	Six.push_back((char*)" _|_|_|  ");
	Six.push_back((char*)" _|    _|");
	Six.push_back((char*)"   _|_|  ");
	vector<char*> Seven;
	Seven.push_back((char*)" _|_|_|_|");
	Seven.push_back((char*)"      _| ");
	Seven.push_back((char*)"     _|  ");
	Seven.push_back((char*)"    _|   ");
	Seven.push_back((char*)"  _|     ");
	vector<char*> Eight;
	Eight.push_back((char*)"   _|_|  ");
	Eight.push_back((char*)" _|    _|");
	Eight.push_back((char*)"   _|_|  ");
	Eight.push_back((char*)" _|    _|");
	Eight.push_back((char*)"   _|_|  ");
	vector<char*> Nine;
	Nine.push_back((char*)"   _|_|  ");
	Nine.push_back((char*)" _|    _|");
	Nine.push_back((char*)"   _|_|_|");
	Nine.push_back((char*)"       _|");
	Nine.push_back((char*)"  _|_|_| ");
	MS.insert(make_pair(0,  Zero));
	MS.insert(make_pair(1,  One));
	MS.insert(make_pair(2,  Two));
	MS.insert(make_pair(3,  Three));
	MS.insert(make_pair(4,  Four));
	MS.insert(make_pair(5,  Five));
	MS.insert(make_pair(6,  Six));
	MS.insert(make_pair(7,  Seven));
	MS.insert(make_pair(8,  Eight));
	MS.insert(make_pair(9,  Nine));
}

int Time::Update()
{
	count++;
	if (count % 14 == 0)
	{
		Second--;
	}

	if (Second == -1)
	{
		Minutes--;
		Second = 9;
	}

	return 0;
}

void Time::Render()
{

	if (Second < 10 && Minutes < 10)
	{
		for (int i = 0; i < 5; ++i)
		{
			CursorManager::
				GetInstance()->WriteBuffer(80.0f, 1.0f + i, MS.find(Minutes)->second[i], 3);
			CursorManager::
				GetInstance()->WriteBuffer(91.0f, 1.0f + i, MS.find(Second)->second[i], 3);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(0.0f, 7.0f,
		(char*)"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");


}

void Time::Release()
{
}
