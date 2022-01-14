/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   Encomendas.h
 * Author: marta
 *
 * Created on 14 de janeiro de 2022, 01:38
 */

#ifndef ENCOMENDAS_H
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include "article_struct.h"
#include "client_struct.h"

#define ENCOMENDAS_H


typedef struct {
    Cliente cliente;
    Artigo artigo;
    int tamanho;
    double precoEncomenda;
    //int contador;
} Encomenda;

typedef struct {
    int contador;
    Encomenda Encomendas[100];
} Encomendas;

void CriarEncomenda(Encomendas *encomendas, Cliente cliente,Artigo artigo);
void listarEncomenda(Encomenda encomenda, int id);
void listarEncomendas(Encomendas encomendas);

void GuardarEncomendasFicheiro(Encomendas encomendas);
void LerEncomendasFicheiro(Encomendas *encomendas);

#endif /* ENCOMENDAS_H */