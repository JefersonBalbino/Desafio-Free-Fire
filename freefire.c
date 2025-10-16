#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int total_itens = 0;

// Função para listar todos os itens
void listarItens() {
    printf("\nItens na mochila:\n");
    if (total_itens == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    for (int i = 0; i < total_itens; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar um item pelo nome
void buscarItem(char nome[]) {
    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    printf("Item '%s' não encontrado na mochila.\n", nome);
}

// Função para cadastrar um novo item
void cadastrarItem() {
    if (total_itens >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    Item novo;
    printf("Nome do item: ");
    scanf("%s", novo.nome);
    printf("Tipo do item: ");
    scanf("%s", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[total_itens] = novo;
    total_itens++;
    printf("Item cadastrado com sucesso!\n");
    listarItens();
}

// Função para remover um item pelo nome
void removerItem() {
    char nome[30];
    printf("Digite o nome do item a remover: ");
    scanf("%s", nome);
    for (int i = 0; i < total_itens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            // Move os itens seguintes para trás
            for (int j = i; j < total_itens - 1; j++) {
                mochila[j] = mochila[j+1];
            }
            total_itens--;
            printf("Item removido com sucesso!\n");
            listarItens();
            return;
        }
    }
    printf("Item '%s' não encontrado na mochila.\n", nome);
}

int main() {
    int opcao;
    char busca[30]; // Variável para busca de item

    do {
        printf("\n=== Mochila Free Fire ===\n"); 
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) { // Adicionado switch-case para melhor legibilidade
            case 1:
                cadastrarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                printf("Digite o nome do item para buscar: ");
                scanf("%s", busca);
                buscarItem(busca);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}