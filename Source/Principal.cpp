#include "../Headers/Precom.h"// precompiledheader
#include "..\Headers\MyHash.h"
#include "..\Source\MyHash.cpp"
//By Aaron Knoww

using namespace std;

int main()
{
	Myhash<int> tabla;

	tabla.insertar(135); tabla.insertar(756); tabla.insertar(45); tabla.insertar(24); tabla.insertar(10);
	tabla.insertar(1);
	tabla.imprimirTabla();
	cout << "\n\n" << endl;
	tabla.insertar(13);	tabla.insertar(12);	tabla.insertar(16);	tabla.insertar(3);	tabla.insertar(31);
	tabla.insertar(23);	tabla.insertar(32);	tabla.insertar(46);	tabla.insertar(53);	tabla.insertar(61);
	tabla.imprimirTabla();
	
	tabla.eliminar(135);tabla.eliminar(756);tabla.eliminar(61);tabla.eliminar(53);tabla.eliminar(13);
	tabla.eliminar(45);tabla.eliminar(24);tabla.eliminar(12);tabla.eliminar(16);tabla.eliminar(10);
	cout << "\n\n" << endl;
	tabla.imprimirTabla();
	if (tabla.buscarDato(1010))
		cout << "\n\n Si se encontro el dato " << endl;
	else
		cout << "\n\n Valiste merga " << endl;
	
	
		
	cout << "\nhello mother fuckers, Aaron Knoww was here" << endl;
	system("pause > null");

	return 0;
}
