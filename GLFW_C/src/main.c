#include <GL/glew.h>     // GLEW must be included first
#include <GLFW/glfw3.h>   // Then include GLFW
#include <GL/gl.h>        // OpenGL headers (or use gl3.h if you're targeting modern OpenGL)
#include <stdio.h>






int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow *window = glfwCreateWindow(600, 600, "GLFW_C Window", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // OpenGL version info
    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Set the background color (clear the screen)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
        //glDrawPixels(100, 100, );
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
