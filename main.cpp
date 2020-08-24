#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define TAM 1000

void llenarVector(int tvec,int vec[])
{

for(int i=0;i<tvec;i++)
{
    cin>>vec[i];
}
}
void llenarVectorAleatorios(int tvec,int vec[],int randNum)
{
   srand(time(NULL));
for(int i=0;i<tvec;i++)
{
    randNum=1+rand()%(101-1);
    vec[i]=randNum;
}
}
void mostrarVector(int tvec,int vec[])
{

for(int i=0;i<tvec;i++)
{
   cout<<vec[i]<<" ";
}
cout<<endl;
}
int hallarMayor(int tvec,int unVector[])
{
    int mayor=0;
//    int posMayor;
for(int i = 0;i<tvec;i++)
{
    if(i==0){
        mayor=unVector[i];
        // posMayor=i+1;
        }


if(unVector[i]>mayor){
    mayor=unVector[i];
    //posMayor=i+1;
}


}
return mayor;
}
//sort
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivote
    int i = (low - 1); // elemento mas pequeño

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        // ordena los elementos antes y depues de la  "particion"
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int A[TAM], B[TAM], C[TAM];
    int dimension;
    char opcion;
    bool bandera=false;
     int last;
    int is_creciente = true;
    int is_decreciente = true;




    int randNum=0;



    //LECTURA
    cout<<"Ingrese el tamaño de sus vectores: "; cin>>dimension;
    do{
    cout<<endl;

cout<<"Seleccione una operacion "<<endl;
cout<<"0.Llenar vectores con numeros aleatorios "<<endl;
cout<<"1.Ingresar A "<<endl;
cout<<"2.Ingresar B "<<endl;
cout<<endl;
cout<<"a. Hallar el mayor de A"<<endl;
cout<<"b. Hallar el mayor de B"<<endl;
cout<<"c. ordenar el vector A"<<endl;
cout<<"d. ordenar el vector B"<<endl;
cout<<"e. verificar si A esta ordenado"<<endl;
cout<<"f. verificar si B esta ordenado"<<endl;
cout<<endl;
cout<<"3.sumar vectores "<<endl;
cout<<"4.restar vectores "<<endl;
cout<<"5.multiplicar vectores "<<endl;
cout<<"6.Fusionar vectores "<<endl;
cout<<"7.Salir "<<endl;
cin>>opcion;
switch(opcion){
case '0':

    llenarVectorAleatorios(dimension,A,randNum);
    llenarVectorAleatorios(dimension,B,randNum);
    mostrarVector(dimension,A);
    mostrarVector(dimension,B);

    break;
case '1':
    cout<<"Lectura del arreglo  A."<<endl;
       llenarVector(dimension,A);
    cout<<endl;
    break;

case '2':

    cout<<"Lectura del arreglo B."<<endl;
    llenarVector(dimension,B);
    cout<<endl;
    break;

case 'a':

    cout<<"el elemento mayor de A es "<<hallarMayor(dimension,A);
    cout<<endl;
    break;
    case 'b':

    cout<<"el elemento mayor de B es "<<hallarMayor(dimension,B);
    cout<<endl;
    break;
    case 'c':
         quickSort(A, 0, dimension - 1);
    cout << "Arreglo ordenado: \n";
    mostrarVector(dimension, A);

        break;
            case 'd':
         quickSort(B, 0, dimension - 1);
    cout << "Arreglo ordenado: \n";
    mostrarVector(dimension,B);

        break;
        case 'f':

    last = B[0];
    for(int z = 1; z < dimension; z++)
    {
        if(B[z] < last) is_creciente = false;
        if(B[z] > last) is_decreciente = false;
        last = A[z];
    }

    // Imprimir resultados

    if(is_creciente && is_decreciente)
        cout<<"El vector tiene todos los valores repetidos.\n";
    else if(is_creciente)
        cout<<"El vector esta ordenado de forma creciente.\n";
    else if(is_decreciente)
        cout<<"El vector esta ordenado de forma decreciente.\n";
    else
        cout<<"El vector esta desordenado.\n";
                break;
                        case 'e':

    last = A[0];
    for(int z = 1; z < dimension; z++)
    {
        if(A[z] < last) is_creciente = false;
        if(A[z] > last) is_decreciente = false;
        last = A[z];
    }

    // Imprimir resultados

    if(is_creciente && is_decreciente)
        cout<<"El vector tiene todos los valores repetidos.\n";
    else if(is_creciente)
        cout<<"El vector esta ordenado de forma creciente.\n";
    else if(is_decreciente)
        cout<<"El vector esta ordenado de forma decreciente.\n";
    else
        cout<<"El vector esta desordenado.\n";
                break;
case '3':
 	cout<<"\nSuma de Vectores\n";
	for(int i=0;i<dimension;i++){
			cout<<A[i]+B[i]<<" ";
		cout<<"\n";
	}
    break;
case '4':
 	cout<<"\n Resta de Vectores\n";
	for(int i=0;i<dimension;i++){
			cout<<A[i]-B[i]<<" ";

		cout<<"\n";
	}
    break;
case '5':


    cout<<"Vector C de multiplicar A+B: ";
    for(int i=0; i<dimension; ++i)
    {
     C[i]=A[i]*B[i];
     cout<<C[i]<<" ";
    }
    cout<<endl;
    break;
case '6':
    cout<<"no estan ordenados "<<endl;
    break;
case '7':
    bandera=true;
    break;
default:
cout<<"error"<<endl;
}
}while(bandera!=true);

    return 0;
}
