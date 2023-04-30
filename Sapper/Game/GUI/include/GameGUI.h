//
// Created by Андрей Юрин on 27.04.2023.
//

#ifndef LEARNING_OPENGL_GAMEGUI_H
#define LEARNING_OPENGL_GAMEGUI_H

#include <utility>
#include "CellGUI.h"
#include "MineGUI.h"
#include "../../Logic/include/Game.h"
#include "NumberDrawer.h"
#include "../../../directories/glfw/3.3.8/glfw3.h"
#include "MouseButtonHandler.h"
#include "FlagGUI.h"

class GameGUI {
private:
    GLFWwindow* _window;
    Game _game;
    MouseButtonHandler _mouseButtonHandler;
    CellGUI _cellGui;
    MineGUI _mineGui;
    FlagGUI _flagGui;
    NumberDrawer _numberDrawer;

public:
    GameGUI(GLFWwindow* window, Game game);
    void RenderGame();

private:
    void RenderProgressGame();
    void RenderLosingGame();
    void RenderWiningGame();
    void Restart();
    void RenderCells(uint32_t height, uint32_t width);
    void RenderCell(uint32_t x, uint32_t y);
    void RenderOpenedCell(uint32_t x, uint32_t y);
    void RenderClosedCell(uint32_t x, uint32_t y);
};


#endif //LEARNING_OPENGL_GAMEGUI_H
