#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <libs/backend.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isFirstFunction(true)
{
    ui->setupUi(this);


    // Подключение кнопок к слотам
    connect(ui->switchButton, &QPushButton::clicked, this, &MainWindow::switchFunction);
    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::resetUI);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validateInputs()
{
    bool ok;
    double tempStart = ui->startInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректную начальную границу.");
        return false;
    }

    double tempEnd = ui->endInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректную конечную границу.");
        return false;
    }

    if (tempEnd < tempStart) {
        QMessageBox::warning(this, "Ошибка", "Конечная граница не может быть меньше начальной.");
        return false;
    }

    double tempStep = ui->stepInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректный шаг.");
        return false;
    }

    if (tempStep > (tempEnd - tempStart)) {
        QMessageBox::warning(this, "Ошибка", "Шаг не может превышать расстояние между границами.");
        return false;
    }

    start = tempStart;
    end = tempEnd;
    step = tempStep;
    return true;
}

bool MainWindow::validateFunction(const QString &function)
{
    // Проверка на наличие 'x' и допустимые символы и выражения
    QRegularExpression regex("^[x0-9+\\-*/^()%&|! ]*$|opposite|factorial|sin|cos|tan|acos|asin|atan");
    if (!function.contains('x') || !regex.match(function).hasMatch()) {
        return false;
    }
    return true;
}

void MainWindow::switchFunction()
{
    // Сохранение введённой строки в переменную
    inputFunction = ui->functionInput->text();

    // Проверка на пустую строку
    if (inputFunction.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите функцию.");
        return;
    }

    // Проверка валидности функции
    if (!validateFunction(inputFunction)) {
        QMessageBox::warning(this, "Ошибка", "Функция должна содержать переменную 'x' и допустимые символы: +, -, *, /, ^, %, &, |, !, (), opposite, factorial, sin, cos, tan, acos, asin, atan.");
        return;
    }

    // Проверка валидности введённых данных
    if (!validateInputs()) {
        return;
    }

    // Скрытие кнопок и полей для ввода
    ui->functionInput->setVisible(false);
    ui->startInput->setVisible(false);
    ui->endInput->setVisible(false);
    ui->stepInput->setVisible(false);
    ui->switchButton->setVisible(false);
    ui->infoLabel->setVisible(false);

    // Показ новых текстовых полей и кнопки "Вернуться назад"
    ui->outputLabel1->setVisible(true);
    ui->outputLabel2->setVisible(true);
    ui->backButton->setVisible(true);

    // Установка текста в новых текстовых полях
    ui->outputLabel1->setText(QString("Введённая функция: %1").arg(inputFunction));
    ui->outputLabel2->setText(QString("Границы: [%1, %2], Шаг: %3").arg(start).arg(end).arg(step));

    QLineSeries* series = new QLineSeries();
    series->setName("График исходной функции");
    QLineSeries* series2 = new QLineSeries();
    series2->setName("График производной");

    std::string stdString = inputFunction.toStdString();
    for (double x = start; x <= end+1; x += step) {
        series->append(x, getDot(stdString, x));
        series2->append(x, tryDif(stdString, x));
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series2);
    chart->legend()->setVisible(true);
    chart->setGeometry(800, 800, 800, 800);
    chart->setTitle("График функций");
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(-end - 5.0, end + 5.0);
    chart->axes(Qt::Horizontal).first()->setRange(start - 5.0, end + 5.0);
    chart->setTheme(QChart::ChartTheme::ChartThemeBrownSand);
    chart->setVisible(true);


    QChartView *chartview = new QChartView(chart);
    chartview -> setRenderHint(QPainter::Antialiasing);
    chartview -> setVisible(true);


}

void MainWindow::resetUI()
{
    // Скрытие новых текстовых полей и кнопки "Вернуться назад"
    ui->outputLabel1->setVisible(false);
    ui->outputLabel2->setVisible(false);
    ui->backButton->setVisible(false);

    // Показ кнопок и полей для ввода
    ui->functionInput->setVisible(true);
    ui->startInput->setVisible(true);
    ui->endInput->setVisible(true);
    ui->stepInput->setVisible(true);
    ui->switchButton->setVisible(true);
    ui->infoLabel->setVisible(true);

    // Восстановление ранее введённой строки в поле ввода
    ui->functionInput->setText(inputFunction);
}
