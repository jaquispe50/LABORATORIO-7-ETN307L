/*Calculo de la media aritmética, la mediana y la moda. 
Se analizó el IVA que se aplica, en diversos países europeos, 
a la compra de obras de arte. Los resultados obtenidos fueron los siguientes
       PAIS
España      0,16
Italia      0,20
Bélgica     0,06
Holanda     0,06
Alemania    0,07
Portugal    0,17
Luxemburgo  0,06
Finlandia   0,2
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	
	int n1=8;//numero de elementos//
	float aux1,media1=0,cont1=0,cont2=0,moda1;
	float IVA[n1]={0.16,0.20,0.06,0.06,0.07,0.17,0.06,0.22}; //datos de la lista//
	system("color 0A");
	cout<<"\tTENEMOS:\n";
	cout<<"\n\t               --------------------";
	cout<<"\n\t               | Espana       o.16|";
	cout<<"\n\t               | Italia       o.20|";
	cout<<"\n\t               | Belgica      o.06|";
	cout<<"\n\t               | Holanda      o.06|";
	cout<<"\n\t               | Alemania     o.07|";
	cout<<"\n\t               | Portugal     o.17|";
	cout<<"\n\t               | Luxemburgo   o.06|";
	cout<<"\n\t               | Finlandia    o.22|";
	cout<<"\n\t               --------------------\n";
	
	//para ordenar de forma ascendente//

	for(int i=0;i<n1;i++){
		for( int j=0;j<n1-1;j++){
			if(IVA[j]>IVA[j+1]){
				aux1=IVA[j];
				IVA[j]=IVA[j+1];
				IVA[j+1]=aux1;
			}
		}
	}
	//sumatoria de todos los terminos para sacar la media//
	for(int i=0;i<n1;i++){
		media1 += IVA[i];	
	}
	
	cout<<"\t - Datos ordenados de manera ascendente de la lista :\n\n";
	cout<<"\t IVA por pais : ";
	for(int i=0;i<n1;i++){
		cout<<IVA[i]<<","; //se muestra los datos ordenados//
	}
	cout<<endl;

	cout<<"\n\n\t - Los calculos con los datos son : \n\n";
	cout<<"\t Mediana de los datos : "<<(IVA[n1/2]+IVA[n1/2 -1]*1.0)/2<<endl; //calculo de la mediana de un numero par de datos//
	
	cout<<"\n\t Media Aritmetica de los datos es : ";
	cout<<(media1)*1.0/n1;  // se muestra la media de los datos//
                                                            
	for(int i=0;i<n1;i++){  //bucles for anidados para detectar la moda de los datos//
		for(int j=0;j<n1;j++){
			if(IVA[i] == IVA[j] && i!=j)cont1++;  //condiciones y contador//
		}
		if(cont1>cont2){
			cont2=cont1;
			moda1=IVA[i];  
		}
		cont1=0;
	}
	cout<<endl;
	cout<<"\n\t Moda de la lista : "<<moda1; //se muestra la moda da los datos//
	
	getch();
	return 0;
}
