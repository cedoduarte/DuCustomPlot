#include "DuPlot.h"
#include "qcustomplot.h"

DuPlot::DuPlot(QCustomPlot *parent, QObject *qtParent)
    : QObject(qtParent)
{   
    mParent = parent;
}

void DuPlot::drawGraph()
{
    mGraph = mParent->addGraph();
    mGraph->setData(mX, mY);
}

