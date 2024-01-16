#include "playscene.h"
#include "Miner.h"
#include "Belt.h"
#include "Cutter.h"
#include "Trash.h"
// #include "math.h"
#include "config.h"
#include <QPainter>

PlayScene::PlayScene()
{
    // 初始化像素画
    hub_small_img.load(HUB_SMALL_PATH); // 交付中心
    hub_big_img.load(HUB_BIG_PATH);
    cycle_mine_field_img.load(CYCLE_MINE_PATH); // 矿地
    rect_mine_field_img.load(RECT_MINE_PATH);
    barrier_img.load(BARRIER_PATH); // 障碍物
    miner_img_W.load(MINER_W_PATH); // 采矿机
    miner_img_A.load(MINER_A_PATH);
    miner_img_D.load(MINER_D_PATH);
    miner_img_S.load(MINER_S_PATH);
    belt_img_A.load(BELT_A_PATH); // 传送带
    belt_img_A_S.load(BELT_A_S_PATH);
    belt_img_A_W.load(BELT_A_W_PATH);
    belt_img_D.load(BELT_D_PATH);
    belt_img_D_S.load(BELT_D_S_PATH);
    belt_img_D_W.load(BELT_D_W_PATH);
    belt_img_S.load(BELT_S_PATH);
    belt_img_S_A.load(BELT_S_A_PATH);
    belt_img_S_D.load(BELT_S_D_PATH);
    belt_img_W.load(BELT_W_PATH);
    belt_img_W_A.load(BELT_W_A_PATH);
    belt_img_W_D.load(BELT_W_D_PATH);
    cutter_img_A.load(CUTTER_A_PATH); // 切割机
    cutter_img_D.load(CUTTER_D_PATH);
    cutter_img_S.load(CUTTER_S_PATH);
    cutter_img_W.load(CUTTER_W_PATH);
    trash_img_A.load(TRASH_A_PATH); // 垃圾桶
    trash_img_D.load(TRASH_D_PATH);
    trash_img_S.load(TRASH_S_PATH);
    trash_img_W.load(TRASH_W_PATH);
    miner_img_blue_W.load(MINER_BLUE_W_PATH); // 采矿机蓝图
    miner_img_blue_A.load(MINER_BLUE_A_PATH);
    miner_img_blue_D.load(MINER_BLUE_D_PATH);
    miner_img_blue_S.load(MINER_BLUE_S_PATH);
    belt_img_blue_A.load(BELT_BLUE_A_PATH); // 传送带蓝图
    belt_img_blue_A_S.load(BELT_BLUE_A_S_PATH);
    belt_img_blue_A_W.load(BELT_BLUE_A_W_PATH);
    belt_img_blue_D.load(BELT_BLUE_D_PATH);
    belt_img_blue_D_S.load(BELT_BLUE_D_S_PATH);
    belt_img_blue_D_W.load(BELT_BLUE_D_W_PATH);
    belt_img_blue_S.load(BELT_BLUE_S_PATH);
    belt_img_blue_S_A.load(BELT_BLUE_S_A_PATH);
    belt_img_blue_S_D.load(BELT_BLUE_S_D_PATH);
    belt_img_blue_W.load(BELT_BLUE_W_PATH);
    belt_img_blue_W_A.load(BELT_BLUE_W_A_PATH);
    belt_img_blue_W_D.load(BELT_BLUE_W_D_PATH);
    cutter_img_blue_A.load(CUTTER_BLUE_A_PATH); // 切割机蓝图
    cutter_img_blue_D.load(CUTTER_BLUE_D_PATH);
    cutter_img_blue_S.load(CUTTER_BLUE_S_PATH);
    cutter_img_blue_W.load(CUTTER_BLUE_W_PATH);
    trash_img_blue_A.load(TRASH_BLUE_A_PATH); // 垃圾桶蓝图
    trash_img_blue_D.load(TRASH_BLUE_D_PATH);
    trash_img_blue_S.load(TRASH_BLUE_S_PATH);
    trash_img_blue_W.load(TRASH_BLUE_W_PATH);
    cycle_img.load(CYCLE_PATH); // 物品
    rect_img.load(RECT_PATH);
    left_cycle_img.load(LEFT_CYCLE_PATH);
    right_cycle_img.load(RIGHT_CYCLE_PATH);
    // 初始化按钮
    shop.setParent(this);
    shop.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    shop.setStyleSheet("QPushButton{image: url(:/res/shop.png)}");
    miner_button.setParent(this);
    miner_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    miner_button.setStyleSheet("QPushButton{image: url(:/res/miner_button.png)}");
    belt_button.setParent(this);
    belt_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    belt_button.setStyleSheet("QPushButton{image: url(:/res/belt_button.png)}");
    cutter_button.setParent(this);
    cutter_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    cutter_button.setStyleSheet("QPushButton{image: url(:/res/cutter_button.png)}");
    trash_button.setParent(this);
    trash_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    trash_button.setStyleSheet("QPushButton{image: url(:/res/trash_button.png)}");
    help_button.setParent(this);
    help_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE);
    help_button.setStyleSheet("QPushButton{image: url(:/res/help.png)}");
    // 未增加矿地的地图
    map.FirstMap();
    // 当前未放置任何建筑
    is_placing_belt = false;
    ready_to_place_belt = false;
    current_building_name = NONE;
    current_building_direction = UP;
    // 未局部升级建筑
    upgrade = NONE;
    // 关卡
    round = 1;
    // 计时器，工厂运转
    timer.setInterval(GAME_HZ);
    this->FactoryRunning();
    // 实时捕获鼠标位置
    setMouseTracking(true);
    cur_x = 0;
    cur_y = 0;
}

