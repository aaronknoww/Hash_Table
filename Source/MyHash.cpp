#include"..\Headers\Precom.h"
#include"..\Headers\MyHash.h"

template<typename TD>
Myhash<TD>::Myhash()
{
	cont_e = 0;
	maximo = 8;
	factor_carga = 65;
	p_tabla = new TD[maximo];// Se inicializa el la tabla.

	for (int i = 0; i < maximo; i++)
		p_tabla[i] = -1;
	return;
}

template<typename TD>
bool Myhash<TD>::insertar(TD dato)
{
	if (factor_carga> _calculoDeCarga())
	{
		// Significa que todavia se puede insertar
		return _insertarAux(dato);

	}
	else
	{
		// Es necesario hacer rehashing.
		if (_rehashing())
			return insertar(dato);
		else
			return false;// no se pudo hacer rehashing por eso es falso.		
	}
	return false;
}

template<typename TD>
void Myhash<TD>::imprimirTabla()
{
	for (int i = 0; i < maximo; i++)
	{
		std::cout << " " << p_tabla[i];
	}
	return;
}

template<typename TD>
bool Myhash<TD>::buscarDato(TD dato)
{
	if (_buscarAux(dato)>=0)
		return true;
	else
		return false;
}


//-------------------- FUNCIONES AUXILIARES PRIVADAS DE LA CLASE ------------------------------//

template<typename TD>
int Myhash<TD>::_funcionHash(TD& dato)
{
	// dato---> Es el dato que quiere introducir el usuario a la tabla hash y que se va a convertir en un indice. 
	
	return dato%maximo;
}

template<typename TD>
int Myhash<TD>::_doubleHash(TD& dato, int& iterador)
{
	//dato--> Es el que se está intentando insertar.
	//iterador--> Debe de ser un número que debe de estar cambiando para funcionar 

	int d = _dependienteD(dato);
	return (dato + d * iterador) % maximo;
}

template<typename TD>
int Myhash<TD>::_dependienteD(TD& dato)
{
	int d = 0;
	d = dato / 2;
	if (d & 1)
		return d; //d es impar
	//pivote = static_cast<int>(ceil(grados / 2) - 1.0); // El grado del arbol es impar
	else
		return d + 1; // Como d es par se le agrega 1 para que se impar.
	
}

template<typename TD>
int Myhash<TD>::_calculoDeCarga()
{
	return (cont_e*100)/maximo;
}

template<typename TD>
bool Myhash<TD>::_insertarAux(TD& dato)
{
	int index = _funcionHash(dato);

	if (p_tabla[index] == -1)
	{
		// Encuentró una posición vacía en el arreglo.

		p_tabla[index] = dato; // como se encontró -1 significa que esa posision esta vacía.
		cont_e++;
		return true;
	}
	else
	{
		// No está vacía esa posición del arrglo.

		for (int i = 1; i <= maximo; i++)
		{
			index = _doubleHash(dato, i);// Calcula el lugar donde se debe de insertar
			
			(index < maximo) ? index : index-=maximo;// Evita que se desborde el indice, regresendolo a un valor valido
			
			if (p_tabla[index]==-1)
			{
				p_tabla[index] = dato; // como se encontró -1 significa que esa posision esta vacía.
				cont_e++;
				return true;
			}

		}
		return false; // Quiere decir que no habia donde insertar, solo en el caso de que el usurio utilice un load factor de 100.
		
	}

	return false;
}

template<typename TD>
bool Myhash<TD>::_rehashing()
{
	TD* auxiliar = new TD[maximo]; //Crea un arreglo del doble que el anterior.
	int cont_aux = cont_e;

	for (int i = 0; i < maximo; i++)
		auxiliar[i] = p_tabla[i];// Copia todo el arreglo para poder agrandar el arreglo de la clase. 
	
	delete[]p_tabla;// se libera la mememoria
	
	p_tabla = new TD[maximo*2];// Se reserva memoria para el nuevo arreglo.
	for (int i = 0; i < maximo*2; i++)
		p_tabla[i]=-1; //Inicializa todo el arreglo.
	
	cont_e = 0;//Como es una variable que utiliza _insertarAux, se inicializa en cero para evitar error.
	for (int i = 0; i < maximo; i++)
	{
		if (auxiliar[i] != -1)
			_insertarAux(auxiliar[i]);
	}
	maximo *= 2;
	delete[]auxiliar;
	auxiliar = nullptr;
	return true;

	//!!!!!!!!!falta hacer codigo en el caso de que no haya suficiente memoria. una excepcion o algo.

}

template<typename TD>
int Myhash<TD>::_buscarAux(TD& dato)
{
	
	for (int i = 0; i < maximo; i++)
	{
		int index = _doubleHash(dato, i);
		(index < maximo) ? index : index -= maximo;//Si se pasa del numero maximo del arrglo, lo regresa al incio del mismo.
		if (dato == p_tabla[index])//Verifica si lo que está en la tabla en la posisón del indice es igual al dato buscado.
			return index;
	}
	return -101;// No se encontro el elmento en la tabla, por eso se regresa un valor negativo
}


