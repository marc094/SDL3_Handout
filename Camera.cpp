#include "Camera.h"
#include "SDL\include\SDL.h"



Camera::Camera()
{
}


Camera::~Camera()
{

	delete _viewPort;
}


void Camera::Scroll(int x, int y)
{
	_viewPort->x += x;
	_viewPort->y += y;
}

SDL_Rect Camera::getCameraRect()
{
	return *_viewPort;
}