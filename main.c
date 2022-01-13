/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/**
 * @file main.c
 * @brief Doxygen
 * @return 
 */

/*
 * File:   main.c
 * Author: Marta Machado <8210403@estg.ipp.pt>
 * Author: Mara Leite <8210320@estg.ipp.pt>
 * Created on 23 de dezembro de 2021, 00:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "order_struct.h"
#include "menu.h"


#define CLIENTE 'c'
#define ADMINISTRADOR 'a'
#define SANDALIA 's'
#define BOTAS 'b'
#define SAPATOS 'sap'


/**** LER VALORES ****/
/**
 * Ciclo para pedir ao utilizador se é cliente ou administrador, e ler para usar no ciclo do while, para ter acesso a diferentes funções
 * @param função para ver qual o utilizador será utilizado
 * @return valor do utilizador(a,c)
 */
char ler_tipo_utilizador() {
    char tipo_utilizador;

    do {
        printf("Insira o tipo de utilizador ( a-administrador, c-cliente): ");
        scanf("%c", &tipo_utilizador);
    } while (tipo_utilizador != ADMINISTRADOR && tipo_utilizador != CLIENTE);

    return tipo_utilizador;
}
int main(int argc, char** argv) {
    /**
     * Declaração de variaveis usadas ao longo do main.c
     */
    int op;
    char tipo_utilizador,menu;
    
    /**
     * 
     * @param contadores dos clientes, artigos e encomendas
     */
    Clientes clientes = {.contador = 0};
    Artigos artigos = {.contador = 0};
    //fata o contador das encomendas
    
    tipo_utilizador=ler_tipo_utilizador();
    
    /**
     * 
     * @param menus apresentados ao administrador e acesso à encomenda feita pelo cliente
     * @return no menu do cliente os v alores da fatura na encomenda
     * @return no menu do adminiosrador tem acesso as funções de gestão dos artigos, clientes e encomendas
     */
    /********MENU*******/
        //CLIENTE
    if(tipo_utilizador == CLIENTE)

    {
        //nao funciona
        //inserirArtigoEncomenda(Encomenda, Cliente, Artigo, Precos );
    }
        //ADMINISTRADOR
    else if(tipo_utilizador == ADMINISTRADOR)
      {  
        Menu_administrador:
        menu_principal();
        scanf("%d",&op);
        do{
            switch(op){               
                case 1:
                    do{                        
                        sub_menu_clientes();
                        scanf("%d",&op);
                        
                        switch(op){

                            case 1:
                                printf("\n");
                                inserirClientes(&clientes);                                
                                break;

                            case 2:
                                printf("\n");
                                atualizarClientes(&clientes);
                                break;

                            case 3:
                                printf("\n");
                                listarClientes(clientes);
                                break;

                            case 4:
                                printf("\n");
                                imprimirCliente(clientes.clientes[0]);
                                break;
                                
                            case 5:
                                printf("\n Insira o código do cliente: ");
                                int cod_cliente=0;
                                scanf("%d",&cod_cliente);
                                int IDcliente = procurarCliente(clientes, cod_cliente);
                                imprimirCliente(clientes.clientes[IDcliente]);
                                break;
                            case 6:
                                printf("\n");
                                //remover nao funciona
                                //removerClientes(&clientes);                               
                                break;

                            default:
                                printf("\n");
                                printf("\nOpcão invalida.");
                        }                       
                    }while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5&& op!=6);
                    break;                   
                case 2:
                    do{                       
                        sub_menu_artigos();
                        scanf("%d",&op);                       
                        switch(op){

                                case 1:
                                    printf("\n");
                                    inserirArtigos(&artigos);
                                    break;
                                case 2:
                                    printf("\n");
                                    atualizarArtigos(&artigos);
                                    break;
                                case 3:
                                    printf("\n");
                                    listarArtigos(artigos);
                                    break;
                                case 4:
                                    printf("\n Insira o código do artigo: ");
                                    int cod_artigo=0;
                                    scanf("%d",&cod_artigo);
                                    int IDartigo = procurarArtigo(artigos, cod_artigo);
                                    imprimirArtigo(artigos.artigos[IDartigo]);
                                    break;
                                case 5:
                                    printf("\n");
                                    //remover nao funciona
                                    //removerArtigos(&artigos);
                                    break;
                                default:
                                    printf("\n");
                                    printf("\nOpcão invalida.");                                 
                            }
                        }while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5);
                break;                              
            case 3:
                do{                   
                    sub_menu_encomendas();
                    scanf("%d",&op);
                         
                        switch(op){

                            case 1:
                               // inserirArtigoEncomenda(encomenda,cliente,artigo,precos);
                               break;
                            case 2:
                                printf("\n");
                                printf("\n");
                                //listarArtigosEncomenda(artigo,encomeda);
                                break;
                            case 3:
                                printf("\n");
                                //procurarArtigoEncomenda(encomenda,artigo,tam);
                                break;
                            default:
                                printf("\n");
                                printf("\nOpcão invalida.");
                        }
                  }while(op!=1 && op!=2 && op!=3);
                  break;
            break;            
         }
         goto Menu_administrador;
       }while(op!=1 && op!=2 && op!=3); 
     }
    return (EXIT_SUCCESS);
}