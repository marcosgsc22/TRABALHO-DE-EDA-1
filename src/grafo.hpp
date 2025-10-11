#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Grafo {
private:
    map<string, vector<string>> adj;
    bool direcionado;

public:
    Grafo(bool dir = false);
    void adicionarAresta(string u, string v);
    void carregarDeArquivo(const string& nomeArquivo);
    void listarArestas() const;
    void listarVizinhos(const string& v) const;
    void verificarAdjacencia(const string& u, const string& v) const;
    void calcularGrau(const string& v) const;
    void encontrarComponentesConexos();
private:
    void dfs(const string& v, map<string, bool>& visitado, vector<string>& componente);
};

#endif
