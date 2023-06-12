#include <iostream>
#include "game.h"

game::game() = default;

/* Pulls another card */
void game::hit(hand* dealtHand, deck deckOfCards) {
	dealtHand->addCardToHand(deckOfCards.dealCard());
}

/* -- UPDATED OVERLOADED RELATIONAL OPERATORS IMPLEMENTED IN THIS FUNCTION --*/
/* Function checks which person won if neither hand was a bust */
void game::endGame(hand* playersHand, hand* dealersHand) {
	/* If players hand was higher than the dealers */
	if (*playersHand > *dealersHand) {
		std::cout << "You win with the greater hand!" << std::endl;
	}
	/* If players hand is less than dealers */
	else if (*playersHand < *dealersHand) {
		std::cout << "Dealer won with a greater hand! You lose!" << std::endl;
	}
	/* If both have the same score */
	else if (*playersHand == *dealersHand) {
		std::cout << "It's a tie!!" << std::endl;
	}
}
/* Prints out action prompt*/
void game::actionPrompt() {
	std::cout << "\nDo you want to hit or stand?" << std::endl
		<< "\t1. Enter 1 to hit (Pull a card)." << std::endl
		<< "\t2. Enter 2 to stand (Pass your turn to the dealer)." << std::endl << std::endl
		<< "Action: ";
}

/* Prints out Black Jack Rules */
void game::rulePrompt() {
	std::cout << "Welcome to a game of Black Jack!" << std::endl << std::endl;
	std::cout << "Black Jack rules:" << std::endl
		<< "\t1. An Ace can either have a value of 1 or 11." << std::endl
		<< "\t2. Face cards (J, Q, K) have a value of 10." << std::endl << std::endl
		<< "How to win the game:" << std::endl
		<< "\t1. Have a hand of 21." << std::endl
		<< "\t2. Have a higher hand than the dealer." << std::endl
		<< "\nNOTE: If both you and the dealer end up with the same hand then it's a tie and the game ends." << std::endl << std::endl
		<< "Actions you can make:" << std::endl
		<< "\t1. Enter 1 to hit (Pull a card)." << std::endl
		<< "\t2. Enter 2 to stand (Pass your turn to the dealer)." << std::endl << std::endl;

	std::cout << "Press 'Enter' to start the game!";
	std::cin.ignore();

	std::cout << "\n******************************************" << std::endl;
}



