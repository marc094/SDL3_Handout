#ifndef __ModuleSound_H__
#define __ModuleSound_H__

#include "Module.h"

#define MAX_SOUNDS 20

struct Mix_Chunk;
class _Mix_Music;
typedef _Mix_Music Mix_Music;

class ModuleSound :
	public Module
{
public:
	Mix_Chunk* sounds[MAX_SOUNDS];
	uint last_sound = 0;

	bool Init();
	Mix_Chunk* Load(const char* path);
	Mix_Music* LoadMusic(const char* path);
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	ModuleSound();
	~ModuleSound();
};

#endif // __ModuleSound_H__