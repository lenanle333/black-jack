#include <iostream>
#include "deck.h"
#include "hand.h"
#include "game.h"

int main()
{
	deck newDeck;
	game newGame;

	std::unique_ptr<hand> playersHand = std::make_unique<hand>();
	std::unique_ptr<hand> dealersHand = std::make_unique<hand>();

	newGame.rulePrompt();

	/* Players first card */
	playersHand->addCardToHand(newDeck.dealCard());

	/* Dealers first card */
	std::cout << "Dealers card: " << std::endl;
	dealersHand->addCardToHand(newDeck.dealCard());
	dealersHand->drawHand();

	/* Players second card */
	playersHand->addCardToHand(newDeck.dealCard());
	std::cout << "\nYour hand: " << std::endl;
	playersHand->drawHand();

	/* Dealers second card */
	dealersHand->addCardToHand(newDeck.dealCard());

	/* If player has a black jack, player wins and game ends */
	if (playersHand->handValueLow() == 21 || playersHand->handValueHigh() == 21) {
		std::cout << "\nBlack Jack! You win!!" << std::endl;
		exit(EXIT_SUCCESS);
	}

	/* -- Players play through -- */
	int playerInput = 0;
	do {
		newGame.actionPrompt();
		std::cin >> playerInput;

		std::cout << "\n************************************************************\n" << std::endl;

		/* Player chooses to hit */
		if (playerInput == 1) {
			std::cout << "Your new hand: " << std::endl;
			newGame.hit(playersHand.get(), newDeck);
			playersHand->drawHand();
		}
		/* Player chooses to stand then it's dealers turn */
		else if (playerInput == 2) {
			break;
		}
		else {
			std::cout << "Invalid input!" << std::endl;
		}

	} while (playersHand->handValueLow() < 21);

	/* If player pulls a hand higher than 21, player loses and game ends */
	if (playersHand->handValueLow() > 21) {
		std::cout << "It's a bust, you lost." << std::endl;
		exit(EXIT_SUCCESS);
	}

	/* Dealers hand is revealed */
	std::cout << "Dealers hand:" << std::endl;
	dealersHand->drawHand();

	/* If dealer has a blackjack, dealer wins and game ends */
	if (dealersHand->handValueLow() == 21 || dealersHand->handValueHigh() == 21) {
		std::cout << "\nDealer wins with a Black Jack! You lose." << std::endl;
		exit(EXIT_SUCCESS);
	}

	/* -- Dealers play through -- */
	do {
		/* Hit: If dealers hand is or less than 16 */
		if (dealersHand->handValueHigh() <= 16) {
			dealersHand->addCardToHand(newDeck.dealCard());
			std::cout << "\nDealer pulls a card." << std::endl << std::endl;
			std::cout << "Dealers hand is: " << std::endl;
			dealersHand->drawHand();
		}
		/* Stand: If dealers hand is between 17 - 21 (inclusive) */
		else if (dealersHand->handValueHigh() >= 17 && dealersHand->handValueHigh() <= 21) {
			std::cout << "\nDealer chose to stand." << std::endl << std::endl;
			break;
		}
	} while (dealersHand->handValueLow() < 21);

	/* If dealer pulls a hand higher than 21 they lose and the program exits */
	if (dealersHand->handValueLow() > 21) {
		std::cout << "Dealer busts, you win!" << std::endl;
		exit(EXIT_SUCCESS);
	}

	newGame.endGame(playersHand.get(), dealersHand.get());
}
