//
// Created by Андрей Юрин on 27.04.2023.
//

#include "../include/Game.h"

Game::Game(uint32_t height, uint32_t width, uint32_t countMines) {
    _map = Map(height, width, countMines);
    _statusGame = StatusGame::InProgress;
}

uint32_t Game::GetHeight() const{
    return _map.GetHeight();
}

uint32_t Game::GetWidth() const{
    return _map.GetWidth();
}

uint8_t Game::GetCountMinesAround(uint32_t x, uint32_t y) const{
    return _map.GetCountMinesAround(x, y);
}

bool Game::IsOpenCell(uint32_t x, uint32_t y) const{
    return _map.IsOpenedCell(x, y);
}

bool Game::IsMineCell(uint32_t x, uint32_t y) const{
    return _map.IsMineCell(x, y);
}

bool Game::IsFlagCell(uint32_t x, uint32_t y) const{
    return _map.isFlagCell(x, y);
}

void Game::TryOpenCells(uint32_t x, uint32_t y) {
    if (_map.isFlagCell(x, y))
        return;

    OpenCellAndAdjacentCells(x, y);

    if (_map.IsMineCell(x, y))
        _statusGame = StatusGame::Lose;

    if (_map.GetCountClosedCell() == _map.GetCountMines())
        _statusGame = StatusGame::Win;
}

void Game::TrySwitchIsFlagCell(uint32_t x, uint32_t y) {
    if (!_map.IsOpenedCell(x, y))
        _map.SwitchIsFlagCell(x, y);
}

void Game::OpenCellAndAdjacentCells(uint32_t x, uint32_t y) {
    if (!_map.IsCoordinateCorrect(x, y) or _map.IsOpenedCell(x, y))
        return;
    _map.OpenCell(x, y);
    if (_map.GetCountMinesAround(x, y) == 0)
        for (int dx = -1; dx < 2; dx++)
            for (int dy = -1; dy < 2; dy++)
                OpenCellAndAdjacentCells(x + dx, y + dy);
}

StatusGame Game::GetStatus() const{
    return _statusGame;
}

void Game::OpenAllCell() {
    _map.OpenAllCel();
}

void Game::Restart() {
    _map = Map(_map.GetHeight(), _map.GetWidth(), _map.GetCountMines());
    _statusGame = StatusGame::InProgress;
}
