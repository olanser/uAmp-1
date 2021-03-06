#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// LOCAL
#include "Playlist.h"
#include "ProgressBar.h"
#include "ImageEdit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void ChangeRepeatMode();

    // TAGS EDITING
    void prepareMenu(const QPoint & pos);

    // PLAYLIST FUNCTIONS
    void OpenSong();
    void LoadSong(std::string filepath);
    void OpenPlaylist();
    void ParseM3U(std::string filepath);
    void ParseJPLAYLST(std::string filepath);
    void SavePlaylist();
    std::string FilepathToTitle(std::string filepath);

    // MESSAGES
    void ShowMessageOk(std::string message);
    void ShowErrorOk(std::string message);

    // PLAYLIST VARS
//    RepeatMode repeatMode{NoRepeat};
    unsigned int selectedSong = 0;

    // WARN VARS
    std::vector<std::string> testLst;

    // ICONS
    QImage emptyImage{"app/res/images/empty-image.png"};
    QIcon previousIcon{"app/res/images/previous.png"};
    QIcon stopIcon{"app/res/images/stop.png"};
    QIcon playIcon{"app/res/images/play.png"};
    QIcon pauseIcon{"app/res/images/pause.png"};
    QIcon nextIcon{"app/res/images/next.png"};
    QIcon repeatIcon{"app/res/images/repeat.png"};
    QIcon playlistIcon{"app/res/images/playlist.png"};
    QIcon saveIcon{"app/res/images/save.png"};
    QIcon plusIcon{"app/res/images/plus.png"};
    QIcon minusIcon{"app/res/images/minus.png"};

    // PROGRESS BAR
    ProgressBar* m_progressBar;

    // AUDIO FILES
    Playlist* m_playlist;

    // QT OBJECTS
    Ui::MainWindow *m_ui;
};

#endif // MAINWINDOW_H
