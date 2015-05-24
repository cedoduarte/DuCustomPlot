#include "Widget.h"
#include "ui_Widget.h"
#include "qcustomplot.h"
#include "DuPlot.h"
#include <QVBoxLayout>
#include <QtMath>

#define XMIN -10.0
#define XMAX 10.0
#define YMIN -10.0
#define YMAX 10.0

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLayout = new QVBoxLayout;
    mPlot = new QCustomPlot(this);

    mLayout->addWidget(mPlot);
    mLayout->setMargin(0);
    setLayout(mLayout);

    mPlot->xAxis->setRange(XMIN, XMAX);
    mPlot->yAxis->setRange(YMIN, YMAX);

    mRaizCuadradaX = new DuPlot(mPlot, this);
    calculaValoresRaizCuadradaX();
    mRaizCuadradaX->drawGraph();

    mRaizCuadradaXN = new DuPlot(mPlot, this);
    calculaValoresRaizCuadradaXN();
    mRaizCuadradaXN->drawGraph();

    mSenoX = new DuPlot(mPlot, this);
    calculaValoresSenoX();
    mSenoX->drawGraph();

    mCosenoX = new DuPlot(mPlot, this);
    calculaValoresCosenoX();
    mCosenoX->drawGraph();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculaValoresRaizCuadradaX()
{
    QVector<double> x;
    QVector<double> y;
    for (double iX = 0.0; iX < XMAX; iX += 0.1) {
        x << iX;
        y << qSqrt(iX);
    }
    mRaizCuadradaX->setX(x);
    mRaizCuadradaX->setY(y);
}

void Widget::calculaValoresRaizCuadradaXN()
{
    QVector<double> x;
    QVector<double> y;
    for (double iX = 0.0; iX < XMAX; iX += 0.1) {
        x << iX;
        y << -qSqrt(iX);
    }
    mRaizCuadradaXN->setX(x);
    mRaizCuadradaXN->setY(y);
}

void Widget::calculaValoresSenoX()
{
    QVector<double> x;
    QVector<double> y;
    for (double iX = XMIN; iX < XMAX; iX += 0.1) {
        x << iX;
        y << qSin(iX);
    }
    mSenoX->setX(x);
    mSenoX->setY(y);
}

void Widget::calculaValoresCosenoX()
{
    QVector<double> x;
    QVector<double> y;
    for (double iX = XMIN; iX < XMAX; iX += 0.1) {
        x << iX;
        y << qCos(iX);
    }
    mCosenoX->setX(x);
    mCosenoX->setY(y);
}
