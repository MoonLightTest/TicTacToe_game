#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"
#include <QTabBar>
#include <QStyleOption>
#include <QFontDatabase>
#include <QGridLayout>
#include <QDebug>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configurationTabWidget();
    setInterfaceStyle();
    addFonts();
    configurationGameAreaButtons();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onComputerSlot);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}

void MainWindow::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
     ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
     ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
     changeLeftRightButtonStatus(1);
     ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
     ui->tab->setStyleSheet(StyleHelper::getTabStyle());
     ui->tab_2->setStyleSheet(StyleHelper::getTabStyle());

     ui->label_3->setStyleSheet(StyleHelper::getAboutTextStyle());

     ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());
     ui->messageLabel->setText("Ходят крестики");

     setGameAreaButtonStyle();
     ui->messageLabel->setText("");
     ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
}

// переключение крестиков-ноликов
void MainWindow::changeLeftRightButtonStatus(bool num)
{
    if (num)
    {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    }
    else
    {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

void MainWindow::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::configurationGameAreaButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            QPushButton *btn = qobject_cast<QPushButton*>(grid->itemAtPosition(row, column)->widget());
            btn->setProperty("row", row);
            btn->setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &MainWindow::onGameAreaButtonClicked);
        }
    }
}

void MainWindow::addFonts()
{
    QFontDatabase::addApplicationFont(":/resources/fonts/Roboto-Medium.ttf"); // font name = "Roboto Medium"
    QFontDatabase::addApplicationFont(":/resources/fonts/Roboto-MediumItalic.ttf"); // font-style: italic
}

void MainWindow::changeButtonStyle(int row, int column, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    QPushButton *btn = qobject_cast <QPushButton*>(grid->itemAtPosition(row, column)->widget());
    btn->setStyleSheet(style);
}

void MainWindow::setGameAreaButtonStyle()
{
    QString style = StyleHelper::getBlankButtonStyle();
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++){
            changeButtonStyle(row, column, style);
        }
    }
}

void MainWindow::start()
{
    setGameAreaButtonStyle();
    for (int i = 0; i < 3; i++)
        for (int i2 = 0; i2 < 3; i2++)
            gameArea[i][i2] = '-';
    progress = 0;
    gameStart = true;
    if(player != 'X')
        computerInGame();
}

void MainWindow::lockPlayer()
{
    if ((player == 'X') && (gameStart)){
        playerLocked = false;
    }
    else{
        playerLocked = true;
    }
}

// Если игрок выбрал крестики
void MainWindow::on_leftButton_clicked()
{
    changeLeftRightButtonStatus(1);
    player = 'X';
}

// Если игрок выбрал нолики
void MainWindow::on_rightButton_clicked()
{
    changeLeftRightButtonStatus(0);
    player = '0';
}


void MainWindow::on_startButton_clicked()
{
    if (gameStart){
        playerLocked = true;
        ui->startButton->setText("Играть");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
        ui->messageLabel->setText("Проиграл");
        ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
    }
    else{
        ui->messageLabel->setText("Поехали!");
        ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
        start();
        lockPlayer();
        ui->startButton->setText("Сдаюсь...");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonGameStyle());
        ui->leftButton->setDisabled(true);
        ui->rightButton->setDisabled(true);
    }
}

void MainWindow::onGameAreaButtonClicked()
{
    if (!playerLocked){
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int row = btn->property("row").toInt();
        int column = btn->property("column").toInt();
        if (gameArea[row][column] != '-')
            return;
        QString style;
        if (player == 'X')
            style = StyleHelper::getCrossNormalButtonStyle();
        else
            style = StyleHelper::getZeroNormalButtonStyle();
        changeButtonStyle(row, column, style);
        gameArea[row][column] = player;
        playerLocked = true;
        checkGameStop();
        computerInGame();
    }
}

void MainWindow::computerInGame()
{
    srand(time(0));
    if (!gameStart)
        return;
    int index = rand()%3;
    QStringList list = {"Мой ход", "Так так так...", "Дайте подумать..."};
    ui->messageLabel->setText(list.at(index));
    timer->start(2000);

}

