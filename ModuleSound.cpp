#include "ModuleSound.h"
#include "SDL_mixer/include/SDL_mixer.h"
//#include "Application.h"
//#include "Game.h"


#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


ModuleSound::ModuleSound()
{
	for (int i = 0; i < MAX_SOUNDS; i++)
		sounds[i] = nullptr;
}


ModuleSound::~ModuleSound()
{
}

bool ModuleSound::Init() {
	//int flags = MIX_INIT_OGG;
	int init = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 4, 4096);
	bool ret = true;
	if (init < 0)
	{
		LOG("Could not initialize Sound lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}
	return ret;
}

update_status ModuleSound::PreUpdate() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleSound::Update() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleSound::PostUpdate() {
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSound::CleanUp() {
	LOG("Freeing sounds and Sound library");

	for (int i = 0; i < MAX_SOUNDS; i++)
	{
		if (sounds[i] != nullptr)
			Mix_FreeChunk(sounds[i]);
	}

	Mix_Quit();
	return true;
}

Mix_Chunk* ModuleSound::Load(const char* path) {
	Mix_Chunk* sound = Mix_LoadWAV(path);
	if (sound == nullptr)
	{
		LOG("\nCould not load sound correctly! MIX_Error: %s", Mix_GetError());
		return nullptr;
	}

	sounds[last_sound] = sound;

	for (int i = 0; i < MAX_SOUNDS; i++) {
		if (sounds[i] != nullptr)
			continue;
		else {
			last_sound = i;
			break;
		}
	}

	return sound;
}

Mix_Music* ModuleSound::LoadMusic(const char* path) {
	Mix_Music* mus = Mix_LoadMUS(path);

	if (mus == nullptr)
	{
		return nullptr;
	}
	else return mus;
}