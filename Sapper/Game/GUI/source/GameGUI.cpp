//
// Created by Андрей Юрин on 27.04.2023.
//

#include <iostream>
#include "../include/GameGUI.h"

GameGUI::GameGUI(GLFWwindow* window, Game game) {
    _window = window;
    _game = std::move(game);
    _cellGui = CellGUI();
    _mineGui = MineGUI();
    _flagGui = FlagGUI();
    _mouseButtonHandler = MouseButtonHandler(_window);

}

void GameGUI::RenderGame() {
    glLoadIdentity();
    glScalef(2.0f / _game.GetWidth(), 2.f / _game.GetHeight(), 1);
    glTranslatef( _game.GetWidth() * (-0.5), _game.GetHeight() * (-0.5), 0);
    RenderCells(_game.GetHeight(), _game.GetWidth());

    switch (_game.GetStatus()){
        case StatusGame::InProgress:
            RenderProgressGame();
            break;
        case StatusGame::Lose:
            RenderLosingGame();
            break;
        case StatusGame::Win:
            RenderWiningGame();
            break;
    }
}

void GameGUI::RenderProgressGame() {
    auto optionalMouseClick = _mouseButtonHandler.ProcessMouseClick();

    if (!optionalMouseClick.has_value())
        return;

    auto coords = _mouseButtonHandler.ConvertScreenToOpenGLCoords(
            {optionalMouseClick->x, optionalMouseClick->y},
            _game.GetWidth(),
            _game.GetWidth());

    switch (optionalMouseClick->mouseButton) {
        case MouseButton::None:
            break;
        case MouseButton::Left:
            _game.TryOpenCells((int) coords.first, (int) coords.second);
            break;
        case MouseButton::Right:
            _game.TrySwitchIsFlagCell((int) coords.first, (int) coords.second);
            break;
    }
}

void GameGUI::RenderLosingGame() {
    _game.OpenAllCell();
    auto optionalMouseClick = _mouseButtonHandler.ProcessMouseClick();
    if (optionalMouseClick.has_value())
        Restart();
}

void GameGUI::RenderWiningGame() {
    Restart();
}

void GameGUI::RenderCells(uint32_t height, uint32_t width) {
    for (uint32_t i = 0; i < height; ++i)
        for (uint32_t j = 0; j < width; ++j) {
            glPushMatrix();
            glTranslatef(i, j, 0);
            RenderCell(i, j);
            glPopMatrix();
        }
}

void GameGUI::RenderCell(uint32_t x, uint32_t y) {

    if (_game.IsOpenCell(x, y))
        RenderOpenedCell(x, y);
    else
        RenderClosedCell(x, y);
}

void GameGUI::RenderOpenedCell(uint32_t x, uint32_t y) {
    _cellGui.RenderOpenedCell();

    if (_game.IsMineCell(x, y))
        _mineGui.RenderMine();
    else if (_game.GetCountMinesAround(x, y) > 0)
        _numberDrawer.RenderNumber(_game.GetCountMinesAround(x, y));
}

void GameGUI::RenderClosedCell(uint32_t x, uint32_t y) {
    _cellGui.RenderClosedCell();

    if (_game.IsFlagCell(x, y))
        _flagGui.RenderFlag();
}

void GameGUI::Restart() {
    _game.Restart();
}
