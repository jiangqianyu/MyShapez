#ifndef WINSCENE_H
#define WINSCENE_H

#include "Scene.h"

class WinScene : public Scene
{
public:
    WinScene();
    QPixmap win;
    void paintEvent(QPaintEvent *e);
};

#endif // WINSCENE_H
