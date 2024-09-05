#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include "DebugHelper.h"

void  testDebugcalssFunction()
{
     DEBUG <<"test the classfunction";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;//测试下上传项目
    w.show();


    int userId = 123;
    QString userName = "John Doe";
    double userScore = 99.5;

    // Use custom DEBUG stream-style writing
    DEBUG << "User ID:" << userId << " Name:" << userName << " Score:" << userScore ;
    testDebugcalssFunction();
    return a.exec();
}
