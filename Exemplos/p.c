#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *nome;
	int id;
} Aluno;

Aluno* alocar(int tam) {
	Aluno *turma;
	turma = (Aluno *) malloc(tam * sizeof (Aluno));
	for (int i = 0; i < tam; i++) {
		turma[i].nome = (char *) malloc(200 * sizeof (char));
	}
	return turma;
}

int main() {
	Aluno *turma;
	int i, j;
	char nome[] = "Iasmin Nimsai Najasmin";
	turma = alocar(5);
	for (i = 0; i < 5; i++) {
		turma[i].id = i;
		strcpy(turma[i].nome, nome);
		printf("Nome: %s\nId: %d\n\n", turma[i].nome, turma[i].id);
	}
	return 0;
}
