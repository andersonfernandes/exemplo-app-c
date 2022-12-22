#include <stdio.h>
#include <string.h>
#include "tratadores.h"
#include "menus.h"
#include "constantes.h"

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            int i = 0;
            for (; i <= *qtd_atual_aluno; i++)
            {
                if (alunos[i] == NULL)
                {
                    break;
                }
            }
            Aluno *aluno = construir_aluno();
            alunos[i] = aluno;
            *qtd_atual_aluno++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            imprimir_aluno(aluno);
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            atualizar_aluno(aluno);
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }

    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_professor(Professor **professores, int *qtd_atual_professor)
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_professor >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");
        }
        else
        {
            int i = 0;
            for (; i <= *qtd_atual_professor; i++)
            {
                if (professores[i] == NULL)
                {
                    break;
                }
            }
            Professor *professor = construir_professor();
            professores[i] = professor;
            *qtd_atual_professor++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            atualizar_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_turma(Turma **turmas, Aluno **alunos, Professor **professores, int *qtd_atual_turma)
{
    int opcao = menu_crud_turma();
    Turma *turma = NULL;
    Aluno *aluno = NULL;
    Professor *professor = NULL;
    
    switch (opcao)
    {
        case 1:
        
            if (*qtd_atual_turma >= MAX_TURMA)
            {
                printf("Número máximo de turmas atingido\n");
            }
            else
            {
                int i = 0;
                for (; i <= *qtd_atual_turma; i++)
                {
                    if (turmas[i] == NULL)
                    {
                       break;
                    }
                }
                Turma *turma = construir_turma();
                turmas[i] = turma;
                *qtd_atual_turma++;
            }
            break;
        case 2:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                imprimir_turma(turma);
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
            break;
        }
        case 3:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                atualizar_turma(turma);
                printf("Turma atualizada com sucesso!\n");
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
            break;
        }
        case 4:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                destruirTurma(turma);
                turmas[posicao] = NULL;
                printf("Turma destruida\n");
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
        }
        break;
        case 5:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                posicao = 0;
                aluno = buscar_aluno(alunos, &posicao);

                if (aluno)
                {
                    adicionarAluno(turma, aluno);
                    printf("Aluno adicionado com sucesso!\n");
                }
                else
                {
                    printf("Aluno não encontrado!!\n");
                }
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
            break;
        }
        default:
            printf("Retornando ao menu principal\n");
            break;
    }
}

