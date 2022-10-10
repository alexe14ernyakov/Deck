namespace Deck {
	#define N_MAX 52

	struct Card {
		int rang;
		int suit;

		Card() {
			rang = 1;
			suit = 1;
		}
		Card(int card_rang, int card_suit) {
			rang = card_rang;
			suit = card_suit;
		}
	};
	typedef struct Card Card;

	class Deck {
	private:
		int count;
		Card cards[N_MAX];

		int generate_suit() const;
		int generate_rang() const;
		bool repeat_check(int r, int s) const;
	public:
		Deck();
		Deck(int n);
		Deck(int rang, int suit);
		void input(std::istream& stream);
		void print(std::ostream& buffer) const;
		void add_card();
		void add_card(int card_rang, int card_suit);
		std::string get_rang(int n) const;
		std::string get_suit(int n) const;
		void sort();
		Deck given_suit_deck(std::string suit);
	};
}
