#ifndef CONFIG_H
#define CONFIG_H

/******************窗口设置*******************/
#define WIDGET_WIDTH 1200           // 窗口宽度
#define WIDGET_HEIGHT 830           // 窗口高度
#define GAME_TITLE "异形工厂"       // 标题
#define GAME_RES_PATH "./res.qrc"   // 资源文件相对路径
#define GAME_ICON "://res/icon.png" // 图标
#define LOGO_PATH ":/res/logo.png"  // logo
#define WIN_PATH ":/res/win.png"    // win图案
/******************游戏界面背景*******************/
#define GAME_WIDTH 1200 // 可放置物体区域宽度
#define GAME_HEIGHT 750 // 可放置物体区域高度
#define WIDTH 24        // 可放置物体区域横向网格数
#define HEIGHT 15       // 可放置物体区域纵向网格数
#define CELLSIZE 50     // 每个格子的边长
#define ITEM_SIZE 30    // 物品大小
/******************矿地资源*******************/
#define CYCLE_MINE_PATH "://res/cycle_mine.png" // 圆形矿地
#define RECT_MINE_PATH "://res/rect_mine.png"   // 方形矿地
#define BARRIER_PATH ":/res/barrier.png"        // 障碍物
/*********************按钮***********************/
#define BUTTON_SIZE 80                                // 选择工具区域的工具按钮大小
#define MINER_BUTTON_PATH "://res/miner_button.png"   // 采矿机
#define BELT_BUTTON_PATH "://res/belt_button.png"     // 传送带
#define CUTTER_BUTTON_PATH "://res/cutter_button.png" // 切割机
#define TRASH_BUTTON_PATH ":/res/trash_button.png"    // 垃圾桶
/****************不同大小的交付中心******************/
#define HUB_SMALL_PATH "://res/hub_small.png" // 小交付中心
#define HUB_BIG_PATH "://res/hub_big.png"     // 大交付中心
/****************不同方向的采矿机******************/
#define MINER_A_PATH "://res/miner_A.png" // 朝左
#define MINER_D_PATH "://res/miner_D.png" // 朝右
#define MINER_S_PATH "://res/miner_S.png" // 朝下
#define MINER_W_PATH "://res/miner_W.png" // 朝上
/****************不同方向的传送带******************/
#define BELT_A_PATH "://res/belt_A.png"
#define BELT_A_S_PATH "://res/belt_A_S.png"
#define BELT_A_W_PATH "://res/belt_A_W.png"
#define BELT_D_PATH "://res/belt_D.png"
#define BELT_D_S_PATH "://res/belt_D_S.png"
#define BELT_D_W_PATH "://res/belt_D_W.png"
#define BELT_S_PATH "://res/belt_S.png"
#define BELT_S_A_PATH "://res/belt_S_A.png"
#define BELT_S_D_PATH "://res/belt_S_D.png"
#define BELT_W_PATH "://res/belt_W.png"
#define BELT_W_A_PATH "://res/belt_W_A.png"
#define BELT_W_D_PATH "://res/belt_W_D.png"
/****************不同方向的切割机******************/
#define CUTTER_A_PATH "://res/cutter_A.png" // 朝左
#define CUTTER_D_PATH "://res/cutter_D.png" // 朝右
#define CUTTER_S_PATH "://res/cutter_S.png" // 朝下
#define CUTTER_W_PATH "://res/cutter_W.png" // 朝上
/****************不同方向的垃圾桶******************/
#define TRASH_A_PATH "://res/trash_A.png" // 朝左
#define TRASH_D_PATH "://res/trash_D.png" // 朝右
#define TRASH_S_PATH "://res/trash_S.png" // 朝下
#define TRASH_W_PATH "://res/trash_W.png" // 朝上
//
/****************不同方向的采矿机******************/
#define MINER_BLUE_A_PATH "://res/miner_blue_A.png" // 朝左
#define MINER_BLUE_D_PATH "://res/miner_blue_D.png" // 朝右
#define MINER_BLUE_S_PATH "://res/miner_blue_S.png" // 朝下
#define MINER_BLUE_W_PATH "://res/miner_blue_W.png" // 朝上
/****************不同方向的传送带******************/
#define BELT_BLUE_A_PATH "://res/belt_blue_A.png"
#define BELT_BLUE_A_S_PATH "://res/belt_blue_A_S.png"
#define BELT_BLUE_A_W_PATH "://res/belt_blue_A_W.png"
#define BELT_BLUE_D_PATH "://res/belt_blue_D.png"
#define BELT_BLUE_D_S_PATH "://res/belt_blue_D_S.png"
#define BELT_BLUE_D_W_PATH "://res/belt_blue_D_W.png"
#define BELT_BLUE_S_PATH "://res/belt_blue_S.png"
#define BELT_BLUE_S_A_PATH "://res/belt_blue_S_A.png"
#define BELT_BLUE_S_D_PATH "://res/belt_blue_S_D.png"
#define BELT_BLUE_W_PATH "://res/belt_blue_W.png"
#define BELT_BLUE_W_A_PATH "://res/belt_blue_W_A.png"
#define BELT_BLUE_W_D_PATH "://res/belt_blue_W_D.png"
/****************不同方向的切割机******************/
#define CUTTER_BLUE_A_PATH "://res/cutter_blue_A.png" // 朝左
#define CUTTER_BLUE_D_PATH "://res/cutter_blue_D.png" // 朝右
#define CUTTER_BLUE_S_PATH "://res/cutter_blue_S.png" // 朝下
#define CUTTER_BLUE_W_PATH "://res/cutter_blue_W.png" // 朝上
/****************不同方向的垃圾桶******************/
#define TRASH_BLUE_A_PATH "://res/trash_blue_A.png" // 朝左
#define TRASH_BLUE_D_PATH "://res/trash_blue_D.png" // 朝右
#define TRASH_BLUE_S_PATH "://res/trash_blue_S.png" // 朝下
#define TRASH_BLUE_W_PATH "://res/trash_blue_W.png" // 朝上
/******************物品*******************/
#define CYCLE_PATH "://res/cycle.png"             // 圆形物品
#define RECT_PATH "://res/rect.png"               // 方形物品
#define LEFT_CYCLE_PATH "://res/left_cycle.png"   // 左圆形物品
#define RIGHT_CYCLE_PATH "://res/right_cycle.png" // 右圆形物品
/******************名字宏*******************/
#define NONE 0
// 方向
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
// 物品
#define CYCLE 11
#define RECT 12
#define LEFT_CYCLE 13
#define RIGHT_CYCLE 14
#define BARRIER 15
// 建筑
#define HUB 21
#define MINER 22
#define CUTTER 23
#define TRASH 24
#define BELT_A 31
#define BELT_A_S 32
#define BELT_A_W 33
#define BELT_D 34
#define BELT_D_S 35
#define BELT_D_W 36
#define BELT_S 37
#define BELT_S_A 38
#define BELT_S_D 39
#define BELT_W 40
#define BELT_W_A 41
#define BELT_W_D 42
#define BELT 43
// Tickable工作状态
#define EMPTY 51
#define RUNNING 52
#define BLOCK 53
// 关卡要求
#define NEED_CYCLE 20
#define NEED_RECT 30
#define NEED_LEFT_CYCLE 40
#define NEED_RIGHT_CYCLE 50
// 物品价值
#define CYCLE_MONEY_1 1
#define RECT_MONEY_1 2
#define LEFT_CYCLE_MONEY_1 3
#define RIGHT_CYCLE_MONEY_1 3
#define CYCLE_MONEY_2 2
#define RECT_MONEY_2 4
#define LEFT_CYCLE_MONEY_2 5
#define RIGHT_CYCLE_MONEY_2 5
// 商店
#define BIGGER_HUB 500
#define CLEAR_BARRIERS 500
#define INCREASE_MINE 500
#define INCREASE_ITEM_VALUE 500
// 建筑速率
#define MINER_SPEED_1 2700
#define MINER_SPEED_2 1800
#define BELT_SPEED_1 1500
#define BELT_SPEED_2 720
#define CUTTER_SPEED_1 2700
#define CUTTER_SPEED_2 1800
//  画面更新频率
#define GAME_HZ 30

#endif // CONFIG_H
