#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow * window, int width, int height);
void processInput(GLFWwindow * window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// glfw : initialize and configure
	// --------------------------------

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

# ifndef __APPLE__
	// 如果是 苹果电脑 需要加上这句话 兼容
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
# endif

	// glfw window creation 
	// --------------------
	GLFWwindow * window = glfwCreateWindow(SCR_WIDTH ,SCR_HEIGHT,"Hello Mr.chen", NULL, NULL);
	if (NULL == window)
	{
		std::cout << "Failed to create GLFW window " << std::endl;
		glfwTerminate( );
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad : load all OpenGL function pointers  传入 OpenGL 的函数指针地址
	// ----------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD " << std::endl;
		return -1;
	}

	// render loop 循环渲染
	// --------------------
	while (! glfwWindowShouldClose(window))
	{
		// input
		// ----- 
		processInput(window);

		// render 
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw : swap buffers and poll IO events (keys pressed/released, mouse moved etc .)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw : terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	
	
	//// 设置视口 
	//glViewport(0, 0, 600, 400);

	//// 设置窗口改变时的回调函数 ，原型如下 ：
	//void framebuffer_size_callback(GLFWwindow * window, int width, int height)
	//{
	//	glViewport(0, 0, width, height);
	//}

	//// 注册这个函数
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw : whether the window size changed this callback function executes
// ----------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{

	// make sure the viewport matches the new window dimensions;
	glViewport(0, 0, width, height);

}