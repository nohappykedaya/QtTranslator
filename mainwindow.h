#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dictmanager.h"
#include "apimanager.h"
#include "favoritesmanage.h"
#include "qlistwidget.h"
#include "ttsmanager.h"
#include "historymanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    dictmanager dictManager;
    apimanager apiManager;
    historymanager historyManager;
    favoritesmanage favoritesManager;
    ttsmanager ttsManager;

    void updateHistory();
    void updateFavorites();
private slots:
    void on_pushButton_query_clicked();
    void on_pushButton_favorite_clicked();
    void on_listWidget_history_itemClicked(QListWidgetItem *item);
    void on_listWidget_favorite_itemClicked(QListWidgetItem *item);
    void on_pushButton_speak_clicked();
    void on_onlineResultReady(const QString &result);
};
#endif // MAINWINDOW_H
