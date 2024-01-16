#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include "scene.h"

class ChooseScene : public Scene
{
public:
    ChooseScene();
    void paintEvent(QPaintEvent *);
    QPushButton choose_miner;
    QPushButton choose_belt;
    QPushButton choose_cutter;
    /**
     * \brief 按钮大小
     */
    int ButtonSize;
};

#endif // CHOOSESCENE_H
