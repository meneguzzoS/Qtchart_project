#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setGeometry(180,100,1300,800);
    setWindowTitle(tr("Tabella Dati"));
    OpenAction=new QAction(tr("Apri"),this);
    OpenAction->setShortcuts(QKeySequence::Open);
    NewAction=new QAction(tr("Nuovo"),this);
    NewAction->setShortcuts(QKeySequence::New);
    SaveAction=new QAction(tr("Salva"),this);
    SaveAction->setShortcuts(QKeySequence::Save);
    SaveAsaction=new QAction(tr("Salva con nome"),this);
    SaveAsaction->setShortcut(QKeySequence::SaveAs);
    CloseAction=new QAction(tr("Chiudi"),this);
    CloseAction->setShortcuts(QKeySequence::Close);
    QuitAction=new QAction(tr("Esci"),this);
    QuitAction->setShortcuts(QKeySequence::Quit);
    barchart=new QAction(tr("Barchart"),this);
    linechart=new QAction(tr("Linechart"),this);
    pointchart=new QAction(tr("PointChart"),this);
    aggiungi=new QAction(tr("Aggiungi"),this);
    remove=new QAction(tr("Rimuovi"),this);
    inserimento=new QAction(tr("Inserisci"),this);
    FileMenu =new QMenu(tr("File"),this);
    FileMenu->addAction(OpenAction);
    FileMenu->addAction(NewAction);
    FileMenu->addAction(SaveAction);
    FileMenu->addAction(SaveAsaction);
    FileMenu->addAction(CloseAction);
    FileMenu->addAction(QuitAction);
    VisualizzaMenu =new QMenu(tr("Visualizza"),this);
    VisualizzaMenu->addAction(barchart);
    VisualizzaMenu->addAction(linechart);
    VisualizzaMenu->addAction(pointchart);
    ModificaMenu= new QMenu(tr("Modifica"),this);
    ModificaMenu->addAction(aggiungi);
    ModificaMenu->addAction(remove);
    ModificaMenu->addAction(inserimento);
    menuBar()->addMenu(FileMenu);
    menuBar()->addMenu(VisualizzaMenu);
    menuBar()->addMenu(ModificaMenu);
    menuBar()->addSeparator();
    statusBar();//creo una status bar
    aggiungi->setEnabled(false);
    remove->setEnabled(false);
    inserimento->setEnabled(false);
    barchart->setEnabled(false);
    linechart->setEnabled(false);
    pointchart->setEnabled(false);
//    QList<record> *p= new QList<record>;
    dataController = new listaDati(/*p*/);
    table* t = new table(dataController);
    setCentralWidget(t);

    connect(t,SIGNAL(closeWindow()),this,SLOT(close()));
    connect(CloseAction,SIGNAL(triggered(bool)),this,SLOT(close()));
//    connect(OpenAction,SIGNAL(triggered(bool)),t,SLOT(importData()));
//    connect(OpenAction,&QPushButton::clicked,this,[this](){emit openF();});
}
