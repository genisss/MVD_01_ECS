#include "GraphicsSystem.h"

void GraphicsSystem::init() {

}

void GraphicsSystem::update(float dt) {

}

void GraphicsSystem::createPlaneGeometry(GLuint& vao, GLuint& num_tris) {
	//create buffers
	const GLfloat position_buffer_data[] = {
		-0.5f, -0.5f, 0.0f, // 0
		0.5f, -0.5f, 0.0f, //1
		0.5f, 1.0f, 0.0f, //2
		-0.5, 0.5f, 0.0f
	};

	const GLfloat texture_buffer_data[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0
	};

	const GLuint index_buffer_data[] = {
		0,1,2,
		0,2,3
	};


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//create and bind Vertex Buffer Objects (VBO) to store data on GPU
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(position_buffer_data),
		position_buffer_data,
		GL_STATIC_DRAW);

	//tell OpenGL that this vertex array should have attribute id of '0' in shader
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, //attribute 0
		3, //compomnents (x,y,z)
		GL_FLOAT,
		GL_FALSE, 0, 0);

	// textures
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(texture_buffer_data),
		texture_buffer_data,
		GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,
		2,
		GL_FLOAT,
		GL_FALSE, 0, 0);

	//do the same for the index buffer
	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(index_buffer_data),
		index_buffer_data,
		GL_STATIC_DRAW);

	num_tris = 2;
}

int GraphicsSystem::loadShader(std::string name, std::string vs_path, std::string fs_path) {
	//We'll store the shader in un undordered Map
	//shaders_[name] = new Shader(vs_path, fs_path);
	//rturn opengl reference to shader (int)
	//return shaders_[name]->program;
	return 0;
}