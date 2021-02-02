#include<iostream>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "Shader.h"


// ��ESC���رմ���
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

float vertices[] = {
	-0.5f, -0.5f, 0.0f,		1.0f, 0, 0,		// 0
	0.5f, -0.5f, 0.0f,		0, 0, 1.0f,		// 1
	0.0f,  0.5f, 0.0f,		0, 1.0f ,0,		// 2
	1.0f, 0.5f, 0.0f,		1.0f,0,1.0f		// 3
};

unsigned int indices[] = { 0,1,2,
							2,3,1 };


int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// ��GLFW����
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		printf("Open window failed.");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Init GLFW
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("Init Glew failed");
		glfwTerminate();
		return -1;
	}

	// ���ô��ڳߴ�
	glViewport(0, 0, 800, 600);
	// ֻ������
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// �涨ֻ���������ֻ������
	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_FRONT);

	// �Զ�����ɫ������
	Shader *myShader = new Shader("vertexSource.txt", "fragmentSource.txt");
	myShader->use();

	// �½�VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// �½�VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// �½�EBO
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



	// �����������ķ���
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// ������Ⱦ
	while (!glfwWindowShouldClose(window))
	{
		// ���������¼�
		processInput(window);

		// ����ɫ
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}