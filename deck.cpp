#include <iostream>
#include "deck.h"

/* deck constructor */
deck::deck() {
    srand(time(0)); // seeding the random function

    for (cards::cardSuit suit : cards::allSuits) {
        for (cards::cardValue value : cards::allValues) {
            deckOfCards.push_back(card(suit, value));
        };
    };
};

/* Deals a random card */
card deck::dealCard() {
    int randomCard = rand() % deckOfCards.size();

    card dealtCard = deckOfCards[randomCard];

    deckOfCards.erase(deckOfCards.begin() + randomCard);

    return dealtCard;
};