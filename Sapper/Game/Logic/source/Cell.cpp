//
// Created by Андрей Юрин on 27.04.2023.
//

#include "../include/Cell.h"

Cell::Cell() {
    _isOpen = false;
    _isMine = false;
    _isFlag = false;
    _countMinesAround = 0;
}

void Cell::ChangeCountMinesAround(uint8_t delta) {
    _countMinesAround += delta;
}

uint8_t Cell::GetCountMinesAround() const {
    return _countMinesAround;
}

bool Cell::IsOpen() const {
    return _isOpen;
}

bool Cell::IsMine() const {
    return _isMine;
}

bool Cell::IsFlag() const {
    return _isFlag;
}

void Cell::Open() {
    _isOpen = true;
}

void Cell::SetMine() {
    _isMine = true;
}

void Cell::SwitchIsFlag() {
    _isFlag = !_isFlag;
}
