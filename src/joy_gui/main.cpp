#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "joygui_backend.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "joy_gui_node");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<JoyGuiBackEnd>("joygui.backend", 1, 0, "JoyGuiBackEnd");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
