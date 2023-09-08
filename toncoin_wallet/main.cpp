#include "my_window.h"

#include <QApplication>
#include <QFontDatabase>
#include <QTranslator>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Register Inter.ttf font
    QFontDatabase::addApplicationFont(":/Inter.ttf");

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
