/**
  * @file AccusationDialog.h
  */
#ifndef ACCUSATIONDIALOG_H
#define ACCUSATIONDIALOG_H

#include <QDialog>
#include <BoardEnums.h>

//UI namespace definition
namespace Ui {
class AccusationDialog;
}

/**
 * @brief The SuggestionDialog class handles input for an accusation action
 */
class AccusationDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AccusationDialog Explicit Constructor
     * @param parent QWidget*
     */
    explicit AccusationDialog(QWidget *parent = 0);

    /**
     * @brief ~AccusationDialog Destructor
     */
    ~AccusationDialog();

private slots:
    /**
     * @brief on_btnAccuse_clicked sends suggestion and closes the dialog
     */
    void on_btnAccuse_clicked();

    /**
     * @brief on_btnCancel_clicked closes the dialog
     */
    void on_btnCancel_clicked();

private:
    /**
     * @brief getWeaponCardEnum returns the selected weapon card enum
     * @return CardEnum
     */
    CardEnum getWeaponCardEnum();

    /**
     * @brief getRoomCardEnum returns the selected room card enum
     * @return CardEnum
     */
    CardEnum getRoomCardEnum();

    /**
     * @brief getPlayerCardEnum returns the selected player card enum
     * @return CardEnum
     */
    CardEnum getPlayerCardEnum();

    //Member Variables
    Ui::AccusationDialog *m_ui;
};

#endif // ACCUSATIONDIALOG_H
