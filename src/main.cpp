#include "grafo.hpp"

int main() {
    Grafo g;
    g.carregarDeArquivo("data/grafo.txt");

    int opcao;
    string v1, v2;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Listar arestas\n";
        cout << "2. Listar vizinhos\n";
        cout << "3. Verificar adjacencia\n";
        cout << "4. Calcular grau\n";
        cout << "5. Encontrar comunidades\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: g.listarArestas(); break;
            case 2:
                cout << "Vertice: "; cin >> v1;
                g.listarVizinhos(v1);
                break;
            case 3:
                cout << "Vertice 1: "; cin >> v1;
                cout << "Vertice 2: "; cin >> v2;
                g.verificarAdjacencia(v1, v2);
                break;
            case 4:
                cout << "Vertice: "; cin >> v1;
                g.calcularGrau(v1);
                break;
            case 5:
                g.encontrarComponentesConexos();
                break;
        }
    } while (opcao != 0);

    return 0;
}
