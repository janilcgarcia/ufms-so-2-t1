#include <iostream>
#include <string>
#include <vector>

#include "simulator.h++"
#include "req-strategy/fifo-strat.h++"
#include "req-strategy/lru-strat.h++"
#include "stream-logger.h++"

static void print_usage();

int main(int argc, char **argv)
{
        constexpr int args_size = 6;

        if (argc < 6)
        {
                print_usage();
                return -1;
        }

        std::vector<std::string> args(argc - 1);

        for (int i = 1; i < argc; i++)
        {
                args[i - 1] = argv[i];
        }

        const std::string &root = args[0];
        const std::string &alg = args[1];

        if (alg != "LRU" && alg != "FIFO")
        {
                std::cerr << "Algoritmo inválido, deve um ser"
                          << " um dentre [FIFO, LRU]"
                          << std::endl;
                std::cerr << "Este argumento diferencial maiúsculas "
                          << "de minúsculas"
                          << std::endl;
                
                return 1;
        }

        std::size_t err;
        std::string sframes;
        int nframes;

        nframes = std::stoi(args[2], &err);

        if (err != args[2].size() || nframes <= 0)
        {
                std::cerr << args[2] << " é um paramêtro inválido. Precisa "
                          << "ser um número inteiro positivo" << std::endl;

                return 1;
        }

        int npages;

        npages = std::stoi(args[3], &err);

        if (err != args[3].size() || nframes <= 0)
        {
                std::cerr << args[3] << " é um paramêtro inválido. Precisa "
                          << "ser um número interio positivo" << std::endl;

                return 1;
        }

        int nreqpages;

        nreqpages = std::stoi(args[4], &err);

        if (err != args[4].size() || nframes <= 0)
        {
                std::cerr << args[4] << " é um paramêtro inválido. Precisa "
                          << "ser um número inteiro positivo" << std::endl;
                
                return 1;
        }

                
        StreamLogger stdout_logger { std::cout };

        if (alg == "LRU")
        {
                Simulator<LruStrategy> lru { root, npages, nframes };
                
                lru.simulate(stdout_logger, nreqpages);
        }
        else
        {
                Simulator<FifoStrategy> fifo { root, npages, nframes };

                fifo.simulate(stdout_logger, nreqpages);
        }

        return 0;
}

static void print_usage()
{
        std::cout << "Usage: pagesim [pagedir] [alg] "
                  << "[nframes] [npages] [nreqpages]" << std::endl;
        std::cout << "Esse programa simula a execução de um algoritmo"
                  << "de substituição de páginas de memória, usando"
                  << "arquivos armazenados em uma pasta como páginas"
                  << std::endl;

        std::cout << "Onde: " << std::endl;

        std::cout << "\tpagedir: Onde ficarão os arquivos de página"
                  << std::endl;

        std::cout << "\talg: Algoritmo de substituição [LRU, FIFO]"
                  << std::endl;

        std::cout << "\tnframes: A quantidade de frames de memória"
                  << std::endl;

        std::cout << "\tnpages: A quantidade de páginas disponíveis"
                  << " para a execução do algoritmo"
                  << std::endl;

        std::cout << "\tnreqpages: O número de páginas requisitas em"
                  << " em toda execução da simulação. Cada requisição"
                  << " será de uma página aleatória"
                  << std::endl;
}

