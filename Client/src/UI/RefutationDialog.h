/**
  * @file RefutationDialog.h
  */
#ifndef REFUTATIONDIALOG_H
#define REFUTATIONDIALOG_H

#include <QDialog>
#include <BoardEnums.h>

//Forward Declaration
class WeaponCard;
class RoomCard;
class PlayerCard;

//UI namespace definition
namespace Ui {
class RefutationDialog;
}

/**
 * @brief The RefutationDialog class handles input for a refutation action
 */
class RefutationDialog : public QDialog
{
    Q_OBJECT

public:
    /**
    * @brief RefutationDialog Explicit Constructor
    * @param parent Widget*
    */
    explicit RefutationDialog(QWidget *parent = 0);

    /**
     * @brief ~RefutationDialog Destructor
     */
    ~RefutationDialog();

    /**
     * @brief setSuggestionCards sets the cards that need refuted
     * @param wCard WeaponCard*
     * @param rCard RoomCard*
     * @param pCard PlayerCard*
     */
    static void setSuggestionCards(WeaponCard* wCard, RoomCard* rCard,
                                   PlayerCard* pCard);

public slots:
    /**
     * @brief show shows the dialog
     */
    void show();

private slots:
    /**
     * @brief on_btnRefute_clicked notifies client manager of the refutation
     * and closes the dialog
     */
    void on_btnRefute_clicked();

    /**
     * @brief on_btnCancel_clicked closes the dialog
     */
    void on_btnCancel_clicked();

private:
    /**
     * @brief getCardEnumFromName returns a card enum based on a card name
     * @param name QString
     * @return CardEnum
     */
    CardEnum getCardEnumFromName(QString name);

    //Member Variables
    Ui::RefutationDialog *m_ui;
    static WeaponCard* m_weaponCard;
    static RoomCard* m_roomCard;
    static PlayerCard* m_playerCard;
};

#endif // REFUTATIONDIALOG_H
