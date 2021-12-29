/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: marta
 *
 * Created on 23 de dezembro de 2021, 00:20
 */

#include <stdio.h>
#include <stdlib.h>
#define CLIENTE 'c'
#define ADMINISTRADOR 'a'
#define SANDALIA 's'
#define BOTAS 'b'
#define SAPATOS 'sap'


/**** LER VALORES ****/
char ler_tipo_utilizador(){
    char tipo_utilizador;
    
    do{
        printf(" Insira o tipo de utilizador ( a-administrador, c-cliente): ");
        scanf("%c", &tipo_utilizador);
    }while (tipo_utilizador != ADMINISTRADOR && tipo_utilizador != CLIENTE);
    
    return tipo_utilizador;
}

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
        scanf(" %c",&calcado);   
    } while (calcado != SANDALIA && calcado != BOTAS && calcado != SAPATOS);
    
    return calcado;
}
int ler_quantidade(){
    int num;
    
    do{
       printf("Insira a quantidade de pares de sapatos: ");
        scanf(" %d",&num); 
    }while (num < 0 || num >= 1000);
    
    return num;
}

float ler_mao_obra(){
    float preco_mao_obra;   
    do {
        printf ("Insira o preço de mão obra: ");
        scanf ("%f", &preco_mao_obra);
    } while (preco_mao_obra <=0);
    
    return preco_mao_obra;
}

float ler_margem (){
    float valor_margem;
    
    do{
        printf("Insira o valor da margem de lucro: ");
        scanf("%f", &valor_margem);
    } while (valor_margem <=0.0 || valor_margem >=1.0 );
    
    return valor_margem;
}

float ler_custo_restante (){
    float valor_custo_restante;
    
    do{
        printf("Insira o valor do custo restante: ");
        scanf("%f", &valor_custo_restante);
    }while (valor_custo_restante <=0);
    
    return valor_custo_restante;
}

/******CALCULOS******/

float cal_mao_obra(int quantidade, float mao_obra,char calcado){
    if(calcado == SANDALIA)
    {
        mao_obra==4;
        return quantidade * mao_obra;
    }
    else if(calcado == BOTAS)
    {
        mao_obra==6;
        return quantidade * mao_obra;
    }
    else if(calcado == SAPATOS)
    {
        mao_obra==5;
        return quantidade * mao_obra;
    }   
}

int main(int argc, char** argv) {
    /*float tamanho_sapatos[15]={0.65,0.7,0.75,0.8,0.85,0.9,0.95,1,1.05,1.10,1.15,1.20,1.25,1.30,1.35};
    float tamanho_botas[15]={0.7,0.75,0.8,0.85,0.9,0.95,1,1.05,1.10,1.15,1.20,1.25,1.30,1.35,1.40};
    float tamanho_sandalias[15]={0.8,0.825,0.850,0.875,0.9,0.925,0.950,0.975,1,1.025,1.050,1.075,1.1,1.125,1.150};*/
    
    float mao_obra,margem,restante;
    int nif,quantidade,cod_cliente;
    char nome[60], pais[40], tipo_utilizador,calcado;
    
    tipo_utilizador=ler_tipo_utilizador();
    
    //CLIENTE
    if(tipo_utilizador == CLIENTE)
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
        mao_obra='cal_mao_obra()';
        
        //Mostrar Valores ao cliente
        printf("\n O seu código cliente é:%d",cod_cliente);
        printf("\n O seu nif é:%d",nif);
        printf("\n O cliente:%s",nome);
        printf("\n País:%s",pais);
        printf("\n O número de pares é:%d",quantidade);
        printf("\n O calçado escolhido é:%c",calcado);
        printf("\n O valor de mão de obra é:%.2f",mao_obra);
    }   
 /**************************************/   
    //ADMINISTRADOR
    
    //Mudar preços
    if(tipo_utilizador == ADMINISTRADOR)
    {
        mao_obra=ler_mao_obra();
        margem=ler_margem();
        restante=ler_custo_restante();
    }
    return (EXIT_SUCCESS);
}

