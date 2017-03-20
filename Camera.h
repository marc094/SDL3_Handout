#ifndef __Camera_H__
#define __Camera_H__

struct SDL_Rect;
class Camera
{
public:
	SDL_Rect *_viewPort;
	void Scroll(int x, int y);
	Camera();
	~Camera();
};

#endif // __Camera_H__