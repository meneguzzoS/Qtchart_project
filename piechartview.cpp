#include "piechartview.h"

pieChartView::pieChartView()
{
    QChart* chart = new QChart;
    series = new QPieSeries;
    chart->addSeries(series);
    chart->setTitle("PIL Continenti");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    //resize(size);
}

void pieChartView::insertData(const AvgContinent& a)
{
    series->append(a.nomeContinente,a.media);
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
    for(auto slice : series->slices())
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1)+(" ")+QString(a.nomeContinente));
}
