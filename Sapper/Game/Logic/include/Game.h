//
// Created by Андрей Юрин on 27.04.2023.
//

#ifndef LEARNING_OPENGL_GAME_H
#define LEARNING_OPENGL_GAME_H


#include "Map.h"

enum class StatusGame{
    InProgress,
    Lose,
    Win
};

class Game {
private:
    Map _map;
    StatusGame _statusGame;
public:
    explicit Game(uint32_t height = 10, uint32_t width = 10, uint32_t countMines = 20);
    [[nodiscard]] uint32_t GetHeight() const;
    [[nodiscard]] uint32_t GetWidth() const;
    [[nodiscard]] uint8_t GetCountMinesAround(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool IsOpenCell(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool IsMineCell(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool IsFlagCell(uint32_t x, uint32_t y) const;
    void TryOpenCells(uint32_t x, uint32_t y);
    void TrySwitchIsFlagCell(uint32_t x, uint32_t y);
    [[nodiscard]] StatusGame GetStatus() const;
    void OpenAllCell();
    void Restart();

private:
    void OpenCellAndAdjacentCells(uint32_t x, uint32_t y);
};


#endif //LEARNING_OPENGL_GAME_H
