/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

/**
 * @file order.c
 * @brief Doxygen
 * @return 
 */

#include <stdio.h>
#include <stdbool.h>
#include "input.h"
#include "order_struct.h"

/**
 * inseirArtigoEncomenda é a função que mostra todos os parametros necessários para fazer uma encomenda
 * procurarArtigoEncemenda é a função que procura nas encomendas os artigos
 * listarArtigoEncomenda é a função que lista todas as encomendas feitas
 * @param encomenda tem acesso aos valores inseridos nos artigos, clientes, preços
 */
/*int inserirArtigoEncomenda(Encomendas *encomenda, Cliente *cliente, Artigo *artigo/*, Precos *precos){
    if(cliente->apagado){
        return -1;
    }
    
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Insira o tamanho do produto entre %d e %d : ", artigo->tam_min, artigo->tam_max);
    int tam = obterInt(artigo->tam_min, artigo->tam_max, buffer);
    
    //int preco = procurarPreco(*precos, artigo->tipo_artigo, tam);
    
    if (procurarArtigoEncomenda(encomenda, artigo, tam) == -1 /*&& preco != -1) {
        encomenda->Encomendas[encomenda->contador].cliente = *cliente;
        encomenda->Encomendas[encomenda->contador].artigos = *artigo;
        encomenda->Encomendas[encomenda->contador].tamanhos = tam;
        encomenda->Encomendas[encomenda->contador].precoEncomenda = 1;//((precos->precos[preco].precoFixo * precos->precos[preco].precoTam) + precos->precos[preco].precoObra) * ( 1 + precos->precos[preco].margem);
        return encomenda->contador++;
    }
    
    return -1;
}*/
int procurarArtigoEncomenda(Encomenda *encomenda, Artigo *artigo, int tam){
    int i;
    for (i = 0; i < encomenda->contador; i++) {
        if (encomenda->artigos[i].cod_artigo == artigo->cod_artigo) {
            if(encomenda->tamanhos[i] == tam) {
                return i;
            }
            break;
        }
    }
    return -1;
}
//mostrar as encomendas

void listarArtigosEncomenda(Encomenda *encomenda){
    printf("\n%s %lf\n", 
            encomenda->cliente.nome, 
            encomenda->precoEncomenda);
//    if (encomenda.contador > 0) {
//        int i;
//        for (i = 0; i < encomenda.contador; i++) {
//            imprimirCliente(encomenda.clientes[i]);
//        }
//    } else {
//        puts(ERRO_LISTA_VAZIA);
//    }
}