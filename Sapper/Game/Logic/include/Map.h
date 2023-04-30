//
// Created by Андрей Юрин on 27.04.2023.
//
#ifndef LEARNING_OPENGL_MAP_H
#define LEARNING_OPENGL_MAP_H


#include <cstdint>
#include <random>
#include <vector>
#include "Cell.h"

class Map {
private:
    uint32_t _height;
    uint32_t _width;
    uint32_t _countMines;
    uint32_t  _countClosedCell;
    std::vector<std::vector<Cell>> _cells;

public:
    explicit Map(uint32_t height = 10, uint32_t width = 10, uint32_t countMines = 20);
    [[nodiscard]] uint32_t GetHeight() const;
    [[nodiscard]] uint32_t GetWidth() const;
    [[nodiscard]] uint32_t GetCountMines() const;
    [[nodiscard]] uint32_t GetCountClosedCell() const;
    [[nodiscard]] uint8_t GetCountMinesAround(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool IsOpenedCell(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool IsMineCell(uint32_t x, uint32_t y) const;
    [[nodiscard]] bool isFlagCell(uint32_t x, uint32_t y) const;
    void OpenCell(uint32_t x, uint32_t y);
    void OpenAllCel();
    void SwitchIsFlagCell(uint32_t x, uint32_t y);
    [[nodiscard]] bool IsCoordinateCorrect(int64_t x, int64_t y) const;

private:
    void GenerateMines();
    void AddMineInfoNeighboringCell(uint32_t x, uint32_t y);
};


#endif //LEARNING_OPENGL_MAP_H
