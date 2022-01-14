/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

/**
 * @file client_struct.c
 * @brief Doxygen
 * @return 
 */

#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include "input.h"
#include "client_struct.h"

//funções dos clientes
/**
 * inserirClientes é a função que cria os clientes, pedindo ao utilizador os dados necessários
 * atualizarCliente é a função que atualiza os dados de um determinado cliente
 * procurarClientes é a função que procura os clientes através do código cliente
 * listarClientes é a função que lista todos clientes inseridos
 * imprimirCliente é a função que mostra todos os dados do cliente com um respetivo código
 * removerClientes é a função que apaga os dados do cliente escolhido
 * @param funções usadas para a gestão dos clientes
 */
void imprimirCliente(Cliente cliente) {
    if( cliente.apagado==0)
    {
        printf("\n%d %s %ld %s \n", cliente.cod_cliente, cliente.nome, cliente.nif,
            cliente.pais);
    }
}

int procurarCliente(Clientes cliente, int cod_cliente) {
    int i;
    for (i = 0; i < cliente.contador; i++) {
        if (cliente.clientes[i].cod_cliente == cod_cliente) {
            return i;
        }
    }
    return -1;
}

int inserirClientes(Clientes *clientes) {
    int cod_cliente = obterInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE);
    if (procurarCliente(*clientes, cod_cliente) == -1) {
        clientes->clientes[clientes->contador].cod_cliente = cod_cliente;
        lerString(clientes->clientes[clientes->contador].nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);
        clientes->clientes[clientes->contador].nif =
                obterLong(MIN_NIF, MAX_NIF, OBTER_NIF);
        lerString(clientes->clientes[clientes->contador].pais, MAX_PAIS_CLIENTE, MSG_OBTER_PAIS);
        clientes->clientes[clientes->contador].apagado = false;
        return clientes->contador++;
    }
    return -1;
}
void atualizarCliente(Cliente *cliente) {
    lerString((*cliente).nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);
    (*cliente).nif =
            obterLong(MIN_NIF, MAX_NIF, OBTER_NIF);
    lerString((*cliente).pais, MAX_PAIS_CLIENTE, MSG_OBTER_PAIS);
}
void atualizarClientes(Clientes *clientes){
    int numero = procurarCliente(*clientes,
            obterInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));
    if (numero != -1) {
        atualizarCliente(&(*clientes).clientes[numero]);
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTE);
    }
}



void removerClientes(Clientes *clientes) {
    int numero = procurarCliente(*clientes,
            obterInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));
    if (numero != -1) {
        (*clientes).clientes[numero].apagado = true;
        printf("O cliente foi apagado!");
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTE);
    }
}

//mostrar clientes

void listarClientes(Clientes clientes) {
    if (clientes.contador > 0) {
        int i;
        for (i = 0; i < clientes.contador; i++) {
            imprimirCliente(clientes.clientes[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void GuardarClientesFicheiro(Clientes clientes){
    FILE *fp = fopen("Clientes.txt", "w");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro");
    }
    if (clientes.contador > 0) {
        int i;
        for (i = 0; i < clientes.contador; i++) {
            fprintf(fp,"\n%d-%s-%d-%s-%d-\n", clientes.clientes[i].cod_cliente, clientes.clientes[i].nome, clientes.clientes[i].nif,
            clientes.clientes[i].pais,clientes.clientes[i].apagado);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
    fclose(fp);
}
void LerClientesFicheiro(Clientes *clientes){
    FILE* fp = fopen("Clientes.txt", "r");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro");
    }
    char linha[500] = "";
    int linhaN = 1;
    while(fgets(linha, sizeof(linha),fp)){
    	if(linhaN % 2 == 0){
    		char delim[] = "-";
			char *ptr = strtok(linha, delim);
			int dado = 0;
			while(ptr != NULL)
			{
				if(dado==0){
					clientes->clientes[clientes->contador].cod_cliente = atoi(ptr);
				}
				if(dado == 1){
					strcpy(clientes->clientes[clientes->contador].nome, ptr);
				}
				if(dado == 2)
				{
					clientes->clientes[clientes->contador].nif = atoi(ptr);
				}
				if(dado == 3){
					strcpy(clientes->clientes[clientes->contador].pais,ptr);
				}
				if(dado == 4){
					clientes->clientes[clientes->contador].apagado = atoi(ptr);
				}
				dado++;
				ptr = strtok(NULL, delim);
			}
			clientes->contador++;	
					
		}
		
		linhaN++;
	}
    
    /*
    clientes->clientes[clientes->contador].cod_cliente = cod_cliente;
    lerString(clientes->clientes[clientes->contador].nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);
    clientes->clientes[clientes->contador].nif =
            obterLong(MIN_NIF, MAX_NIF, OBTER_NIF);
    lerString(clientes->clientes[clientes->contador].pais, MAX_PAIS_CLIENTE, MSG_OBTER_PAIS);
    clientes->clientes[clientes->contador].apagado = false;*/
}