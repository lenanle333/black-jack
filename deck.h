#pragma once
#include <vector>
#include "card.h"

class deck {
public:
    deck();

    card dealCard();

private:
    std::vector<card> deckOfCards;
};