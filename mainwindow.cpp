#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QApplication>
#include <QResource>
#include "SystemClassesHeaderFiles/json.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load and apply the stylesheet from Qt resources
    QFile styleFile(":/stylesheet.qss"); // Note the :/ prefix for resources
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString styleSheet = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(styleSheet); // Apply to entire application
        styleFile.close();
    }
    else
    {
        // Optional: Print error if stylesheet couldn't be loaded
        qDebug() << "Could not open stylesheet file:" << styleFile.errorString();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