void MainWindow::checkGameStop()
{
    if (gameArea[1][1] != '-'){
        if ((gameArea[0][0] == gameArea[1][1]) && (gameArea[1][1] == gameArea[2][2])){
            endGame(gameArea[1][1], {0, 0}, {1, 1}, {2, 2});
            return;
        }
        if ((gameArea[0][2] == gameArea[1][1]) && (gameArea[1][1] == gameArea[2][0])){
            endGame(gameArea[1][1], {0, 2}, {1, 1}, {2, 0});
            return;
        }

    }
    unsigned int counter = 0;
    for (int row = 0; row < 3; row++){
        int count = 0;
        int count2 = 0;
        for (int column = 0; column < 3; column++){
            if (gameArea[row][column] != '-')
                counter++;
            // X
            if (gameArea[row][column] == 'X')
                count++;
            if (gameArea[column][row] == 'X')
                count2++;
            // 0
            if (gameArea[row][column] == '0')
                count--;
            if (gameArea[column][row] == '0')
                count2--;
        }
        if ((count == 3) || (count == -3)){
            endGame(gameArea[row][0], {row, 0}, {row, 1}, {row, 2});
            return;
        }
        if ((count2 == 3) || (count2 == -3)){
            endGame(gameArea[0][row], {0, row}, {1, row}, {2, row});
            return;
        }
    }
    if (counter == 9)
        endGame('-', {0, 0}, {0, 0}, {0, 0});
}

void MainWindow::endGame(char winner, QPair<int, int> x, QPair<int, int> y, QPair<int, int> z)
{
    playerLocked = true;
    gameStart = false;
    QString style;
    ui->startButton->setText("Начать новую игру");
    ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    if (winner == player){
        ui->messageLabel->setText("Победа!");
        ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());
        if (player == 'X')
            style = StyleHelper::getCrossVictoryButtonStyle();
        else
            style = StyleHelper::getZeroVictoryButtonStyle();
    }
    else if (winner == '-'){
        ui->messageLabel->setText("Ничья...");
        ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle()); // !
    }
    else{
        ui->messageLabel->setText("Проиграл...");
        ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
        if (player == 'X')
            style = StyleHelper::getZeroLostButtonStyle();
        else
            style = StyleHelper::getCrossLostButtonStyle();
    }

    if (winner != '-'){
        changeButtonStyle(x.first, x.second, style);
        changeButtonStyle(y.first, y.second, style);
        changeButtonStyle(z.first, z.second, style);
    }

    ui->leftButton->setDisabled(false);
    ui->rightButton->setDisabled(false);
}


void MainWindow::onComputerSlot()
{
    char computer;
    QString style;
    if (player == 'X'){
        computer = '0';
        style = StyleHelper::getZeroNormalButtonStyle();
    }
    else{
        computer = 'X';
        style = StyleHelper::getCrossNormalButtonStyle();
    }
    timer->stop();
    while(true){
        int row = rand()%3;
        int column = rand()%3;
        if (gameArea[row][column] == '-'){
            gameArea[row][column] = computer;
            changeButtonStyle(row, column, style);
            ui->messageLabel->setText("Твой ход!");
            checkGameStop();
            playerLocked = false;
            break;
        }
    }
}


void MainWindow::on_aboutButton_clicked()
{
    if (!activeTab){
        ui->tabWidget->setCurrentIndex(1);
        ui->startButton->setVisible(false);
        ui->leftButton->setVisible(false);
        ui->rightButton->setVisible(false);
        ui->label->setVisible(false);
        ui->messageLabel->setVisible(false);
        ui->aboutButton->setText("назад");
        activeTab = 1;
    }
    else{
        ui->tabWidget->setCurrentIndex(0);
        ui->startButton->setVisible(true);
        ui->leftButton->setVisible(true);
        ui->rightButton->setVisible(true);
        ui->label->setVisible(true);
        ui->messageLabel->setVisible(true);
        ui->aboutButton->setText("Об игре");
        activeTab = 0;
    }
}

