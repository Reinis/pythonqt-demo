#include "PythonQt/PythonQt.h"
#include "PythonQt/PythonQt_QtAll.h"
#include "PythonQt/gui/PythonQtScriptingConsole.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QMainWindow>



class QAction;
class QMenu;
class QPlainTextEdit;


class MainWindow: public QMainWindow
{

Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

public slots:
  void runPyScript(const QString& fileName);
  void updateWindowTitle();

private:
  void createActions();
  void createMenus();
  void readSettings();
  void writeSettings();

  QMenu* fileMenu;
  QMenu* pluginMenu;
  QAction* runPyAct;
  QAction* exitAct;
  QList<QAction*> pluginActList;
  PythonQtScriptingConsole* pyConsole;
};

