//
// Created by Андрей Юрин on 27.04.2023.
//

#ifndef LEARNING_OPENGL_NUMBERDRAWER_H
#define LEARNING_OPENGL_NUMBERDRAWER_H


#include <cstdint>
#include "../../../directories/glew/2.2.0_1/glew.h"

class NumberDrawer {
public:
    void RenderNumber(uint8_t number);

private:
    void RenderLine(float x1, float y1, float x2, float y2);
};


#endif //LEARNING_OPENGL_NUMBERDRAWER_H
