#include <iostream>
#include "DeckLib.h"

namespace Deck {
	int Deck::generate_rang() {
		int r = rand() % 4 + 1;
		return r;
	}

	int Deck::generate_suit() {
		int r = rand() % 13 + 1;
	}

	bool Deck::repeat_check(int r, int s) const {
		for (int i = 0; i < count; i++) {
			if (cards[i].rang == r && cards[i].rang == s)
				return true;
		}
		return false;
	}

	bool Deck::suit_sorted() const {
		for (int i = 0; i < count - 1; i++) {
			if (cards[i].suit > cards[i + 1].suit)
				return false;
		}
		return true;
	}

	bool Deck::rang_sorted() const {
		for (int i = 0; i < count - 1; i++) {
			if (cards[i].suit == cards[i + 1].suit && cards[i].rang < cards[i + 1].rang)
				return false;
		}
		return true;
	}

	Deck::Deck() {
		count = 0;
	}

	Deck::Deck(int n) {
		count = n;
		int r;
		int s;
		for (int i = 0; i < n; i++) {
			do {
				r = generate_rang();
				s = generate_suit();
			} while (repeat_check(r, s));

			cards[i] = Card(r, s);
		}
	}

	Deck::Deck(int rang, int suit) {
		count = 1;
		cards[0] = Card(rang, suit);
	}

	void Deck::input(std::istream& stream) {

	}

	void Deck::print(std::ostream& buffer) const {
		for (int i = 0; i < count; i++) {
			buffer << i + 1 << ": " << get_rang(i + 1) << " " << get_suit(i + 1) << std::endl;
		}
	}

	void Deck::add_card() {
		int r, s;
		do {
			r = generate_rang();
			s = generate_suit();
		} while (repeat_check(r, s));
		cards[count] = Card(r, s);
		count++;		
	}

	void Deck::add_card(int card_rang, int card_suit) {
		cards[count].rang = card_rang;
		cards[count].suit = card_suit;
		count++;
	}

	std::string Deck::get_rang(int n) const {
		if (count < n || n < 0)
			throw std::logic_error("There is no such card");
		int s = cards[n - 1].rang;
		switch (s) {
		case(1): return "ACE";
		case(2): return "2";
		case(3): return "3";
		case(4): return "4";
		case(5): return "5";
		case(6): return "6";
		case(7): return "7";
		case(8): return "8";
		case(9): return "9";
		case(10): return "10";
		case(11): return "JACK";
		case(12): return "QUEEN";
		case(13): return "KING";
		default: return "UNKNOWN";
		}
	}

	std::string Deck::get_suit(int n) const {
		if (count < n || n < 0)
			throw std::logic_error("There is no such card");
		int s = cards[n - 1].suit;
		switch (s) {
		case(1): return "CLUBS";
		case(2): return "DIAMONDS";
		case(3): return "HEARTS";
		case(4): return "SPADES";
		default: return "UNKNOWN";
		}
	}

	void Deck::sort() {
		int d = 0;
		while (!suit_sorted()) {
			for (int i = 0; i < count; i++) {
				if (cards[i].suit > cards[i].suit) {
					Card tmp = cards[i];
					cards[i] = cards[i + 1];
					cards[i + 1] = tmp;
				}
			}
		}
		while (!rang_sorted()) {
			for (int i = 0; i < count; i++) {
				if (cards[i].suit == cards[i].suit && cards[i].rang < cards[i+1].rang) {
					Card tmp = cards[i];
					cards[i] = cards[i + 1];
					cards[i + 1] = tmp;
				}
			}
		}		
	}

	Deck Deck::given_suit_deck(std::string suit){
		int s = 0;
		if (suit == "CLUBS")
			s = 1;
		if (suit == "DIAMONDS")
			s = 2;
		if (suit == "HEARTS")
			s = 3;
		if (suit == "SPADES")
			s = 4;
		
		Deck res;
		for (int i = 0; i < count; i++) {
			if (cards[i].suit == s) {
				res.add_card(cards[i].rang, cards[i].suit);
			}
		}
		return res;
	}
}