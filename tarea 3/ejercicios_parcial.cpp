#include <iostream>

using namespace std;
void imprimir(int *a){
    while (*a != -1){
        cout << *a << ",";
        ++a;
    }
    cout << *a << endl;
}
void mezclar(int *origenA, int *origenB, int *Destino){
	while (*origenA != -1 && *origenB != -1){
		if (*origenA < *origenB){
			*Destino = *origenA;
			origenA++;
		} else {
			*Destino = *origenB;
			origenB++;
		}
		Destino++;
	}
	while (*origenA != -1){
		*Destino = *origenA;
		Destino++;
		origenA++;
	}
	while (*origenB != -1){
		*Destino = *origenB;
		Destino++;
		origenB++;
	}
	*Destino = -1;
}

int comparar(char* CadenaA, char* CadenaB){
	while (*CadenaA != '\0' && *CadenaB != '\0'){
  	if (*CadenaA < *CadenaB)
    	return 1;
		else if (*CadenaA > *CadenaB)
			return -1;
		CadenaA++;
		CadenaB++;
	}
	if (*CadenaA == '\0' && *CadenaB == '\0')
		return 0;
	else if (*CadenaA != '\0')
		return -1;
	else
		return 1;
}

int main()
{
    int a[] = {2,3,4,5,6,8,9,-1};
    int b[] = {1,3,4,6,7,8,10,-1};
    int c[50];
    mezclar(a,b,c);
//    imprimir(c);

    char x[] = "MARIA";
    char y[] = "MARIA";
    cout << comparar(x,y) << endl;

}
