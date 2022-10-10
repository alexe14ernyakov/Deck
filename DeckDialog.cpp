#include <iostream>
#include "Deck.h"

template <typename T>
int get_num(T& a) {
    std::cin >> a;
    if (!std::cin.good())
        return 1;
    return 0;
}
void menu();
void action(Deck::Deck& d, int s);

int main()
{
    std::cout << "How do you want to set your deck?" << std::endl;
    std::cout << "Set card's count " << std::endl;
    std::cout << "Set first card " << std::endl;
    std::cout << ">" << std::endl;
    try {
        Deck::Deck d(16);
        int s = 1;
        while (s != 0) {
            menu();
            get_num(s);
            action(d, s);
        }
        Deck::Deck ND = d.given_suit_deck("SPADES");
        s = 1;
        while (s != 0) {
            menu();
            get_num(s);
            action(ND, s);
        }
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
        return 0;
    }

    return 0;
}

void menu() {
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "0. Exit program " << std::endl;
    std::cout << "1. Check deck's info " << std::endl;
    std::cout << "2. Generate random card" << std::endl;
    std::cout << "3. Check card's rang by its number" << std::endl;
    std::cout << "4. Check card's suit by its number" << std::endl;
    std::cout << "5. Sort the deck" << std::endl;
    std::cout << ">";
}

void action(Deck::Deck& d, int s) {
    int n;
    switch (s) {
        case 0:
            break;
        case 1:
            d.print(std::cout);
            break;
        case 2:
            d.add_card();
            break;
        case 3:
            std::cout << "Enter number of card: ";
            get_num(n);
            try {
                std::string res = d.get_rang(n);
                std::cout << std::endl << "It is " << res << std::endl << std::endl;
            }
            catch (std::logic_error &LE) {
                std::cout << LE.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Enter number of card: ";
            get_num(n);
            try{
                std::string res = d.get_suit(n);
                std::cout << std::endl << "It is " << res << std::endl << std::endl;
            }
            catch(std::logic_error& LE){
                std::cout << LE.what() << std::endl;
            }
            break;
        case 5:
            d.sort();
            break;
        default:
            std::cout << "Invalid choice..." << std::endl;
    }
}
