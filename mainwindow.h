#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTCore>
#include <QTCharts>
#include <QtGui>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void switchFunction();
    void resetUI();

private:
    Ui::MainWindow *ui;
    bool isFirstFunction;
    QString inputFunction; // Переменная для хранения введённой строки
    double start, end, step; // Переменные для хранения границ и шага

    bool validateInputs(); // Проверка ввода
    bool validateFunction(const QString &function); // Проверка функции
};

#endif // MAINWINDOW_H
