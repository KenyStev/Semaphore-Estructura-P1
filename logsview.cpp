#include "logsview.h"
#include "ui_logsview.h"

LogsView::LogsView(Stack<Log*>*l,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogsView)
{
    ui->setupUi(this);
    logs=l;
    fillLogs();
}

LogsView::~LogsView()
{
    delete ui;
}

void LogsView::fillLogs()
{
    ui->listLogs->clear();
    if(logs)
    {
        Log* tmp= logs->top();
        while(tmp)
        {
            QListWidgetItem *item = new QListWidgetItem();
//            cout<<tmp->log->toStdString()<<endl;
            item->setText(*tmp->log);
            tmp = tmp->next;
            ui->listLogs->addItem(item);
        }
    }
}
