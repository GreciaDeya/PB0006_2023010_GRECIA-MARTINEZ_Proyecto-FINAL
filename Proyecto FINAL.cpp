#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include <vector>
using namespace std;

void Alta();
void Modificar();
void Eliminar();
void Lista();
void Archivo();

int alta, * numtra, * preciouni, * cant, * preciocita;
float* total, * iva, * pago;
string* nombre, * tra, * desc;

int main()
{
	int digito = 1;
	while (digito == 1)
	{
		int op;
		cout << "D E N T I S T A" << endl;
		cout << "MENU DE OPCIONES" << endl;
		cout << "1. Agendar cita" << endl;
		cout << "2. Modificar cita" << endl;
		cout << "3. Eliminar cita" << endl;
		cout << "4. Lista de citas vigentes" << endl;
		cout << "5. Limpiar pantalla" << endl;
		cout << "6. Salir (ARCHIVO)" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			Alta();
			return main();
			break;

		case 2:
			Modificar();
			return main();
			break;

		case 3:
			Eliminar();
			return main();
			break;

		case 4:
			Lista();
			return main();
			break;

		case 5:
			system("CLS");
			return main();
			break;

		case 6:
			Archivo();
			digito = 2;
			break;
		}
	}
}

void Alta()
{
	cout << "INGRESE un NUMERO de CITAS" << endl;
	cin >> alta;
	nombre = new string[alta];
	numtra = new int[alta];
	tra = new string[alta];
	desc = new string[alta];
	preciouni = new int[alta];
	cant = new int[alta];
	pago = new float[alta];
	iva = new float[alta];
	total = new float[alta];
	for (int i = 0; i < alta; i++) {
		cout << "Su NUM. de CITA es:" << i + 1 << endl;
		while (getchar() != '\n');
		cout << "Ingrese el NOMBRE del paciente:" << endl;
		getline(cin, nombre[i]);
		int n;
		n = 1;
		while (n == 1)
		{
			cout << "Ingrese la HORA del tratamiento : (procure en formato 24hrs)" << endl;
			cin >> numtra[i];
			if (numtra[i] >= 7, numtra[i] < 22)
			{
				cout << "ABIERTO, el Dr.Adolfo Sanchez se encuentra DISPONIBLE." << endl;
				n = 2;
			}
			else
			{
				cout << "CERRADO, el horario que ingreso NO esta DISPONIBLE." << endl;
			}
		}
		while (getchar() != '\n');

		cout << "T R A T A M I E N T O S" << endl;
		cout << "1.- CARIES: El tratamiento incluye el uso de fluor, empaste y coronas. ($350 por uno)" << endl;
		cout << "2.- LIMPIEZA: El tratamiento usa aparato de ultrasonido. ($500)" << endl;
		cout << "3.- BRACKETS:" << endl;
		cout << " - Parte SUPERIOR e INFERIOR por separado. ($540)" << endl;
		cout << " - COMPLETO. ($1200)" << endl;
		cout << " - CAIDA de BRACKET. ($250 por uno)" << endl;
		cout << "4.- REMPLAZO de DIENTES:" << endl;
		cout << " - PROTESIS Removibles. ($3500)" << endl;
		cout << " - PUENTES Fijos. ($4800)" << endl;
		cout << " - IMPLANTES. ($5700)" << endl;
		cout << "5.- CIRUGIA ORTOGNATICA: Se realiza para colocar el maxilar en la posicion correcta de modo que se pueda lograr la armonia facial. ($12,800)" << endl;

		cout << "NOMBRE del tratamiento:" << endl;
		getline(cin, tra[i]);
		while (getchar() != '\n');

		cout << "DESCRIBA la cosulata:" << endl;
		getline(cin, desc[i]);
		while (getchar() != '\n');

		cout << "Precio UNITARIO del tratamiento:" << endl;
		cin >> preciouni[i];

		cout << "CANTIDAD del tratamiento:" << endl;
		cin >> cant[i];
	}
}

