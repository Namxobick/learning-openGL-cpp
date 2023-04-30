//
// Created by Андрей Юрин on 27.04.2023.
//


#include "../include/MineGUI.h"

void MineGUI::RenderMine() {
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0, 0, 0);
        glVertex2f(0.3, 0.3);
        glVertex2f(0.7, 0.3);
        glVertex2f(0.7, 0.7);
        glVertex2f(0.3, 0.7);
    glEnd();
}
