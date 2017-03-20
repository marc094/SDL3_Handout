#include "Camera.h"
#include "Globals.h"
#include "SDL\include\SDL.h"



Camera::Camera()
{
	_viewPort = new SDL_Rect{ 0, (1863 - SCREEN_HEIGHT) * SCALING_FACTOR, SCREEN_WIDTH * SCALING_FACTOR, SCREEN_HEIGHT * SCALING_FACTOR };
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