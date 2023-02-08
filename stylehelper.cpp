#include "stylehelper.h"


QString StyleHelper::getMainWidgetStyle()
{
    return
    "QWidget{"
        "background-image:url(:/resources/images/bg.png);"
    "}";
}

QString StyleHelper::getStartButtonsStyle()
{
    return
    "QPushButton{"
        "color: #fff;"
        "background: none;"
        "border: none;"
        "border-radius: 19px;"
        "background-color: qlineargradient(spread:pad, x1:0.0391061, y1:0.023, x2:1, y2:1, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
        "font-family: 'RobotoMedium';"
        "font-size: 16px;"
        "}"
    "QPushButton::hover{"
        "background-color: qlineargradient(spread:pad, x1:0.0391061, y1:0.023, x2:1, y2:1, stop:0 rgba(98, 173, 230, 255), stop:0.988827 rgba(77, 140, 218, 255), stop:1 rgba(65, 118, 184, 255));"
    "}"
    "QPushButton::pressed{"
        "background-color: qlineargradient(spread:pad, x1:0.0391061, y1:0.023, x2:1, y2:1, stop:0 rgba(146, 193, 230, 255), stop:0.988827 rgba(101, 157, 226, 255), stop:1 rgba(65, 118, 184, 255));"
    "}";
}

QString StyleHelper::getStartButtonGameStyle()
{
    return
    "QPushButton{"
        "color: #fff;"
        "background: none;"
        "border: none;"
        "border-radius: 19px;"
        "background-color: qlineargradient(spread:pad, x1:0.502793, y1:0.063, x2:0.530726, y2:1, stop:0 rgba(202, 51, 53, 255), stop:1 rgba(255, 218, 218, 255));"
        "font-family: 'RobotoMedium';"
        "font-size: 16px;"
        "}"
    "QPushButton::hover{"
        "background-color: qlineargradient(spread:pad, x1:0.502793, y1:0.063, x2:0.530726, y2:1, stop:0 rgba(202, 103, 105, 255), stop:1 rgba(255, 239, 239, 255));"
    "}"
    "QPushButton::pressed{"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(121, 121, 121, 255), stop:1 rgba(89, 89, 89, 255));"""
    "}";
}

QString StyleHelper::getNormalMessageStyle()
{
    return
    "QLabel{"
        "font-family: 'Roboto Medium';"
        "font-size: 12px;"
        "background: none;"
        "color: #ffffff"
    "}";
}

QString StyleHelper::getVictoryMessageStyle()
{
    return
    "QLabel{"
        "font-family: 'Roboto Medium';"
        "font-size: 12px;"
        "background: #055902;"
        "border: 1px solid #1C7C32;"
        "color: #ffffff"
    "}";
}

QString StyleHelper::getLostMessageStyle()
{
    return
    "QLabel{"
        "font-family: 'Roboto Medium';"
        "font-size: 12px;"
        "background: #961F99;"
        "border: 1px solid #E237F5;"
        "color: #ffffff"
    "}";
}

QString StyleHelper::getLeftButtonStyle()
{
    return
    "QPushButton{"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(121, 121, 121, 255), stop:1 rgba(89, 89, 89, 255));"
        "background-image: url(:/resources/images/cross_small.png);"
        "background-repeat: no-repeat;"
        "background-position: center center;"
        "border: 1px solid #333;"
        "border-top-left-radius: 5px;"
        "border-bottom-left-radius: 5px;"
    "}";
}

QString StyleHelper::getRightButtonStyle()
{
    return
    "QPushButton{"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(121, 121, 121, 255), stop:1 rgba(89, 89, 89, 255));"
        "background-image: url(:/resources/images/zero_small.png);"
        "background-repeat: no-repeat;"
        "background-position: center center;"
        "border: 1px solid #333;"
        "border-left: none;"
        "border-top-right-radius: 5px;"
        "border-bottom-right-radius: 5px;"
    "}";
}

QString StyleHelper::getLeftButtonActiveStyle()
{
    return
    "QPushButton{"
        "background-color: #2d313b;"
        "background-image: url(:/resources/images/cross_small.png);"
        "background-repeat: no-repeat;"
        "background-position: center center;"
        "border: 1px solid #333;"
        "border-top-left-radius: 5px;"
        "border-bottom-left-radius: 5px;"
    "}";
}

QString StyleHelper::getRightButtonActiveStyle()
{
    return
    "QPushButton{"
        "background-color: #2d313b;"
        "background-image: url(:/resources/images/zero_small.png);"
        "background-repeat: no-repeat;"
        "background-position: center center;"
        "border: 1px solid #333;"
        "border-left: none;"
        "border-top-right-radius: 5px;"
        "border-bottom-right-radius: 5px;"
    "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return
    "QTabWidget{"
        "border: none;"
    "}"
    "QTabWidget::pane{"
        "border: none;"
        "border: 1px solid #222;"
        "border-radius: 3px;"
    "}";
}

QString StyleHelper::getTabStyle()
{
    return
    "QWidget{"
        "background: none;"
        "background: rgb(33, 40, 50);"
    "}";
}

QString StyleHelper::getBlankButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #272D39;"
    "}"
    "QPushButton::hover{"
        "background: #373D49;"
    "}";
}

QString StyleHelper::getCrossNormalButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #272D39 url(:/resources/images/cross_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getCrossVictoryButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #20401B url(:/resources/images/cross_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getCrossLostButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #7F1F8C url(:/resources/images/cross_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getZeroNormalButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #272D39 url(:/resources/images/zero_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getZeroVictoryButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #20401B url(:/resources/images/zero_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getZeroLostButtonStyle()
{
    return
    "QPushButton{"
        "border: none;"
        "background: #7F1F8C url(:/resources/images/zero_large.png) no-repeat center center;"
    "}";
}

QString StyleHelper::getAboutTextStyle()
{
    return
    "QLabel{"
        "font-famaly: 'Roboto Medium';"
        "font-size: 12px;"
        "color: #ffffff;"
        "font-style:italic;"
    "}";
}

