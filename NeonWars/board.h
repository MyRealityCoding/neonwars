#ifndef BOARD_H
#define BOARD_H


#include <QGraphicsObject>
#include <QMultiMap>
#include <QPaintEvent>
#include <QPainter>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

#include "arrow.h"
#include "settings.h"
#include "ship.h"
#include "AI.h"
#include "preview.h"

namespace Neighbour {

    enum Type {
        NONE,
        UPPER,
        LOWER,
        LEFT,
        RIGHT,
        UPPER_LEFT,
        UPPER_RIGHT,
        LOWER_LEFT,
        LOWER_RIGHT
    };
}

class Board : public QGraphicsObject
{
    Q_OBJECT

private:
    Ship* _map[Settings::COLUMN_COUNT][Settings::ROW_COUNT];
    int _rows[Settings::COLUMN_COUNT];
    Preview *previewA, *previewB;
    Player::Type currentPlayer;
    Arrow arrow;
    QMediaPlayer *mediaPlayer;
    AI *ai;
    bool aiMode;
public:
    Board(Preview*, Preview*);
    virtual ~Board();
    Ship* getShip(const int &x, const int &y, Neighbour::Type);
    Ship* getShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y);
    bool hasShip(const int &x, const int &y, Neighbour::Type);
    bool add(Ship*, int columnIndex);
    bool canAdd(const int &columnIndex) const;
    bool remove(const int&, const int&);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getWidth() const;
    int getHeight() const;
    int getCellSize() const;
    int getColumn(int xPos) const;
    Preview *getPreview(Player::Type);
    Player::Type getCurrentPlayer() const;
    std::vector<QPoint> getNeighbours(const int&, const int&);
    void reset();
    Player::Type won();
    void toggleKIMode();
    bool isAIMode() const;
    bool eventFilter(QObject *obj, QEvent *event);

    /* Returns all positions of the given direction
     *
     * Example:
     *
     * std::vector<QPoint> diagonal1 = getShips(1, 1, Neighbour::UPPER_LEFT, Neighbour::LOWER_RIGHT);
     * std::vector<QPoint> diagonal2 = getShips(1, 1, Neighbour::LOWER_LEFT, Neighbour::UPPER_RIGHT);
     * std::vector<QPoint> vertical = getShips(1, 1, Neighbour::UPPER, Neighbour::LOWER);
     * std::vector<QPoint> horizontal = getShips(1, 1, Neighbour::LEFT, Neighbour::RIGHT);
     *
     * RETURNS only LEFT and UPPER_LEFT:
     * std::vector<QPoint> crap = getShips(1, 1, Neighbour::LEFT, Neighbour::UPPER_LEFT);
     *
     * RETURNS only UPPER and RIGHT:
     * std::vector<QPoint> crap = getShips(1, 1, Neighbour::UPPER, Neighbour::RIGHT);
     *
     * etc.
     */
    std::vector<QPoint> getShips(const int&, const int&, const QVector2D&);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
signals:

public slots:

private:

    int transformIndexX(const int&, Neighbour::Type);
    int transformIndexY(const int&, Neighbour::Type);
    bool validIndex(const int&, const int&) const;
    bool validIndexX(const int&) const;
    bool validIndexY(const int&) const;
    bool removeByColumn(const int&);
    void checkWon();
};

#endif // BOARD_H
