#include "barchartview.h"

barChartView::barChartView()
{
    chart = new QChart;
    series = new QBarSeries;
    chart->addSeries(series);
    chart->setTitle("PIL Stati");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
}

void barChartView::insertData(ChartData* s)
{
    state* p = dynamic_cast<state*>(s);
    if(p) {
        QBarSet* set = new QBarSet(p->nome);
        *set << p->pil;
        series->append(set);
    }

}

void barChartView::setDesign(int year, double max)
{
    QStringList categories;
    categories << QString::number(year);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,max+5000);
//    qDebug() << min << max;
//    for(auto& a : d->getData()) {
//        state* p = dynamic_cast<state*>(a);
//        if(p)
//        qDebug() << p->nome << p->pil;
//    }

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setLabelsVisible();
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    axisX->setTitleText("Anno di riferimento");
    axisY->setTitleText("PIL Stato (in mld)");
}
