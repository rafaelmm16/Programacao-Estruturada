/* CABEÇALHO
   Arquivo: calcularMediaAluno.versao1.c
   Objetivo: Solicita dados de um aluno (nome, matrícula, disciplina, curso, período),
             incluindo disciplina e as notas de 2 provase imprime na tela recibo de matrícula,
             junto com a média do aluno na disciplina
   Autor(a): Rafael Merlo Mendes
   Versão: 1.0
   Versão: 3.0*/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <string.h>
#include <locale.h>

/* Programa Principal */
int main() {

   /* Declare variáveis */
   setlocale (LC_ALL, "Portuguese");
   char nome[64], curso[64], data_nascimento[12], disciplina[64], matricula[12];
   int periodo;
   float nota1, nota2, media, nota_final;

   /* Solicitar valores */
   printf("Curso: ");
   fflush(stdin); /* Limpeza de buffer */
   /* scanf("%s",curso); */
   gets(curso);

   printf("Período: ");
   scanf("%d",&periodo);

   printf("\nInforme de dados de um aluno\n");

   printf("Nome: ");
   fflush(stdin); /* Limpeza de buffer */
   /* scanf("%s",nome); */ /* PROBLEMA PARA LEITURA DE NOMES COMPOSTOS */
   gets(nome); /* NÃO HÁ PROBLEMA PARA LEITURA DE NOMES COMPOSTOS */

   printf("Matrícula (11 digidos): ");
   fflush(stdin); /* Limpeza de buffer */
   gets(matricula);

   printf("Data de nascimento (Formato dd/mm/aaaa): ");
   fflush(stdin); /* Limpeza de buffer */
   gets(data_nascimento);

   printf("\nDisciplina: ");
   fflush(stdin); /* Limpeza de buffer */
   gets(disciplina);

   printf("Nota da Avaliação 1: ");
   scanf("%f",&nota1);
   printf("Nota da Avaliação 2: ");
   scanf("%f",&nota2);

   media = (nota1 + nota2)/2;
   if (media>=7)
   {
        printf("\n\n--------------- RECIBO DE MATRÍCULA ---------------");
        printf("\n- Aluno: %s    - ", nome);
        printf("\n- Curso: %s   - ", curso);
        printf("\n- Período: %d   - ", periodo);
        printf("\n- Matrícula: %s   - ", matricula);
        printf("\n- Data de Nascimento: %s   - ", data_nascimento);
        printf("\n- Disciplina: %s   - ", disciplina);
        printf("\n---------------------------------------------------\n\n");
        printf("--------------- HISTORICO NA DISCIPLINA %s ---------------", disciplina);
        printf("\n- Nota da Avaliacao 1: %f   - ", nota1);
        printf("\n- Nota da Avaliacao 2: %f   - ", nota2);
        printf("\n- Média: %f   - ", media);
        printf("\n- O aluno esta:   - Aprovado! ");
        printf("\n---------------------------------------------------\n\n");
   }
   if (media<7)
   {
        printf("--------------- HISTORICO NA DISCIPLINA %s ---------------", disciplina);
        printf("\n- Nota da Avaliacao 1: %f   - ", nota1);
        printf("\n- Nota da Avaliacao 2: %f   - ", nota2);
        printf("\n- Média: %f   - ", media);
        printf("\n- O aluno esta:   - Reprovado! ");
        printf("\n---------------------------------------------------\n\n");
   }

   return 0;
}
