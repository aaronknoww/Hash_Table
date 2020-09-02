#pragma once

template<typename TD>
class Myhash
{
public:
	Myhash();
	bool insertar(TD);
	//~Myhash();

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
	bool _rehashing();// Aumenta el tama�o del arreglo en la siguiente potencia de 2 ademas de reicertar todos los elementos.
};

// La funci�n que se utilizar� para el manejo de colisiones ser� dependiente de la clave. 
// Para garantizar una distribuci�n correcta, el tamanio de la tabla debe de ser una potencia de 2
// D siempre debe de ser un n�mero impar d= k div max  int d=k/max.
// h=(k+d*i)%tamanio;