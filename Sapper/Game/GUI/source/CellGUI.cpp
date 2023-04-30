//
// Created by Андрей Юрин on 27.04.2023.
//

#include "../include/CellGUI.h"

void CellGUI::RenderClosedCell() {
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.8, 0.8, 0.8); glVertex2f(0, 1);
        glColor3f(0.7, 0.7, 0.7); glVertex2f(1, 1); glVertex2f(0, 0);
        glColor3f(0.6, 0.6, 0.6); glVertex2f(1, 0);
    glEnd();
}

void CellGUI::RenderOpenedCell() {
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.3, 0.7, 0.3); glVertex2f(0, 1);
        glColor3f(0.3, 0.6, 0.3); glVertex2f(1, 1); glVertex2f(0, 0);
        glColor3f(0.3, 0.5, 0.3); glVertex2f(1, 0);
    glEnd();
}
