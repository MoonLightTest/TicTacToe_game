#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include <QPainter>
#include <QTimer>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_startButton_clicked();
    void onGameAreaButtonClicked();
    void onComputerSlot();

    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
    void setInterfaceStyle();
    void changeLeftRightButtonStatus(bool num);
    void configurationTabWidget();
    void configurationGameAreaButtons();
    void addFonts();
    void changeButtonStyle(int row, int column, QString Style);
    void setGameAreaButtonStyle();
    void start();
    void lockPlayer();
    void computerInGame();
    void checkGameStop();
    void endGame(char, QPair<int, int>, QPair<int, int>, QPair<int, int>);

    char gameArea[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    char player = 'X'; // 'X' or '0'
    int progress = 0;
    bool gameStart = false;
    bool playerLocked = true;
    bool activeTab = 0;

    QTimer *timer;
};
#endif // MAINWINDOW_H
