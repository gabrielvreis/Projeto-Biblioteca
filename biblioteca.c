#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char titulo[100];
    char autor[100];
    int ano;
}Livro;

#define MAX_LIVROS 100

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    Livro novo;

    novo.id = totalLivros + 1; 
    printf("Digite o titulo do livro: ");
    fgets(novo.titulo, sizeof(novo.titulo), stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(novo.autor, sizeof(novo.autor), stdin);
    novo.autor[strcspn(novo.autor, "\n")] = '\0';

    printf("Digite o ano de publicacao: ");
    scanf("%d", &novo.ano);
    getchar();

    biblioteca[totalLivros] = novo;
    totalLivros++;

    printf("Livro cadastrado com sucesso! ID: %d\n", novo.id);
};

void listarLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n===== Lista de Livros =====\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("ID: %d\n", biblioteca[i].id);
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Ano: %d\n", biblioteca[i].ano);
        printf("---------------------------\n");
    }
};

void buscarLivro() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    char tituloBusca[100];
    printf("Digite o titulo que deseja buscar: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(biblioteca[i].titulo, tituloBusca) == 0) {
            printf("\nLivro encontrado!\n");
            printf("ID: %d\n", biblioteca[i].id);
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Ano: %d\n", biblioteca[i].ano);
            printf("---------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro nao encontrado.\n");
    }
};

void removerLivro() {
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int idRemover;
    printf("Digite o ID do livro que deseja remover: ");
    scanf("%d", &idRemover);
    getchar();

    int encontrado = -1;
    for (int i = 0; i < totalLivros; i++) {
        if (biblioteca[i].id == idRemover) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Livro com ID %d nao encontrado.\n", idRemover);
        return;
    }

    for (int i = encontrado; i < totalLivros - 1; i++) {
        biblioteca[i] = biblioteca[i + 1];
        biblioteca[i].id = i + 1; 
    }

    totalLivros--;
    printf("Livro removido com sucesso!\n");
};

int main() {
    int opcao;

    do {
        printf("\n===== Sistema de Biblioteca =====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro por titulo\n");
        printf("4. Remover livro por ID\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                listarLivros();
                break;
            case 3:
                buscarLivro();
                break;
            case 4:
                removerLivro();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
