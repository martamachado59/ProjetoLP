/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

/**
 * @file menu.c
 * @brief Doxygen
 * @return 
 */

#include <stdio.h>
#include <string.h>
#include "input.h"
#include "article_struct.h"


/**
 * Acesso a todos os menus utilizados no main
 * menu_principal mostra ao utilizador quais os tipos de gestões que tem acesso
 * sub_menu_artigos mostra as opções sobre a gestão dos artigos que o utilizador pode ter acesso
 * sub_menu_clientes mostra as opções sobre a gestão dos clientes que o utilizador pode ter acesso
 * sub_menu_encomendas mostra as opções sobre a gestão das encomendas que o utilizador pode ter acesso
 */
void menu_principal()
{
    int op;
    
    printf("\n Escolha uma das opções:\n"
                    " 1-Gestão dos Clientes\n"
                    " 2-Gestão dos Artigos\n"
                    " 3-Gestão dos Encomendas\n"
                    " Indique a sua opção:");
      
}

void sub_menu_artigos()
{
   printf("\n Administração dos artigos\n");
   printf("\n Escolha uma das opções:\n"
        " 1-Inserir Artigos\n"
        " 2-Atualizar Artigos\n"
        " 3-Listar Artigos\n"
        " 4-Procurar Artigos\n"
        " 5-Remover Artigos\n"
        " Indique a sua opção:");
   
}

void sub_menu_clientes()
{
    printf("\n Administração dos clientes \n");
    printf("\n Escolha uma das opções:\n"
            " 1-Inserir cliente\n"
            " 2-Atualizar cliente\n"
            " 3-Listar clientes\n"
            " 4-Imprimir Cliente\n"
            " 5-Procurar Cliente\n"
            " 6-Remover Cliente\n"
             " Indique a sua opção:");
    
}

void sub_menu_encomendas()
{
    printf("\n Administração das encomendas\n");
    printf("\n Escolha uma das opções:\n"
            " 1-Inserir encomendas\n"
            " 2-Listar Artigos\n"
            " 3-Procurar Artigos\n"
            " Indique a sua opção:");
    
}