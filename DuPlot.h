#ifndef DUPLOT_H
#define DUPLOT_H

#include <QVector>
#include <QObject>

class QCPGraph;
class QCustomPlot;

class DuPlot : public QObject
{
public:
    DuPlot(QCustomPlot *parent, QObject *qtParent = nullptr);

    void drawGraph();

    void setX(const QVector<double> &x)
    {
        mX = x;
    }

    void setY(const QVector<double> &y)
    {
        mY = y;
    }
private:
    QCPGraph *mGraph;
    QVector<double> mX;
    QVector<double> mY;
    QCustomPlot *mParent;
};

#endif // DUPLOT_H
