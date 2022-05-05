/*4 Los datos que se dan a continuacion corresponden a los pesos en Kg. de ochenta personas:   
    (a) Obtengase una distribucion de datos en intervalos de amplitud 5, siendo el primer intervalo [50; 55] 
	(b) Calculese el porcentaje de personas de peso menor que 65 Kg. (c) Cuantas personas tienen peso mayor 
	(c) Cuantas personas tienen peso mayor o igual que 70 Kg. pero menor que 85?
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	
	int n=80, i, j, nci=6, freq = 0, freq1=0, freq2=0;//numero de elementos, intervalos y frecuencias//
	float temp, min, max, rango, interval, cibase;
	float x[n]={60, 66, 77, 70, 66, 68, 57, 70, 66, 50, 75, 65, 69, 71, 58, 66, 67, 74, 61, 63, 69, 80, 59,  //datos del arreglo//
	               66, 70, 67, 78, 75, 64, 71, 81, 62, 64, 69, 68, 72, 83, 56, 65, 74, 67, 54, 65, 65, 69, 61, 
	               67, 73, 57, 62, 67, 68, 63, 67, 71, 68, 76, 61, 62, 63, 76, 61, 67, 67, 64, 72, 64, 73, 79, 
	               58, 67, 71, 68, 59, 69, 70, 66, 62, 63, 66};
	system("color 0A");
	cout<<"\n   (a) Obtengase una distribucion de datos en intervalos de amplitud 5, siendo el primer intervalo [50; 55] ";
	cout<<"\n   (b) Calculese el porcentaje de personas de peso menor que 65 Kg. ";
	cout<<"\n   (c) Cuantas personas tienen peso mayor o igual que 70 Kg. pero menor que 85?\n";

    if(nci >= 0 && nci <= 6){
        for(i = 0; i < n; ++i){
            for(j = 1 + i; j < n; ++j){//para ordenar los datos de menor a mayor//
                if(x[i] > x[j]){
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }

        printf("\n");

        min = x[0];   //el menor seria el primer termino del arreglo ordenado
        max = x[n - 1];  //el mayor seria el ultimo termino del arreglo ordenado
        rango = max - min;   //rango de comprension de los datos
        interval = ceil(rango / nci);   //intervalo de analisis de frecuencias

        printf("   Intervalo  \t");
        printf("    Frequencia \t");
        printf("rango de intervalo \t\n");

        cibase = min;   //empezamos por el termino menor//
        while(cibase <= max){
            printf("%5.0f - %4.0f\t\t", cibase, (cibase - 1) + interval); //vamos avanzando el intervalo de 5 de amplitud
            freq = 0;
            for(i = 0; i < n; ++i){
                if(x[i] >= cibase && x[i] <= ((cibase - 1) + interval)){// contamos los numeros pertenecientes a su respectivo intervalo
                    ++freq;
                }
            }
            printf("%4d\t", freq);      //se muestran las frecuencias de los intervalos//
            printf("%6.1f - %6.1f\t\t", cibase - 0.5, (cibase - 0.5) + interval);//para mostrar el rango de cada intervalo
            printf("\n");
            cibase = cibase + interval;
        }

        printf("\n  Maximo: %6.1f\n", max);  //mostramos el mayor termino detectado
        printf("  Rango: %6.1f\n", rango);   //mostramos el rango mayor
        
        freq1=0;
        for(i=0;i<n;++i){
        	if(x[i] >=50 && x[i]<65){ //condicion para determinar el intervalo 50-65
        		++freq1;              //contador de datos pertenecientes
			}
		}	
		cout<<"  El porcentaje de personas de peso menor que 65 Kg es : "<<(freq1*1.0/80)*100<<" % de los datos\n";//mostramos porcentaje
		freq2=0;
        for(i=0;i<n;++i){
        	if(x[i] >=70 && x[i]<85){ //condicion para determinar el intervalo 70-85
        		++freq2;              //contador de datos pertenecientes
			}
		}
		cout<<"  El porcentaje de personas de peso Mayor o igual a 70 pero menor que 85 kg es : "<<(freq2*1.0/80)*100<<" % de los datos";//mostramos porcentaje
    }
	getch();
	return 0;
	
}
