#include <iostream>

using namespace std;

long int v[45001];
long int t[45001];

//Struct to store indexes
struct aux
{
    long int value;
    int i;
};
typedef struct aux delivery;

//binary search
/**
 * @brief Function busca
 * @param vetor - vetor contendo os indices e o valores das casas
 * @param number - encomenda a ser buscada 
 * @param size - tamanho do vetor 
 * @return - index do vetor que contém a encomenda encontrada.
 * 
 */
int busca(delivery *vetor, int number, int size)
{
    int esq = -1, dir = size;
    while (esq < dir - 1)
    {
        int half = (esq + dir) / 2;
        (vetor[half].value < number) ?
            esq = half :
            dir = half;
    }
    return dir;
}

//mergeSort
//binary search
/**
 * @brief Function merge
 * @param vetor - vetor contendo os indices e o valores das casas
 * @param start - inicio 
 * @param half - meio
 * @param end - fim  
 * 
 */
void merge(delivery *vetor, int start, int half, int end) {

    delivery * auxArray = new delivery[end - start + 1];

    int i = start, 
    j = half + 1, 
    cont = 0; 

    while(i <= half && j <= end)
      (vetor[i].value < vetor[j].value) ? 
        auxArray[cont++] = vetor[i++] : 
        auxArray[cont++] = vetor[j++];
    
    while(i <= half)
        auxArray[cont++] = vetor[i++];
    
    while(j <= end) 
        auxArray[cont++] = vetor[j++];
    
    for(int i = start ; i <= end; ++i)
        vetor[i] = auxArray[i-start];
    
    free(auxArray);
}
/**
 * @brief Function mergeSort
 * @param vetor - vetor contendo os indices e o valores das casas
 * @param start - inicio 
 * @param end - tamanho vetor (a principio).
 * 
 */
void mergeSort(delivery *vetor, int start, int end){
    if (start < end) {
        int half = (end+start)/2;
        mergeSort(vetor, start, half);//sub-Vetor Esq
        mergeSort(vetor, half+1, end);//sub-Vetor Dir
        merge(vetor, start, half, end);//Merge
    }
}

int main (void) {

    delivery * houses = new delivery[45001];  
    int current = 0, previous = 0; 
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; ++i, houses[i].i = i)
      scanf("%ld", &houses[i].value);
  
    for (int j = 0; j < M; ++j)
        scanf("%ld", &t[j]);

    //Ordenando Vetor
    mergeSort(houses, 0, N-1);  

    int time = houses[busca(houses,t[0], N-1)].i;
    
    for (int i = 1; i < M; ++i) {
        current = houses[busca(houses,t[i], N)].i;
        previous = houses[busca(houses,t[i-1], N)].i;

        (current > previous) ? 
        time+=current-previous : 
        time+=previous-current;    
    }

     cout << time << "/n";
    
    return 0;
}