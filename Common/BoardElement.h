#pragma once

#include <set>;

class BoardElement;
enum BoardElementType { hallway, room };

// Hallways are ordered here according to the board diagram: first, the horizontal hallways in 
// left-to-right then top-to-bottom; then, vertical hallways in left-to-right and top-to-bottom.
enum HallwayName { studyHall, hallLounge, libraryBilliard, billiardDining, conservBall, ballKitchen, 
					studyLibrary, libraryConserv, hallBilliard, billiardBall, loungeDining, diningKitchen, none };
enum RoomName { study, hall, lounge, library, billiard, dining, conserv, ball, kitchen, none };

class BoardElement
{
public:
	BoardElement(BoardElementType boardElementType, HallwayName hallwayName, RoomName roomName);
	~BoardElement();

	// Returns the board element type.
	BoardElementType get_element_type();
	RoomName get_room_name();
	HallwayName get_hallway_name();
	bool is_element_connected(BoardElement otherElement);

private:
	std::set<Hallway> connectedHallways_;
	std::set<Room> connectedRooms_;
	std::set<Player> playersInElement_;
	BoardElementType boardElementType_;
	RoomName roomName_;
	HallwayName hallwayName_;

};

