#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* --- Aluno --- */

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno)
    {
        strcpy(aluno->matricula, matricula);
        strcpy(aluno->cpf, cpf);
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return aluno;
}

Aluno *atualizarAluno(Aluno *aluno, Aluno *novo_aluno)
{
    if (aluno && novo_aluno)
    {
        strcpy(aluno->cpf, novo_aluno->cpf);
        strcpy(aluno->nome, novo_aluno->nome);
        aluno->endereco = novo_aluno->endereco;
    }
    return aluno;
}

void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end);
        free(aluno);
    }
}

/* --- Endereco --- */

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return endereco;
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}

/* --- Professor --- */

Professor *criarProfessor(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {
        strcpy(professor->matricula, matricula);
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return professor;
}

Professor *atualizarProfessor(Professor *professor, Professor *novo_professor)
{
    if (professor && novo_professor)
    {
        strcpy(professor->cpf, novo_professor->cpf);
        strcpy(professor->nome, novo_professor->nome);
        professor->endereco = novo_professor->endereco;
    }
    return professor;
}

void destruirProfessor(Professor *professor)
{
    if (professor)
    {
        Endereco *end = professor->endereco;
        destruirEndereco(end);
        free(professor);
    }
}


/* --- Turma --- */

Turma *atualizarTurma(Turma *turma, Turma *nova_turma)
{
    if (turma && nova_turma)
    {
        strcpy(turma->nome_disciplina, nova_turma->nome_disciplina);
        turma->media_turma = nova_turma->media_turma;
    }
    return turma;
}

Turma *criarTurma(char *codigo_turma,
                  char *nome_disciplina,
                  float media_turma) 
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    if(turma)
    {
        strcpy(turma->codigo, codigo_turma);
        strcpy(turma->nome_disciplina, nome_disciplina);
        turma->professor = NULL;
        turma->media_turma = media_turma;
        turma->qtd_alunos = 0;
    }
    else 
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }

    return turma;
}

Turma *adicionarAluno(Turma *turma, Aluno *aluno) 
{
    if (turma && aluno) 
    {
        turma->lista_alunos[turma->qtd_alunos] = aluno;
        turma->qtd_alunos += 1;
    }
    return turma;
}

void destruirTurma(Turma *turma)
{
    if (turma)
        free(turma);
}

Turma *adicionarProfessor(Turma *turma, Professor *professor)
{
    turma->professor = (Professor *)realloc(turma->professor, sizeof(Professor));
    if (turma && professor)
    {
        turma->professor = professor;
    }

    return turma;
}