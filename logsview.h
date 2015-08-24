#ifndef LOGSVIEW_H
#define LOGSVIEW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "stack.h"
#include "log.h"
#include <iostream>

using namespace std;

namespace Ui {
class LogsView;
}

class LogsView : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogsView(Stack<Log*>*l,QWidget *parent = 0);
    ~LogsView();

    void fillLogs();

private:
    Ui::LogsView *ui;

    Stack<Log*> *logs;
};

#endif // LOGSVIEW_H
