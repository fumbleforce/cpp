#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>
#include "cards.h"
using namespace std;



string intTostring(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

string suitTostring(Suit s)
{
	switch (s)
	{
		case CLUBS:
			return "Clubs";
			break;
		case DIAMONDS:
			return "Diamonds";
			break;
		case HEARTS:
			return "Hearts";
			break;
		case SPADES:
			return "Spades";
			break;
	}
}

string rankTostring(Rank r)
{
	std::map <int, string> rankNames;
	rankNames[2] = "Two";
	rankNames[3] = "Three";
	rankNames[4] = "Four";
	rankNames[5] = "Five";
	rankNames[6] = "Six";
	rankNames[7] = "Seven";
	rankNames[8] = "Eight";
	rankNames[9] = "Nine";
	rankNames[10] = "Ten";
	rankNames[11] = "Jack";
	rankNames[12] = "Queen";
	rankNames[13] = "King";
	rankNames[14] = "Ace";
	return rankNames[r];
}

string toString(CardStruct card)
{
	return rankTostring(card.rank) + " of " + suitTostring(card.suit);
}

string toStringShort(CardStruct card)
{
	return suitTostring(card.suit).substr(0,1) + rankTostring(card.rank);
}


// Card Class

Card::Card(Suit s, Rank r)
{
	initialize(s, r);
}
void Card::initialize(Suit suit, Rank rank)
{
	s = suit;
	r = rank;
	invalid = false;
}
CardStruct Card::getStruct()
{
	CardStruct c = { s, r };
	return c;
}
string Card::toString()
{
	if (invalid) return "Invalid Card";
	return ::toString(getStruct());
}
string Card::toStringShort()
{
	if (invalid) return "Invalid Card";
	return ::toStringShort(getStruct());
}



// CardDeck class 

CardDeck::CardDeck()
{
	int cardCount = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			cards[cardCount] = Card(static_cast<Suit>(i), static_cast<Rank>(j));
			cardCount++;
		}
	}
	currentCardIndex = 0;
	size = 52;
}
int CardDeck::getCurrentSize()
{
	return size-currentCardIndex;
}
void CardDeck::swap(int x, int y)
{
	Card temp = cards[x];
	cards[x] = cards[y];
	cards[y] = temp;
}
void CardDeck::print()
{
	for (int i = 0; i < getCurrentSize(); i++)
	{
		cout << cards[i].toString() << endl;
	}
}
void CardDeck::printShort()
{
	for (int i = 0; i < getCurrentSize(); i++)
	{
		cout << cards[i].toStringShort() << endl;
	}
}
void CardDeck::shuffle()
{
	for (int i = 0; i < getCurrentSize(); i++)
	{
		swap(i, rand() % getCurrentSize());
	}
}
Card CardDeck::drawCard()
{
	Card card = cards[getCurrentSize()-1];
	currentCardIndex++;
	return card;
}



// BlackJack Class
BlackJack::BlackJack()
{
	deck = CardDeck();
	deck.shuffle();
}
int BlackJack::getCardValue(Card c)
{
	if (isAce(c)) return -1;
	return c.getRank();
}
bool BlackJack::isAce(Card c)
{
	return c.getRank() == ACE;
}
int BlackJack::getPlayerCardValue(Card c)
{
	int value = getCardValue(c);
	int answer = 0;

	if (isAce(c)) {
		cout << "Card is an ace, is the value 1 or 11?" << endl;
		while (answer != 1 && answer != 11)
		{
			cin >> answer;
		}
		value = answer;
	}
	return value;
}
int BlackJack::getDealerCardValue(Card c, int handValue)
{
	int value = getCardValue(c);

	if (isAce(c)) {
		if (handValue + 11 > 21) {
			value = 1;
		}
		else {
			value = 11;
		}
	}
	return value;
}
bool BlackJack::askPlayerDrawCard()
{
	cout << "Do you want a card? Answer 1 for yes, 0 for no" << endl;

	int answer;
	cin >> answer;

	if (answer == 1) return true;
	return false;
}
void BlackJack::playGame()
{
	cout << "Let's play Black Jack!" << endl << endl;

	int playerValue = 0;
	int dealerValue = 0;
	Card c;
	bool bust = false;

	while (dealerValue < 17)
	{
		c = deck.drawCard();
		cout << "Dealer drew " << c.toString() << endl;
		dealerValue += getDealerCardValue(c, dealerValue);
		cout << "Dealer's card value is " << dealerValue << endl;
	}

	cout << endl;
	c = deck.drawCard();
	cout << "You drew " << c.toString() << endl;
	playerValue +=getPlayerCardValue(c);

	c = deck.drawCard();
	cout << "You drew " << c.toString() << endl;
	playerValue +=getPlayerCardValue(c);

	cout << endl;

	if (playerValue > 21) bust = true;
	else if (playerValue == 21) 
	{
		cout << "BLACKJACK! YOU WON!" << endl;
		return;
	}

	while (!bust)
	{
		cout << "Your card value is " << playerValue << endl;
		if (askPlayerDrawCard())
		{
			c = deck.drawCard();
			cout << "You drew " << c.toString() << endl;
			playerValue +=getPlayerCardValue(c);

			if (playerValue > 21)
			{
				bust = true;
				break;
			}
		}
		else {
			break;
		}
	}

	if (bust)
	{
		cout << "You busted with value of " << playerValue <<"! Dealer keeps all your money" << endl;
	}
	else if (playerValue < dealerValue)
	{
		if (dealerValue > 21)
		{
			cout << "The dealer busts! You won" << endl;
		}
		else
		{
			cout << "Dealer has a better hand than you! Dealer keeps all your money" << endl;
		}
		
	}
	else
	{
		cout << "You won! You are now rich" << endl;
	}
}