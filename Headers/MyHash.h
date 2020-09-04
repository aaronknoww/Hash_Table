#pragma once

template<typename TD>
class Myhash
{
public:
	Myhash();
	bool insertar(TD);
	void imprimirTabla();// imprime todos los elementos de la tabla
	bool buscarDato(TD);
	bool eliminar(TD);
	~Myhash();

private:

	TD* p_tabla;
	int cont_e;// Cuenta cada elemento que se inserta en la tabla.
	int maximo;// Inicializa el arreglo de la tabla hash con la cantidad indicada.
	int factor_carga;//	Indica el porcentaje maximo de uso de la tabla Hash.



	/////--------- FUNCIONES AUXILIARES PRIVADS DE LA CLASE NO ---------------//

	int _funcionHash(TD&);// Regresa el indice en el que se debe de insetar el dato.
	int _doubleHash(TD&, int&);// Regresa el indice utilizando otra funcion.
	int _dependienteD(TD&);// Regresa un entero impar para ayudar a calcular donde introducir el elmento. 
	int _calculoDeCarga();// Regresa el factor de carga actual de la tabla Hash.
	bool _insertarAux(TD&);
	bool _rehashing();// Aumenta el tamaño del arreglo en la siguiente potencia de 2 ademas de reicertar todos los elementos.
	bool _rehashingDown();// Libera memoria cuando se han eliminado muchos elementos.
	int _buscarAux(TD&);// Regresa el indice donde se encuentra el dato buscado o un -1 si no se encuentra.
	
};


// ----------------------N O T A S -------------------------------------\\
// La función que se utilizará para el manejo de colisiones será dependiente de la clave. 
// Para garantizar una distribución correcta, el tamanio de la tabla debe de ser una potencia de 2
// D siempre debe de ser un número impar d= k div max  int d=k/max.
// h=(k+d*i)%tamanio;