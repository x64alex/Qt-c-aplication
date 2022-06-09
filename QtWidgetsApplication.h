#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication.h"
#include <string>
#include "Repo.h"
#include "Member.h"
#include <QTimer>


using namespace std;

class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication(Repo&r ,Member m,QWidget *parent = Q_NULLPTR);

private:
    Repo& repo;
    Member member;
    Ui::QtWidgetsApplicationClass ui;
    QTimer* tmr_counter;
    int getIndex();

public slots:
    void add();
    void remove();
    void resolve();
    void populate();
    void status();
};
