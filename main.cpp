#include <QApplication>
#include <QPushButton>
#include "Tests.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Tests tests;
    tests.testAll();
    qDebug() << "All tests passed";

    Repository repository = Repository("date.txt");
    Service service = Service(repository);
    GUI gui = GUI(service);
    gui.show();
    return QApplication::exec();
}
