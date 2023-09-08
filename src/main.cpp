#include "mywindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(translations);

    QApplication app(argc, argv);

    // Load the translator
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":/" + baseName + ".qm")) {
            app.installTranslator(&translator);
            break;
        }
    }

    MyWindow w;
    w.show();
    return app.exec();
}
