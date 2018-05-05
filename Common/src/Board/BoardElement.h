#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#include "BoardEnums.h"
#include "QList"
#include <QLabel>

/**
 * @brief The BoardElements class represents a board element, either a Room or Hallway
 */
class BoardElement
{ 
private:
    LocationTypeEnum m_type;
    LocationEnum m_location;
    QList<LocationEnum> m_connected;
    QLabel* m_scarletLabel;
    QLabel* m_mustardLabel;
    QLabel* m_whiteLabel;
    QLabel* m_greenLabel;
    QLabel* m_peacockLabel;
    QLabel* m_plumLabel;

public:
    /**
     * @brief BoardElement Explicit Constructor
     * @param type LocationTypeEnum
     * @param loc LocationEnum
     */
    explicit BoardElement(LocationTypeEnum type, LocationEnum loc);

    /**
     * @brief BoardElement Destructor
     */
    virtual ~BoardElement();

    /**
     * @brief getBoardElementType returns LocationTypeEnum
     */
    LocationTypeEnum getBoardElementType();

    /**
     * @brief getBoardElementEnum returns LocationEnum
     */
    LocationEnum getBoardElementEnum();

    /**
     * @brief getConnectedElements returns list of connected elements
     * @return QList<BoardElement*>
     */
    QList<BoardElement*> getConnectedElements();

    /**
     * @brief isBoardElementConnected, returns true if LocationEnum supplied a valid move
     * @param loc LocationEnum
     */
    bool isBoardElementConnected(LocationEnum loc);


    /**
     * @brief openForNewPlayer (Abstract) Determines if a player can move into
     * the board element
     * @return bool true if the location can accept a player, false otherwise
     */
    virtual bool openForNewPlayer() = 0;

    /**
     * @brief setScarletLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setScarletLabel(QLabel* lb);

    /**
     * @brief setMustardLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setMustardLabel(QLabel* lb);

    /**
     * @brief setWhiteLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setWhiteLabel(QLabel* lb);

    /**
     * @brief setGreenLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setGreenLabel(QLabel* lb);

    /**
     * @brief setPeacockLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setPeacockLabel(QLabel* lb);

    /**
     * @brief setPlumLabel Sets a pointer to the ui label
     * @param lb QLabel*
     */
    void setPlumLabel(QLabel* lb);

    /**
     * @brief getScarletLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getScarletLabel();

    /**
     * @brief getMustardLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getMustardLabel();

    /**
     * @brief getWhiteLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getWhiteLabel();

    /**
     * @brief getGreenLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getGreenLabel();

    /**
     * @brief getPeacockLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getPeacockLabel();

    /**
     * @brief getPlumLabel Gets a pointer to the ui label
     * @return QLabel*
     */
    QLabel* getPlumLabel();

    /**
     * @brief hideAllLabels hides all of the UI labels
     */
    void hideAllLabels();

};



#endif // BOARDELEMENT_H
