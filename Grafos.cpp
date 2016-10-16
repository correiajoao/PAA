//============================================================================
// Name        : Grafos.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;


class Aresta{
    int peso;
public:
    Aresta(int peso){
        this->peso = peso;
    }

    int getPeso(){
         return peso;
    }
    void setPeso(int peso){
        this->peso = peso;
    }
};

class Vertice{
    int id;
    char tipo; // 0 tipo B e 1 tipo S
    bool uso = false; // Somente para tipos S

public:
    Vertice(int id, char tipo, bool uso){
        this->id = id;
        this->tipo = tipo;
        this->uso = uso;
    }

    int getId(){
         return id;
    }

    char getTipo(){
         return tipo;
    }
    bool getUso(){
        return uso;
    }

    void setId(int id){
         this->id = id;
    }

    void setTipo(char tipo){
         this->tipo = tipo;
    }

    void setUso(bool uso){
        this->uso = uso;
    }

};

class Grafo{
public:
    int v; //Número de vertices
    list<pair<Vertice,Aresta> > *node; //Vizinhos de um determinado nó

    Grafo(int v){
        this->v = v;
        node = new list<pair<Vertice,Aresta> >[v];
    }

    void adicionarAresta(Vertice v1, Vertice v2, Aresta a){
        pair <Vertice,Aresta> newPair = make_pair(v2,a);
        node[v1.getId()].push_back(newPair);
    }

    void mostrarLigacoes(Vertice v1){
        cout << v1.getId() << " se liga com:";
        list<pair <Vertice,Aresta> >::iterator iterator;
        for (iterator = node[v1.getId()].begin(); iterator != node[v1.getId()].end(); ++iterator) {
            std::cout << iterator->first.getId() << " Peso: " << iterator->second.getPeso() << endl;
        }
    }

    void excluirAresta(Vertice v1){

    }

    int verificarMaiorSalto(){
        int maiorSalto = 0;

        for(int i=0; i<v; i++){
           
             maiorSalto = max(node[i].front().second.getPeso(),maiorSalto);
			//cout << maiorSalto << endl;
           
			int salto = 0;	
			if(node[i].front().first.getTipo() == 'S'){
			cout << i << " para " << i+1 << endl;
			for(int j=i; j<v; j++){
                if(node[j].front().first.getTipo() == 'S'){
					cout << " Peso adicionado " << j << " -- " << j+1 << " S " << node[j].front().second.getPeso() << endl;
					 salto+= node[j].front().second.getPeso();
                }else{
					cout << " Peso adicionado " << j << " -- " << j+1 << " B " << node[j].front().second.getPeso() << endl;
					salto+= node[j].front().second.getPeso();
					i=j;
					break;
				}
             }
			
			cout << "Total " << salto << endl;
			maiorSalto = max(salto, maiorSalto);
			
			}
            }

        return maiorSalto;
    }

};

int main(){
   int x,n,d;
   cin >> x; //Execuções
   for(int i=0; i<x; i++){
       cin >> n; // número de pedras
       cin >> d; // distancia total


       Grafo *grafo = new Grafo(n+1);

       Vertice verticeAnterior(0,'B', false);
       Aresta arestaAnterior(0);

       char tipo, aux;
       int distancia = 0;
       int distanciaAlcance = 0;

       for(int j=1;j<=n;j++){
           cin >> tipo>>aux>>distancia;

           Vertice verticeCorrente(j, tipo, false);
           Aresta arestaCorrente(distancia - distanciaAlcance);
		   distanciaAlcance += (distancia - distanciaAlcance);
		   
           grafo->adicionarAresta(verticeAnterior, verticeCorrente, arestaCorrente);

		   //grafo->mostrarLigacoes(verticeAnterior);
		   
           verticeAnterior.setId(verticeCorrente.getId());
		   verticeAnterior.setTipo(verticeCorrente.getTipo());
		   verticeAnterior.setUso(verticeCorrente.getUso());
			   
           arestaAnterior.setPeso(arestaCorrente.getPeso());

       }

        Vertice verticeCorrente(n+1, 'B', false);
        Aresta arestaCorrente(d - distanciaAlcance);
        grafo->adicionarAresta(verticeAnterior, verticeCorrente, arestaCorrente);

        cout << "Case " << i+1 << ":" << " " << grafo->verificarMaiorSalto() << endl;
   }
        return 0;
}
