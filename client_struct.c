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
    printf("\n%d %s %ld %s %d \n", cliente.cod_cliente, cliente.nome, cliente.nif,
            cliente.pais, cliente.apagado);
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

void atualizarClientes(Clientes *clientes) {
    int numero = procurarCliente(*clientes,
            obterInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));
    if (numero != -1) {
        atualizarCliente(&(*clientes).clientes[numero]);
    } else {
        puts(ERRO_CLIENTE_NAO_EXISTE);
    }
}

void atualizarCliente(Cliente *cliente) {
    lerString((*cliente).nome, MAX_NOME_CLIENTE, MSG_OBTER_NOME);
    (*cliente).nif =
            obterLong(MIN_NIF, MAX_NIF, OBTER_NIF);
    lerString((*cliente).pais, MAX_PAIS_CLIENTE, MSG_OBTER_PAIS);
}

void removerClientes(Clientes *clientes) {
    int numero = procurarCliente(*clientes,
            obterInt(MIN_NUM_CLIENTE, MAX_NUM_CLIENTE, MSG_OBTER_NUM_CLIENTE));
    if (numero != -1) {
        (*clientes).clientes[numero].apagado = true;
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