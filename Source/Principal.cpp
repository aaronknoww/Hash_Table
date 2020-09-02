#include "../Headers/Precom.h"// precompiledheader
#include "..\Headers\MyHash.h"
#include "..\Source\MyHash.cpp"
//By Aaron Knoww

using namespace std;

int main()
{
	Myhash<int> tabla;

	tabla.insertar(135);
	tabla.insertar(756);
	tabla.insertar(45);
	tabla.insertar(24);
	tabla.insertar(10);
	tabla.insertar(1);
	tabla.insertar(13);

	//!!!!!!!!!!!!!!! NECESITO DEPURAR Y VER QUE PASA DESPUES DE SALIR DE LA FUCION REHASHING!!!!!!!
	cout << "\nhello mother fuckers, Aaron Knoww was here" << endl;
	system("pause > null");

	return 0;
}
