#include <stdio.h>
#include <string.h>

int expressao_simplificada(int a, int b, int c, int d) {
    return (!b && d)&&(a||c);
}

int ler_bit(const char *pergunta) {
    char linha[64];
    while (1) {
        printf("%s (0 ou 1): ", pergunta);
        if (fgets(linha, sizeof linha, stdin) == NULL)
            return -1;

        if (strchr(linha, '\n') == NULL) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Entrada invalida: muito longa. Digite apenas 0 ou 1.\n");
            continue;
        }

        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, "0") == 0) return 0;
        if (strcmp(linha, "1") == 0) return 1;
        printf("Entrada invalida. Digite apenas 0 ou 1.\n");
    }
}

int ler_opcao(void) {
    char linha[64];
    while (1) {
        printf("\nEscolha uma opcao: ");
        if (fgets(linha, sizeof linha, stdin) == NULL)
            return -1;

        if (strchr(linha, '\n') == NULL) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Opcao invalida. Digite 0 ou 1.\n");
            continue;
        }

        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, "0") == 0) return 0;
        if (strcmp(linha, "1") == 0) return 1;
        printf("Opcao invalida. Digite 0 ou 1.\n");
    }
}

void mostrar_avisos(void) {
    printf("==============================================================\n");
    printf(" CITIZEN ASSIST AI - Orientacao inicial para passaporte\n");
    printf("==============================================================\n");
    printf(" AVISOS:\n");
    printf(" - Este prototipo NAO e um canal oficial da Policia Federal.\n");
    printf(" - Confirme sempre as exigencias no site oficial da PF.\n");
    printf("==============================================================\n");
}

void mostrar_menu(void) {
    printf("\n1 - Consultar (informar as 4 condicoes)\n");
    printf("0 - Sair\n");
}

void consultar(void) {
    int a, b, c, d;

    printf("\nResponda cada pergunta com 1 (sim) ou 0 (nao).\n");

    if ((a = ler_bit("A - Voce tem 18 anos ou mais?")) < 0) return;
    if ((b = ler_bit("B - Voce possui alguma pendencia eleitoral?")) < 0) return;
    if ((c = ler_bit("C - Voce possui autorizacao dos responsaveis?")) < 0) return;
    if ((d = ler_bit("D - Voce possui os documentos basicos?")) < 0) return;

    int s = expressao_simplificada(a, b, c, d);

    if (s) {
        printf("\nSIM: pelas informacoes fornecidas, voce parece reunir as\n");
        printf("condicoes para iniciar o processo de passaporte.\n");
    } else {
        printf("\nNAO: pelas informacoes fornecidas, voce ainda nao parece\n");
        printf("reunir as condicoes para iniciar o processo.\n");
        if (b) printf(" - Ha pendencia eleitoral a resolver.\n");
        if (!d) printf(" - Faltam documentos basicos.\n");
        if (!a && !c) printf(" - Menor de idade precisa de autorizacao dos responsaveis.\n");
    }
}

int main(void) {
    mostrar_avisos();

    while (1) {
        mostrar_menu();
        int op = ler_opcao();
        if (op < 0 || op == 0) {
            printf("\nEncerrando.\n");
            break;
        }
        if (op == 1) consultar();
    }
    return 0;
}
