#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define N 3

int cambio(int* v,int P,int* vector){
	int tab[N][P+1];
	for(int i = 0;i < N;i++){
		for(int j = 0;j <= P;j++){
			if(j != 0)
				tab[i][j] = -1;
		}
	}
	tab[0][0] = 0;						//Primera 
        for(int j = 1;j <= P + 1;j++){				//Fila
        	if(j >= v[0] && tab[0][j - v[0]] != -1){	//De
			tab[0][j] = 1 + tab[0][j - v[0]];	//La
		}						//Tabla
	}	
	for(int i = 1;i < N;i++){							//Resto
		tab[i][0] = 0;								//De
		for(int j = 1;j <= P;j++){						//Filas
			if(j < v[i] || tab[i][j - v[i]] == -1)
				tab[i][j] = tab[i - 1][j];
			else if(tab[i - 1][j] != -1)
				tab[i][j] = std::min(tab[i - 1][j],(1 + tab[i][j - v[i]]));
			else
				tab[i][j] = 1 + tab[i][j - v[i]];
		}
	}
	
	int i = N - 1;
	int j = P;
	
	while(j > 0){
		if(tab[i][j] == tab[i-1][j]){
			i--;
		}
		else{
			j -= v[i];
			vector[i]++;
		}	
	}
	
	return tab[N-1][P];
}

int main(int argc,char** argv){
	int v[N] = {1,4,6};
	int vector[N];
	int cant = atoi(argv[1]);
	
	std::cout << "Monedas minimas: " <<  cambio(v,cant,vector) << std::endl;
	
	for(int i = 0;i < N;i++){
		std::cout << vector[i] << " monedas de " << v[i] << std::endl;
	}
	
	return 0;
}
