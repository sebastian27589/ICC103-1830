void insertarElemento(Cola* cola, int elemento) 
{
    if (colaLlena(cola)) 
    {
        printf("Error: la cola está llena.\n");
        return;
    }

    cola->cola = (cola->cola + 1) % 100;
    cola->arr[cola->cola] = elemento;
    cola->cont++;
}

void eliminarElemento(Cola* cola) 
{
    if (colaVacia(cola)) 
    {
        printf("Error: la cola está vacía.\n");
        return;
    }

    cola->frente = (cola->frente + 1) % 100;
    cola->cont--;
}