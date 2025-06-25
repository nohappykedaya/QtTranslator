#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&apiManager, &apimanager::resultReady, this, &MainWindow::on_onlineResultReady);

    updateHistory();
    updateFavorites();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_query_clicked() {
    QString word = ui->lineEdit_search->text().trimmed();
    if (word.isEmpty()) return;

    QString result = dictManager.query(word);
    if (!result.isEmpty()) {
        ui->textEdit_result->setText(result);
        historyManager.addHistory(word, result);
        updateHistory();
    } else {
        ui->textEdit_result->setText("正在查询在线翻译...");
        apiManager.queryOnline(word);
    }
}

void MainWindow::on_onlineResultReady(const QString &result) {
    QString word = ui->lineEdit_search->text().trimmed();
    ui->textEdit_result->setText(result);
    historyManager.addHistory(word, result);
    updateHistory();
}

void MainWindow::on_pushButton_favorite_clicked() {
    QString word = ui->lineEdit_search->text().trimmed();
    QString result = ui->textEdit_result->toPlainText();
    if (word.isEmpty() || result.isEmpty()) return;
    favoritesManager.addFavorite(word, result);
    updateFavorites();
}

void MainWindow::on_listWidget_history_itemClicked(QListWidgetItem *item) {
    QString word = item->text();
    QString result = historyManager.getResult(word);
    ui->lineEdit_search->setText(word);
    ui->textEdit_result->setText(result);
}

void MainWindow::on_listWidget_favorite_itemClicked(QListWidgetItem *item) {
    QString word = item->text();
    QString result = favoritesManager.getResult(word);
    ui->lineEdit_search->setText(word);
    ui->textEdit_result->setText(result);
}

void MainWindow::on_pushButton_speak_clicked() {
    QString text = ui->textEdit_result->toPlainText().trimmed();
    if (!text.isEmpty())
        ttsManager.speak(text);
}

void MainWindow::updateHistory() {
    ui->listWidget_history->clear();
    for (const QString &word : historyManager.getAllWords()) {
        ui->listWidget_history->addItem(word);
    }
}

void MainWindow::updateFavorites() {
    ui->listWidget_favorite->clear();
    for (const QString &word : favoritesManager.getAllWords()) {
        ui->listWidget_favorite->addItem(word);
    }
}
