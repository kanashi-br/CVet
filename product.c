#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "product.h"
#include "database.h"
#include "utils.h"
#include "aux_functions.h"


// Produtos
/////////////////////////////////////////////////////////////////////////
char product_menu() {
    int op = -1;
    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = = =  Menu Produto = = = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    printf("|||            1. Cadastrar um novo produto                                 |||\n");
    printf("|||            2. Listar todos os produtos                                  |||\n");
    printf("|||            3. Pesquisar os dados de um produto                          |||\n");
    printf("|||            4. Atualizar o cadastro de um produto                        |||\n");
    printf("|||            5. Excluir um produto do sistema                             |||\n");
    printf("|||            0. Voltar ao menu anterior                                   |||\n");
    printf("|||                                                                         |||\n");
    printf("|||            Escolha a opção desejada: ");
    scanf("%d", &op);
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); getchar();
    return op;
}


void create_product() {
    char caractere;
    char description[100], type[100];
    float price;
    int day, month, year;
    int is_valid = 0;

    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = =  Cadastrar Produto  = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    do
    {
        printf("|||            Descrição: ");
        scanf("%[^\n]%*c", description);

        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_name(description);
        if (is_valid){
            printf("|||            Descrição digitada: %s\n", description);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Descrição digitada inválida.                                 |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);

    do
    {
        printf("|||            Tipo/categoria: ");
        scanf("%[^\n]%*c", type);

        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_name(type);
        if (is_valid){
            printf("|||            Tipo/categoria digitado: %s\n", type);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Tipo/categoria digitada inválida.                            |||\n");
            printf("|||            Digite apenas letras e espaços.                              |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);

    do
    {
        printf("|||            Preço: ");
        scanf("%f", &price);

        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_price(price);
        if (is_valid){
            printf("|||            Preço digitado: %.2f\n", price);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Preço digitado inválido. Verifique se é maior que 0.         |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);
    do
    {
        printf("|||            Validade (dd/mm/aaaa):                                       |||\n");
        printf("|||            (NOTA: insira 00/00/0000 para datas indeterminadas)          |||\n");
        printf("|||            Digite: ");
        scanf("%d%*c%d%*c%d", &day, &month, &year);

        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_expiration_date(day, month, year);
        if (is_valid){
            if (year == 0 && month == 0 && day == 0)
            {
                printf("|||            Data inserida como \"INDETERMINADA\"                               |||\n");

            } else {
                printf("|||            Data digitada: %02d/%02d/%04d                                    |||\n", day, month, year);

            }
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Data digitada inválida.                                      |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    insert_product(description, type, price, day, month, year);
    printf("CADASTRADO COM SUCESSO!!\n");
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void all_products() {
    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = =  Lista de Produtos  = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    printf("|||            Todos os produtos cadastrados:                               |||\n");
    list_products();
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void search_product() {
    char caractere; 
    char search[100];
    int is_valid = 0;
    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = =  Pesquisar Produto  = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    
    do
    {
        printf("|||            Informe a descrição do produto: ");
        scanf("%[^\n]%*c", search);
        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_name(search);
        if (is_valid){
            printf("|||            Descrição digitada: %s\n", search);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Descrição digitada inválida.                                 |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    find_product(search);
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void edit_product() {
    char caractere; 
    char search[100];
    int is_valid = 0;
    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = =  Alterar Produto  = = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    
    do
    {
        printf("|||            Informe a descrição do produto: ");
        scanf("%[^\n]%*c", search);
        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_name(search);
        if (is_valid){
            printf("|||            Descrição digitada: %s\n", search);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Descrição digitada inválida.                                 |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    update_product(search);
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void delete_product() {
    char caractere; 
    char search[100];
    int is_valid = 0;
    system("clear||cls");
    printf("\n");
    header();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||            = = = = = = = = Excluir Produto = = = = = = = =              |||\n");
    printf("|||            = = = = = = = = = = = = = = = = = = = = = = = =              |||\n");
    printf("|||                                                                         |||\n");
    do
    {
        printf("|||            Descrição do produto: ");
        scanf("%[^\n]%*c", search);

        while ((caractere = getchar()) != '\n' && caractere != EOF);
        is_valid = validate_name(search);
        if (is_valid){
            printf("|||            Descrição digitada: %s\n", search);
            printf("|||                                                                         |||\n");
        } else {
            printf("|||            Descrição digitada inválida.                                 |||\n");
            printf("|||                                                                         |||\n");
        }
    } while (!is_valid);
    
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    remove_product(search);
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}