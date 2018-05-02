/**
  * @file NotebookDialog.h
  */
#ifndef NOTEBOOKDIALOG_H
#define NOTEBOOKDIALOG_H

#include <QDialog>

//UI namespace definition
namespace Ui {
class NotebookDialog;
}

/**
 * @brief The NotebookDialog class handles user notebook actions
 */
class NotebookDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief NotebookDialog Explicit Constructor
     * @param parent Widget*
     */
    explicit NotebookDialog(QWidget *parent = 0);

    /**
     * @brief ~NotebookDialog Destructor
     */
    ~NotebookDialog();

private slots:
    /**
     * @brief on_btnClose_clicked closes the dialog
     */
    void on_btnClose_clicked();

private:
    //Member Variables
    Ui::NotebookDialog *m_ui;
};

#endif // NOTEBOOKDIALOG_H
