//
// Created by Андрей Юрин on 27.04.2023.
//

#ifndef LEARNING_OPENGL_CELL_H
#define LEARNING_OPENGL_CELL_H

#include <cstdint>

class Cell {
private:
    bool _isOpen;
    bool _isMine;
    bool _isFlag;
    int8_t _countMinesAround;
public:
    Cell();
    [[nodiscard]] bool IsOpen() const;
    [[nodiscard]] bool IsMine() const;
    [[nodiscard]] bool IsFlag() const;
    void Open();
    void SetMine();
    void SwitchIsFlag();
    void ChangeCountMinesAround(uint8_t delta);
    [[nodiscard]] uint8_t GetCountMinesAround() const;
};


#endif //LEARNING_OPENGL_CELL_H
