/*Los resultados en el análisis del valor calórico (Kcal/ración) 
de 20m marcas de galletas normales y 12 integrales, considerando 
como ración 5 o 6 galletas (30 gramos) son los siguientes:

Calcular la media aritmética, mediana y moda
*/
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	
	int n1=20,n2=12,aux1,aux2,media1=0,media2=0,cont1=0,cont2=0,cont3=0,cont4=0,moda1,moda2;
	int NORMALES[n1]={125,125,150,135,150,130,130,145,135,145,130,150,140,150,140,145,130,130,130,140};//datos de la tabla
	int INTEGRALES[n2]={135,135,130,135,125,140,150,135,135,145,150,130};//datos de la tabla
	system("color 0A");
	
	cout<<"\n\tTENEMOS LOS SIGUIENTES VALORES:\n";
	cout<<"\n         | NORMALES   | 125| 125| 150| 135| 150| 130| 130| 145| 135| 145| 130| 150| 140| 150| 140| 145| 130| 130| 135| 140| ==> x";
	cout<<"\n         | INTEGRALES | 135| 135| 130| 135| 125| 140| 150| 135| 135| 145| 150| 130|  ==> Y";
	cout<<"\n\t - Calcular la media aritmetica, mediana y moda \n\n";
	
	//para ordenar las listas 1 de forma ascendente//
	for(int i=0;i<n1;i++){
		for( int j=0;j<n1-1;j++){
			if(NORMALES[j]>NORMALES[j+1]){
				aux1=NORMALES[j];
				NORMALES[j]=NORMALES[j+1];
				NORMALES[j+1]=aux1;
			}
		}
	}
	//para ordenar las listas 2 de forma ascendente//
	for(int i=0;i<n2;i++){
		for( int j=0;j<n2-1;j++){
			if(INTEGRALES[j]>INTEGRALES[j+1]){
				aux1=INTEGRALES[j];
				INTEGRALES[j]=INTEGRALES[j+1];
				INTEGRALES[j+1]=aux1;
			}
		}
	}
	//sumamos cada uno de los terminos del arreglo en las 2 listas//

	cout<<"\t - Datos ordenados de manera ascendente de ambas listas :\n\n";
	cout<<"\t Galletas normales : ";
	for(int i=0;i<n1;i++){
		cout<<NORMALES[i]<<" ; ";//mostramos la primera lista ordenada//
	}
	cout<<endl;
	cout<<"\t Galletas Integrales : ";
	for(int i=0;i<n2;i++){
		cout<<INTEGRALES[i]<<" ; ";//mostramos la segunta lista ordenada//
	}
	cout<<"\n\n\t - Los calculos con los datos son : \n\n";
	cout<<"\t Mediana Galletas normales : "<<(NORMALES[n1/2]+NORMALES[n1/2 -1]*1.0)/2<<endl;      //mediana de la lista de galletas normales//
	cout<<"\t Mediana Galletas Integrales : "<<(INTEGRALES[n2/2]+INTEGRALES[n2/2 -1]*1.0)/2<<endl;//mediana de la lista de galletas integrales//
	
	//sumamos cada uno de los terminos del arreglo en las 2 listas y mostramos la media Aritmetica//
	for(int i=0;i<n1;i++){
		media1 += NORMALES[i];	
	}
	cout<<"\n\t Media Aritmetica de las galletas Normales es : ";
	cout<<(media1)*1.0/n1;
	
	for(int i=0;i<n2;i++){
		media2 += INTEGRALES[i];	
	}
	cout<<"\n\t Media Aritmetica de las galletas Integrales es : ";
	cout<<(media2)*1.0/n2<<endl;

	//bucles anidados para encontrar la moda de la lista de galletas normales//                                                           
	for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++){
			if(NORMALES[i] == NORMALES[j] && i!=j)cont1++;
		}
		if(cont1>cont2){
			cont2=cont1;
			moda1=NORMALES[i];
		}
		cont1=0;
	}
	cout<<"\n\t Moda de las galletas Normales es : "<<moda1;//mostramos moda//
	
	//bucles anidados para encontrar la moda de la lista de galletas integrales//     
	for(int i=0;i<n2;i++){
		for(int j=0;j<n2;j++){
			if(INTEGRALES[i] == INTEGRALES[j] && i!=j)cont3++;
		}
		if(cont3>cont4){
			cont4=cont3;
			moda2=INTEGRALES[i];
		}
		cont3=0;
	}
	cout<<"\n\t Moda de las galletas Integrales es : "<<moda2<<endl;//mostramos moda//
	return 0;
}
