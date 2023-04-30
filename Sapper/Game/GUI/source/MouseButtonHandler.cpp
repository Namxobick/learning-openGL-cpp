//
// Created by Андрей Юрин on 28.04.2023.
//

#include <iostream>
#include "../include/MouseButtonHandler.h"


MouseButtonHandler::MouseButtonHandler(GLFWwindow *window) {
    _window = window;
    isMouseUp = true;
}

std::optional<MouseClick> MouseButtonHandler::ProcessMouseClick() {

    glfwSetMouseButtonCallback(_window, MouseCallback);
    auto* mouseClick = static_cast<MouseClick*>(glfwGetWindowUserPointer(_window));

    if (mouseClick != nullptr and isMouseUp) {
        isMouseUp = false;
        return *mouseClick;
    }

    delete mouseClick;
    glfwSetWindowUserPointer(_window, nullptr);
    isMouseUp = true;
    return std::nullopt;
}

void MouseButtonHandler::MouseCallback(GLFWwindow *window, int button, int action, int mods) {
    double x , y;
    glfwGetCursorPos(window, &x, &y);

    if (button == GLFW_MOUSE_BUTTON_LEFT and action == GLFW_PRESS)
        glfwSetWindowUserPointer(window, new MouseClick{(float)x, (float)y, MouseButton::Left});
    else if (button == GLFW_MOUSE_BUTTON_RIGHT and action == GLFW_PRESS)
        glfwSetWindowUserPointer(window, new MouseClick{(float)x, (float)y, MouseButton::Right});

}

std::pair<float, float> MouseButtonHandler::ConvertScreenToOpenGLCoords(std::pair<float, float> coords,
                                                                        uint32_t mapHeight, uint32_t mapWidth) {
    std::pair<float, float> newCoords;
    int width = 0, height = 0;
    glfwGetWindowSize(_window, &width, &height);
    newCoords.first = coords.first / float(width) * mapWidth;
    newCoords.second = mapHeight - coords.second  / float(height) * mapHeight;
    return newCoords;
}

