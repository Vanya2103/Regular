#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QRegularExpression>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool isValidEmail(const QString& email) {
    QRegularExpression pattern(R"(^[\w.%+-]+@[\w.-]+\.[A-Za-z]{2,}$)");
    QRegularExpressionMatch match = pattern.match(email);
    return match.hasMatch();
}

void MainWindow::on_validateButton_clicked()
{
    QString email = ui->emailInput->text();
    if(isValidEmail(email)){
        // ui->textBrowser->setTextColor(QColor(120,0,120));
        ui->textBrowser->setText("Почта " + email + " корректна");
    }
    else {
        ui->textBrowser->setText(email + " это вообще что?");
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("");
}

