#include "piechartview.h"

pieChartView::pieChartView()
{
    chart = new QChart;
    series = new QPieSeries;
    chart->addSeries(series);
    chart->setTitle("PIL Continenti");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    //chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    //resize(size);
}

pieChartView::~pieChartView()
{
    delete this;
}

void pieChartView::insertData(ChartData* a)
{
    AvgContinent* p = dynamic_cast<AvgContinent*>(a);
    if(p) {
        series->append(p->nome,p->media);
        qDebug() << p->nome << p->media;
    }

}

void pieChartView::setDesign(QList<ChartData*> s)
{
    int i = 0;
    for(QPieSlice* slice : series->slices()) {
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1)+(" ")+QString(s.at(i)->nome));
        slice->setExploded();
        slice->setLabelVisible();
        slice->setLabelPosition(QPieSlice::LabelOutside);
        i++;
    }
//    QValueAxis* axisX = new QValueAxis;
    //axisX->setLabelFormat("%d");
}
