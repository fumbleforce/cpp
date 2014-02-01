#include "cards.h"
#include "cards.cpp"



int main()
{
	srand(time(0));

	BlackJack blackjack = BlackJack();

	blackjack.playGame();

	return 0;
}