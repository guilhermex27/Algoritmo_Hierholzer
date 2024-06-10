#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    cout << endl << "MATRIZ DE ADJACÊNCIA:" << endl << endl ;
    cout << "   ";
    for (int u = 0; u < n; u++){
         cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++){
        cout << u << ": ";
        for (int v = 0; v < n; v++){
            cout << G[u][v] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void imprimirvetor(vector<int> &vet, int n){
    for (int v = 0; v < n; v++)
        {
            cout << vet[v] << " ";
        }
    cout <<  endl << endl;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--){
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
}

int somatorio(vector<vector<int>> &G, int vertice ,int n){
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum = G[vertice][i] + sum;
    }
    return sum;
}

void hierholzer(vector<vector<int>> &G, int u, int n){
    cout << "CONSTRUÇÃO DO CAMINHO" << endl << endl;
    int vertice = u, proximo = 0;
    stack<int> aux;
    aux.push(vertice);
    vector<int> caminho;
    vector<int> vizinhos;

    while(aux.size()> 0){
        vertice = aux.top();
        if(somatorio(G,vertice,n) > 0){
            vizinhos.clear();
            for(int i = 0; i<n; i++){
                if(G[vertice][i] == 1){
                    vizinhos.emplace_back(i);
                }
            }
            proximo = vizinhos[0];

            cout << vertice << " --> " << proximo << endl;

            aux.push(proximo);

            cout << "Push = " << proximo << endl;

            G[proximo][vertice] = 0;
            G[vertice][proximo] = 0;

            vertice = proximo;
        }
        else{
            aux.pop();
            cout << "Pop = "<< vertice << endl;
            caminho.emplace_back(vertice);
        }
    }
    cout << endl;
    cout << "CAMINHO EULERIANO: ";
    imprimirvetor(caminho,caminho.size());
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>Grafo;
    Grafo.assign(n, vector<int>(n, 0));

    leituraGrafo(Grafo,m);
    escritaGrafo(Grafo);
    hierholzer(Grafo,0,n);
}