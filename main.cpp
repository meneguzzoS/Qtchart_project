#include <QApplication>
#include "listadati.h"
#include "listacontroller.h"
#include "table.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    listaDati d;
    table t(&d);
    listacontroller c(&d,&t);
    t.show();
    return a.exec();
}
