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
	// 初始化glfw窗口
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//指定OpenGL主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//指定OpenGL子版本号
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//使用OpenGL的核心模式

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);//创建窗口
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();//如果出错，终止进程
		return -1;
	}
	glfwMakeContextCurrent(window);//将窗口的上下文环境设置为当前主线程的上下文环境
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册窗口回调函数

	// glad: load all OpenGL function pointers  初始化glad
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop 循环渲染
	// -----------
	while (!glfwWindowShouldClose(window))//检测是否关闭窗口
	{
		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(1, 1, 0, 1.0f);//设置清屏颜色
		glClear(GL_COLOR_BUFFER_BIT);//清屏

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);//将显示缓存和离屏缓存交换
		glfwPollEvents();//检查是否有事件触发
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();//终止进程
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//检查Esc键有没有按下
		glfwSetWindowShouldClose(window, true);//设置窗口关闭
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);//调整OpenGL视口大小
}