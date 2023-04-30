//
// Created by Андрей Юрин on 30.04.2023.
//

#include "../include/FlagGUI.h"

void FlagGUI::RenderFlag() {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(0.25, 0.75);
        glVertex2f(0.85, 0.5);
        glVertex2f(0.25, 0.25);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(0.25, 0.75);
        glVertex2f(0.25, 0);
    glEnd();
}
