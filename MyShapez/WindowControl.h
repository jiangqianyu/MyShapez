#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "StartScene.h"
#include "PlayScene.h"
#include "RoundScene.h"
#include "ChooseScene.h"
#include "ShopScene.h"
#include "WinScene.h"
#include "HelpScene.h"

class WindowControl : public QWidget
{
    Q_OBJECT

public:
    /**
     * \brief  创建PlayScene实例，加载存档；RoundScene，关卡与PlayScene同步；创建ChooseScene，ShopScene。
     * 先show StartScene，放音乐，设置界面间的联系，开启计时器，每1s检查一下有没有通过某一关
     */
    WindowControl(QWidget *parent = nullptr);
    /**
     * \brief  删除PlayScene、RoundScene、ChooseScene、ShopScene实例
     */
    ~WindowControl();

    // 界面
    StartScene *start;
    PlayScene *play;
    RoundScene *round;
    ChooseScene *choose;
    ShopScene *shop;
    WinScene *win;
    HelpScene *help;

    /**
     * \brief  每1s检查一下有没有通过某一关
     */
    QTimer timer;
    /**
     * \brief  开启计时器，每1s检查一下有没有通过某一关。如果通过了某关，请用户选择局部强化的建筑，hub更新目标，更新关卡数。
     */
    void CheckPassCertainRound();
    /**
     * \brief  用信号与槽，实现按钮按下后界面跳转。round与play，shop与play，全局优化，局部优化
     */
    void connections();
    /**
     * \brief  局部优化miner
     */
    void ChooseUpgradeMiner();
    /**
     * \brief  局部优化belt
     */
    void ChooseUpgradeBelt();
    /**
     * \brief  局部优化cutter
     */
    void ChooseUpgradeCutter();
};
#endif // GAMEWINDOW_H
