#pragma once
#include <string>

enum Suit
{
	CLUBS = 0,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Rank
{
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

struct CardStruct
{
	Suit suit;
	Rank rank;
};



std::string intTostring(int number);

std::string suitTostring(Suit s);

std::string rankTostring(Rank r);

std::string toString(CardStruct card);

std::string toStringShort(CardStruct card);



class Card
{
private:
	Suit s;
	Rank r;
	bool invalid;
	
public:
	Card() { invalid = true; };
	Card(Suit s, Rank r);
	void initialize(Suit s, Rank r);
	CardStruct getStruct();
	std::string toString();
	std::string toStringShort();

	Suit getSuit() { return s; }
	Rank getRank() { return r; }
};


class CardDeck
{
private:
	Card cards[52];
	int currentCardIndex;
	int size;

	void swap(int x, int y);

public:
	CardDeck();
	int getCurrentSize();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};


class BlackJack
{
private:
	CardDeck deck;

public:
	BlackJack();
	int getCardValue(Card c);
	bool isAce(Card c);
	int getPlayerCardValue(Card c);
	int getDealerCardValue(Card c, int handValue);
	bool askPlayerDrawCard();
	void playGame();
};