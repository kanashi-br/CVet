// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |||             Universidade Federal do Rio Grande do Norte                 |||
// |||                 Centro de Ensino Superior do Seridó                     |||
// |||               Departamento de Computação e Tecnologia                   |||
// |||                  Disciplina DCT1106 -- Programação                      |||
// |||          Projeto Sistema de Gestão de Clínica Veterinária               |||
// |||           Desenvolvido por @iamrlison -- desde Ago, 2023                |||
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |||                                Semana 2                                 |||
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "client.h"
#include "animal.h"
#include "product.h"
#include "service.h"
#include "sale.h"
#include "worker.h"
#include "about.h"
#include "aux_functions.h"

#define true 1
#define false 0

//
// Variáveis globais
char caractere;
// Definição da estrutura do nó da lista de clientes
struct Client {
    char cpf[11];
    char name[100];
    char email[255];
    char phone[13];
    int dayBorn, monthBorn, yearBorn;
    struct Client* next;
};

struct Client* listClients = NULL; // Lista de clientes

/////
// Assinatura das funções
// Menu principal
char main_menu();






/////
// Programa principal
int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");
    int isRunning = true;
    while (isRunning){
        char op = main_menu();
        char inMenu = false;
        char sub_op;
        switch (op)
        {
        case '0': // FECHAR PROGRAMA
            isRunning = false;
            break;
        case '1': // CLIENTES
            inMenu = true;
            while(inMenu) { 
                sub_op = client_menu();
                if (sub_op == '0') { // Sair clientes
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar cliente
                    create_client();
                } else if (sub_op == '2') { // Pesquisar cliente
                    search_client();
                } else if (sub_op == '3') { // Atualizar cliente
                    edit_client();
                } else if (sub_op == '4') { // Remover cliente
                    delete_client();
                } else {
                    no_operation("Menu Clientes");
                }
            }
            break;
        case '2': // ANIMAIS
            inMenu = true;
            while(inMenu) { 
                sub_op = animal_menu();
                if (sub_op == '0') { // Sair animais
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar animal
                    create_animal();
                } else if (sub_op == '2') { // Pesquisar animal
                    search_animal();
                } else if (sub_op == '3') { // Atualizar animal
                    edit_animal();
                } else if (sub_op == '4') { // Remover animal
                    delete_animal();
                } else {
                    no_operation("Menu Animais");
                }
            }
            break;
        
        case '3': // PRODUTOS 
            inMenu = true;
            while(inMenu) { 
                sub_op = product_menu();
                if (sub_op == '0') { // Sair produtos
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar produtos
                    create_product();
                } else if (sub_op == '2') { // Pesquisar produtos
                    search_product();
                } else if (sub_op == '3') { // Atualizar produtos
                    edit_product();
                } else if (sub_op == '4') { // Remover produtos
                    delete_product();
                } else {
                    no_operation("Menu Produtos");
                }
            }
            break;
        case '4': // SERVIÇOS    
            inMenu = true;
            while(inMenu) { 
                sub_op = service_menu();
                if (sub_op == '0') { // Sair serviços
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar serviços
                    create_service();
                } else if (sub_op == '2') { // Pesquisar serviços
                    search_service();
                } else if (sub_op == '3') { // Atualizar serviços
                    edit_service();
                } else if (sub_op == '4') { // Remover serviços
                    delete_service();
                } else {
                    no_operation("Menu Serviços");
                }
            }
            break;

        case '5': // VENDAS
            inMenu = true;
            while(inMenu) { 
                sub_op = sale_menu();
                if (sub_op == '0') { // Sair vendas
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar venda
                    create_sale();
                } else if (sub_op == '2') { // Pesquisar venda
                    search_sale();
                } else if (sub_op == '3') { // Remover venda
                    delete_sale();
                } else {
                    no_operation("Menu Vendas");
                }
            }
            break;
        case '6': // FUNCIONÁRIOS 
            inMenu = true;
            while(inMenu) { 
                sub_op = worker_menu();
                if (sub_op == '0') { // Sair funcionários
                    inMenu = false;
                } else if (sub_op == '1') { // Cadastrar funcionário
                    create_worker();
                } else if (sub_op == '2') { // Pesquisar funcionário
                    search_worker();
                } else if (sub_op == '3') { // Atualizar funcionário
                    edit_worker();
                } else if (sub_op == '4') { // Remover funcionário
                    delete_worker();
                } else {
                    no_operation("Menu Funcionários");
                }
            }
            break;
        
        case '7':
            about_soft();
            break;
        case '8':
            about_dev();
            break;
        default:
            no_operation("Menu Principal");
            break;
        }
          
    }
    return 0;
}


// Funções
/////////////////////////////////////////////////////////////////////////
char main_menu() {
    char op;
    system("clear||cls");
    printf("\n");
    header_complete();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||            = = = =      Clínica Veterinária CVet      = = = =           |||\n");
    printf("|||                                                                         |||\n");
    printf("|||            1. Módulo Clientes                                           |||\n");
    printf("|||            2. Módulo Animais                                            |||\n");
    printf("|||            3. Módulo Produtos                                           |||\n");
    printf("|||            4. Módulo Serviços                                           |||\n");
    printf("|||            5. Módulo Vendas                                             |||\n");
    printf("|||            6. Módulo Funcionários                                       |||\n");
    printf("|||            7. Sobre o software                                          |||\n");
    printf("|||            8. Sobre o desenvolvedor                                     |||\n");
    printf("|||            0. Sair                                                      |||\n");
    printf("|||                                                                         |||\n");
    printf("|||            Escolha a opção desejada: ");
    scanf(" %c", &op);
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); getchar();
    return op;
}




