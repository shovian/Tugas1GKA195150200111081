#include "Demo.h"
// Nama  :Muhammad Shovian Hadi Al Baihaqy
// NIM   :195150200111081


Demo::Demo() {

}


Demo::~Demo() {
}



void Demo::Init() {
	// build and compile our shader program*
	// ------------------------------------
	shaderProgram = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);

	BuildColoredCube();

	BuildColoredPlane();
}

void Demo::DeInit() {
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteBuffers(1, &EBO2);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Demo::ProcessInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Demo::Update(double deltaTime) {

}

void Demo::Render() {
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(this->shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view = glm::lookAt(glm::vec3(0, 3, 8), glm::vec3(0, 0, 0), glm::vec3(0.0f, 1.0f, 0.0f));
	GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	DrawColoredCube();

	DrawColoredPlane();

	glDisable(GL_DEPTH_TEST);
}

void Demo::BuildColoredCube() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("crate.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// 
		-0.5,  0.5, 0.5, 0, 1,
		0.5, 0.5, 0.5, 1, 1,
		0.5, 0.5, -0.5, 1, 1,
		-0.5,  0.5, -0.5, 0, 1,

		-0.5,  0.4, 0.5, 0, 0,
		0.5, 0.4, 0.5, 1, 0,
		0.5, 0.4, -0.5, 1, 0,
		-0.5,  0.4, -0.5, 0, 0,

		//============================================================ bawah
		-0.5,  0.2, 0.4, 0, 1,
		0.5, 0.2, 0.4, 1, 1,
		0.5, 0.2, -0.5, 1, 1,
		-0.5,  0.2, -0.5, 0, 1,

		-0.5,  0.1, 0.4, 0, 0,
		0.5, 0.1, 0.4, 1, 0,
		0.5, 0.1, -0.5, 1, 0,
		-0.5,  0.1, -0.5, 0, 0,
		//============================================================kiri
		-0.5,  0.4, 0.4, 0, 1,
		-0.4, 0.4, 0.4, 1, 1,
		-0.4, 0.4, -0.5, 1, 1,
		-0.5,  0.4, -0.5, 0, 1,

		-0.5,  0.2, 0.4, 0, 0,
		-0.4, 0.2, 0.4, 1, 0,
		-0.4, 0.2, -0.5, 1, 0,
		-0.5,  0.2, -0.5, 0, 0,
		//============================================================ kanan
		0.4,  0.4, 0.4, 0, 1,
		0.5, 0.4, 0.4, 1, 1,
		0.5, 0.4, -0.5, 1, 1,
		0.4,  0.4, -0.5, 0, 1,

		0.4,  0.2, 0.4, 0, 0,
		0.5, 0.2, 0.4, 1, 0,
		0.5, 0.2, -0.5, 1, 0,
		0.4,  0.2, -0.5, 0, 0,
		//============================================================ sekat
		-0.05,  0.4, 0.4, 0, 1,
		0.05, 0.4, 0.4, 1, 1,
		0.05, 0.4, -0.5, 1, 1,
		-0.05,  0.4, -0.5, 0, 1,

		-0.05,  0.2, 0.4, 0, 0,
		0.05, 0.2, 0.4, 1, 0,
		0.05, 0.2, -0.5, 1, 0,
		-0.05,  0.2, -0.5, 0, 0,
		//============================================================ kaki
		0.4,  0.2, 0.4, 0, 1,
		0.5, 0.2, 0.4, 1, 1,
		0.5, 0.2, 0.3, 1, 1,
		0.4,  0.2, 0.3, 0, 1,

		0.4,  -0.5, 0.4, 0, 0,
		0.5, -0.5, 0.4, 1, 0,
		0.5, -0.5, 0.3, 1, 0,
		0.4,  -0.5, 0.3, 0, 0,
		//============================================================ kaki
		-0.5,  0.2, 0.4, 0, 1,
		-0.4, 0.2, 0.4, 1, 1,
		-0.4, 0.2, 0.3, 1, 1,
		-0.5,  0.2, 0.3, 0, 1,

		-0.5,  -0.5, 0.4, 0, 0,
		-0.4, -0.5, 0.4, 1, 0,
		-0.4, -0.5, 0.3, 1, 0,
		-0.5,  -0.5, 0.3, 0, 0,
		//============================================================ kaki2
		0.4,  0.2, -0.4, 0, 1,
		0.5, 0.2, -0.4, 1, 1,
		0.5, 0.2, -0.5, 1, 1,
		0.4,  0.2, -0.5, 0, 1,

		0.4,  -0.5, -0.4, 0, 0,
		0.5, -0.5, -0.4, 1, 0,
		0.5, -0.5, -0.5, 1, 0,
		0.4,  -0.5, -0.5, 0, 0,
		//============================================================ kaki2
		-0.5,  0.2, -0.4, 0, 1,
		-0.4, 0.2, -0.4, 1, 1,
		-0.4, 0.2, -0.5, 1, 1,
		-0.5,  0.2, -0.5, 0, 1,

		-0.5,  -0.5, -0.4, 0, 0,
		-0.4, -0.5, -0.4, 1, 0,
		-0.4, -0.5, -0.5, 1, 0,
		-0.5,  -0.5, -0.5, 0, 0,
		//============================================================

	};

	unsigned int indices[] = {
		0, 1, 2,  // Top Face
		0, 2, 3,  // --------

		4, 5, 6,   // Bottom Face
		4, 6, 7,   // -----------

		4, 5, 1,   // Front Face
		4, 1, 0,   // ----------

		7, 6, 2,   // Back Face
		7, 2, 3,   // ---------

		5, 2, 6,   // Right Face
		5, 1, 2,   // ----------

		4, 7, 3,   // Left Face
		4, 3, 0,    // ----------

		8,9,10,8,10,11,12,13,14,12,14,15,12,13,9,12,9,8,15,14,10,15,10,11,13,10,14,13,9,10,12,15,11,12,11,8,
		16,17,18,16,18,19,20,21,22,20,22,23,20,21,17,20,17,16,23,22,18,23,18,19,21,18,22,21,17,18,20,23,19,20,19,16,
		24,25,26,24,26,27,28,29,30,28,30,31,28,29,25,28,25,24,31,30,26,31,26,27,29,26,30,29,25,26,28,31,27,28,27,24,
		32,33,34,32,34,35,36,37,38,36,38,39,36,37,33,36,33,32,39,38,34,39,34,35,37,34,38,37,33,34,36,39,35,36,35,32,
		40,41,42,40,42,43,44,45,46,44,46,47,44,45,41,44,41,40,47,46,42,47,42,43,45,42,46,45,41,42,44,47,43,44,43,40,
		48,49,50,48,50,51,52,53,54,52,54,55,52,53,49,52,49,48,55,54,50,55,50,51,53,50,54,53,49,50,52,55,51,52,51,48,
		56,57,58,56,58,59,60,61,62,60,62,63,60,61,57,60,57,56,63,62,58,63,58,59,61,58,62,61,57,58,60,63,59,60,59,56,
		64,65,66,64,66,67,68,69,70,68,70,71,68,69,65,68,65,64,71,70,66,71,66,67,69,66,70,69,65,66,68,71,67,68,67,64
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::DrawColoredCube()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 324, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildColoredPlane()
{
	// Load and create a texture 
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("marble.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		// bottom
		-50.0, -0.5, -50.0,  0,  0,
		 50.0, -0.5, -50.0, 50,  0,
		 50.0, -0.5,  50.0, 50, 50,
		-50.0, -0.5,  50.0,  0, 50,


	};

	GLuint indices[] = { 0,  2,  1,  0,  3,  2 };

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}



void Demo::DrawColoredPlane()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 1);

	glBindVertexArray(VAO2); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

int main(int argc, char** argv) {
	RenderEngine &app = Demo();
	app.Start("Texture Mapping: Draw textured cube and plane", 800, 600, true, false);
}