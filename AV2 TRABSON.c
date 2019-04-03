


#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

struct arv {
  int info;
  struct arv*pai;
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;



Arv* arv_criavazia (void){
     return NULL;
}



int arv_vazia (Arv* a){
    return a==NULL;
}



Arv* arv_libera (Arv* a){
     if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
     }
     return NULL;
}

 Arv* abb_insere (Arv* r, int val) /*Vai inserir, iterativamente, valores na árvore*/
{
/*	if(r==NULL)//FUNCIONANDO!!!
	{
		r=(Arv*)malloc(sizeof(Arv));
		r->info=val;
		r->pai=NULL;
		r->esq=NULL;
		r->dir=NULL;
		return r;
		
	}
		else if(val<r->info)r->esq=abb_insere(r->esq,val);
		
		else if(val>=r->info)r->dir=abb_insere(r->dir,val);
return r;*/
Arv*novo=(Arv*)malloc(sizeof(Arv));
novo->info=val;
novo->pai=NULL;
novo->esq=NULL;
novo->dir=NULL;
if(r==NULL)return novo;
else{
	
	Arv*p=r;
	Arv*ant=NULL;
	while(p!=NULL)
	{	ant=p;
		if(val<p->info)p=p->esq;
		else p=p->dir;
		
	}
	if(val < ant->info)
	{
		ant->esq=novo;
		novo->pai=ant;
	}else
		{
			ant->dir=novo;
			novo->pai=ant;
		}
		return r;
	}
}

void imprime_crescente(Arv *a){/* Vai imprimir, recursivamente, todos os elementos em ordem crescente */
	if (!arv_vazia(a)){
	imprime_crescente(a->esq);
	printf("%d ",a->info);
	imprime_crescente(a->dir);
							}
}

Arv* abb_busca (Arv* r, int v)/*Vai buscar, recursivamente, um valor na árvore e retornar um ponteiro para o no correspondente*/
{
if (r == NULL) return NULL;
else if (r->info > v) return abb_busca (r->esq, v);
else if (r->info < v) return abb_busca (r->dir, v);
else return r;
}
 
void showmenor(Arv* a, int x){  /*imprime, recursivamente, todos os valores nos nós da árvore que sejam menores que x, em ordem
crescente.*/
if (a==NULL)return;
showmenor(a->esq,x);
if (a->info<x){
printf ("%d ", a->info);
showmenor(a->dir,x);  
}
				} 
Arv* menor (Arv* a){/* Encontra, iterativamente, um ponteiro para o menor valor da árvore*/
Arv* aux=a;
while(aux->esq!=NULL){
aux=aux->esq;
}
return aux;
}

Arv* busca_no (Arv* a){/* Encontra, iterativamente, o valor que antecede a raiz*/
	if(a==NULL)return NULL;
	
	if(a->esq==NULL)return NULL;
	
	Arv* aux=a->esq;
	
	while(aux->dir!=NULL)
	aux=aux->dir;
	
	return aux;
}

Arv* raiz(Arv* k){/* a partir do ponteiro para o nó encontrado anteriormente, encontra um ponteiro para a raiz da árvore */
if(k->pai==NULL)return k;
	else{
		while(k->pai!=NULL)k=k->pai;
		return k;
 		}
}

 
int main(){
    setlocale(LC_ALL,"portuguese");
    
    Arv*a, *b;
    a = arv_criavazia();

    /*Vai inserir, iterativamente, valores na árvore*/
    a = abb_insere (a,6);
    a = abb_insere (a,2);
    a = abb_insere (a,8);
    a = abb_insere (a,1);
    a = abb_insere (a,4);
    a = abb_insere (a,3);
    
    
    /* Vai imprimir, recursivamente, todos os elementos em ordem crescente */
    printf("Ordem crescente: ");
    imprime_crescente(a); 
    printf("\n\n");
    /*Vai buscar, recursivamente, um valor na árvore e retornar um ponteiro para o no correspondente*/
    Arv*k = abb_busca(a,1);
    if (k!=NULL) printf("Informação do nó encontrado anteriormente = %d", k->info);
    printf("\n\n");
   
    /*imprime, recursivamente, todos os valores nos nós da árvore que sejam menores que x, em ordem
crescente.*/
    printf("Menores que 5: ");
    showmenor(a,5);
    printf("\n\n");
    
    /* Encontra, iterativamente, um ponteiro para o menor valor da árvore*/
    k = menor(a);
    if (k!=NULL) printf("A menor informação = %d\n\n", k->info);

    /* Encontra, iterativamente, o valor que antecede a raiz*/
    k = busca_no(a);
    if (k!=NULL) printf("Valor que antecede a raíz = %d\n\n", k->info);
	else printf("Não há valor!\n\n");
   
   /* a partir do ponteiro para o nó encontrado anteriormente, encontra um ponteiro para a raiz da árvore */
    b = raiz(k);
    printf("A informação da raíz da árvore =  %d\n\n", b->info);
    
    arv_libera(a);
    system("pause");
    return 0;
}//Sucesso

