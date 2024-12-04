// Representação de árvore binária aplicada em vetor, usado para a
// construção de filas de prioridade.
// O heap pode ser mínimo ou máximo. Os índices são ordenados de cima
// para baixo e da esquerda para a direita.

// lower_round(i/2) = pai de i;
// 2i é o filho esquerdo de i;
// 2i + 1 é o filho direito de i.

// Heap max: v[pai] >= v[filho(esq||dir)];
// - maior elemento na primeira posição.
// Heap min: v[pai] <= v[filho(esq||dir)];
// - menor elemento na primeira posição.

// A inserção ocorre no final do heap e a remoção é no primeiro
// elemento do heap.

// OBS: Os índices começam em 1.

#include <stdio.h>
#include <stdlib.h>

// Além de inserir, garante que o heap obedece às propriedades da
// estrutura [O(log(n))]
void heapInsert(int m, int v[]){
    int f = m + 1;
    while(f > 1 && v[f/2] < v[f]){
        // Troca o valor
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        // Altera a posição(índice)
        f = f/2;
    }
}

// Corrige o heap após a remoção ou troca de elementos do heap.
void heapify(int m, int v[]){
    int t, f = 2;
    while(f <= m){
        if(f < m && v[f] < v[f + 1])
            f++;
        if(v[f/2] >= v[f])
            break;
        // Troca o valor
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;

        f *= 2;
    }
}

// Ordena o heap
void heapSort(int n, int v[]){
    int m;
    for(m = 1; m < n; m++)
        heapInsert(m, v);
    for(m = n; m > 1; m--){
        // Troca o primeiro valor com o último do loop
        int t = v[1];
        v[1] = v[m];
        v[m] = t;

        heapify(m - 1, v);
    }
}

int main(void){

    return 0;
}