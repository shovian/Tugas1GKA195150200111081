#include "Demo.h"



Demo::Demo() {

}


Demo::~Demo() {
}



void Demo::Init() {
	// build and compile our shader program-
	// ------------------------------------
	shaderProgram = BuildShader("Cube.vert", "Cube.frag", nullptr);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// position ------- color atas
		-0.5f,  0.5f, 0.5f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.5f, 0.5f, 0.5f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl
		
		-0.5f,  0.4f, 0.5f, 0.0f, 1.0f, 0.0f,  // front top left 1 fbl
		0.5f, 0.4f, 0.5f,  0.0f, 1.0f, 0.0f,   // front top right 3 fbr
		0.5f, 0.4f, -0.5f, 0.0f, 1.0f, 0.0f,   // back top right 5 bbr
		-0.5f,  0.4f, -0.5f, 0.0f, 1.0f, 0.0f, // back top left 7 bbl

		//============================================================ bawah
		-0.5f,  0.2f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.5f, 0.2f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.5f, 0.2f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.5f,  0.2f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		-0.5f,  0.1f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		0.5f, 0.1f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		0.5f, 0.1f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		-0.5f,  0.1f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================kiri
		-0.5f,  0.4f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		-0.4f, 0.4f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		-0.4f, 0.4f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.5f,  0.4f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		-0.5f,  0.2f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		-0.4f, 0.2f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		-0.4f, 0.2f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		-0.5f,  0.2f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ kanan
		0.4f,  0.4f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.5f, 0.4f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.5f, 0.4f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		0.4f,  0.4f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		0.4f,  0.2f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		0.5f, 0.2f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		0.5f, 0.2f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		0.4f,  0.2f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ sekat
		-0.05f,  0.4f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.05f, 0.4f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.05f, 0.4f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.05f,  0.4f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		-0.05f,  0.2f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		0.05f, 0.2f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		0.05f, 0.2f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		-0.05f,  0.2f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ kaki
		0.4f,  0.2f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.5f, 0.2f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.5f, 0.2f, 0.3f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		0.4f,  0.2f, 0.3f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		0.4f,  -0.5f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		0.5f, -0.5f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		0.5f, -0.5f, 0.3f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		0.4f,  -0.5f, 0.3f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ kaki
		-0.5f,  0.2f, 0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		-0.4f, 0.2f, 0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		-0.4f, 0.2f, 0.3f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.5f,  0.2f, 0.3f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		-0.5f,  -0.5f, 0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		-0.4f, -0.5f, 0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		-0.4f, -0.5f, 0.3f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		-0.5f,  -0.5f, 0.3f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ kaki2
		0.4f,  0.2f, -0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		0.5f, 0.2f, -0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		0.5f, 0.2f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		0.4f,  0.2f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		0.4f,  -0.5f, -0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		0.5f, -0.5f, -0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		0.4f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================ kaki2
		-0.5f,  0.2f, -0.4f, 1.0f, 0.0f, 0.0f,  // front top left 0 ftl
		-0.4f, 0.2f, -0.4f,  1.0f, 0.0f, 0.0f,   // front top right 2 ftr
		-0.4f, 0.2f, -0.5f, 1.0f, 0.0f, 0.0f,   // back top right 4 btr
		-0.5f,  0.2f, -0.5f, 1.0f, 0.0f, 0.0f, // back top left 6 btl

		-0.5f,  -0.5f, -0.4f, 0.0f, 1.0f, 0.0f,  // front bottom left 1 fbl
		-0.4f, -0.5f, -0.4f,  0.0f, 1.0f, 0.0f,   // front bottom right 3 fbr
		-0.4f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // back bottom right 5 bbr
		-0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // back bottom left 7 bbl
		//============================================================

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, // front bottom left 4
		0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f, // front bottom right 5
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // back bottom right 6
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f // back bottom left 7 
	};
	unsigned int indices[] = {  // note that we start from 0!
		//0,1,2,
		//2,1,3, //front
		//0,2,6,
		//6,2,4
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define color pointer layout 1
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void Demo::DeInit() {
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Demo::Update(double deltaTime) {

}

void Demo::Render() {
	// render
	// ------
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	// draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(this->shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view = glm::lookAt(glm::vec3(0, 1, 2), glm::vec3(0, 0, 0), glm::vec3(0.0f, 1.0f, 0.0f));
	GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	glDrawElements(GL_TRIANGLES, 252+72, GL_UNSIGNED_INT, 0);
	// glBindVertexArray(0); // no need to unbind it every time
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Demo::ProcessInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(int argc, char** argv) {
	RenderEngine &app = Demo();
	app.Start("Primitive: Draw a Cube using Triangles", 800, 600, true, false);
}