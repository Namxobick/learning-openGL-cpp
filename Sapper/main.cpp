#include <iostream>
#include "directories/glew/2.2.0_1/glew.h"
#include "directories/glfw/3.3.8/glfw3.h"
#include "Game/Logic/include/Game.h"
#include "Game/GUI/include/GameGUI.h"


int main()
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(500, 500, "Test", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << glGetString(GL_VERSION) << std::endl;

    Game game = Game();
    GameGUI gameGui = GameGUI(window, game);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        gameGui.RenderGame();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
