#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
using namespace std::chrono;
typedef duration<long, ratio<1, 1000000000>> d; // Definicao de tipo utilizado devido a biblioteca chrono

//Funcao de media dos tempos

void avg(d x[]){
    double soma = 0, media;
    for (int i = 0; i<50; i++){
      soma = soma + x[i].count();
    }
    media = soma/50;
    cout << trunc(media) << " nano segundos" << endl;
}

int main (){
  
  int k, w, p[1000000];
  d tmps1[50], tmps2[50], tmps3[50];
  double soma;

  // Preenchimento da pilha
  
  for(int j = 0; j<50; j++){
    auto str1 = steady_clock::now();
    for (int i=0; i<1000000; i++){
      p[i] = i+1;
    }
    auto fin1 = steady_clock::now();
    auto tempo1 = fin1 - str1;
    tmps1[j] = tempo1;
  }
  
  // Soma dos itens da pilha
  
  for(int j = 0; j<50; j++){
    auto str2 = steady_clock::now();
    for (int i: p){
     soma += i;
    }
    auto fin2 = steady_clock::now();
    auto tempo2 = fin2 - str2;
    tmps2[j] = tempo2;
  }

  // Verificação de um número aleatório

  for(int j = 0; j<50; j++){
    k = 0;
    srand(time(0));
    int r = 1+rand()%1000000;
    auto str3 = steady_clock::now();
    while (p[k] != r){
      k++;
    }
  auto fin3 = steady_clock::now();
  auto tempo3 = fin3 - str3;
  tmps3[j] = tempo3;
  }

  cout << "Todos os tempos foram medidos em nano segundo (10^-9 segundos) para maior precisao:"<< endl << endl;
  cout << "Preenchimento da pilha: "; avg(tmps1);
  cout << "Soma da pilha: "; avg(tmps2);
  cout << "Verificacao de numero na pilha: "; avg(tmps3);
}