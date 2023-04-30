//
// Created by Андрей Юрин on 27.04.2023.
//

#include "../include/Map.h"

Map::Map(uint32_t height, uint32_t width, uint32_t countMines) {
    _height = height;
    _width = width;
    _countMines = countMines;
    _cells = std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));
    _countClosedCell = _height * _width;

    GenerateMines();
}

void Map::GenerateMines() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_x(0,int(_width) - 1);
    std::uniform_int_distribution<> dist_y(0,int(_height) - 1);


    for (uint32_t i = 0; i < _countMines; ++i) {
        uint16_t x = dist_x(gen);
        uint16_t y = dist_y(gen);

        if (_cells[x][y].IsMine()){
            i--;
        }
        else {
            _cells[x][y].SetMine();
            AddMineInfoNeighboringCell(x , y);
        }
    }
}

uint32_t Map::GetHeight() const {
    return _height;
}

uint32_t Map::GetWidth() const {
    return _width;
}

uint32_t Map::GetCountMines() const {
    return _countMines;
}

uint32_t Map::GetCountClosedCell() const {
    return _countClosedCell;
}

void Map::AddMineInfoNeighboringCell(uint32_t x, uint32_t y)  {
    for (int dx = -1; dx < 2; ++dx)
        for (int dy = -1; dy < 2; ++dy)
            if (IsCoordinateCorrect(x + dx, y + dy))
                _cells[x + dx][y + dy].ChangeCountMinesAround(1);
}

bool Map::IsCoordinateCorrect(int64_t x, int64_t y) const {
    return ((x >= 0) and (y >= 0) and (x < _width) and (y < _height));
}

uint8_t Map::GetCountMinesAround(uint32_t x, uint32_t y) const{
    return _cells[x][y].GetCountMinesAround();
}

bool Map::IsOpenedCell(uint32_t x, uint32_t y) const{
    return _cells[x][y].IsOpen();
}

bool Map::IsMineCell(uint32_t x, uint32_t y) const{
    return _cells[x][y].IsMine();
}

bool Map::isFlagCell(uint32_t x, uint32_t y) const{
    return _cells[x][y].IsFlag();
}

void Map::OpenCell(uint32_t x, uint32_t y) {
    _countClosedCell--;
    _cells[x][y].Open();
}

void Map::SwitchIsFlagCell(uint32_t x, uint32_t y){
    _cells[x][y].SwitchIsFlag();
}

void Map::OpenAllCel() {
    for (uint32_t i = 0; i < _height; ++i)
        for (uint32_t j = 0; j < _width; ++j)
            OpenCell(i, j);
}
