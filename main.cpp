#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>


#include "sqlrelationaltablemodel.h"

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

//    SqlRelationalTableModel *driversModel = new SqlRelationalTableModel;

//    if(!driversModel->select()) {
//        qWarning() << "Model select failed!";
//    }

    //qDebug() << driversModel->roleNames();
    //qDebug() << driversModel->data(driversModel->index(1,1),257);


    QQmlApplicationEngine engine;

    qmlRegisterType<SqlRelationalTableModel>("SqlRelationalTableModel",1,0,"SqlRelationalTableModel");

//    SqlRelationalTableModel *driversModel = new SqlRelationalTableModel;
//    driversModel->setTableName("drivers");

//    engine.rootContext()->setContextProperty(QStringLiteral("driversModel"), driversModel);

    qmlRegisterSingletonType(QUrl("qrc:///Constants.qml"), "App", 1, 0, "Constants");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    //qDebug() << "Model Context Property:" << engine.rootContext()->contextProperty("driversModel");

    voyagesdb.close();
    //delete driversModel;
    return app.exec();
}
