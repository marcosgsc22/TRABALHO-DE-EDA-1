#include "grafo.hpp"

Grafo::Grafo(bool dir) : direcionado(dir) {}

void Grafo::adicionarAresta(string u, string v) {
    adj[u].push_back(v);
    if (!direcionado) adj[v].push_back(u);
}

void Grafo::carregarDeArquivo(const string& nomeArquivo) {
    ifstream arq(nomeArquivo);
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string tipo, u, v;
    arq >> tipo;
    direcionado = (tipo == "D");

    while (arq >> u >> v) adicionarAresta(u, v);

    arq.close();
}

void Grafo::listarArestas() const {
    cout << "\nArestas:" << endl;
    for (auto& [v, vizinhos] : adj)
        for (auto& viz : vizinhos)
            if (direcionado || v < viz)
                cout << "(" << v << ", " << viz << ")\n";
}

void Grafo::listarVizinhos(const string& v) const {
    auto it = adj.find(v);
    if (it == adj.end()) { cout << "Vertice nao encontrado.\n"; return; }

    cout << "Vizinhos de " << v << ": ";
    for (auto& viz : it->second) cout << viz << " ";
    cout << endl;
}

void Grafo::verificarAdjacencia(const string& u, const string& v) const {
    auto it = adj.find(u);
    if (it == adj.end()) { cout << "Vertice nao encontrado.\n"; return; }

    for (auto& viz : it->second)
        if (viz == v) {
            cout << u << " e " << v << " sao adjacentes.\n";
            return;
        }
    cout << u << " e " << v << " NAO sao adjacentes.\n";
}

void Grafo::calcularGrau(const string& v) const {
    auto it = adj.find(v);
    if (it == adj.end()) { cout << "Vertice nao encontrado.\n"; return; }

    if (!direcionado) cout << "Grau de " << v << ": " << it->second.size() << endl;
    else {
        int entrada = 0, saida = it->second.size();
        for (auto& [x, vizinhos] : adj)
            for (auto& viz : vizinhos)
                if (viz == v) entrada++;
        cout << "Grau de entrada: " << entrada << ", Grau de saida: " << saida << endl;
    }
}

void Grafo::dfs(const string& v, map<string, bool>& visitado, vector<string>& componente) {
    visitado[v] = true;
    componente.push_back(v);
    for (auto& viz : adj[v])
        if (!visitado[viz])
            dfs(viz, visitado, componente);
}

void Grafo::encontrarComponentesConexos() {
    map<string, bool> visitado;
    int cont = 0;

    for (auto& [v, _] : adj) visitado[v] = false;

    for (auto& [v, _] : adj) {
        if (!visitado[v]) {
            vector<string> componente;
            dfs(v, visitado, componente);
            cont++;
            cout << "Comunidade " << cont << ": ";
            for (auto& x : componente) cout << x << " ";
            cout << endl;
        }
    }

    cout << "Total de comunidades: " << cont << endl;
}
