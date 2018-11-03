#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include<QMessageBox>
class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QVector<QPushButton*> vec;   // вектор кнопок
    QPushButton* createButton(int); // метод создания кнопки
    QGridLayout* ptopLayout;     // табличный layout
    QTimer *timer;               // генератор для нажатий
    int count;                   // длинна последовательности (default = 5)
    QMessageBox b;               // message box для вывода результатов
    QVector<int> order;          // порядок кнопок

public:
    MainWindow(QWidget *parent = nullptr);
    void Rand();
    void startWriting();
    ~MainWindow();
public slots:
    void update();
    void slotButtonClicked();
};

#endif // MAINWINDOW_H
