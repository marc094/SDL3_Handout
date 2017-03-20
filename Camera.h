#ifndef __Camera_H__
#define __Camera_H__
struct SDL_Rect;
class Camera
{
private:
	SDL_Rect *_viewPort;
public:
	void Scroll(int x, int y);
	SDL_Rect getCameraRect();
	Camera();
	~Camera();
};

#endif // __Camera_H__