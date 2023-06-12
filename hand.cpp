#include <iostream>
#include "hand.h"
using namespace std;

/* Hand constructor */
hand::hand() = default;

/* -- UPDATED OVERLOADED RELATIONAL OPERATORS IMPLEMENTED IN GAME.CPP --*/
/* -- Overloaded equality operator for hand object-- */
bool operator==(hand& h1, hand& h2) {
    if (h1.handValueLow() == h2.handValueHigh() || h1.handValueHigh() == h2.handValueHigh()) {
        return true;
    }
    else {
        return false;
    }
};

/* -- Overloaded greater than operator for hand object-- */
bool operator> (hand& h1, hand& h2) {
    if (h1.handValueHigh() > h2.handValueHigh() || h1.handValueLow() > h2.handValueHigh()
        || h1.handValueHigh() > h2.handValueLow() || h1.handValueLow() > h2.handValueLow()) {
        return true;
    }
    else {
        return false;
    }
};

/* -- Overloaded less than operator for hand object-- */
bool operator< (hand& h1, hand& h2) {
    if (h1.handValueHigh() < h2.handValueHigh() || h1.handValueLow() < h2.handValueHigh()
        || h1.handValueHigh() < h2.handValueLow() || h1.handValueLow() < h2.handValueLow()) {
        return true;
    }
    else {
        return false;
    }
};

/* Adds a card to the hand */
void hand::addCardToHand(card dealtCard) {
    dealtHand.push_back(dealtCard);
};

/* Draws a hand */
void hand::drawHand() {
    for (card dealtCard : dealtHand) {
        std::cout << dealtCard;
    };
};

/* Returns the low value of the hand -- Ace = 1*/
int hand::handValueLow() {
    cards::cardValue dealtCardValue;

    int handValue = 0;

    for (card dealtCard : dealtHand) {

        dealtCardValue = dealtCard.getCardValue();

        switch (dealtCardValue) {
        case cards::cardValue::Ace:
            handValue += 1;
            break;
        case cards::cardValue::Two:
            handValue += 2;
            break;
        case cards::cardValue::Three:
            handValue += 3;
            break;
        case cards::cardValue::Four:
            handValue += 4;
            break;
        case cards::cardValue::Five:
            handValue += 5;
            break;
        case cards::cardValue::Six:
            handValue += 6;
            break;
        case cards::cardValue::Seven:
            handValue += 7;
            break;
        case cards::cardValue::Eight:
            handValue += 8;
            break;
        case cards::cardValue::Nine:
            handValue += 9;
            break;
        case cards::cardValue::Ten:
        case cards::cardValue::Jack:
        case cards::cardValue::Queen:
        case cards::cardValue::King:
            handValue += 10;
            break;
        default:
            std::cout << "Oops, that value does not exist!" << std::endl;
            break;
        };
    };

    return handValue;
};

/* Returns the high value of the hand -- Ace = 11*/
int hand::handValueHigh() {
    cards::cardValue dealtCardValue;

    int handValue = 0;
    bool foundAceAlready = false;

    for (card dealtCard : dealtHand) {

        dealtCardValue = dealtCard.getCardValue();

        switch (dealtCardValue) {
        case cards::cardValue::Ace:
            if (foundAceAlready) {
                handValue += 1;
            }
            else {
                handValue += 11;
                foundAceAlready = true;
            }
            break;
        case cards::cardValue::Two:
            handValue += 2;
            break;
        case cards::cardValue::Three:
            handValue += 3;
            break;
        case cards::cardValue::Four:
            handValue += 4;
            break;
        case cards::cardValue::Five:
            handValue += 5;
            break;
        case cards::cardValue::Six:
            handValue += 6;
            break;
        case cards::cardValue::Seven:
            handValue += 7;
            break;
        case cards::cardValue::Eight:
            handValue += 8;
            break;
        case cards::cardValue::Nine:
            handValue += 9;
            break;
        case cards::cardValue::Ten:
        case cards::cardValue::Jack:
        case cards::cardValue::Queen:
        case cards::cardValue::King:
            handValue += 10;
            break;
        default:
            std::cout << "Oops, that value does not exist!" << std::endl;
            break;
        };
    };

    return handValue;
};

