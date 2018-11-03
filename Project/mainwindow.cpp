#include "mainwindow.h"

#include <QSet>
#include <QTimer>
#include <QMessageBox>
#include <QVector>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Game");
    ptopLayout = new QGridLayout();
    int mem=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
           ptopLayout->addWidget(createButton(mem),i,j);
           mem++;
        }
    }
    this->setLayout(ptopLayout);
}

void MainWindow::Rand()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this , SLOT(update()));
    timer->start(1000);
}

void MainWindow::startWriting()
{
    QVector<QPushButton*>::Iterator it = vec.begin();
    while(it!= vec.end())
    {
        connect(*it, SIGNAL(clicked()), SLOT(slotButtonClicked()));
        it++;
    }
}

QPushButton* MainWindow::createButton(int n)
{
    QPushButton* pcmd = new QPushButton(QString::number(n));
    count = 5;
    pcmd->setMinimumSize(40, 40);
    pcmd->setMaximumSize(40, 40);
    vec.push_back(pcmd);
    return pcmd;
}

void MainWindow::update()
{
    srand( time(nullptr) );
    if (!count)
    {
        timer->stop();
        this->startWriting();
        return;
    }
    count--;
    int mem = rand()%16;
    order.push_back(mem);
    vec[mem]->animateClick();

}

void MainWindow::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();

    if (order[count] != str.toInt())
    {
        b.setText("Game over");
        b.setWindowTitle("=(");
        b.show();
        this->close();
    }
    if(count == (order.size()-1))
    {
        b.setText("You win!!!");
        b.setWindowTitle("=)");
        b.show();
        this->close();
    }
    count++;

}



MainWindow::~MainWindow()
{

}

