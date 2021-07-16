// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height); //Callback function prototype declaration
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char *argv[])
{

    //Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    //Create a window object
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "FirstGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Notify GLFW to set the context of our window as the main context of the current thread
    glfwMakeContextCurrent(window);
    //Register a callback function for the window. Whenever the window changes size, GLFW will call this function and fill in the corresponding parameters for you to deal with
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //Initialize the function pointer used by GLAD to manage OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //Rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // Rendering instructions
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call the event, exchange buffer
        glfwSwapBuffers(window); //Check the trigger event
        glfwPollEvents();        //Exchange color buffer
    }

    //Release/delete all resources allocated before
    glfwTerminate();
    return EXIT_SUCCESS;
}

//Input control, check if the user presses the return key (Esc)
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// When the user changes the size of the window, the viewport should also be adjusted
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // Note: For Retina display, the width and height will be significantly higher than the original input value.
    glViewport(0, 0, width, height);
}
