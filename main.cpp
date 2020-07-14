#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);    

    QGuiApplication app(argc, argv);

    QSqlDatabase voyagesdb = QSqlDatabase::addDatabase("QMYSQL");
    voyagesdb.setHostName("localhost");
    voyagesdb.setDatabaseName("voyagesdb");

    if(!voyagesdb.open("root","")) {
        qFatal("Cannot connect to database!");
    }

    QQmlApplicationEngine engine;
    qmlRegisterSingletonType(QUrl("qrc:///Constants.qml"), "App", 1, 0, "Constants");
//    QQmlContext* context = engine.rootContext();

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    voyagesdb.close();
    return app.exec();
}
