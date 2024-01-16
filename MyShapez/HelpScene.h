#ifndef HELPSCENE_H
#define HELPSCENE_H

#include "scene.h"
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
class HelpScene : public Scene
{
public:
    HelpScene();
    void paintEvent(QPaintEvent *e);
    QPushButton return_button;
    void setTxt();
};

#endif // HELPSCENE_H
