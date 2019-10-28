#include "Game.h"
#include "extern.h"
#include "Shader.h"
#include "Texture.h"

void Game::init() {

	//******** INITIALISATION CODE **********//
    
	//set 'background' colour of framebuffer
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	//Transform& my_trans = createComponentFOR

	int my_ent = ECS.createEntity("BOB");
	ECS.createComponentForEntity<Transform>(my_ent);
}

//Entry point for game update code
void Game::update(float dt) {



}

