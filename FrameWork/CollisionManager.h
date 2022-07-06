#pragma once

#include "Headers.h"
#include "Object.h"
#include "ObjectPool.h"
#include "CursorManager.h"


class CollisionManager
{
public:
	static bool Collision(const Object* _ObjA, const Object* _ObjB)
	{
		Vector3 Position_A = _ObjA->GetPosition();
		Vector3 Position_B = _ObjB->GetPosition();

		Vector3 Scale_A = _ObjA->GetScale();
		Vector3 Scale_B = _ObjB->GetScale();

		// ** 탑뷰 (범버맨)

		//if (Position_A.x + Scale_A.x > Position_B.x &&
		//	Position_B.x + Scale_B.x > Position_A.x &&
		//	Position_A.y == Position_B.y)
		//	return true;

		// ** 횡스크롤 게임에서의 폭이 있는 게임일 경우

		//if (Position_A.x + (Scale_A.x * 0.5f) > Position_B.x - (Scale_B.x * 0.5f) &&
		//	Position_B.x + (Scale_B.x * 0.5f) > Position_A.x - (Scale_A.x * 0.5f) &&
		//	Position_B.y + (Scale_B.y * 0.5f) == Position_A.y + (Scale_A.y * 0.5f))
		//	return true;

		// ** 사이드 뷰 게임 (메이플)
		if (Position_A.x + (Scale_A.x * 0.5f) > Position_B.x - (Scale_B.x * 0.5f) &&
			Position_B.x + (Scale_B.x * 0.5f) > Position_A.x - (Scale_A.x * 0.5f) &&
			Position_A.y + (Scale_A.y * 0.5f) > Position_B.y - (Scale_B.y * 0.5f) &&
			Position_B.y + (Scale_B.y * 0.5f) > Position_A.y - (Scale_A.y * 0.5f))
			return true;

		

		return false;
	}
	
};