void tratador_menu_estatisticas(Turma **turmas, Professor **professores)
{
    int opcao = menu_estatisticas();
    switch (opcao)
    {
        case 1:
            imprimir_nomes_dos_professores(professores);
            break;
        case 2:
            imprimir_professores_sem_turma(professores, turmas);
            break;
        case 3:
            imprimir_media_de_turmas(turmas);
            break;
        case 4:
            break;
    }
}

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Número\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;
    printf("Matrícula do aluno\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF do aluno\t> ");
    fgets(aluno.cpf, 13, stdin);
    printf("Nome do aluno\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *atualizar_aluno(Aluno *aluno)
{
    Aluno novo_aluno;
    printf("CPF\t> ");
    fgets(novo_aluno.cpf, 13, stdin);
    printf("Nome\t> ");
    fgets(novo_aluno.nome, 49, stdin);
    novo_aluno.endereco = construir_endereco();
    return atualizarAluno(aluno, &novo_aluno); 
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matrícula do aluno > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_aluno(Aluno *aluno)
{
    printf("Matrícula do aluno: %s", aluno->matricula);
    printf("Nome do aluno: %s", aluno->nome);
    printf("CPF do aluno: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Número: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

/*  -------------------------------   */

Professor *construir_professor()
{
    Professor professor;
    printf("Matrícula do professor\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("CPF do professor\t> ");
    fgets(professor.cpf, 13, stdin);
    printf("Nome do professor\t> ");
    fgets(professor.nome, 49, stdin);
    professor.endereco = construir_endereco();
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *atualizar_professor(Professor *professor)
{
    Professor novo_professor;
    printf("CPF\t> ");
    fgets(novo_professor.cpf, 12, stdin);
    printf("Nome\t> ");
    fgets(novo_professor.nome, 49, stdin);
    novo_professor.endereco = construir_endereco();
    return atualizarProfessor(professor, &novo_professor); 
}

Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matrícula do professor> ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_professor(Professor *professor)
{
    printf("Matrícula do professor: %s", professor->matricula);
    printf("Nome do professor: %s", professor->nome);
    printf("CPF do professor: %s", professor->cpf);
    imprimir_endereco(professor->endereco);
}

/*  -------------------------------   */

Turma *construir_turma()
{
    Turma turma;
    printf("Codigo da turma\t> ");
    fgets(turma.codigo, 50, stdin);
    printf("Nome da disciplina\t> ");
    fgets(turma.nome_disciplina, 50, stdin);
    printf("Media\t> ");
    scanf("%f", &turma.media_turma);
    getchar();
    return criarTurma(turma.codigo, turma.nome_disciplina, turma.media_turma);
}

Turma *buscar_turma(Turma **turmas, int *posicao)
{
    char codigo[50];
    printf("Codigo da turma > ");
    fgets(codigo, 49, stdin);
    Turma *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_TURMA; i++)
    {
        if (turmas[i] && !strcmp(codigo, turmas[i]->codigo))
        {
            resultado = turmas[i];
            pos_resultado = i;
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

Turma *atualizar_turma(Turma *turma)
{
    Turma nova_turma;
    printf("Nome da Disciplina\t> ");
    fgets(nova_turma.nome_disciplina, 12, stdin);
    printf("Media\t> ");
    scanf("%f", &nova_turma.media_turma);
    return atualizarTurma(turma, &nova_turma);
}

void imprimir_turma(Turma *turma)
{
    printf("== Turma ==\n");
    printf("Codigo: %s", turma->codigo);
    printf("Nome da Disciplina: %s", turma->nome_disciplina);
    printf("Media da Turma: %.2f\n", turma->media_turma);
    printf("Quantidade de alunos: %d\n", turma->qtd_alunos);

    if (turma->professor != NULL)
    {
        printf("Professor: %s", turma->professor->nome);
    }
    
    if (turma->qtd_alunos != 0) {
        printf("---------------------\n");
        for (int i = 0; i < turma->qtd_alunos; i++)
        {
            printf("Nº do aluno: %d\n", i+1);
            printf("Matrícula do aluno: %s", turma->lista_alunos[i].matricula);
            printf("Nome do aluno: %s", turma->lista_alunos[i].nome);
            printf("---------------------\n");
        }
    }
}

void adicionar_aluno(Turma *turma, Aluno *aluno)
{
    adicionarAluno(turma, aluno);
}

void imprimir_nomes_dos_professores(Professor **professores)
{
    if (professores[0] == NULL)
    {
        printf("\nSem professores cadastrados.\n\n");
        return;
    }

    printf("== Lista de Professores ==\n\n");

    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        if (professores[i] == NULL)
        {

            printf("\n");
            return;
        }

        printf("> %s", professores[i]->nome);
    }
}

void imprimir_professores_sem_turma(Professor **professores, Turma **turmas)
{
    if (professores[0] == NULL)
    {
        printf("\nSem professores cadastrados.\n\n");
        return;
    }

    printf("== Lista de Professores sem turma ==\n\n");

    int qtd_professores_sem_turma = 0;
    Professor *professores_sem_turma[MAX_PROFESSOR];
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        if (professores[i] == NULL)
        {
            break;
        }

        int turma_achada = 0;
        for (int i = 0; i < MAX_TURMA; i++)
        {
            if (turmas[i] == NULL)
            {
                break;
            }

            if (turmas[i]->professor == professores[i])
            {
                turma_achada = 1;
                break;
            }
        }

        if (!turma_achada)
        {
            professores_sem_turma[qtd_professores_sem_turma] = professores[i];
            ++qtd_professores_sem_turma;
        }
    }

    if (professores_sem_turma[0] == NULL)
    {
        printf("\nTodos os professores cadastratos estão alocados em turma\n\n");
        return;
    }

    for (int i = 0; i < qtd_professores_sem_turma; i++)
    {
        if (professores_sem_turma[i] == NULL)
        {
            break;
        }

        printf("> %s", professores_sem_turma[i]->matricula);
    }
}

void imprimir_media_de_turmas(Turma **turmas)
{
    if (turmas[0] == NULL)
    {
        printf("\nSem turmas cadastrados.\n\n");
        return;
    }

    float soma = 0.0;
    int qtd_turmas = 0;
    for (int i = 0; i < MAX_TURMA; i++)
    {
        if (turmas[i] == NULL)
        {
            break;
        }

        ++qtd_turmas;
        soma += turmas[i]->media_turma;
    }

    printf("\n\nNota média de todas as turmas: %.2f\n\n", soma / qtd_turmas);
}
