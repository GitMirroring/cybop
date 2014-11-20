/********************************************************************************
** Form generated from reading UI file 'cybolmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYBOLMAINWINDOW_H
#define UI_CYBOLMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CybolMainWindow
{
public:
    QAction *action_Neu;
    QAction *action_OEffnen;
    QAction *action_Speichern;
    QAction *action_Speichern_unter;
    QAction *action_Speichern_2;
    QAction *actionSpeichern_unter;
    QAction *action_Drucken;
    QAction *action_Vorschaubild_speichern;
    QAction *actionSchli_e_en;
    QAction *action_Beenden;
    QAction *actionR_ckg_ngig;
    QAction *actionWiederherstellen;
    QAction *actionAusschneiden;
    QAction *actionKopieren;
    QAction *actionEinf_gen;
    QAction *actionL_schen;
    QAction *actionAlles_Ausw_hlen;
    QAction *actionNach_hinten;
    QAction *actionNach_Vorne;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_Datein;
    QMenu *menu_Bearbeiten;
    QMenu *menuAnsicht;
    QMenu *menuEinstellungen;
    QMenu *menuFenster;
    QMenu *menuHilfe;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *widgetbox;
    QWidget *contentWidgetBox;
    QDockWidget *objectinspector;
    QWidget *contentObjectInspector;

    void setupUi(QMainWindow *CybolMainWindow)
    {
        if (CybolMainWindow->objectName().isEmpty())
            CybolMainWindow->setObjectName(QStringLiteral("CybolMainWindow"));
        CybolMainWindow->resize(784, 615);
        action_Neu = new QAction(CybolMainWindow);
        action_Neu->setObjectName(QStringLiteral("action_Neu"));
        action_OEffnen = new QAction(CybolMainWindow);
        action_OEffnen->setObjectName(QStringLiteral("action_OEffnen"));
        action_Speichern = new QAction(CybolMainWindow);
        action_Speichern->setObjectName(QStringLiteral("action_Speichern"));
        action_Speichern_unter = new QAction(CybolMainWindow);
        action_Speichern_unter->setObjectName(QStringLiteral("action_Speichern_unter"));
        action_Speichern_2 = new QAction(CybolMainWindow);
        action_Speichern_2->setObjectName(QStringLiteral("action_Speichern_2"));
        actionSpeichern_unter = new QAction(CybolMainWindow);
        actionSpeichern_unter->setObjectName(QStringLiteral("actionSpeichern_unter"));
        action_Drucken = new QAction(CybolMainWindow);
        action_Drucken->setObjectName(QStringLiteral("action_Drucken"));
        action_Vorschaubild_speichern = new QAction(CybolMainWindow);
        action_Vorschaubild_speichern->setObjectName(QStringLiteral("action_Vorschaubild_speichern"));
        actionSchli_e_en = new QAction(CybolMainWindow);
        actionSchli_e_en->setObjectName(QStringLiteral("actionSchli_e_en"));
        action_Beenden = new QAction(CybolMainWindow);
        action_Beenden->setObjectName(QStringLiteral("action_Beenden"));
        actionR_ckg_ngig = new QAction(CybolMainWindow);
        actionR_ckg_ngig->setObjectName(QStringLiteral("actionR_ckg_ngig"));
        actionWiederherstellen = new QAction(CybolMainWindow);
        actionWiederherstellen->setObjectName(QStringLiteral("actionWiederherstellen"));
        actionAusschneiden = new QAction(CybolMainWindow);
        actionAusschneiden->setObjectName(QStringLiteral("actionAusschneiden"));
        actionKopieren = new QAction(CybolMainWindow);
        actionKopieren->setObjectName(QStringLiteral("actionKopieren"));
        actionEinf_gen = new QAction(CybolMainWindow);
        actionEinf_gen->setObjectName(QStringLiteral("actionEinf_gen"));
        actionL_schen = new QAction(CybolMainWindow);
        actionL_schen->setObjectName(QStringLiteral("actionL_schen"));
        actionAlles_Ausw_hlen = new QAction(CybolMainWindow);
        actionAlles_Ausw_hlen->setObjectName(QStringLiteral("actionAlles_Ausw_hlen"));
        actionNach_hinten = new QAction(CybolMainWindow);
        actionNach_hinten->setObjectName(QStringLiteral("actionNach_hinten"));
        actionNach_Vorne = new QAction(CybolMainWindow);
        actionNach_Vorne->setObjectName(QStringLiteral("actionNach_Vorne"));
        centralWidget = new QWidget(CybolMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(153, 153, 153, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(230, 230, 230, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(191, 191, 191, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(76, 76, 76, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(102, 102, 102, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(204, 204, 204, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        centralWidget->setPalette(palette);
        CybolMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CybolMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 784, 21));
        menu_Datein = new QMenu(menuBar);
        menu_Datein->setObjectName(QStringLiteral("menu_Datein"));
        menu_Bearbeiten = new QMenu(menuBar);
        menu_Bearbeiten->setObjectName(QStringLiteral("menu_Bearbeiten"));
        menuAnsicht = new QMenu(menuBar);
        menuAnsicht->setObjectName(QStringLiteral("menuAnsicht"));
        menuEinstellungen = new QMenu(menuBar);
        menuEinstellungen->setObjectName(QStringLiteral("menuEinstellungen"));
        menuFenster = new QMenu(menuBar);
        menuFenster->setObjectName(QStringLiteral("menuFenster"));
        menuHilfe = new QMenu(menuBar);
        menuHilfe->setObjectName(QStringLiteral("menuHilfe"));
        CybolMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CybolMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CybolMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CybolMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CybolMainWindow->setStatusBar(statusBar);
        widgetbox = new QDockWidget(CybolMainWindow);
        widgetbox->setObjectName(QStringLiteral("widgetbox"));
        widgetbox->setMinimumSize(QSize(146, 38));
        widgetbox->setFeatures(QDockWidget::AllDockWidgetFeatures);
        widgetbox->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        contentWidgetBox = new QWidget();
        contentWidgetBox->setObjectName(QStringLiteral("contentWidgetBox"));
        contentWidgetBox->setLayoutDirection(Qt::LeftToRight);
        widgetbox->setWidget(contentWidgetBox);
        CybolMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), widgetbox);
        objectinspector = new QDockWidget(CybolMainWindow);
        objectinspector->setObjectName(QStringLiteral("objectinspector"));
        objectinspector->setMinimumSize(QSize(146, 38));
        objectinspector->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        contentObjectInspector = new QWidget();
        contentObjectInspector->setObjectName(QStringLiteral("contentObjectInspector"));
        objectinspector->setWidget(contentObjectInspector);
        CybolMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), objectinspector);

        menuBar->addAction(menu_Datein->menuAction());
        menuBar->addAction(menu_Bearbeiten->menuAction());
        menuBar->addAction(menuAnsicht->menuAction());
        menuBar->addAction(menuEinstellungen->menuAction());
        menuBar->addAction(menuFenster->menuAction());
        menuBar->addAction(menuHilfe->menuAction());
        menu_Datein->addAction(action_Neu);
        menu_Datein->addAction(action_OEffnen);
        menu_Datein->addAction(action_Speichern);
        menu_Datein->addSeparator();
        menu_Datein->addAction(action_Speichern_2);
        menu_Datein->addAction(actionSpeichern_unter);
        menu_Datein->addSeparator();
        menu_Datein->addAction(action_Drucken);
        menu_Datein->addAction(action_Vorschaubild_speichern);
        menu_Datein->addSeparator();
        menu_Datein->addAction(actionSchli_e_en);
        menu_Datein->addSeparator();
        menu_Datein->addAction(action_Beenden);
        menu_Bearbeiten->addAction(actionR_ckg_ngig);
        menu_Bearbeiten->addAction(actionWiederherstellen);
        menu_Bearbeiten->addSeparator();
        menu_Bearbeiten->addAction(actionAusschneiden);
        menu_Bearbeiten->addAction(actionKopieren);
        menu_Bearbeiten->addAction(actionEinf_gen);
        menu_Bearbeiten->addAction(actionL_schen);
        menu_Bearbeiten->addAction(actionAlles_Ausw_hlen);
        menu_Bearbeiten->addSeparator();
        menu_Bearbeiten->addAction(actionNach_hinten);
        menu_Bearbeiten->addAction(actionNach_Vorne);
        menu_Bearbeiten->addSeparator();

        retranslateUi(CybolMainWindow);

        QMetaObject::connectSlotsByName(CybolMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CybolMainWindow)
    {
        CybolMainWindow->setWindowTitle(QApplication::translate("CybolMainWindow", "CybolMainWindow", 0));
        action_Neu->setText(QApplication::translate("CybolMainWindow", "&Neu", 0));
        action_OEffnen->setText(QApplication::translate("CybolMainWindow", "&\303\226ffnen", 0));
        action_OEffnen->setShortcut(QApplication::translate("CybolMainWindow", "Ctrl+O", 0));
        action_Speichern->setText(QApplication::translate("CybolMainWindow", "&Zuletzt ge\303\266ffnete Formulare", 0));
        action_Speichern_unter->setText(QApplication::translate("CybolMainWindow", "&Speichern unter", 0));
        action_Speichern_2->setText(QApplication::translate("CybolMainWindow", "&Speichern", 0));
        actionSpeichern_unter->setText(QApplication::translate("CybolMainWindow", "Speichern &unter", 0));
        action_Drucken->setText(QApplication::translate("CybolMainWindow", "&Drucken", 0));
        action_Vorschaubild_speichern->setText(QApplication::translate("CybolMainWindow", "&Vorschaubild speichern", 0));
        actionSchli_e_en->setText(QApplication::translate("CybolMainWindow", "Schli&e\303\237en", 0));
        action_Beenden->setText(QApplication::translate("CybolMainWindow", "&Beenden", 0));
        actionR_ckg_ngig->setText(QApplication::translate("CybolMainWindow", "R\303\274ckg\303\244ngig", 0));
        actionWiederherstellen->setText(QApplication::translate("CybolMainWindow", "Wiederherstellen", 0));
        actionAusschneiden->setText(QApplication::translate("CybolMainWindow", "Ausschneiden", 0));
        actionKopieren->setText(QApplication::translate("CybolMainWindow", "Kopieren", 0));
        actionEinf_gen->setText(QApplication::translate("CybolMainWindow", "Einf\303\274gen", 0));
        actionL_schen->setText(QApplication::translate("CybolMainWindow", "L\303\266schen", 0));
        actionAlles_Ausw_hlen->setText(QApplication::translate("CybolMainWindow", "Alles Ausw\303\244hlen", 0));
        actionNach_hinten->setText(QApplication::translate("CybolMainWindow", "Nach hinten", 0));
        actionNach_Vorne->setText(QApplication::translate("CybolMainWindow", "Nach vorne", 0));
        menu_Datein->setTitle(QApplication::translate("CybolMainWindow", "&Datei", 0));
        menu_Bearbeiten->setTitle(QApplication::translate("CybolMainWindow", "&Bearbeiten", 0));
        menuAnsicht->setTitle(QApplication::translate("CybolMainWindow", "Ansicht", 0));
        menuEinstellungen->setTitle(QApplication::translate("CybolMainWindow", "Einstellungen", 0));
        menuFenster->setTitle(QApplication::translate("CybolMainWindow", "Fenster", 0));
        menuHilfe->setTitle(QApplication::translate("CybolMainWindow", "Hilfe", 0));
        widgetbox->setWindowTitle(QApplication::translate("CybolMainWindow", "Widgetbox", 0));
        objectinspector->setWindowTitle(QApplication::translate("CybolMainWindow", "Objektinspektor", 0));
    } // retranslateUi

};

namespace Ui {
    class CybolMainWindow: public Ui_CybolMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYBOLMAINWINDOW_H
