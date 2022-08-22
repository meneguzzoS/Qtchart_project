#include "barchartview.h"
#include <QBarCategoryAxis>
#include <QValueAxis>

barChartView::barChartView()
{
    QChart* chart = new QChart;
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



        QStringList categories;
            categories << "2008";
            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            axisX->append(categories);
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            QValueAxis *axisY = new QValueAxis();
            axisY->setRange(0,10000);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

}

void barChartView::insertBar(const state& s)
{
    QBarSet* set = new QBarSet(s.nomeStato);
    *set << s.pil;
    series->append(set);

}
