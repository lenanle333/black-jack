#include <iostream>
#include <string>
#include "card.h"

/* Card constructors */
card::card() = default;

card::card(cards::cardSuit s, cards::cardValue v) {
    setCardSuit(s);
    setCardValue(v);
};

/* Sets the card value */
void card::setCardValue(cards::cardValue v) {
    value = v;
};

/* Returns value of card */
cards::cardValue card::getCardValue() {
    return value;
}

/* Sets the card suit */
void card::setCardSuit(cards::cardSuit s) {
    suit = s;
};

/* Returns suit of card */
cards::cardSuit card::getCardSuit() {
    return suit;
}

/* -- Returns the card value --*/
std::string returnValue(cards::cardValue value) {
    switch (value) {
    case cards::cardValue::Ace:
        return "A";
        break;
    case cards::cardValue::Two:
        return "2";
        break;
    case cards::cardValue::Three:
        return "3";
        break;
    case cards::cardValue::Four:
        return "4";
        break;
    case cards::cardValue::Five:
        return "5";
        break;
    case cards::cardValue::Six:
        return "6";
        break;
    case cards::cardValue::Seven:
        return "7";
        break;
    case cards::cardValue::Eight:
        return "8";
        break;
    case cards::cardValue::Nine:
        return "9";
        break;
    case cards::cardValue::Ten:
        return "10";
        break;
    case cards::cardValue::Jack:
        return "J";
        break;
    case cards::cardValue::Queen:
        return "Q";
        break;
    case cards::cardValue::King:
        return "K";
        break;
    default:
        std::cout << "Oops, that value does not exist!" << std::endl;
        break;
    };
};

/* -- Returns the card suit --*/
char returnSuit(cards::cardSuit suit) {
    switch (suit) {
    case cards::cardSuit::heart:
        return char(3);
        break;
    case cards::cardSuit::diamond:
        return char(4);
        break;
    case cards::cardSuit::club:
        return char(5);
        break;
    case cards::cardSuit::spade:
        return char(6);
        break;
    default:
        std::cout << "Oh no, this suit does not exist" << std::endl;
        break;
    };
};

/* -- Prints out card -- */
std::ostream& operator << (std::ostream& os, card& dealtCard) {
    cards::cardValue dealtCardValue = dealtCard.getCardValue();
    cards::cardSuit dealtCardSuit = dealtCard.getCardSuit();

    std::string valueAndSuit = returnValue(dealtCardValue) + returnSuit(dealtCardSuit);

    os << valueAndSuit << std::endl;

    return os;
};




