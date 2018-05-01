/**
  * @file SuggestionDialog.h
  */
#ifndef SUGGESTIONDIALOG_H
#define SUGGESTIONDIALOG_H

#include <QDialog>
#include <BoardEnums.h>

//UI namespace definition
namespace Ui {
class SuggestionDialog;
}

/**
 * @brief The SuggestionDialog class handles input for a suggestion action
 */
class SuggestionDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief SuggestionDialog Explicit Constructor
     * @param parent QWidget*
     */
    explicit SuggestionDialog(QWidget *parent = 0);

    /**
     * @brief ~SuggestionDialog Destructor
     */
    ~SuggestionDialog();

private slots:
    /**
     * @brief on_btnSuggest_clicked sends suggestion and closes the dialog
     */
    void on_btnSuggest_clicked();

    /**
     * @brief on_btnCancel_clicked closes the dialog
     */
    void on_btnCancel_clicked();

private:
    /**
     * @brief getWeaponCardEnum returns the selected weapon card enum
     * @return int
     */
    CardEnum getWeaponCardEnum();

    /**
     * @brief getRoomCardEnum returns the selected room card enum
     * @return int
     */
    CardEnum getRoomCardEnum();

    /**
     * @brief getPlayerCardEnum returns the selected player card enum
     * @return CardEnum
     */
    CardEnum getPlayerCardEnum();

    //Member Variables
    Ui::SuggestionDialog *m_ui;
};

#endif // SUGGESTIONDIALOG_H
