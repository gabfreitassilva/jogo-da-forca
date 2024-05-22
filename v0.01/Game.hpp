#include <iostream>
#include <fstream> // biblioteca para manipulacao de arquivos
#include <cmath>   // biblioteca para auxilio na geracao do numero aleatorio
#include <vector>

class Game {
	private:
		std::vector<std::string> dictionary;
		std::vector<std::string> wrong_words;
		std::string word, secret_word, user_word;
		int random_line, chance = 6, word_size;
		bool win = false, letter_exist = false;

	public:
		std::string random_word (void); // funcao para gerar uma palavra aleatoria
		void display_game(void);        // principal funcao para exibicao do jogo
		void end_game(void);            // funcao de finzalicao do jogo
		void wrong_answers(void);       // funcao para guardar as palavras erradas
};