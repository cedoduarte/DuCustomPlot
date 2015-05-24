#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QVBoxLayout;
class QCustomPlot;
class DuPlot;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    QVBoxLayout *mLayout;
    QCustomPlot *mPlot;
    DuPlot *mRaizCuadradaX;
    DuPlot *mRaizCuadradaXN;
    DuPlot *mSenoX;
    DuPlot *mCosenoX;

    void calculaValoresRaizCuadradaX();
    void calculaValoresRaizCuadradaXN();
    void calculaValoresSenoX();
    void calculaValoresCosenoX();
};

#endif // WIDGET_H
