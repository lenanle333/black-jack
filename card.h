#pragma once

namespace cards {
    enum cardSuit {
        heart,
        diamond,
        club,
        spade
    };

    static const cardSuit allSuits[]{
        cardSuit::heart,
        cardSuit::diamond,
        cardSuit::club,
        cardSuit::spade
    };

    enum cardValue {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    static const cardValue allValues[]{
        cardValue::Ace, cardValue::Two, cardValue::Three,
        cardValue::Four, cardValue::Five, cardValue::Six,
        cardValue::Seven, cardValue::Eight, cardValue::Nine,
        cardValue::Ten, cardValue::Jack, cardValue::Queen,
        cardValue::King
    };
};

class card {
public:
    card();
    card(cards::cardSuit s, cards::cardValue v);

    void setCardValue(cards::cardValue v);
    void setCardSuit(cards::cardSuit s);

    cards::cardValue getCardValue();
    cards::cardSuit getCardSuit();

    friend std::ostream& operator << (std::ostream& os, card& dealtCard);

private:
    cards::cardSuit suit;

    cards::cardValue value;
};