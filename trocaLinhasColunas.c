//
//  main.c
//  trocaLinhasColunas
//
//  Created by Cast on 17/01/19.
//  Copyright © 2019 Lucask84ever. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define TAM_MATRIZ 5
#define TAM_MAX 10

void mudaLinha(int tabela[TAM_MATRIZ][TAM_MATRIZ], int linha1, int linha2);
void mudaColuma(int tabela[TAM_MATRIZ][TAM_MATRIZ], int coluna1, int coluna2);
void trocaDiagonais(int tabela[TAM_MATRIZ][TAM_MATRIZ]);
void printaMatriz(int tabela[TAM_MATRIZ][TAM_MATRIZ]);
void adicionaValoresMatriz(int tabela[TAM_MATRIZ][TAM_MATRIZ], int tamMax);
void apresentaMensagemParaContinuar();

int main(int argc, const char * argv[]) {
	int tabela[TAM_MATRIZ][TAM_MATRIZ];
	adicionaValoresMatriz(tabela, TAM_MAX);
	//Apresenta a matriz normal
	printf("Matriz normal\n");
	printaMatriz(tabela);
	apresentaMensagemParaContinuar();
	
	// Trocando as linhas 2 e 5 (1 e 4);
	printf("Trocando linhas 2 e 5(1 e 4)\n");
	mudaLinha(tabela, 1, 4);
	printaMatriz(tabela);
	apresentaMensagemParaContinuar();
	
	// Troca as colunas 1 e 4 (0 e 3)
	printf("Mesclando Colunas 1 e 4(0 e 3)\n");
	mudaColuma(tabela, 0, 3);
	printaMatriz(tabela);
	apresentaMensagemParaContinuar();
	
	//Troca as diagonais
	printf("Trocando diagonais\n");
	trocaDiagonais(tabela);
	printaMatriz(tabela);
	printf("Programa encerrado.");
	return 0;
}

// Recebe a matriz e troca linha1 e linha2
void mudaLinha(int tabela[TAM_MATRIZ][TAM_MATRIZ], int linha1, int linha2) {
	int i = 0;
	for (i = 0; i < TAM_MATRIZ; i += 1) {
		tabela[linha1][i] = tabela[linha1][i] + tabela[linha2][i];
		tabela[linha2][i] = tabela[linha1][i] - tabela[linha2][i];
		tabela[linha1][i] = tabela[linha1][i] - tabela[linha2][i];
	}
}

// Recebe a matriz e troca coluna1 e coluna2
void mudaColuma(int tabela[TAM_MATRIZ][TAM_MATRIZ], int coluna1, int coluna2) {
	int i = 0;
	for (i = 0; i < TAM_MATRIZ; i += 1) {
		tabela[i][coluna1] = tabela[i][coluna1] + tabela[i][coluna2];
		tabela[i][coluna2] = tabela[i][coluna1] - tabela[i][coluna2];
		tabela[i][coluna1] = tabela[i][coluna1] - tabela[i][coluna2];
	}
}

// Troca a diagonal principal e a diagonal secundária
void trocaDiagonais(int tabela[TAM_MATRIZ][TAM_MATRIZ]) {
	int i = 0;
	int j = TAM_MATRIZ - 1
	;
	for(i = 0; i < TAM_MATRIZ; i += 1 ,j -= 1) {
		tabela[i][i] = tabela[i][i] + tabela[i][j];
		tabela[i][j] = tabela[i][i] - tabela[i][j];
		tabela[i][i] = tabela[i][i] - tabela[i][j];
	}
}

// Recebe a tabela e adiciona.
void adicionaValoresMatriz(int tabela[TAM_MATRIZ][TAM_MATRIZ], int tamMax) {
	int i, j;
	for(i = 0; i < TAM_MATRIZ; i += 1) {
		for(j = 0; j < TAM_MATRIZ; j++) {
			tabela[i][j] = (rand() % TAM_MAX + 1);
		}
	}
}

// Printa a matriz
void printaMatriz(int tabela[TAM_MATRIZ][TAM_MATRIZ]) {
	int i, j;
	for(i = 0; i < TAM_MATRIZ; i += 1) {
		for(j = 0; j < TAM_MATRIZ; j++) {
			printf("%02d ", tabela[i][j]);
		}
		printf("\n");
	}
}

void apresentaMensagemParaContinuar(){
	printf("\n Aperte uma tecla para continuar\n");
	getchar();
}
