#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Scene.h"

class StartScene : public Scene
{
public:
    StartScene();
    void paintEvent(QPaintEvent *e);
    QPushButton new_game;
    QPushButton continue_game;
    QPixmap logo;
};

#endif // STARTSCENE_H
