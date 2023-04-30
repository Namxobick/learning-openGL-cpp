//
// Created by Андрей Юрин on 27.04.2023.
//

#include "../include/NumberDrawer.h"

void NumberDrawer::RenderNumber(uint8_t number) {
    glLineWidth(3);
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
        if ((number != 1) and (number != 4)) RenderLine(0.3, 0.85, 0.7, 0.85);
        if ((number != 0) and (number != 1) and (number != 7)) RenderLine(0.3, 0.5, 0.7, 0.5);
        if ((number != 1) and (number != 4) and (number != 7)) RenderLine(0.3, 0.15, 0.7, 0.15);

        if ((number != 5) and (number != 6)) RenderLine(0.7, 0.5, 0.7, 0.85);
        if ((number != 2)) RenderLine(0.7, 0.5, 0.7, 0.15);

        if ((number != 1) and (number != 2) and (number != 3) and (number != 7)) RenderLine(0.3, 0.5, 0.3, 0.85);
        if ((number == 0) or (number == 2) or ( number == 6) or (number == 8)) RenderLine(0.3, 0.5, 0.3, 0.15);
    glEnd();
}

void NumberDrawer::RenderLine(float x1, float y1, float x2, float y2) {
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
}
