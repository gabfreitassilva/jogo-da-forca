#include "game.hpp"

std::string Game::random_word(void) {
	std::ifstream read;
	read.open("palavras.txt");
	if (read.is_open()) {
		while (std::getline(read, word))
			dictionary.push_back(word);
		srand(time(0));
		random_line = rand()%dictionary.size();
		word = dictionary.at(random_line);
		read.close();
	}
	return word;
}

void Game::wrong_answers(void) {
	std::cout << "Wrong words:\n";
	if (user_word != word)
		wrong_words.push_back(user_word);
	for (int i = 0; i < wrong_words.size(); i++)
		std::cout << wrong_words[i] << '\n';
}

void Game::display_game(void) {
	secret_word = random_word();
	word_size = secret_word.length();
	for (int i = 0; i < word_size; i++)
		secret_word[i] = '-';
	do {
		system("cls");
		std::cout << "You have " << chance << " chances\n";
		std::cout << "Guess the word: " << secret_word << '\n';
		wrong_answers();
		std::cout << "\nYour guess: ";
		std::cin >> user_word;
		for (int j = 0; j < word_size; j++) {
			for (int k = 0; k < word_size; k++) {
				if (user_word[j] == word[k])
					secret_word[k] = user_word[j];
			}
		}
		if (secret_word != word)
			chance--;
		else
			win = true;
	} while (chance > 0 && win != true);
}

void Game::end_game(void) {
	system("cls");
	if (chance == 0) {
		std::cout << "You have " << chance << " chances\n";
		std::cout << "Word is: " << word << '\n';
		wrong_answers();
		std::cout << "\nBe better in the next time\n";
	}
	if (win == true) {
		std::cout << "You have " << chance << " chances\n";
		std::cout << "Guess the word: " << secret_word << '\n';
		wrong_answers();
		std::cout << "\nCongratulations, you win the game!!!\n";
	}
}