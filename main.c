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
 * Author: Marta Machado
 * Author: Mara Leite
 * Created on 23 de dezembro de 2021, 00:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "order_struct.h"

#define CLIENTE 'c'
#define ADMINISTRADOR 'a'
#define SANDALIA 's'
#define BOTAS 'b'
#define SAPATOS 'sap'


/**** LER VALORES ****/

char ler_tipo_utilizador() {
    char tipo_utilizador;

    do {
        printf("Insira o tipo de utilizador ( a-administrador, c-cliente): ");
        scanf("%c", &tipo_utilizador);
    } while (tipo_utilizador != ADMINISTRADOR && tipo_utilizador != CLIENTE);

    return tipo_utilizador;
}
/*
int ler_nif() {
    int nif;

    do {
        printf("Insira o seu nif: \n");
        scanf(" %d", &nif);
    } while (nif <= 99999999 || nif >= 999999999);

    return nif;
}

char ler_tipo_calcado() {
    char calcado;

    do {
        printf("Insira o tipo de calçado (s-sandalia,b-botas,sap-sapatos): ");
        scanf(" %c", &calcado);
    } while (calcado != SANDALIA && calcado != BOTAS && calcado != SAPATOS);

    return calcado;
}

int ler_quantidade() {
    int num;

    do {
        printf("Insira a quantidade de pares de sapatos: ");
        scanf(" %d", &num);
    } while (num < 0 || num >= 1000);

    return num;
}

float ler_mao_obra() {
    float preco_mao_obra;
    do {
        printf("Insira o preço de mão obra: ");
        scanf("%f", &preco_mao_obra);
    } while (preco_mao_obra <= 0);

    return preco_mao_obra;
}

float ler_margem() {
    float valor_margem;

    do {
        printf("Insira o valor da margem de lucro: ");
        scanf("%f", &valor_margem);
    } while (valor_margem <= 0.0 || valor_margem >= 1.0);

    return valor_margem;
}

float ler_custo_restante() {
    float valor_custo_restante;

    do {
        printf("Insira o valor do custo restante: ");
        scanf("%f", &valor_custo_restante);
    } while (valor_custo_restante <= 0);

    return valor_custo_restante;
}

/******CALCULOS******/
<<<<<<< Updated upstream

float cal_mao_obra(int quantidade,char calcado){
    if(calcado == SANDALIA)
    {
        int mao_obra=4;
        return quantidade * mao_obra;
    }
    else if(calcado == BOTAS)
    {
        int mao_obra=6;
        return quantidade * mao_obra;
    }
    else if(calcado == SAPATOS)
    {
        int mao_obra=5;
=======
/*
float cal_mao_obra(int quantidade, char calcado) {
    if (calcado == SANDALIA) {
        int mao_obra = 4;
        return quantidade * mao_obra;
    } else if (calcado == BOTAS) {
        int mao_obra = 6;
        return quantidade * mao_obra;
    } else if (calcado == SAPATOS) {
        int mao_obra = 5;
>>>>>>> Stashed changes
        return quantidade * mao_obra;
    }
}
 */

int main(int argc, char** argv) {
    int op;
    char tipo_utilizador;
    
    tipo_utilizador=ler_tipo_utilizador();
    
    /********MENU*******/
        //CLIENTE
    if(tipo_utilizador == CLIENTE)
<<<<<<< Updated upstream
    {
        //TENTAR POR AUTOMATICO O CODIGO
        printf("Insira o seu código cliente: \n");
        scanf(" %d",&cod_cliente);
        nif=ler_nif(); 
        printf("Insira o seu nome: \n");
        scanf(" %s",&nome);  
        printf("Insira o seu pais: \n");
        scanf(" %s",&pais);
        calcado=ler_tipo_calcado();
        quantidade=ler_quantidade();
        mao_obra=cal_mao_obra(quantidade,calcado);
=======
      {
>>>>>>> Stashed changes
        
      }
        //ADMINISTRADOR
    else if(tipo_utilizador == ADMINISTRADOR)
      {
        /****ADM-CLIENTES****/
        printf("Escolha uma das opções:\n"
                "1-Inserir cliente\n"
                "2-Atualizar cliente\n"
                "3-Listar clientes\n"
                "4-Imprimir Cliente\n"
                "5-Remover Cliente\n"
                "Indique a sua opção:");
        scanf("%d",&op);
         Clientes clientes = {.contador = 0};
        switch(op){
           
            case 0:
            break;
            
            case 1:
                inserirClientes(&clientes);
                break;
            
            case 2:
                atualizarClientes(&clientes);
                break;
            
            case 3:
                listarClientes(clientes);
                break;
            
            case 4:
                imprimirCliente(clientes.clientes[0]);
                break;
            
            case 5:
                removerClientes(&clientes);
                break;
            
            default:
            printf("\nOpcão invalida.");
      }
       
        /****ADM-ARTIGOS****/
     //   Artigos artigos = {.contador = 0};
     //   inserirArtigos(&artigos);
     //   imprimirArtigo(artigos.artigos[0]);
        
        /****ADM-PREÇOS****/
     //   Precos precos = {.contador = 0};
     //   inserirPrecos(&precos);
     //   imprimirPreco(precos.precos[0]);
        
        /****ADM-ENCOMENDAS****/
     //   Encomenda encomenda = {.contador = 0, .precoEncomenda = 0};
     //   inserirArtigoEncomenda(&encomenda, &clientes.clientes[0], &artigos.artigos[0], &precos);
     //   listarArtigosEncomenda(&encomenda);
      }
    return (EXIT_SUCCESS);
}