#include"DeckCard.h"


const string Card::suits[4] = { " ¬õ¤ß ", " ¤è¶ô ", " ¶Â®ç ", " ±öªá " };
const string Card::faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10","J", "Q", "K" };

Card::Card(int f, int s) : face(f), suit(s){}

string Card::toString()
{
	string CardName = suits[suit] + " " + faces[face];
	return CardName;

}

DeckOfCards::DeckOfCards()
{
	for (int s = 0; s < 4; s++)
		for (int f = 0; f < 13; f++)
		{
			Card newCard(f, s);
			deck.push_back(newCard);
		}
	
	currentCard = 0;

}

void DeckOfCards::shuffle()
{
	srand(time(NULL));
	int randNumber = 51;
	int num;
	Card temp;
	

	for (int i = 0; i < 51; i++)
	{
		num = rand() % randNumber + 1;
		temp = deck[i];
		deck[i] = deck[i + num];
		deck[i + num] = temp;

		randNumber--;
	}

}

Card& DeckOfCards::dealCard()
{
	currentCard++;
	return deck[currentCard - 1];
		
}

bool DeckOfCards::moreCards()
{
	if (currentCard == 52)
		return false;
	else
		return true;

}