// Genericas

struct nodo //arbol
{
  //Cambiar info;
	int info;
	struct nodo *izq, *der;
};

typedef struct nodo *ABB;

ABB crearNodo(int info)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->info= info;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, int info)
{
	if(arbol==NULL)            arbol = crearNodo(info);
	else if(info < arbol->info)    insertar(arbol->izq, info);
	else if(info >= arbol->info)   insertar(arbol->der, info);
}


void enOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->info;
		enOrden(arbol->der);
	}
}

// Particulares:

int recorrer(ABB arbol,int &count)
{
	int X=0;
	if(arbol!=NULL)
	{
		recorrer(arbol->izq,count);
		if (arbol->info>X)
		{
			++count;
			X=arbol->info;
		}
		recorrer(arbol->der,count);
	}
	
	return count;
}

bool incluido(ABB &arbol, int A, int B)
{
	if(A<=arbol->min && B>=arbol->max)
	{
		arbol->min=A;
		arbol->max=B;
		return true;
	}
	return false;
}
