#include "linechartview.h"


lineChartView::lineChartView()
{
    chart = new QChart();
    //QLineSeries *series = new QLineSeries;
    //chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);

    //chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

//    QT_CHARTS_NAMESPACE::QValueAxis *axisX = new QT_CHARTS_NAMESPACE::QValueAxis;
//     axisX->setRange(0, this->series->points().length());
//     axisX->setTickCount(10);
//     axisX->setLabelFormat("%d");
//     chartView->chart()->setAxisX(axisX, series);

//     QT_CHARTS_NAMESPACE::QValueAxis *axisY = new QT_CHARTS_NAMESPACE::QValueAxis;
//     axisY->setRange(0, 50);
//     axisY->setTickCount(1);
//     axisY->setLabelFormat("%d");
//     chartView->chart()->setAxisY(axisY, series);

    /*QValueAxis* axisY = new QValueAxis();
        axisY->setRange(0,6000);
        chart->addAxis(axisY, Qt::AlignLeft);
        //series->attachAxis(axisY);
        QValueAxis* axisX = new QValueAxis();
                axisX->setRange(0,6000);
                chart->addAxis(axisX, Qt::AlignBottom);
              //series->attachAxis(axisX);*/

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
}

void lineChartView::insertData(ChartData* d)
{
    stateData* p = dynamic_cast<stateData*>(d);
    if(p) {
        series = new QLineSeries;
        series->setName(d->nome);

        for(int i=0; i<p->values.size(); i++) { //values da controllare
            series->append(p->years.at(i) , p->values.at(i));
            qDebug() << i << p->years.at(i) << p->values.at(i);
            //series->setPointLabelsFormat(QString::number(d.values.at(i)));
        }
        chart->addSeries(series);

        //series->setPointLabelsVisible();
        series->setPointsVisible();
    }

}

void lineChartView::setDesign(double min, double max)
{
    chart->createDefaultAxes();

    chart->axisX()->setLabelsVisible();
    chart->axisX()->setTitleText("Anni di riferimento");
    chart->axisY()->setTitleText("PIL Stati (in mln)");
    chart->axisY()->setRange(min-1000,max+1000);
}
