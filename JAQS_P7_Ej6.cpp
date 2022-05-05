/*Un fabricante de neumáticos ha recabado, de los diferentes concesionarios, 
información sobre la cantidad de miles de kilómetros recorridos por un modelo
 concreto de esos neumáticos hasta que se ha producido un pinchazo o un reventón 
 del neumático. Los concesionarios la han proporcionado los siguientes datos:

Se pide:
a) Construir una taba de frecuencias para esos datos tomando como número de 
   intervalos el que proporciona la fórmula de Sturgess. Interpretas la tabla.
b) Construir las tablas de frecuencias acumuladas ascendente y descendente.
c) Dibujar el histograma de frecuencias relativas sin acumular y acumulado.
d) Calcular las principales medidas de tendencia central e interpretarlas. 
e) Obtener las medidas de dispersión más importantes e interpretarlas.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include <conio.h>

using namespace std;

COORD coord={0,0};
void gotoxy(int x, int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    int i, j, n=100, freq = 0,k, s;
    float temp, min, max, range,interval,cibase,aux1,media ,cont1,cont2,moda,auxe;
    float x[n]={52.452, 50.432, 37.748, 51.831, 73.808, 61.065, 35.807, 57.277,  //datos del arreglo//
	            48.698, 65.854, 75.850, 36.949, 75.548, 69.010, 61.477, 65.585, 
	            44.411, 41.886, 34.754, 59.888, 59.449, 67.632, 89.116, 69.483, 
	            63.692, 70.003, 65.996, 55.989, 49.677, 46.502, 67.467, 64.398,
	            84.588, 40.709, 50.238, 61.390, 85.720, 45.313, 46.724, 61.752,
	            55.643, 55.912, 46.681, 66.519, 59.168, 66.313, 35.884, 28.625,
	            47.012, 71.360, 78.635, 41.715, 72.635, 41.463, 48.996, 48.172,
	            48.240, 67.662, 53.324, 49.011, 29.480, 41.128, 30.252, 33.412,
	            74.239, 57.884, 55.257, 84.656, 48.662, 10.504, 60.951, 38.420,
	            79.426, 60.727, 56.155, 86.070, 90.565, 53.751, 76.580, 68.629,
	            51.179, 74.582, 58.708, 48.035, 67.124, 41.830, 61.030, 58.267,
	            61.979, 4.3068, 41.539, 62.215, 51.269, 82.919, 34.182, 37.654,
	            80.502, 35.342, 44.719, 37.402};
	
	system("color 0A");
	cout<<"\n   (a)	Construir una tabla de frecuencias para esos datos tomando como numero de  ";
	cout<<"\n       intervalos el que proporciona la formula de Sturgess. Interpretas la tabla.  ";
	cout<<"\n   (b) Construir las tablas de frecuencias acumuladas ascendente y descendente. ";
	cout<<"\n   (c) Dibujar el histograma de frecuencias relativas sin acumular y acumulado.";
	cout<<"\n   (d) Calcular las principales medidas de tendencia central e interpretarlas. ";
	cout<<"\n   (e) Obtener las medidas de dispersion más importantes e interpretarlas.\n\n ";
	
	k=1+3.3*log10(n) +1 ;
    cout << "\t- Segun la formula de Sturgess  k = 1+3.3*log(n) tenemos : k="<<k<<endl;

    if(k >= 7 && k <= 20){
        for(i = 0; i < n; ++i){
            for(j = 1 + i; j < n; ++j){
                if(x[i] > x[j]){
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }

        cout << endl;

        min = x[0];
        max = x[n - 1];
        range = max - min;
        interval = range / k;

        cout << "  Intervalos                 Frecuencia   \n\n";

        cibase = min;
        while(cibase <= max){
            cout.width(5); cout << right << cibase << " - ";
            cout.width(4); cout << right << (cibase ) + interval << "\t\t";
            freq = 0;
            for(i = 0; i < n; ++i){
                if(x[i] >= cibase && x[i] <= ((cibase - 1) + interval)){
                    ++freq;
                }
            }
            cout.width(4); cout << right << freq << "\t";
            cout <<  "\n" << endl;
            cibase = cibase + interval;
        }

        cout.width(6); cout << "\nMinimo: " << setprecision(5) << right << min << endl;
        cout.width(6); cout << "Maximo: " << setprecision(5) << right << max << endl;
        cout.width(6); cout << "Rango: " << setprecision(5) << right << range << endl;
        cout.width(6); cout << "Intervalo: " << setprecision(5) << right << interval << endl;
    }
    int Freq[9]={2,0,7,15,21,25,12,7,1};
    for( i=0;i<9;i++){
    	s=Freq[i];
    	for(j=0;j<s;j++){
    		gotoxy(70+i,41-j);
    		cout<<char(178);
		}
	}
	
	cout<<"\n\t\t\t\t\t\t\t\t      |||||||||";
	cout<<"\n\t\t\t\t\t\t\t  Intervalos= 123456789"<<endl<<endl;//señalamos los intervalos pertenecientes al histograma
	for(int i=0;i<n;i++){
		for( int j=0;j<n-1;j++){ //para ordenar la lista de forma ascendente
			if(x[j]>x[j+1]){
				aux1=x[j];
				x[j]=x[j+1];
				x[j+1]=aux1;
			}
		}
	}
	cout<<" - Datos ordenados de manera ASCENDENTE :\n\n";
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ; ";//mostramos la primera lista ordenada//
	}
	for(int i=0;i<n;i++){
		for( int j=0;j<n-1;j++){ //para ordenar la lista de forma descendente
			if(x[j]<x[j+1]){
				aux1=x[j];
				x[j]=x[j+1];
				x[j+1]=aux1;
			}
		}
	}
	cout<<"\n\n - Datos ordenados de manera DESCENDENTE :\n\n";
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ; ";//mostramos la segunda lista ordenada//
	}
	
	cout<<"\n\n - Medidas de tendencia central : \n\n";
	cout<<"\t Mediana de la lista de datos : "<<(x[n/2]+x[n/2 -1]*1.0)/2<<endl;      //mediana de la lista de datos //
	
	//sumamos cada uno de los terminos del arreglo en las 2 listas y mostramos la media Aritmetica//
	for(int i=0;i<n;i++){
		media += x[i];	
	}
	cout<<"\t Media Aritmetica de la lista de datos : ";
	cout<<(media)*1.0/n;
	
	//bucles anidados para encontrar la moda de la lista de datos//                                                           
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i] == x[j] && i!=j)cont1++;//contador de numeros parecidos//
		}
		if(cont1>cont2){
			cont2=cont1;
			moda=x[i];
		}
		cont1=0;
	}
	cout<<"\n\t Moda de las galletas Normales es : "<<moda;//mostramos moda//
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			auxe=x[j]-media;//para el calculo del error
		}
	}
	cout<<"\n\n\tEl error Absoluto es = +"<<auxe/n;
	cout<<"\n\tEl error Relativo es = +"<<((auxe/n)*pow(10,4))/media <<"%";	 //mostramos los 2 tipos de errores
	getch();
    return 0;
}
