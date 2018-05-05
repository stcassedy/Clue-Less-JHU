#include "BoardElement.h"
#include "QList"
#include "Board.h"


// -----------------------------------------------------------------------------
//Constructor
BoardElement::BoardElement(LocationTypeEnum typ, LocationEnum loc) :
    m_scarletLabel(NULL),
    m_mustardLabel(NULL),
    m_whiteLabel(NULL),
    m_greenLabel(NULL),
    m_peacockLabel(NULL),
    m_plumLabel(NULL)
{
    m_type = typ;
    m_location = loc;
    if(loc == STUDY)
    {
        m_connected.append(HALLWAY_1);
        m_connected.append(HALLWAY_3);
        m_connected.append(KITCHEN);
    }
    else if(loc == HALLWAY_1)
    {
        m_connected.append(STUDY);
        m_connected.append(HALL);
    }
    else if(loc == HALL)
    {
         m_connected.append(HALLWAY_1);
         m_connected.append(HALLWAY_2);
         m_connected.append(HALLWAY_4);
    }
    else if(loc == HALLWAY_2)
    {
         m_connected.append(HALL);
         m_connected.append(LOUNGE);
    }
    else if(loc == LOUNGE)
    {
         m_connected.append(HALLWAY_5);
         m_connected.append(HALLWAY_2);
         m_connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_3)
    {
         m_connected.append(STUDY);
         m_connected.append(LIBRARY);
    }
    else if(loc == HALLWAY_4)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(HALL);
    }
    else if(loc == HALLWAY_5)
    {
         m_connected.append(LOUNGE);
         m_connected.append(DINING_ROOM);
    }
    else if(loc == LIBRARY)
    {
         m_connected.append(HALLWAY_3);
         m_connected.append(HALLWAY_6);
         m_connected.append(HALLWAY_8);
    }
    else if(loc == HALLWAY_6)
    {
         m_connected.append(LIBRARY);
         m_connected.append(BILLIARD_ROOM);
    }
    else if(loc == BILLIARD_ROOM)
    {
         m_connected.append(HALLWAY_4);
         m_connected.append(HALLWAY_6);
         m_connected.append(HALLWAY_7);
         m_connected.append(HALLWAY_9);
    }
    else if(loc == HALLWAY_7)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(DINING_ROOM);
    }
    else if(loc == DINING_ROOM)
    {
         m_connected.append(HALLWAY_5);
         m_connected.append(HALLWAY_7);
         m_connected.append(HALLWAY_10);
    }
    else if(loc == HALLWAY_8)
    {
         m_connected.append(LIBRARY);
         m_connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_9)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(BALLROOM);
    }
    else if(loc == HALLWAY_10)
    {
         m_connected.append(DINING_ROOM);
         m_connected.append(KITCHEN);
    }
    else if(loc == CONSERVATORY)
    {
         m_connected.append(HALLWAY_8);
         m_connected.append(HALLWAY_11);
         m_connected.append(LOUNGE);
    }
    else if(loc == HALLWAY_11)
    {
         m_connected.append(CONSERVATORY);
         m_connected.append(BALLROOM);
    }
    else if(loc == BALLROOM)
    {
         m_connected.append(HALLWAY_11);
         m_connected.append(HALLWAY_12);
    }
    else if(loc == HALLWAY_12)
    {
         m_connected.append(BALLROOM);
         m_connected.append(KITCHEN);
    }
    else if(loc == KITCHEN)
    {
         m_connected.append(HALLWAY_10);
         m_connected.append(HALLWAY_12);
         m_connected.append(STUDY);
    }

}

// -----------------------------------------------------------------------------
//Destructor
BoardElement::~BoardElement()
{

}

// -----------------------------------------------------------------------------
//Public Functions

LocationTypeEnum BoardElement::getBoardElementType()
{
    return m_type;
}

LocationEnum BoardElement::getBoardElementEnum()
{
    return m_location;
}

QList<BoardElement*> BoardElement::getConnectedElements()
{
    //creates the return list
    QList<BoardElement*> elemList;

    for (int i = 0; i < m_connected.size(); ++i)
    {
        //gets a pointer to the board element object and adds it to the list
        BoardElement* elem =
                Board::getInstance()->getBoardElement(m_connected.at(i));
        elemList.append(elem);
    }

    //returns a list of connected BoardElement objects
    return elemList;
}

bool BoardElement::isBoardElementConnected(LocationEnum destination)
{
    return m_connected.contains(destination);
}


void BoardElement::setScarletLabel(QLabel* lb)
{
    //sets pointer to the label
    m_scarletLabel = lb;
}

void BoardElement::setMustardLabel(QLabel* lb)
{
    //sets pointer to the label
    m_mustardLabel = lb;
}

void BoardElement::setWhiteLabel(QLabel* lb)
{
    //sets pointer to the label
    m_whiteLabel = lb;
}

void BoardElement::setGreenLabel(QLabel* lb)
{
    //sets pointer to the label
    m_greenLabel = lb;
}

void BoardElement::setPeacockLabel(QLabel* lb)
{
    //sets pointer to the label
    m_peacockLabel = lb;
}

void BoardElement::setPlumLabel(QLabel* lb)
{
    //sets pointer to the label
    m_plumLabel = lb;
}

QLabel* BoardElement::getScarletLabel()
{
    //returns pointer to the label
    return m_scarletLabel;
}

QLabel* BoardElement::getMustardLabel()
{
    //returns pointer to the label
    return m_mustardLabel;
}

QLabel* BoardElement::getWhiteLabel()
{
    //returns pointer to the label
    return m_whiteLabel;
}

QLabel* BoardElement::getGreenLabel()
{
    //returns pointer to the label
    return m_greenLabel;
}

QLabel* BoardElement::getPeacockLabel()
{
    //returns pointer to the label
    return m_peacockLabel;
}

QLabel* BoardElement::getPlumLabel()
{
    //returns pointer to the label
    return m_plumLabel;
}

void BoardElement::hideAllLabels()
{
    //hides all of the board element labels
    m_scarletLabel->hide();
    m_mustardLabel->hide();
    m_whiteLabel->hide();
    m_greenLabel->hide();
    m_peacockLabel->hide();
    m_plumLabel->hide();
}
