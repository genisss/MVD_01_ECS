#include "Game.h"
#include "extern.h"
#include "Shader.h"
#include "Texture.h"

void Game::init() {

	//******** INITIALISATION CODE **********//

	graphics_system_.init();
    
	//set 'background' colour of framebuffer
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	graphics_system_.createPlaneGeometry(temp_vao, temp_tris);
	temp_program = graphics_system_.loadShader("phong", "data/shaders/phong.vert", "data/shaders/phong.frag");
}

//Entry point for game update code
void Game::update(float dt) {
	graphics_system_.update(dt);
	glUseProgram(temp_program);
	glBindVertexArray(temp_vao);
	glDrawElements(GL_TRIANGLES, temp_tris, GL_UNSIGNED_INT, 0);

}

