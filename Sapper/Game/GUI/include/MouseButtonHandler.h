//
// Created by Андрей Юрин on 28.04.2023.
//

#ifndef LEARNING_OPENGL_MOUSEBUTTONHANDLER_H
#define LEARNING_OPENGL_MOUSEBUTTONHANDLER_H


#include <utility>
#include "../../../directories/glfw/3.3.8/glfw3.h"

enum class MouseButton{
    None,
    Left,
    Right
};

struct MouseClick{
    float x;
    float y;
    MouseButton mouseButton;
};

class MouseButtonHandler {
private:
    GLFWwindow* _window{};
    bool isMouseUp;
public:
    MouseButtonHandler() = default;
    explicit MouseButtonHandler(GLFWwindow* window);
    std::optional<MouseClick> ProcessMouseClick();
    std::pair<float, float> ConvertScreenToOpenGLCoords(std::pair<float, float> coords,
                                                        uint32_t mapHeight, uint32_t mapWidth);
private:
    static void MouseCallback(GLFWwindow* window, int button, int action, int mods);
};


#endif //LEARNING_OPENGL_MOUSEBUTTONHANDLER_H