void PlayScene::draw_cells()
{
    // 绘制背景淡灰色网格
    QPen pen;                            // 笔
    pen.setColor(QColor(220, 220, 220)); // 淡灰色
    QPainter gridPainter(this);          // 画家
    gridPainter.setPen(pen);             // 画家拿笔
    for (int y = 0; y <= GAME_HEIGHT; y += CELLSIZE)
    {
        gridPainter.drawLine(0, y, GAME_WIDTH, y);
    }
    for (int x = 0; x <= GAME_WIDTH; x += CELLSIZE)
    {
        gridPainter.drawLine(x, 0, x, GAME_HEIGHT);
    }
}

void PlayScene::draw_map_resources()
{
    // 绘制矿地
    QPainter mineFieldPainter(this);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            switch (map.Resource[i][j])
            {
            case CYCLE:
                mineFieldPainter.drawPixmap(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE, cycle_mine_field_img);
                break;
            case RECT:
                mineFieldPainter.drawPixmap(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE, rect_mine_field_img);
                break;
            case BARRIER:
                mineFieldPainter.drawPixmap(j * CELLSIZE, i * CELLSIZE, CELLSIZE, CELLSIZE, barrier_img);
                break;
            default:
                break;
            }
        }
    }
}
void PlayScene::draw_building()
{
    if (buildings.size() > 0)
    {
        QPainter painter(this);
        for (int i = 0; i < buildings.size(); i++)
        {
            Building *building = buildings[i];
            switch (building->name)
            {
            case HUB:
                if (!hub->upgradehub)
                {
                    // 未升级的hub
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE * 2, CELLSIZE * 2, hub_small_img);
                }
                else
                {
                    // 升级后的hub
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE * 4, CELLSIZE * 4, hub_big_img);
                }
                break;
            case TRASH:
                switch (building->direction)
                {
                case UP:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, trash_img_W);
                    break;
                case DOWN:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, trash_img_S);
                    break;
                case LEFT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, trash_img_A);
                    break;
                case RIGHT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, trash_img_D);
                    break;
                default:
                    break;
                }
                break;
            case MINER:
                switch (building->direction)
                {
                case UP:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, miner_img_W);
                    break;
                case DOWN:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, miner_img_S);
                    break;
                case LEFT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, miner_img_A);
                    break;
                case RIGHT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, miner_img_D);
                    break;
                default:
                    break;
                }
                break;
            case BELT_A:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_A);
                break;
            case BELT_A_S:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_A_S);
                break;
            case BELT_A_W:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_A_W);
                break;
            case BELT_D:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_D);
                break;
            case BELT_D_S:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_D_S);
                break;
            case BELT_D_W:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_D_W);
                break;
            case BELT_S:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_S);
                break;
            case BELT_S_A:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_S_A);
                break;
            case BELT_S_D:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_S_D);
                break;
            case BELT_W:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_W);
                break;
            case BELT_W_A:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_W_A);
                break;
            case BELT_W_D:
                painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_W_D);
                break;
            case CUTTER:
                switch (building->direction)
                {
                case UP:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE * 2, CELLSIZE, cutter_img_W);
                    break;
                case DOWN:
                    painter.drawPixmap((building->pos.j - 1) * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE * 2, CELLSIZE, cutter_img_S);
                    break;
                case LEFT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, (building->pos.i - 1) * CELLSIZE, CELLSIZE, CELLSIZE * 2, cutter_img_A);
                    break;
                case RIGHT:
                    painter.drawPixmap(building->pos.j * CELLSIZE, building->pos.i * CELLSIZE, CELLSIZE, CELLSIZE * 2, cutter_img_D);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}
