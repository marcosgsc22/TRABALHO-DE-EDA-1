#include "grafo.hpp"
#include <iostream> 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    Grafo g;
    g.carregarDeArquivo("data/grafo.txt");
    gerarDOT("data/grafo.txt", "output/grafo.dot");
    gerarImagem("output/grafo.dot", "output/grafo.png");

    int opcao = -1;
    string v1, v2;

    do {
        cout << "------------------------REDE SOCIAL-----------------------\n";
        cout << "[1] Listar arestas existentes\n";
        cout << "[2] Listar todos os vizinhos de um vertice\n";
        cout << "[3] Grau de um vertice\n";
        cout << "[4] Verificar se adjacencia entre dois vertices\n";
        cout << "[5] Exibir comunidades\n";
        cout << "[0] Sair\n";
        cout << "----------------------------------------------------\n";
        cout << "SELECIONE UMA OPCAO: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                g.listarArestas(); 
                break;
            case 2:
                cout << "Vertice: "; cin >> v1;
                g.listarVizinhos(v1);
                break;
            case 3:
                cout << "Vertice: "; cin >> v1;
                g.calcularGrau(v1);
                break;
            case 4:
                cout << "Vertice 1: "; cin >> v1;
                cout << "Vertice 2: "; cin >> v2;
                g.verificarAdjacencia(v1, v2);
                break;
            case 5:
                g.encontrarComponentesConexos();
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Por favor, tente uma opcao compativel.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}

