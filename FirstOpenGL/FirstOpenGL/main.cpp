#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// ��ʼ��glfw����
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//ָ��OpenGL���汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//ָ��OpenGL�Ӱ汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//ʹ��OpenGL�ĺ���ģʽ

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);//��������
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();//���������ֹ����
		return -1;
	}
	glfwMakeContextCurrent(window);//�����ڵ������Ļ�������Ϊ��ǰ���̵߳������Ļ���
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//ע�ᴰ�ڻص�����

	// glad: load all OpenGL function pointers  ��ʼ��glad
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop ѭ����Ⱦ
	// -----------
	while (!glfwWindowShouldClose(window))//����Ƿ�رմ���
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(1, 1, 0, 1.0f);//����������ɫ
		glClear(GL_COLOR_BUFFER_BIT);//����

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);//����ʾ������������潻��
		glfwPollEvents();//����Ƿ����¼�����
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();//��ֹ����
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//���Esc����û�а���
		glfwSetWindowShouldClose(window, true);//���ô��ڹر�
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);//����OpenGL�ӿڴ�С
}