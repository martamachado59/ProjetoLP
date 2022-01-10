/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   clientStruct.h
 * Author: Marta
 * Author: Mara
 * Created on 2 de janeiro de 2022, 16:25
 */

#include <stdbool.h>

#define CLIENTSTRUCT_H

#define MAX_CLIENTES 50
#define ERRO_CLIENTE_NAO_EXISTE "O cliente não existe na lista."
#define ERRO_LISTA_VAZIA "A lista de cliente está vazia."
#define ERRO_LISTA_CHEIA "A lista de cliente está cheia."
#define ERRO_CLIENTE_EXISTE "O número de cliente já se encontra atribuído."

#define MAX_NOME_CLIENTE 50
#define MSG_OBTER_NOME "Insira o nome do cliente: "

#define MIN_NIF 000000001
#define MAX_NIF 999999999
#define OBTER_NIF "Insira o NIF: "

#define MAX_PAIS_CLIENTE 50
#define MSG_OBTER_PAIS "Insira o nome do pais: "

#define MIN_NUM_CLIENTE 0
#define MAX_NUM_CLIENTE 1000
#define MSG_OBTER_NUM_CLIENTE "Insira um número de cliente [0-1000]: "

//struct do cliente
typedef struct {
    int cod_cliente;
    char nome[MAX_NOME_CLIENTE];
    long nif;
    char pais[MAX_PAIS_CLIENTE];
    bool apagado;
} Cliente;

typedef struct {
    int contador;
    Cliente clientes[MAX_CLIENTES];
} Clientes;

//funções dos clientes

int inserirClientes(Clientes *clientes);
int procurarCliente(Clientes cliente, int cod_cliente);
void atualizarClientes(Clientes *clientes);
void removerClientes(Clientes *clientes);
void listarClientes(Clientes clientes);