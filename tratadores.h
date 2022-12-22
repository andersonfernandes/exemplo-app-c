#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);
void tratador_menu_turma(Turma **turmas, Aluno **alunos, int *qtd_atual_turma);
void tratador_menu_estatisticas(Turma **turmas, Professor **professores);

Endereco *construir_endereco();
void imprimir_endereco(Endereco *endereco);

Aluno *construir_aluno();
Aluno *atualizar_aluno();
Aluno *buscar_aluno(Aluno **alunos, int *posicao);
void imprimir_aluno(Aluno *aluno);

Professor *construir_professor();
Professor *atualizar_professor();
Professor *buscar_professor(Professor **professores, int *posicao);
void imprimir_professor(Professor *professor);

Turma *construir_turma();
Turma *buscar_turma(Turma **turmas, int *posicao);
void imprimir_turma(Turma *turma);
void adicionar_aluno(Turma *turma, Aluno *aluno);

void imprimir_nomes_dos_professores(Professor **professores);
void imprimir_professores_sem_turma(Professor **professores, Turma **turmas);
void imprimir_media_de_turmas(Turma **turmas);

#endif
