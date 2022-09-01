#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include"record.h"
#include "listacontroller.h"

class fileHandler
{
public:
    fileHandler() = delete;
    static void readFile(const listaController&);
};

#endif // FILEHANDLER_H
