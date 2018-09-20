#include "SpecialBrick.h"





bool SpecialBrick::IsDestroyed()
{
	//return isDestroyed;
	return false;
}

void SpecialBrick::Destroy()
{
	
	IfDestroyed = true;
	

}

SpecialBrick::~SpecialBrick()
{
}
