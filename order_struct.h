/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/**
 * @file order_struct.h
 * @brief Doxygen
 * @return 
 */

/* 
 * File:   order_struct.h
 * Author: Marta
 * Author: Mara
 * 
 * Created on 9 de janeiro de 2022, 21:56
 */

#ifndef ARTICLE_STRUCT_H

#define MAX_ARTIGOS_ENCOMENDA 50
#include "client_struct.h"
#include "article_struct.h"

#define ARTICLE_STRUCT_H
/**
 *Cria um struct para armazenar todas as encomendas
 */

typedef struct {
    Cliente cliente;
    Artigo artigos[MAX_ARTIGOS_ENCOMENDA];
    int tamanhos[MAX_ARTIGOS_ENCOMENDA];
    double precoEncomenda;
    int contador;
} Encomenda;

typedef struct {
    int contador;
    Encomenda Encomendas[100];
} Encomendas;

/**
 * Assinaturas das funções das encomendas
 * @param encomenda
 * @param cliente
 * @param artigo
 * @param precos
 * @return valores usados nas encomendas
 */

//int inserirArtigoEncomenda(Encomendas *encomenda, Cliente cliente, Artigo artigo /*,Precos *precos*/);
int procurarArtigoEncomenda(Encomenda *encomenda, Artigo *artigo, int tam);
void listarArtigosEncomenda(Encomenda *encomenda);

#endif