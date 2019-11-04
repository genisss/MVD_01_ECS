#pragma once

#include "includes.h" //openGL staff
#include "Shader.h"
#include "Components.h"
#include "Texture.h"
#include <vector>
#include <unordered_map>

class GraphicsSystem {
public:
	void init();
	void update(float dt);
	void createPlaneGeometry(GLuint& vao, GLuint& num_tris);
	int loadShader(std::string name, std::string vs_path, std::string fs_path);
	int getShaderProgram(std::string name);

private:
	unordered_map<std::string, Shader *> shaders_;
};