
#include "game.h"
#include <iostream>
#include <vector>
#include <string>


game::game()
{
}


void game::regular(){

	std::vector<Player> name;
	int plCt; // player count intializer

	std::cout << "How many players do you have? "; // asks player how many people are there
	std::cin >> plCt; // inputs player count response

	while (std::cin.fail()) {
		std::cout << "Please enter a valid number!\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> plCt;
	}

	while (plCt > 6 || plCt < 2)  // while loop forces player to reinput number if it's above acceptable levels.
	{
		std::cout << "You have too many or not enough players,\nplease enter a value between 2 and 6... ";
		std::cin >> plCt; //inputs the new response into player count
		while (std::cin.fail()) {
			std::cout << "Please enter a valid number!\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> plCt;
		}
	}
	for (int i = 1; i <= plCt; i++) // for loop increments a list containing string names.
	{
		std::cout << "Please enter player " << i << "'s name: "; //asks name input, calls i to reference which player.
		std::string x;
		std::cin >> x; // inputs string into x
		name.push_back(Player(x)); //moves on to the next string in the player vector?
	}

	for (std::vector<Player>::iterator it = name.begin(); it != name.end(); it++) {

		for (int i = 0; i < 60; i++) {
			it->addCardDeck(std::to_string(i)); // Will create cards from 0 to 59 to put in deck.
		}

		it->shuffleDeck();

		for (int i = 0; i < 60; i++) {
			it->drawCard();                     // Draws the 60 cards from deck to hand.
		}

		it->displayHand();

	}
	for (std::vector<Player>::iterator it = name.begin(); it != name.end(); it++) {



	}
}

