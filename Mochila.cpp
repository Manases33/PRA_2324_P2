#include <iostream>
#include <algorithm>
#define N 4

int mochila(int* p,int* b,int pmax,int* sol){
	int tab[N][pmax+1];
	for(int i = 0;i < N;i++){		//Inicializar
		for(int j = 1;j <= pmax;j++){	//La
			if(j != 0)		//Tabla
				tab[i][j] = -1;	
		}
	}
	tab[0][0] = 0;
	for(int j = 1;j <= pmax;j++){		//Primera
		if(j >= p[0])			//fila
			tab[0][j] = b[0]; 	//de
		else				//la 
			tab[0][j] = 0;		//tabla
	}
	
	for(int i = 1;i < N;i++){									//Resto
		tab[i][0] = 0;										//de
		for(int j = 1;j <= pmax;j++){								//filas
			if(j >= p[i]){									//de
				tab[i][j] = std::max(tab[i - 1][j],(tab[i - 1][j - p[i]] + b[i]));	//la
			}										//tabla
			else
				tab[i][j] = tab[i - 1][j];
		}
	}
	
	int i = N - 1;						//Crear 
	int j = pmax;						//Vector
								//de
	while(j > 0){						//solucion	
		if(tab[i][j] != tab[i - 1][j]){
			j -= p[i];
			sol[i] = 1;
			i--;
		}
		else{
			i--;
		}
	}

	return tab[N-1][pmax];					//Devolver resultado
}


int main(){
	int p[N] = {2,1,3,2};
	int b[N] = {12,10,20,15};
	int pmax = 5;
	int sol[N] = {0,0,0,0};

	std::cout << "Máximo beneficio obtenible: " << mochila(p,b,pmax,sol) << " usando:" << std::endl;

	for(int i = 0;i < N;i++){
		std::cout << sol[i] << " Objeto "  << i + 1 << std::endl;
	}

	return 0;
}
