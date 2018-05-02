/**
  * @file NotebookDialog.cpp
  */
#include "NotebookDialog.h"
#include "ui_NotebookDialog.h"

// -----------------------------------------------------------------------------
// Constructor:
NotebookDialog::NotebookDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NotebookDialog)
{
    //sets up the UI
    m_ui->setupUi(this);
    setWindowTitle("Notebook");
}

// -----------------------------------------------------------------------------
// Destructor:
NotebookDialog::~NotebookDialog()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Private Slots:
void NotebookDialog::on_btnClose_clicked()
{
    //closes the dialog
    close();
}
