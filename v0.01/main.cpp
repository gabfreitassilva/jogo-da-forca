#include "Game.hpp" // biblioteca com todas as funcoes referente ao jogo

int main() {
    char escolhaUsuario; // variavel para escolha do usuario em continuar a jogar

    INICIO: // palavra chave para retornor ao jogo

	Game game;
	game.display_game(); // inicio do jogo com todas as funcoes
	game.end_game();     // funcao de finzalicao do jogo

    std::cout << "Deseja jogar novamente? (S ou N): ";
    std::cin >> escolhaUsuario;
    if (toupper(escolhaUsuario) != 'N') { goto INICIO; } // condicao de retorno para jogar novamente

	return 0;
}