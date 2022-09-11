#include "linechartview.h"


lineChartView::lineChartView()
{
    chart = new QChart();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);

    chart->setTitle("Simple line chart example");
    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    resize(1000,700);
    setMinimumSize(800,500);
}

lineChartView::~lineChartView()
{
    delete this;
}

void lineChartView::insertData(ChartData* d)
{
    stateData* p = dynamic_cast<stateData*>(d);
    if(p) {
        series = new QLineSeries;
        series->setName(d->nome);

        for(int i=0; i<p->values.size(); i++) { //values da controllare
            series->append(p->years.at(i) , p->values.at(i));
        }
        chart->addSeries(series);
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
