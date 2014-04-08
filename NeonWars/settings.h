#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QMediaPlayer>

namespace Settings {

    using namespace std;

    // Name of this game
    static const QString APP_TITLE = "Neon Wars";

    // Current versionr
    static const QString APP_VERSION = "0.9";

    // Width of the game
    static const int WINDOW_WIDTH = 640;

    // Height of the game
    static const int WINDOW_HEIGHT = 480;

    // Sounds enabled?
    static const bool SOUNDS = true;

    // Number of future ships
    static const int PREVIEW_COUNT = 4;

    // Preview Icon Size
    static const int PREVIEW_SIZE = 64;

    // Number of rows
    static const int ROW_COUNT = 6;

    // Number of columns
    static const int COLUMN_COUNT = 12;

    // Padding of the GUI
    static const int GLOBAL_PADDING = 20;

    // Padding of the cells
    static const int CELL_PADDING = 4;

    // Color of Player 1
    static const QString COLOR_PLAYER_1 = "#00ffb4";

    // Color of Player 2
    static const QString COLOR_PLAYER_2 = "#ff0036";

    // Opacity of Panels
    static const double PANEL_OPACITY = 0.6;

    // Chance for special item
    static const int SPECIAL_FACTOR = 40;

    // Number of ships in a row to win
    static const int WIN_AMMOUNT = 5;

    // Number of iterations an enemy should think
    static const bool AI_ENABLED = true;

    // Number of iterations an enemy should think
    static const int AI_ITERATIONS = 20;

    //Switch to turn of KI
    static const bool KI_ENABLED = false;
}

#endif // SETTINGS_H
