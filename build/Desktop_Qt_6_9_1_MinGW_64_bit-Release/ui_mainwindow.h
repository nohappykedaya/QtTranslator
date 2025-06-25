/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_query;
    QPushButton *pushButton_speak;
    QPushButton *pushButton_favorite;
    QTextEdit *textEdit_result;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_history;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget_favorite;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(502, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 471, 485));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_search = new QLineEdit(widget);
        lineEdit_search->setObjectName("lineEdit_search");

        horizontalLayout->addWidget(lineEdit_search);

        pushButton_query = new QPushButton(widget);
        pushButton_query->setObjectName("pushButton_query");

        horizontalLayout->addWidget(pushButton_query);

        pushButton_speak = new QPushButton(widget);
        pushButton_speak->setObjectName("pushButton_speak");

        horizontalLayout->addWidget(pushButton_speak);

        pushButton_favorite = new QPushButton(widget);
        pushButton_favorite->setObjectName("pushButton_favorite");

        horizontalLayout->addWidget(pushButton_favorite);


        verticalLayout->addLayout(horizontalLayout);

        textEdit_result = new QTextEdit(widget);
        textEdit_result->setObjectName("textEdit_result");

        verticalLayout->addWidget(textEdit_result);

        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget_history = new QListWidget(tab);
        listWidget_history->setObjectName("listWidget_history");

        horizontalLayout_2->addWidget(listWidget_history);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        listWidget_favorite = new QListWidget(tab_2);
        listWidget_favorite->setObjectName("listWidget_favorite");

        horizontalLayout_3->addWidget(listWidget_favorite);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ShaO_o\347\232\204\347\256\200\346\230\223\347\277\273\350\257\221\350\275\257\344\273\266", nullptr));
        pushButton_query->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_speak->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\237\263", nullptr));
        pushButton_favorite->setText(QCoreApplication::translate("MainWindow", "\346\224\266\350\227\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\224\266\350\227\217\345\244\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
