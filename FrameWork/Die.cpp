
#include "Die.h"
#include "CursorManager.h"
#include "InputManager.h"
Die::Die() {}
Die::Die(Transform _Info) {}
Die::~Die() {}

void Die::Initialize()
{
	count = 0;

	strKey = "Die";
}

int Die::Update()
{
	return 0;
}

void Die::Render()
{

}

void Die::Release()
{
}
