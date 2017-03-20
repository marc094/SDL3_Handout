#include "Globals.h"
#include "Application.h"
#include "SDL\include\SDL.h"
#include "Game.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleSound.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "Camera.h"


Game::Game()
{
}


Game::~Game()
{
}


bool Game::Init() {
	bool ret = true;

	_bgm = App->sound->LoadMusic("Game/3-Hintergrundmusik1.wav");
	if (_bgm == nullptr)
		ret = false;
	else Mix_PlayMusic(_bgm, -1);

	_background_texture = App->textures->Load("Game/map1.png");
	if (_background_texture == nullptr)
		ret = false;

	_bgRect = new SDL_Rect{ 0, 0, 203 * SCALING_FACTOR, 1863 * SCALING_FACTOR };
	_mainCameraCafe = new Camera();

	return ret;
}

update_status Game::PreUpdate() {
	if (App->input->keyboard != nullptr) {
		if (App->input->keyboard[SDL_SCANCODE_W]) {
			_mainCameraCafe->Scroll(0, -5);
		}
		if (App->input->keyboard[SDL_SCANCODE_S]) {
			_mainCameraCafe->Scroll(0, +5);
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status Game::Update() {
	int world_camera_X = _mainCameraCafe->_viewPort->x,
		world_camera_Y = _mainCameraCafe->_viewPort->y;


	bool blit_ok = App->render->Blit(_background_texture, _bgRect->x - world_camera_X, _bgRect->y - world_camera_Y, _bgRect);
	update_status ret = update_status::UPDATE_CONTINUE;

	if (blit_ok == false) {
		ret = update_status::UPDATE_ERROR;
	}
	return ret;
}

update_status Game::PostUpdate() {
	return update_status::UPDATE_CONTINUE;
}

bool Game::CleanUp() {
	delete _bgRect;
	delete _mainCameraCafe;
	return true;
}