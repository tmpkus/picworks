/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun May 16 19:48:48 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *genButton;
    QLabel *label;
    QLineEdit *wcUrlInput;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDateEdit *buildDateInput;
    QSpinBox *majorInput;
    QSpinBox *minorInput;
    QSpinBox *buildInput;
    QSpinBox *rivisionInput;
    QPushButton *fileBrowserButton;
    QLineEdit *filePathInput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(437, 160);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(437, 160));
        MainWindow->setMaximumSize(QSize(437, 160));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        genButton = new QPushButton(centralWidget);
        genButton->setObjectName(QString::fromUtf8("genButton"));
        genButton->setGeometry(QRect(180, 130, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 21));
        wcUrlInput = new QLineEdit(centralWidget);
        wcUrlInput->setObjectName(QString::fromUtf8("wcUrlInput"));
        wcUrlInput->setGeometry(QRect(90, 10, 321, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 70, 41, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 31, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 70, 41, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 71, 54, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 61, 21));
        buildDateInput = new QDateEdit(centralWidget);
        buildDateInput->setObjectName(QString::fromUtf8("buildDateInput"));
        buildDateInput->setGeometry(QRect(90, 40, 110, 22));
        majorInput = new QSpinBox(centralWidget);
        majorInput->setObjectName(QString::fromUtf8("majorInput"));
        majorInput->setGeometry(QRect(50, 70, 42, 22));
        minorInput = new QSpinBox(centralWidget);
        minorInput->setObjectName(QString::fromUtf8("minorInput"));
        minorInput->setGeometry(QRect(150, 70, 42, 22));
        buildInput = new QSpinBox(centralWidget);
        buildInput->setObjectName(QString::fromUtf8("buildInput"));
        buildInput->setGeometry(QRect(250, 70, 42, 22));
        rivisionInput = new QSpinBox(centralWidget);
        rivisionInput->setObjectName(QString::fromUtf8("rivisionInput"));
        rivisionInput->setGeometry(QRect(370, 70, 42, 22));
        fileBrowserButton = new QPushButton(centralWidget);
        fileBrowserButton->setObjectName(QString::fromUtf8("fileBrowserButton"));
        fileBrowserButton->setGeometry(QRect(340, 100, 75, 21));
        filePathInput = new QLineEdit(centralWidget);
        filePathInput->setObjectName(QString::fromUtf8("filePathInput"));
        filePathInput->setGeometry(QRect(11, 100, 321, 21));
        MainWindow->setCentralWidget(centralWidget);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(wcUrlInput);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VerGen", 0, QApplication::UnicodeUTF8));
        genButton->setText(QApplication::translate("MainWindow", "generate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Workcopy URL", 0, QApplication::UnicodeUTF8));
        wcUrlInput->setText(QApplication::translate("MainWindow", "http://picworks.hg.sourceforge.net:8000/hgroot/picworks/picworks", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Minor", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Major", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Build", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Rivision", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Build Date", 0, QApplication::UnicodeUTF8));
        fileBrowserButton->setText(QApplication::translate("MainWindow", "Browser...", 0, QApplication::UnicodeUTF8));
        filePathInput->setText(QApplication::translate("MainWindow", "version.in", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
