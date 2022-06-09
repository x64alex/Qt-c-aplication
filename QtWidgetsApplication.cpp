#include "QtWidgetsApplication.h"
#include <QTimer>
#include <qmessagebox.h>

QtWidgetsApplication::QtWidgetsApplication(Repo& r, Member m, QWidget *parent)
    : QMainWindow(parent),repo{r},member{m}
{
    ui.setupUi(this);
    if (m.getType() == "tester") {
        this->ui.ResolveButton->hide();
    }
    else {
        this->ui.label->hide();
        this->ui.addButton->hide();
        this->ui.addLineEdit->hide();
    }
    this->setWindowTitle(QString::fromStdString(member.getName() + " " + m.getType()));
    

    this->tmr_counter = new QTimer(this);
    connect(this->tmr_counter, SIGNAL(timeout()), this, SLOT(populate()));
    this->tmr_counter->start(10000);

    this->ui.ResolveButton->setEnabled(false);


    this->populate();
}

void QtWidgetsApplication::populate()
{
    this->repo.sortV();
    this->ui.listWidget->clear();
    for (auto el : this->repo.getIssues()) {
        this->ui.listWidget->addItem(QString::fromStdString(el.toStr()));
    }

    this->ui.ResolveButton->setEnabled(false);

}

void QtWidgetsApplication::status()
{
    int selectedIndex = this->getIndex();
    if (selectedIndex >= 0) {
        Issue i = this->repo.getIssues()[selectedIndex];
        if (i.status == "open") {
            this->ui.ResolveButton->setEnabled(true);
        }
        else {
            this->ui.ResolveButton->setEnabled(false);
        }
    }
}

void QtWidgetsApplication::add()
{
    string desc = this->ui.addLineEdit->text().toStdString();
    string s = this->member.name;

    if (desc == "") {
        QMessageBox msgBox;
        msgBox.setText("The msg is empty");
        msgBox.exec();
    }
    else {
        for (auto el : this->repo.getIssues()) {
            if (el.description == desc) {
                QMessageBox msgBox;
                msgBox.setText("The msg already exists");
                msgBox.exec();
                return;
            }
        }

        Issue i{ desc,"open",s,"none" };
        this->repo.addIssue(i);

        this->populate();
    }
}

int QtWidgetsApplication::getIndex()
{
    QModelIndexList i = this->ui.listWidget->selectionModel()->selectedIndexes();
    if (i.size() == 0) {
        return -1;
    }
    return i.at(0).row();
}

void QtWidgetsApplication::remove()
{
    int selectedIndex = this->getIndex();
    if (selectedIndex < 0) {
        QMessageBox::critical(this, "Eroor", "No issue was selected");
        return;
    }
    Issue i = this->repo.getIssues()[selectedIndex];
    if (i.status == "closed") {
        this->repo.removeIssue(i);
    }

    this->populate();
}

void QtWidgetsApplication::resolve()
{
    int selectedIndex = this->getIndex();
    this->repo.modify(selectedIndex,this->member.getName());

    this->populate();
}
