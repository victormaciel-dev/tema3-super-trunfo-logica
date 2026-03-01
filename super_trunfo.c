#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    long populacao;
    double pib;
    double area;
    int turismo;
} Carta;

Carta criarCarta() {
    Carta c;

    printf("\nNome da cidade: ");
    scanf(" %[^\n]", c.nome);

    printf("Populacao: ");
    scanf("%ld", &c.populacao);

    printf("PIB: ");
    scanf("%lf", &c.pib);

    printf("Area: ");
    scanf("%lf", &c.area);

    printf("Pontos turisticos: ");
    scanf("%d", &c.turismo);

    return c;
}

void mostrarCarta(Carta c) {
    printf("\n--- Carta ---\n");
    printf("Cidade: %s\n", c.nome);
    printf("Populacao: %ld\n", c.populacao);
    printf("PIB: %.2f\n", c.pib);
    printf("Area: %.2f\n", c.area);
    printf("Turismo: %d\n", c.turismo);
}

void compararAtributo(Carta a, Carta b, int escolha) {
    printf("\nResultado:\n");

    switch(escolha) {

        case 1:
            if(a.populacao > b.populacao)
                printf("%s venceu em populacao\n", a.nome);
            else if(a.populacao < b.populacao)
                printf("%s venceu em populacao\n", b.nome);
            else
                printf("Empate!\n");
        break;

        case 2:
            if(a.pib > b.pib)
                printf("%s venceu em PIB\n", a.nome);
            else if(a.pib < b.pib)
                printf("%s venceu em PIB\n", b.nome);
            else
                printf("Empate!\n");
        break;

        case 3:
            if(a.area > b.area)
                printf("%s venceu em Area\n", a.nome);
            else if(a.area < b.area)
                printf("%s venceu em Area\n", b.nome);
            else
                printf("Empate!\n");
        break;

        case 4:
            if(a.turismo > b.turismo)
                printf("%s venceu em Turismo\n", a.nome);
            else if(a.turismo < b.turismo)
                printf("%s venceu em Turismo\n", b.nome);
            else
                printf("Empate!\n");
        break;

        default:
            printf("Opcao invalida\n");
    }
}

void compararDoisAtributos(Carta a, Carta b) {

    int pontosA = 0;
    int pontosB = 0;

    pontosA += (a.populacao > b.populacao) ? 1 : 0;
    pontosB += (b.populacao > a.populacao) ? 1 : 0;

    pontosA += (a.pib > b.pib) ? 1 : 0;
    pontosB += (b.pib > a.pib) ? 1 : 0;

    printf("\nResultado Final:\n");

    if(pontosA > pontosB)
        printf("%s venceu no geral!\n", a.nome);
    else if(pontosB > pontosA)
        printf("%s venceu no geral!\n", b.nome);
    else
        printf("Empate geral!\n");
}

int main() {

    int opcao;

    printf("Cadastro da Carta 1\n");
    Carta c1 = criarCarta();

    printf("\nCadastro da Carta 2\n");
    Carta c2 = criarCarta();

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Mostrar cartas\n");
        printf("2 - Comparar por atributo\n");
        printf("3 - Comparacao geral (2 atributos)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                mostrarCarta(c1);
                mostrarCarta(c2);
            break;

            case 2:
                printf("\nEscolha atributo:\n");
                printf("1 Populacao\n");
                printf("2 PIB\n");
                printf("3 Area\n");
                printf("4 Turismo\n");
                printf("Opcao: ");

                int att;
                scanf("%d", &att);
                compararAtributo(c1,c2,att);
            break;

            case 3:
                compararDoisAtributos(c1,c2);
            break;

            case 0:
                printf("Encerrando...\n");
            break;

            default:
                printf("Opcao invalida\n");
        }

    } while(opcao != 0);

    return 0;
}
