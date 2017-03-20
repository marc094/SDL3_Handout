#ifndef __GAME_H__
#define __GAME_H__
#include "Module.h"

struct SDL_Texture;
class Camera;
struct SDL_Rect;
class _Mix_Music;
typedef _Mix_Music Mix_Music;
class Game :
	public Module
{
private:
	Mix_Music* _bgm;
	SDL_Texture *_background_texture;
	SDL_Rect *_bgRect;
	Camera *_mainCameraCafe;
public:
	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	Game();
	~Game();
};

#endif // __GAME_H__