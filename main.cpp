#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include "Repo.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin("1.txt");
    string name, type;
    Repo r{};
    QApplication a(argc, argv);
    int i = 0;
    while (fin >> name >> type) {
        Member m{ name,type };
        auto* w = new QtWidgetsApplication{r,m};
        w->show();
        i++;
    }
    return a.exec();
}
