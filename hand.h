#pragma once
#include <vector>
#include "card.h"

class hand {

public:
	hand();

	/* -- UPDATED OVERLOADED RELATIONAL OPERATORS --*/
	friend bool operator==(hand& h1, hand& h2);
	friend bool operator>(hand& h1, hand& h2);
	friend bool operator<(hand& h1, hand& h2);

	void addCardToHand(card dealtCard);
	void drawHand();

	int handValueLow();
	int handValueHigh();


private:
	std::vector<card> dealtHand;
};