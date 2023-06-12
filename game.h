#pragma once
#include "hand.h"
#include "deck.h"

class game {
public:
	game();

	void hit(hand* dealtHand, deck deckOfCards);
	void endGame(hand* playersHand, hand* dealersHand);

	void actionPrompt();
	void rulePrompt();
};