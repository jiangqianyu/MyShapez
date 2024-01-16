#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QTimer>
#include <QKeyEvent>
#include <QSettings>
#include <QMediaPlayer> //需要配置cmake
#include <QAudioOutput>

#include "Scene.h"
#include "GameMap.h"
#include "Hub.h"

class PlayScene : public Scene
{
public:
    /**
     * \brief  初始化像素画、按钮，加载未增加矿地的地图，当前未放置任何建筑，未局部升级建筑，关卡为1，计时器，工厂运转，实时捕获鼠标位置
     */
    PlayScene();
    /**
     * \brief  计时器，画面更新频率
     */
    QTimer timer;
    /**
     * \brief  地图，维护网格上所有建筑
     */
    GameMap map;
    /**
     * \brief  建筑list，管理所有建筑tickable状态
     */
    QList<Building *> buildings;
    /**
     * \brief  hub
     */
    Hub *hub;
    /**
     * \brief  某个传送带在网格里的坐标
     */
    GridVec belt_grid_Point;
    /**
     * \brief  当前放置的传送带的路径
     */
    QList<GridVec> belt_grid_path;
    /**
     * \brief  选择了传送带图标，准备放置传送带
     */
    bool ready_to_place_belt;
    /**
     * \brief  判断是否在拖动鼠标放置传送带
     */
    bool is_placing_belt;
    /**
     * \brief  当前选择放置的建筑的名字
     */
    int current_building_name;
    /**
     * \brief  当前选择放置的建筑的方向
     */
    int current_building_direction;
    /**
     * \brief  局部加强升级的建筑的名字
     */
    int upgrade;
    /**
     * \brief  当前关卡数
     */
    int round;
    /**
     * \brief  是否保存
     */
    bool saved;
    /**
     * \brief  是否增加了矿地
     */
    bool increased_mine;
    /**
     * \brief  是否清空了障碍
     */
    bool clear_barriers;
    /**
     * \brief  实时捕捉的鼠标的x
     */
    int cur_x;
    /**
     * \brief  实时捕捉的鼠标的y
     */
    int cur_y;
    /**************音乐***************/
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    /**************按钮***************/
    QPushButton shop;
    QPushButton miner_button;
    QPushButton belt_button;
    QPushButton cutter_button;
    QPushButton trash_button;
    QPushButton help_button;
    /**************像素画***************/
    // 背景
    QPixmap hub_small_img;        // 小交付中心
    QPixmap hub_big_img;          // 大交付中心
    QPixmap cycle_mine_field_img; // 圆形矿矿地
    QPixmap rect_mine_field_img;  // 方形矿矿地
    QPixmap barrier_img;          // 障碍物
    // 不同方向的建筑
    QPixmap miner_img_A; // 采矿机
    QPixmap miner_img_D;
    QPixmap miner_img_S;
    QPixmap miner_img_W;
    QPixmap belt_img_A; // 传送带
    QPixmap belt_img_A_S;
    QPixmap belt_img_A_W;
    QPixmap belt_img_D;
    QPixmap belt_img_D_S;
    QPixmap belt_img_D_W;
    QPixmap belt_img_S;
    QPixmap belt_img_S_A;
    QPixmap belt_img_S_D;
    QPixmap belt_img_W;
    QPixmap belt_img_W_A;
    QPixmap belt_img_W_D;
    QPixmap cutter_img_A; // 切割机
    QPixmap cutter_img_D;
    QPixmap cutter_img_S;
    QPixmap cutter_img_W;
    QPixmap trash_img_A; // 垃圾桶
    QPixmap trash_img_D;
    QPixmap trash_img_S;
    QPixmap trash_img_W;
    // 不同方向的建筑蓝图
    QPixmap miner_img_blue_A; // 采矿机
    QPixmap miner_img_blue_D;
    QPixmap miner_img_blue_S;
    QPixmap miner_img_blue_W;
    QPixmap belt_img_blue_A; // 传送带
    QPixmap belt_img_blue_A_S;
    QPixmap belt_img_blue_A_W;
    QPixmap belt_img_blue_D;
    QPixmap belt_img_blue_D_S;
    QPixmap belt_img_blue_D_W;
    QPixmap belt_img_blue_S;
    QPixmap belt_img_blue_S_A;
    QPixmap belt_img_blue_S_D;
    QPixmap belt_img_blue_W;
    QPixmap belt_img_blue_W_A;
    QPixmap belt_img_blue_W_D;
    QPixmap cutter_img_blue_A; // 切割机
    QPixmap cutter_img_blue_D;
    QPixmap cutter_img_blue_S;
    QPixmap cutter_img_blue_W;
    QPixmap trash_img_blue_A; // 垃圾桶
    QPixmap trash_img_blue_D;
    QPixmap trash_img_blue_S;
    QPixmap trash_img_blue_W;
    // 物品
    QPixmap cycle_img;
    QPixmap rect_img;
    QPixmap left_cycle_img;
    QPixmap right_cycle_img;

    /**
     * \brief 画出所有网格
     */
    void draw_cells();
    /**
     * \brief 画出所有矿地，障碍物
     */
    void draw_map_resources();
    /**
     * \brief 画出所有建筑，包括交付中心，没画物体
     */
    void draw_building();
    /**
     * \brief 画按钮
     */
    void draw_ui();
    /**
     * \brief 绘制hub文字
     */
    void draw_hub_text();
    /**
     * \brief 绘制belt上的item
     */
    void draw_item();
    /**
     * \brief 可视化放置建筑，包括belt
     */
    void draw_overlay(int x, int y);
    /***************重载函数**************/
    /**
     * \brief 绘图事件重构
     */
    void paintEvent(QPaintEvent *e);
    /**
     * \brief 鼠标点击事件重构
     */
    void mousePressEvent(QMouseEvent *e);
    /**
     * \brief 鼠标移动事件
     */
    void mouseMoveEvent(QMouseEvent *e);
    /**
     * \brief  鼠标释放事件
     */
    void mouseReleaseEvent(QMouseEvent *e);
    /**
     * \brief  键盘事件重构
     */
    void keyPressEvent(QKeyEvent *e);
    /**
     * \brief  窗口关闭事件重构
     */
    void closeEvent(QCloseEvent *e);
    /**
     * \brief  工厂运转
     */
    void FactoryRunning();
    /**
     * \brief 把鼠标拖动放置传送带时经过的新网格点压入list
     * \param grid_j x方向
     * \param grid_i y方向
     */
    void PushBackNewBeltGridPoint(int grid_j, int grid_i);
    /**
     * \brief 清空当前放置的传送带的路径
     */
    void ClearBeltGridPath();
    /**
     * \brief 根据传送带路径判断某单位是何种形态的传送带
     * \param belt_grid_path_index 路径index
     * \return BELT_W，BELT_A_S
     */
    int WhichBeltImg(int belt_grid_path_index);
    /**
     * \brief 移除建筑
     * \param pos 需要remove建筑的网格位置
     */
    void RemoveBuilding(GridVec pos);
    /**
     * \brief 升级hub
     */
    void UpgradeHub();
    /**
     * \brief 播放音乐
     */
    void music();
    /**
     * \brief 把游戏状态保存下来
     */
    void DoSave();
    /**
     * \brief 加载之前的游戏状态
     */
    void LoadSave();
};

#endif // PLAYSCENE_H
