//============================================================================
// Name        : repo_parcial1.cpp
// Author      : Yazmín Sierra
//============================================================================

#include <iostream>
using namespace std;

struct Nodo{
int dato;
Nodo*siguiente;
}
void insertarLista(Nodo*&, int);

int main(){
Nodo *lista =NULL;

return 0;
}

void insertarLista(Nodo*&lista,int n ){
Nodo*nuevo_nodo=new Nodo();
nuevo_nodo->dato=n;
Nodo *a1= lista;
Nodo *a2;

while ((a1!=NULL) && (a1->dato< n)){
	a2=a1;
	a1=a1->siguiente;
	}
if (lista == a1){
lista =nuevo_nodo;
}
else{
	a2 -> siguiente=nuevo_nodo;
}
nuevo_nodo->siguiente=a1;

//LISTA DOBLEMENTE ENLAZADA

typedef struct celda {
   tElemento elemento;
   struct celda *siguiente,*anterior;
} tipocelda;

typedef tipocelda *tPosicion;
typedef tipocelda *tLista;


static void error(char *cad)
{
   fprintf(stderr, "ERROR: %s\n", cad);
   exit(1);
}

tLista crear()
{
   tLista l;

   l = (tLista)malloc(sizeof(tipocelda));
   if (l == NULL)
	error("Memoria insuficiente.");
   l->siguiente = l->anterior = l;
   return l;
}

void Destruir (tLista l)
{
   tPosicion p;


   for (p=l, l->anterior->siguiente=NULL; l!=NULL; p=l) {
	l = l->siguiente;
	free(p);
   }
}

tPosicion Primero (tLista l)
{
   return l->siguiente;
}

tPosicion Fin (tLista l)
{

   return l;
}

void Insertar (tElemento x, tPosicion p, tLista l)
{
   tPosicion nuevo;


   nuevo = (tPosicion)malloc(sizeof(tipocelda));
   if (nuevo == NULL)
	Error("Memoria insuficiente.");
   nuevo->elemento = x;
   nuevo->siguiente = p;
   nuevo->anterior = p->anterior;
   p->anterior->siguiente = nuevo;
   p->anterior = nuevo;
}
void Borrar (tPosicion *p, tLista l)
{
   tPosicion q;

   if (*p == l){
	Error("Posicion fin(l)");
   }
   q = (*p)->siguiente;
   (*p)->anterior->siguiente = q;
   q->anterior = (*p)->anterior;
   free(*p);
   (*p) = q;
}

tElemento elemento(tPosicion p, tLista l)
{
   if (p == l){
	Error("Posicion fin(l)");
   }
   return p->elemento;
}

tPosicion siguiente (tPosicion p, tLista l)
{

   if (p == l){
	Error("Posicion fin(l)");
   }
   return p->siguiente;
}

tPosicion anterior( tPosicion p, tLista l)
{

   if (p == l->siguiente){
	Error("Posicion primero(l)");
   }
   return p->anterior;
}

tPosicion posicion (tElemento x, tLista l)
{
   tPosicion p;
   int encontrado;

   p = primero(l);
   encontrado = 0;
   while ((p != fin(l)) && (!encontrado))
	if (p->elemento == x)
		encontrado = 1;
	else
		p = p->siguiente;
   return p;
}



void Reemplazar(pila P,int nuevo,int viejo)
{
  pila Q;
  int aux;
  Q=CrearPila(sizeof(int));


  while (!VaciaPila(P)){
    Tope(&aux,P);
    if (aux==viejo)
       Push(&nuevo,Q);
    else Push(&aux,Q);
    Pop(P);
  }
  while(!VaciaPila(Q)){
    Tope(&aux,Q);
    Pop(Q);
    Push(&aux,P);
  }



  DestruirPila(Q);

}




