#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buildDateInput->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_fileBrowserButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open"), ".", "Accept (*.in)");
    ui->filePathInput->setText(filePath);
}

void MainWindow::on_genButton_clicked()
{
    QString content;
    QFile targetTemplate(ui->filePathInput->text());
    if(targetTemplate.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&targetTemplate);
        content = in.readAll();
        content.replace("$$workcopy_url$$", ui->wcUrlInput->text());
        content.replace("$$major_version$$", ui->majorInput->text());
        content.replace("$$minor_version$$", ui->minorInput->text());
        content.replace("$$build_version$$", ui->buildInput->text());
        content.replace("$$build_date$$", ui->buildDateInput->text());
        QDate date = ui->buildDateInput->date();
        int y = date.year();
        int m = date.month();
        int d = date.day();
        QString sdate = QString::number(y);
        sdate += m < 10 ? ("0" + QString::number(m)) : QString::number(m);
        sdate += d < 10 ? ("0" + QString::number(d)) : QString::number(d);
        content.replace("$$rivision$$", sdate);
        targetTemplate.close();
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("VerGen could not open template file."));
        return;
    }
    QFile target("version.cpp");
    if(target.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&target);
        out << content;
        target.close();
    }
    QMessageBox::information(this, tr("Congradulation"), tr("Generate finished."));
}
