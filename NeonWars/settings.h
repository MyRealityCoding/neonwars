#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

namespace Settings {

    using namespace std;

    // Name of this game
    static const QString APP_TITLE = "Neon Wars";

    // Current versionr
    static const QString APP_VERSION = "0.0.1";

    // Width of the game
    static const int WINDOW_WIDTH = 640;

    // Height of the game
    static const int WINDOW_HEIGHT = 480;

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
    static const double PANEL_OPACITY = 0.1;

    // Chance for special item
    static const int SPECIAL_FACTOR = 30;
}

#endif // SETTINGS_H
