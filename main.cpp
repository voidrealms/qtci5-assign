#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(test);
Q_LOGGING_CATEGORY(test,"test");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting test";
    bool debug = true;
    if(!debug){
        QLoggingCategory::setFilterRules("test.debug=false");
    } else {
        QLoggingCategory::setFilterRules("test.debug=true");
    }

    for (int i = 0;i < 1000;i++) {
     qDebug(test) << "Test" << i;
    }

    qDebug() << "Complete";
    return a.exec();
}
