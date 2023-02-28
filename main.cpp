#include <iostream>
#include "palavra.h"

int main() {
    std::string word_secret, random_word, user_word;

    random_word = palavra();
    word_secret = "-----";

    std::cout << "Adivinhe a palavra: " << word_secret << std::endl;
    
    while(word_secret != random_word) {
        std::cout << "Seu palpite       : ";
        std::cin >> user_word;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(user_word[i] == random_word[j]) {
                    word_secret[j] = user_word[i];
                }
            }
        }

        std::cout << "Adivinhe a palavra: " << word_secret << std::endl;
    }
    return 0;
}