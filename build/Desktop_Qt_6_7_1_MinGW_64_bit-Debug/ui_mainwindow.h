/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *functionInput;
    QLineEdit *startInput;
    QLineEdit *endInput;
    QLineEdit *stepInput;
    QPushButton *switchButton;
    QPushButton *backButton;
    QLabel *outputLabel1;
    QLabel *outputLabel2;
    QSpacerItem *verticalSpacer1;
    QLabel *infoLabel;
    QSpacerItem *verticalSpacer2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        functionInput = new QLineEdit(centralwidget);
        functionInput->setObjectName("functionInput");
        functionInput->setMinimumSize(QSize(200, 30));

        verticalLayout->addWidget(functionInput);

        startInput = new QLineEdit(centralwidget);
        startInput->setObjectName("startInput");
        startInput->setMinimumSize(QSize(200, 30));

        verticalLayout->addWidget(startInput);

        endInput = new QLineEdit(centralwidget);
        endInput->setObjectName("endInput");
        endInput->setMinimumSize(QSize(200, 30));

        verticalLayout->addWidget(endInput);

        stepInput = new QLineEdit(centralwidget);
        stepInput->setObjectName("stepInput");
        stepInput->setMinimumSize(QSize(200, 30));

        verticalLayout->addWidget(stepInput);

        switchButton = new QPushButton(centralwidget);
        switchButton->setObjectName("switchButton");
        switchButton->setMinimumSize(QSize(100, 30));

        verticalLayout->addWidget(switchButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setMinimumSize(QSize(100, 30));
        backButton->setVisible(false);

        verticalLayout->addWidget(backButton);

        outputLabel1 = new QLabel(centralwidget);
        outputLabel1->setObjectName("outputLabel1");
        outputLabel1->setVisible(false);

        verticalLayout->addWidget(outputLabel1);

        outputLabel2 = new QLabel(centralwidget);
        outputLabel2->setObjectName("outputLabel2");
        outputLabel2->setVisible(false);

        verticalLayout->addWidget(outputLabel2);

        verticalSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer1);

        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setAlignment(Qt::AlignCenter);
        infoLabel->setWordWrap(true);

        verticalLayout->addWidget(infoLabel);

        verticalSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\320\260\321\202\320\276\321\200 \320\264\320\270\321\201\320\272\321\200\320\265\321\202\320\275\321\213\321\205 \321\204\321\203\320\275\320\272\321\206\320\270\320\271", nullptr));
        functionInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\321\216...", nullptr));
        startInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\203\321\216 \320\263\321\200\320\260\320\275\320\270\321\206\321\203...", nullptr));
        endInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\275\320\265\321\207\320\275\321\203\321\216 \320\263\321\200\320\260\320\275\320\270\321\206\321\203...", nullptr));
        stepInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\210\320\260\320\263...", nullptr));
        switchButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\203\321\216!", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        outputLabel1->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\265 \320\277\320\276\320\273\320\265 1", nullptr));
        outputLabel2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\265 \320\277\320\276\320\273\320\265 2", nullptr));
        infoLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\264\320\276\320\273\320\266\320\275\320\260 \321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 'x'.\n"
"	   \320\224\320\276\320\277\321\203\321\201\321\202\320\270\320\274\321\213\320\265 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270: \"+\", \"-\", \"*\", \"/\", \"^\", \"opposite\", \"factorial\", \"sin\", \"cos\", \"tan\", \"acos\", \"asin\", \"atan\".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
