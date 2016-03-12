#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QMainWindow>

#include "mainwindow.h"



MainWindow::MainWindow()
{
  textEdit = new QPlainTextEdit;
  setCentralWidget(textEdit);

  createActions();
  createMenus();

  readSettings();

  updateWindowTitle();
}


MainWindow::~MainWindow()
{
  writeSettings();
}


void MainWindow::runPyScript(const QString& fileName)
{
  qDebug() << "Running script" << fileName;
}


void MainWindow::updateWindowTitle()
{
  QString title = tr("Demo");

  setWindowTitle(title);
}


void MainWindow::createActions()
{
  QDir pluginDir("plugins");
  QStringList filesList = pluginDir.entryList(QDir::NoDotAndDotDot | QDir::Files);

  foreach(QString filename, filesList) {
    qDebug() << filename;

    runPyAct = new QAction(filename, this);
    runPyAct->setStatusTip(tr("Custom Python plugin invoked from menu"));
    connect(runPyAct, &QAction::triggered, [this, filename]{ runPyScript(filename); });

    pluginActList << runPyAct;
  }

  exitAct = new QAction(tr("E&xit"), this);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));
  connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}


void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(exitAct);

  pluginMenu = menuBar()->addMenu(tr("&Plugins"));
  foreach(runPyAct, pluginActList) {
    pluginMenu->addAction(runPyAct);
  }
}


void MainWindow::readSettings()
{
  QSettings settings("rei4dan", "Demo");
  QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
  QSize size = settings.value("size", QSize(400, 400)).toSize();
  resize(size);
  move(pos);
}


void MainWindow::writeSettings()
{
  QSettings settings("rei4dan", "Demo");
  settings.setValue("pos", pos());
  settings.setValue("size", size());
}


int main(int argc, char* argv[])
{
  //Q_INIT_RESOURCE(application);

  QApplication app(argc, argv);
  app.setOrganizationName("rei4dan");
  app.setApplicationName("Demo");

  MainWindow mainWin;
  mainWin.show();

  return app.exec();
}