void Modificar()
{
	int z, opc;
	cout << "Cual CITA quiere MODIFICAR:" << endl;
	cin >> z;
	z = z - 1;
	cout << "M O D I F I C A C I O N" << endl;
	cout << "1. Nombre" << endl;
	cout << "2. Hora" << endl;
	cout << "3. Tratamiento" << endl;
	cout << "4. Descripcion" << endl;
	cout << "5. Precio Unitario" << endl;
	cout << "6. Cantidad" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		for (int i = z; i == z; i++)
		{
			while (getchar() != '\n');
			cout << "Nombre:" << endl;
			getline(cin, nombre[i]);
		}
		break;
	case 2:
		for (int i = z; i == z; i++)
		{
			cout << "Hora:" << endl;
			cin >> numtra[i];
		}
		break;
	case 3:
		for (int i = z; i == z; i++)
		{
			while (getchar() != '\n');
			cout << "Tratamiento:" << endl;
			getline(cin, tra[i]);
		}
		break;
	case 4:
		for (int i = z; i == z; i++)
		{
			while (getchar() != '\n');
			cout << "Descripcion:" << endl;
			getline(cin, desc[i]);
		}
		break;
	case 5:
		for (int i = z; i == z; i++)
		{
			cout << "Precio Unitario:" << endl;
			cin >> preciouni[i];
		}
		break;
	case 6:
		for (int i = z; i == z; i++)
		{
			cout << "Cantidad:" << endl;
			cin >> cant[i];
		}
		break;
	}
}

void Eliminar()
{
	int z;
	cout << "Ingrese el REGISTRO a Eliminar";
	cin >> z;
	z = z - 1;

	for (int i = z; i == z; i++)
	{
		cout << "ELIMINANDO registro" << z + 1 << endl;
		nombre[i] = " ";
		numtra[i] = 0;
		tra[i] = " ";
		desc[i] = " ";
		preciouni[i] = 0;
		cant[i] = 0;
	}
}

void Lista()
{
	for (int i = 0; i < alta; i++)
	{
		if (nombre[i] == " ")
		{
			cout << "Su CITA fue ELIMINADA:" << i + 1 << endl;
		}
		else
		{
			cout << "NOMBRE:" << nombre[i] << endl;
			cout << "HORA:" << numtra[i] << endl;
			cout << "TRATAMIENTO:" << tra[i] << endl;
			cout << "DESCRIPCION:" << desc[i] << endl;
			cout << "PRECIO UNITARIO:" << preciouni[i] << endl;
			cout << "CANTIDAD:" << cant[i] << endl;

			pago[i] = preciouni[i] * cant[i];
			iva[i] = pago[i] * 0.16;
			total[i] = pago[i] + iva[i];

			cout << "SUBTOTAL:" << pago[i] << endl;
			cout << "IVA:" << iva[i] << endl;
			cout << "TOTAL:" << total[i] << endl;
		}
	}

}

void Archivo()
{
	ofstream archivo;
	string nomarchivo;
	string texto;
	int texto2;

	nomarchivo = "Archivo D E N T I S T A";

	archivo.open(nomarchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR de ARCHIVO";
		exit(1);
	}

	archivo << "Nombre" << "\t";
	archivo << "Hora" << "\t";
	archivo << "Tratamiento" << "\t";
	archivo << "Descripcion" << "\t";
	archivo << "Precio Unitario" << "\t";
	archivo << "Cantidad" << "\t";
	archivo << "Subtotal" << "\t";
	archivo << "IVA" << "\t";
	archivo << "Total" << "\t";

	for (int i = 0; i < alta; i++)
	{
		if (nombre[i] == " ")
		{

		}
		else
		{
			texto = nombre[i];
			archivo << texto << "\t" << "\t";
			texto2 = numtra[i];
			archivo << texto2 << "\t" << "\t";
			texto = tra[i];
			archivo << texto << "\t" << "\t";
			texto = desc[i];
			archivo << texto << "\t" << "\t";
			texto2 = preciouni[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = cant[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = pago[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = total[i];
			archivo << texto2 << "\t" << "\t";
		}
	}
	archivo.close();
}
