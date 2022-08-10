
#include "Score.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Score::Score() {}
Score::Score(Transform _Info) {}
Score::~Score() {}

void Score::Initialize()
{
	count = 0;

	strKey = "Score";


}

int Score::Update()
{

	return 0;
}

void Score::Render()
{

	CursorManager::GetInstance()->WriteBuffer(
		0,0,0,0
	);

}

void Score::Release()
{
}