void PlayScene::draw_ui()
{
    shop.move(BUTTON_SIZE * 1, CELLSIZE * 15);
    shop.show();
    miner_button.move(BUTTON_SIZE * 4, CELLSIZE * 15);
    miner_button.show();
    belt_button.move(BUTTON_SIZE * 6, CELLSIZE * 15);
    belt_button.show();
    cutter_button.move(BUTTON_SIZE * 8, CELLSIZE * 15);
    cutter_button.show();
    trash_button.move(BUTTON_SIZE * 10, CELLSIZE * 15);
    trash_button.show();
    help_button.move(BUTTON_SIZE * 2, CELLSIZE * 15);
    help_button.show();
}
void PlayScene::draw_hub_text()
{
    QPainter hubPainter(this);
    // 绘制hub文字
    if (!hub->upgradehub)
    {
        // 未升级的hub
        hubPainter.drawText(hub->pos.j * CELLSIZE + 35, hub->pos.i * CELLSIZE + 40, QString("￥ ") + QString::number(hub->money));
        hubPainter.drawText(hub->pos.j * CELLSIZE + 35, hub->pos.i * CELLSIZE + 60, QString::number(hub->current_have) + QString("/") + QString::number(hub->need));
    }
    else
    {
        // 升级后的hub
        hubPainter.setFont(QFont("楷体", 35, QFont::Bold));
        hubPainter.drawText(hub->pos.j * CELLSIZE + 36, hub->pos.i * CELLSIZE + 90, QString("￥") + QString::number(hub->money));
        hubPainter.drawText(hub->pos.j * CELLSIZE + 40, hub->pos.i * CELLSIZE + 145, QString::number(hub->current_have) + QString("/") + QString::number(hub->need));
    }
}
void PlayScene::draw_item()
{
    if (buildings.size() > 0)
    {
        QPainter itemPainter(this);
        for (auto &building : buildings)
        {
            if (building->name >= BELT_A && building->name <= BELT_W_D)
            {
                if (building->state != EMPTY)
                {
                    switch (building->shape.name)
                    {
                    case CYCLE:
                        itemPainter.drawPixmap(building->shape.x0 - ITEM_SIZE / 2, building->shape.y0 - ITEM_SIZE / 2, ITEM_SIZE, ITEM_SIZE, cycle_img);
                        break;
                    case RECT:
                        itemPainter.drawPixmap(building->shape.x0 - ITEM_SIZE / 2, building->shape.y0 - ITEM_SIZE / 2, ITEM_SIZE, ITEM_SIZE, rect_img);
                        break;
                    case LEFT_CYCLE:
                        itemPainter.drawPixmap(building->shape.x0 - ITEM_SIZE / 2, building->shape.y0 - ITEM_SIZE / 2, ITEM_SIZE / 2, ITEM_SIZE, left_cycle_img);
                        break;
                    case RIGHT_CYCLE:
                        itemPainter.drawPixmap(building->shape.x0, building->shape.y0 - ITEM_SIZE / 2, ITEM_SIZE / 2, ITEM_SIZE, right_cycle_img);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
}
void PlayScene::draw_overlay(int x, int y)
{
    QPainter painter(this);
    switch (current_building_name)
    {
    case MINER:
        switch (current_building_direction)
        {
        case UP:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, miner_img_blue_W);
            break;
        case DOWN:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, miner_img_blue_S);
            break;
        case LEFT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, miner_img_blue_A);
            break;
        case RIGHT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, miner_img_blue_D);
            break;
        default:
            break;
        }
        break;
    case CUTTER:
        switch (current_building_direction)
        {
        case UP:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE * 2, CELLSIZE, cutter_img_blue_W);
            break;
        case DOWN:
            painter.drawPixmap(x - CELLSIZE - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE * 2, CELLSIZE, cutter_img_blue_S);
            break;
        case LEFT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE - CELLSIZE / 2, CELLSIZE, CELLSIZE * 2, cutter_img_blue_A);
            break;
        case RIGHT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE * 2, cutter_img_blue_D);
            break;
        default:
            break;
        }
        break;
    case TRASH:
        switch (current_building_direction)
        {
        case UP:
            // qDebug() << tr("try to draw trash");
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, trash_img_blue_W);
            break;
        case DOWN:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, trash_img_blue_S);
            break;
        case LEFT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, trash_img_blue_A);
            break;
        case RIGHT:
            painter.drawPixmap(x - CELLSIZE / 2, y - CELLSIZE / 2, CELLSIZE, CELLSIZE, trash_img_blue_D);
            break;
        default:
            break;
        }
    case BELT:
    default:
        break;
    }
    if (current_building_name == BELT)
    {
        if (belt_grid_path.size() >= 2)
        {
            int which_belt = 0;
            for (int i = 0; i < belt_grid_path.size(); i++)
            {
                which_belt = WhichBeltImg(i);
                switch (which_belt)
                {
                case BELT_A:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_A);
                    break;
                case BELT_S_A:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_S_A);
                    break;
                case BELT_W_A:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_W_A);
                    break;
                case BELT_S:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_S);
                    break;
                case BELT_A_S:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_A_S);
                    break;
                case BELT_D_S:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_D_S);
                    break;
                case BELT_W:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_W);
                    break;
                case BELT_A_W:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_A_W);
                    break;
                case BELT_D_W:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_D_W);
                    break;
                case BELT_D:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_D);
                    break;
                case BELT_S_D:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_S_D);
                    break;
                case BELT_W_D:
                    painter.drawPixmap(belt_grid_path[i].j * CELLSIZE, belt_grid_path[i].i * CELLSIZE, CELLSIZE, CELLSIZE, belt_img_blue_W_D);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void PlayScene::paintEvent(QPaintEvent *)
{
    draw_cells();
    draw_map_resources();
    draw_building();
    draw_ui();
    draw_hub_text();
    draw_item();
    draw_overlay(cur_x, cur_y);
}
void PlayScene::mousePressEvent(QMouseEvent *e)
{
    int click_x = e->pos().x();
    int click_y = e->pos().y();
    int grid_j = click_x / CELLSIZE;
    int grid_i = click_y / CELLSIZE;
    GridVec cur;
    Building *current_building;
    cur.j = grid_j;
    cur.i = grid_i;
    if (e->button() == Qt::LeftButton)
    {
        if (ready_to_place_belt)
        {
            PushBackNewBeltGridPoint(grid_j, grid_i);
            ready_to_place_belt = false;
            is_placing_belt = true;
            return;
        }
        if (current_building_name)
        {
            switch (current_building_name)
            {
            case MINER:
                current_building = new Miner(cur, current_building_name, current_building_direction);
                break;
            case CUTTER:
                current_building = new Cutter(cur, current_building_name, current_building_direction);
                break;
            case TRASH:
                current_building = new Trash(cur, current_building_name, current_building_direction);
            default:
                break;
            }
            switch (upgrade)
            {
            case MINER:
                current_building->FirstRequire_ms = MINER_SPEED_2;
                break;
            case CUTTER:
                current_building->FirstRequire_ms = CUTTER_SPEED_2;
                break;
            default:
                break;
            }
            // 放置建筑
            if (current_building->CanPlace(cur, current_building_direction, map))
            {
                map.SetBuilding(cur, current_building, current_building_direction, current_building_name);
                for (int i = 0; i < buildings.size(); i++)
                {
                    for (auto poscur : current_building->BuildingAllPos())
                    {
                        if (buildings[i]->pos == poscur)
                        {
                            buildings.remove(i);
                        }
                    }
                }
                buildings.push_back(current_building);
                current_building_name = NONE;
                update();
            }
        }
    }
    else if (e->button() == Qt::RightButton)
    {
        RemoveBuilding(cur);
        update();
    }
}
void PlayScene::RemoveBuilding(GridVec pos)
{
    if (map.BuildingsMap[pos.i][pos.j] != nullptr)
    {
        for (auto curr : map.BuildingsMap[pos.i][pos.j]->BuildingAllPos())
        {
            for (int i = 0; i < buildings.size(); i++)
            {
                if (buildings[i]->pos == curr)
                {
                    if (buildings[i]->name != HUB)
                    {
                        buildings.remove(i);
                        break;
                    }
                }
            }
        }
        map.RemoveBuilding(pos);
    }
}
void PlayScene::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_A:
        current_building_direction = LEFT;
        break;
    case Qt::Key_D:
        current_building_direction = RIGHT;
        break;
    case Qt::Key_W:
        current_building_direction = UP;
        break;
    case Qt::Key_S:
        current_building_direction = DOWN;
        break;
    default:
        break;
    }
}
void PlayScene::PushBackNewBeltGridPoint(int grid_j, int grid_i)
{
    // 把鼠标拖动放置传送带时经过的新网格点压入qlist
    belt_grid_Point.i = grid_i;
    belt_grid_Point.j = grid_j;
    if (!belt_grid_path.contains(belt_grid_Point)) //
    {
        belt_grid_path.append(belt_grid_Point);
    }
}
void PlayScene::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->pos().x();      // 鼠标点击的屏幕位置的横坐标
    int y = e->pos().y();      // 鼠标点击的屏幕位置的纵坐标
    int grid_j = x / CELLSIZE; // 在网格里的横坐标
    int grid_i = y / CELLSIZE; // 在网格里的纵坐标
    if (current_building_name)
    {
        cur_x = x;
        cur_y = y;
        update();
        if (is_placing_belt)
        {
            PushBackNewBeltGridPoint(grid_j, grid_i);
        }
    }
}
void PlayScene::ClearBeltGridPath()
{
    while (!belt_grid_path.empty())
    {
        belt_grid_path.removeLast();
    }
}
int PlayScene::WhichBeltImg(int belt_grid_path_index)
{
    if (belt_grid_path_index == 0)
    {
        if (belt_grid_path[1] - belt_grid_path[0] == RIGHT)
        {
            return BELT_D;
        }
        else if (belt_grid_path[1] - belt_grid_path[0] == LEFT)
        {
            return BELT_A;
        }
        else if (belt_grid_path[1] - belt_grid_path[0] == UP)
        {
            return BELT_W;
        }
        else if (belt_grid_path[1] - belt_grid_path[0] == DOWN)
        {
            return BELT_S;
        }
    }
    int end_index = belt_grid_path.size() - 1;
    if (belt_grid_path_index == end_index)
    {
        if (belt_grid_path[end_index] - belt_grid_path[end_index - 1] == RIGHT)
        {
            return BELT_D;
        }
        else if (belt_grid_path[end_index] - belt_grid_path[end_index - 1] == LEFT)
        {
            return BELT_A;
        }
        else if (belt_grid_path[end_index] - belt_grid_path[end_index - 1] == UP)
        {
            return BELT_W;
        }
        else if (belt_grid_path[end_index] - belt_grid_path[end_index - 1] == DOWN)
        {
            return BELT_S;
        }
    }
    if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == RIGHT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == RIGHT))
    {
        return BELT_D;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == LEFT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == LEFT))
    {
        return BELT_A;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == UP) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == UP))
    {
        return BELT_W;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == DOWN) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == DOWN))
    {
        return BELT_S;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == RIGHT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == UP))
    {
        return BELT_W_D;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == LEFT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == UP))
    {
        return BELT_W_A;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == RIGHT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == DOWN))
    {
        return BELT_S_D;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == LEFT) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == DOWN))
    {
        return BELT_S_A;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == UP) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == LEFT))
    {
        return BELT_A_W;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == DOWN) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == LEFT))
    {
        return BELT_A_S;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == UP) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == RIGHT))
    {
        return BELT_D_W;
    }
    else if ((belt_grid_path[belt_grid_path_index + 1] - belt_grid_path[belt_grid_path_index] == DOWN) && (belt_grid_path[belt_grid_path_index] - belt_grid_path[belt_grid_path_index - 1] == RIGHT))
    {
        return BELT_D_S;
    }
    return 0;
}
void PlayScene::mouseReleaseEvent(QMouseEvent *e)
{
    if (is_placing_belt)
    {
        is_placing_belt = false;
        if (belt_grid_path.size() >= 2)
        {
            int which_belt = 0;
            int belt_direction = 0;
            for (int i = 0; i < belt_grid_path.size(); i++)
            {
                which_belt = WhichBeltImg(i);
                switch (which_belt)
                {
                case BELT_A:
                case BELT_S_A:
                case BELT_W_A:
                    belt_direction = LEFT;
                    break;
                case BELT_S:
                case BELT_A_S:
                case BELT_D_S:
                    belt_direction = DOWN;
                    break;
                case BELT_W:
                case BELT_A_W:
                case BELT_D_W:
                    belt_direction = UP;
                    break;
                case BELT_D:
                case BELT_S_D:
                case BELT_W_D:
                    belt_direction = RIGHT;
                    break;
                default:
                    break;
                }
                Building *current_building = new Belt(belt_grid_path[i], which_belt, belt_direction);
                if (current_building->CanPlace(belt_grid_path[i], belt_direction, map))
                {
                    if (upgrade == BELT)
                    {
                        current_building->FirstRequire_ms = BELT_SPEED_2;
                    }
                    map.SetBuilding(belt_grid_path[i], current_building, belt_direction, which_belt);
                    buildings.push_back(current_building);
                }
            }
        }
        ClearBeltGridPath();
        update();
        current_building_name = NONE;
    }
}
void PlayScene::FactoryRunning()
{
    timer.start();
    // 监听定时器
    connect(&timer, &QTimer::timeout, this, [=]()
            {
        //重新绘制图片
        update();
        if(buildings.size())
        {
            for(auto &building : buildings)
            {
                if(building->name != HUB && building->name != TRASH)
                {
                    building->UpdateTickableState(map);
                }
            }
        } });
}
void PlayScene::UpgradeHub()
{
    hub->pos.i = HEIGHT / 2 - 2;
    hub->pos.j = WIDTH / 2 - 2;
    GridVec hubvec(WIDTH / 2 - 2, HEIGHT / 2 - 2);
    map.SetBuilding(hubvec, hub, UP, HUB);
}
void PlayScene::DoSave()
{
    QSettings setting("Parameter.ini", QSettings::IniFormat);
    setting.remove("building");
    setting.beginWriteArray("building");
    for (int i = 0; i < buildings.size(); i++)
    {
        setting.setArrayIndex(i);
        setting.setValue("j", buildings[i]->pos.j);
        setting.setValue("i", buildings[i]->pos.i);
        setting.setValue("direction", buildings[i]->direction);
        setting.setValue("name", buildings[i]->name);
    }
    setting.endArray();
    setting.beginGroup("savecondition");
    setting.setValue("saved", saved);
    setting.setValue("increased_mine", increased_mine);
    setting.setValue("cleared_barriers", clear_barriers);
    setting.setValue("increased_item_value", hub->increase_item_value);
    setting.setValue("upgradedhub", hub->upgradehub);
    setting.setValue("money", hub->money);
    setting.setValue("round", round);
    setting.setValue("upgradewhich", upgrade);
    setting.setValue("current_have", hub->current_have);
    setting.endGroup();
    setting.sync();
}
void PlayScene::LoadSave()
{
    QSettings setting("Parameter.ini", QSettings::IniFormat);
    setting.beginGroup("savecondition");
    saved = setting.value("saved").toBool();
    increased_mine = setting.value("increased_mine").toBool();
    clear_barriers = setting.value("cleared_barriers").toBool();
    bool tempincrease = setting.value("increased_item_value").toBool();
    int tempmoney = setting.value("money").toInt();
    bool tempupgradehub = setting.value("upgradedhub").toBool();
    int temphave = setting.value("current_have").toInt();
    upgrade = setting.value("upgradewhich").toInt();
    if (setting.value("round").toInt() > 1)
    {
        round = setting.value("round").toInt();
    }
    setting.endGroup();
    if (increased_mine)
    {
        map.SecondMap();
    }
    if (clear_barriers)
    {
        map.ClearBarriers();
    }
    if (saved)
    {
        int size = setting.beginReadArray("building");
        for (int i = 0; i < size; i++)
        {
            setting.setArrayIndex(i);
            GridVec cur = GridVec(setting.value("j").toInt(), setting.value("i").toInt());
            int name = setting.value("name").toInt();
            int direction = setting.value("direction").toInt();
            if (name == HUB)
            {
                hub = new Hub;
                hub->name = name;
                hub->direction = direction;
                hub->pos = cur;
                Building *smallhub = hub;
                map.SetBuilding(cur, smallhub, direction, name);
                buildings.push_back(smallhub);
                continue;
            }
            Building *cur_building;
            switch (name)
            {
            case MINER:
                cur_building = new Miner(cur, name, direction);
                break;
            case CUTTER:
                cur_building = new Cutter(cur, name, direction);
                break;
            case TRASH:
                cur_building = new Trash(cur, name, direction);
                break;
            case BELT_A:
            case BELT_A_S:
            case BELT_A_W:
            case BELT_D:
            case BELT_D_S:
            case BELT_D_W:
            case BELT_S:
            case BELT_S_A:
            case BELT_S_D:
            case BELT_W:
            case BELT_W_A:
            case BELT_W_D:
                cur_building = new Belt(cur, name, direction);
                break;
            }
            map.SetBuilding(cur, cur_building, direction, name);
            buildings.push_back(cur_building);
        }
    }
    if (!saved)
    {
        hub = new Hub;
        hub->name = HUB;
        hub->pos.i = HEIGHT / 2;
        hub->pos.j = WIDTH / 2;
        hub->direction = UP;
        GridVec hubvec(WIDTH / 2, HEIGHT / 2);
        Building *smallhub = hub;
        map.SetBuilding(hubvec, smallhub, hub->direction, hub->name);
        buildings.push_back(smallhub);
    }
    hub->increase_item_value = tempincrease;
    hub->money = tempmoney;
    hub->upgradehub = tempupgradehub;
    hub->current_have = temphave;
    if (tempupgradehub)
    {
        UpgradeHub();
    }
    switch (upgrade)
    {
    case NONE:
        break;
    case MINER:
        for (int i = 0; i < buildings.size(); i++)
        {
            switch (buildings[i]->name)
            {
            case MINER:
                buildings[i]->FirstRequire_ms = 1800;
                break;
            case CUTTER:
                buildings[i]->FirstRequire_ms = 2700;
                break;
            case BELT_A:
            case BELT_A_S:
            case BELT_A_W:
            case BELT_D:
            case BELT_D_S:
            case BELT_D_W:
            case BELT_S:
            case BELT_S_A:
            case BELT_S_D:
            case BELT_W:
            case BELT_W_A:
            case BELT_W_D:
                buildings[i]->FirstRequire_ms = 1500;
                break;
            default:
                break;
            }
        }
        break;
    case BELT:
        for (int i = 0; i < buildings.size(); i++)
        {
            switch (buildings[i]->name)
            {
            case MINER:
                buildings[i]->FirstRequire_ms = 2700;
                break;
            case CUTTER:
                buildings[i]->FirstRequire_ms = 2700;
                break;
            case BELT_A:
            case BELT_A_S:
            case BELT_A_W:
            case BELT_D:
            case BELT_D_S:
            case BELT_D_W:
            case BELT_S:
            case BELT_S_A:
            case BELT_S_D:
            case BELT_W:
            case BELT_W_A:
            case BELT_W_D:
                buildings[i]->FirstRequire_ms = 720;
                break;
            default:
                break;
            }
        }
        break;
    case CUTTER:
        for (int i = 0; i < buildings.size(); i++)
        {
            switch (buildings[i]->name)
            {
            case MINER:
                buildings[i]->FirstRequire_ms = 2700;
                break;
            case CUTTER:
                buildings[i]->FirstRequire_ms = 1800;
                break;
            case BELT_A:
            case BELT_A_S:
            case BELT_A_W:
            case BELT_D:
            case BELT_D_S:
            case BELT_D_W:
            case BELT_S:
            case BELT_S_A:
            case BELT_S_D:
            case BELT_W:
            case BELT_W_A:
            case BELT_W_D:
                buildings[i]->FirstRequire_ms = 1500;
                break;
            default:
                break;
            }
        }
        break;
    default:
        break;
    }
    switch (round)
    {
    case 1:
        hub->need_shape_name = CYCLE;
        hub->need = NEED_CYCLE;
        break;
    case 2:
        hub->need_shape_name = RECT;
        hub->need = NEED_RECT;
        break;
    case 3:
        hub->need_shape_name = LEFT_CYCLE;
        hub->need = NEED_LEFT_CYCLE;
        break;
    case 4:
        hub->need_shape_name = RIGHT_CYCLE;
        hub->need = NEED_RIGHT_CYCLE;
        break;
    default:
        break;
    }
}
void PlayScene::closeEvent(QCloseEvent *)
{
    saved = true;
    DoSave();
}
void PlayScene::music()
{
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/res/theme-full.mp3"));
    player->play();
}
