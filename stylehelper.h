#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

class StyleHelper
{
public:
    // Style
    // left window
        // label
        static QString getMainWidgetStyle();
        static QString getStartButtonsStyle();
        static QString getStartButtonGameStyle();
        static QString getNormalMessageStyle();
        static QString getVictoryMessageStyle();
        static QString getLostMessageStyle();
        // buttons
        static QString getLeftButtonStyle();
        static QString getRightButtonStyle();
        static QString getLeftButtonActiveStyle();
        static QString getRightButtonActiveStyle();

    // right window (tabWidget)
    static QString getTabWidgetStyle();
        // tab
        static QString getTabStyle();
            // game buttons
            static QString getBlankButtonStyle();
                // crosses
                static QString getCrossNormalButtonStyle();
                static QString getCrossVictoryButtonStyle();
                static QString getCrossLostButtonStyle();
                // zeros
                static QString getZeroNormalButtonStyle();
                static QString getZeroVictoryButtonStyle();
                static QString getZeroLostButtonStyle();
        // tab2
                static QString getAboutTextStyle();



};

#endif // STYLEHELPER_H
