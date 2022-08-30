#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QDir>
#include <QStatusBar>
#include <QMessageBox>
#include <string>
#include "table.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setGeometry(180,100,1300,800);
    setWindowTitle(tr("Tabella Dati"));
    OpenAction=new QAction(QIcon(":/Images/open.png"),tr("Apri"),this);
    OpenAction->setShortcuts(QKeySequence::Open);               //creo un accesso veloce
    NewAction=new QAction(QIcon(":/Images/new.png"),tr("Nuovo"),this);
    NewAction->setShortcuts(QKeySequence::New);                 //creo un accesso veloce
    SaveAction=new QAction(QIcon(":/Images/save.png") ,tr("Salva"),this);
    SaveAction->setShortcuts(QKeySequence::Save);               //creo un accesso veloce
    SaveAsaction=new QAction(tr("Salva con nome"),this);
    SaveAsaction->setShortcut(QKeySequence::SaveAs);          //creo un accesso veloce
    CloseAction=new QAction(QIcon(":/Images/close.png"),tr("Chiudi"),this);
    CloseAction->setShortcuts(QKeySequence::Close);             //creo un accesso veloce
    QuitAction=new QAction(tr("Esci"),this);
    QuitAction->setShortcuts(QKeySequence::Quit);               //creo un accesso veloce
    barchart=new QAction(QIcon(":/Images/barchart.jpeg"),tr("Barchart"),this);
    linechart=new QAction(QIcon(":/Images/linechart.jpg"),tr("Linechart"),this);
    pointchart=new QAction(QIcon(":/Images/pointchart.png"),tr("PointChart"),this);
    aggiungi=new QAction(QIcon(":/Images/add.png"),tr("Aggiungi"),this);
    remove=new QAction(QIcon(":/Images/remove.png"),tr("Rimuovi"),this);
    inserimento=new QAction(QIcon(":/Images/Ok.png"),tr("Inserisci"),this);
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
    File=addToolBar(tr("File"));
    File->addAction(OpenAction);
    File->addAction(NewAction);
    File->addAction(SaveAction);
    File->addAction(CloseAction);
    Chart=addToolBar(tr("Chart"));
    Chart->addAction(barchart);
    Chart->addAction(linechart);
    Chart->addAction(pointchart);
    Modifica=addToolBar(tr("Modifica"));
    Modifica->addAction(aggiungi);
    Modifica->addAction(remove);
    Modifica->addAction(inserimento);
    aggiungi->setEnabled(false);
    remove->setEnabled(false);
    inserimento->setEnabled(false);
    barchart->setEnabled(false);
    linechart->setEnabled(false);
    pointchart->setEnabled(false);
    QList<record> *p= new QList<record>;
    dataController = new listaController(p);
    table* t = new table(dataController);
    setCentralWidget(t);

    connect(t,SIGNAL(closeWindow()),this,SLOT(close()));

//    tab=new Tab(&val,this);
//    setCentralWidget(tab);
}
