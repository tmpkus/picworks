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
        content.replace("$$build_date$$", ui->buildDateInput->text());
        content.replace("$$rivision$$", ui->rivisionInput->text());
        content.replace("$$major_version$$", ui->majorInput->text());
        content.replace("$$minor_version$$", ui->minorInput->text());
        content.replace("$$build_version$$", ui->buildInput->text());
        targetTemplate.close();
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("VerGen could not open template file."));
    }
    QFile target("version.cpp");
    if(target.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&target);
        out << content;
        target.close();
    }
    QMessageBox::information(this, tr("Congradulation"), tr("Generate finished."));
}
