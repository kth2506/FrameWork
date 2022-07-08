#pragma once
#include "Headers.h"
#include "CursorManager.h"

class MathManager
{
public:

	static float GetDistance(Vector3 _Current, Vector3 _Target)
	{
		float Width = _Target.x - _Current.x;
		float Height = _Target.y - _Current.y;
		
		
		return sqrt((Width * Width) + (Height * Height));
	}

	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{

		float Width = _Target.x - _Current.x;
		float Height = _Target.y - _Current.y;

		float Distance = sqrt((Width * Width) + (Height * Height));
		
		return Vector3(Width / Distance, Height / Distance);
	}


	static float GetCursorDistance(Vector3 _Current)
	{
		Vector3 _Target = CursorManager::GetInstance()->GetVector();
		float Width = _Target.x - _Current.x;
		float Height = _Target.y - _Current.y;


		return sqrt((Width * Width) + (Height * Height));
	}

	static Vector3 GetCursorDirection(Vector3 _Current)
	{
		Vector3 _Target = CursorManager::GetInstance()->GetVector();

		float Width = _Target.x - _Current.x;
		float Height = _Target.y - _Current.y;

		float Distance = sqrt((Width * Width) + (Height * Height));

		return Vector3(Width / Distance, Height / Distance);
	}

};

