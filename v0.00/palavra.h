#include <string>
#include <random>
#include <fstream>

std::string palavra() {
    std::string words_archive, word;
    int count_words, word_position, random_number;

    std::fstream fs;
    fs.open("C:\\Users\\conta\\Documents\\aprendendo\\palavras.txt", std::fstream::in); // abre o arquivo desejado em modo de leitura somente.

    if(fs.is_open()) { 
        // se o arquivo estiver aberto, o programa continua
    } else {
        return "erro na abertura do arquivo";
    } // caso ele não esteja aberto, o programa termina e retorna a mensagem acima

    std::getline(fs, words_archive); // faz a leitura de uma única linha do arquivo e guarda a informação na variável informada.

    fs.close(); // fecha o arquivo.

    count_words = (words_archive.size() / 5) - 1; // efetua a contagem de palavras contidas no arquivo, porém o resultado deve ser subtraído por 1.

    // aqui faremos a geração do número aleatório entre 0 e a quantidade de palavras guardada.
    // antes fizemos a subtração de uma unidade, pois a contagem de vetores
    // sempre inicia pelo número 0.
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, count_words);
    random_number = dist(mt);

    // aqui fazemos com que o número aleatório gerado seja sempre um múltiplo de 5
    // assim sempre vamos ter número de 5 em 5, indicando onde a nossa palavra
    // vai estar começando.
    word_position = random_number * 5;

    for(int i = word_position; i < (word_position + 5); i++) {
        word += words_archive[i]; // de acordo com a posição da palavra, guardaremos a mesmo em uma variável separada.
    }

    return word; // aqui retornaremos a palavra escolhida aleatoriamente.
}