#include <iostream>

using namespace std;

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void burbuja(int *a, int *b)
{
    int *aux_primer, *aux_sig, *inicio, *aux_fin;
    aux_fin = b;
    int cont=0;
    while(aux_fin-a > 0){
        aux_primer = a;
        aux_sig= a+1; //aux_sig=aux_primer+1 ¿?
        for(b; b>a; b--)
        {
            if(*aux_primer > *aux_sig)
            {
                swap(*aux_primer, *aux_sig); //verifica
                cont++;
            }

            *aux_primer++;
            *aux_sig++;
        }
        if(cont==0)
            break;
        b=aux_fin;
        aux_primer = a; //o aux_primer = inicio ?
        aux_sig= a+1;
        aux_fin--;

    }

}
void selection_sort(int *a, int *b)
{
  int *minpos, *aux;
//  int *aux_2;
  for(a; a<b; a++)
  {
      minpos=a;
      aux=a;
      int cont=0;
      for(aux; aux<b; aux++)
      {
//          aux2= aux+1;
          if(*aux > *(aux+1))
            minpos = aux+1;
          if(*minpos != *aux)
          {
              if(*minpos < *a){
                swap(a, minpos);
                cont++;
              }
          }
      }
      if(cont==0)
        break;
  }
}

void insertSort(int *a, int *length)
{
    int *i, *j;
    int value; //*value?
    i = a+1;
    for(i ; i < length+1; i++)
    {
        value = *i;
        j= i;
        for (j; j > a && *(j-1) > value; j--)
            *(j) = *(j-1);
        *(j) = value;
    }
}

void imprimir(int *a, int tam){

    for(int i = 0; i <= tam; i++)
            cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[]= {-1,7,0,5,-20,3};
    int tam=sizeof(a)/sizeof(int)-1;
    int b[]= {4,-3,5,200,1};
    int tam_b=sizeof(b)/sizeof(int)-1;
    int c[]= {3,5,1,2,-5};
    int tam_c=sizeof(c)/sizeof(int)-1;
    ///////////////
    burbuja(a, a+tam);
    cout<< "Burbuja: ";
    imprimir(a, tam);
    /////////////////
    selection_sort(b, b+tam_b);
    cout<< "Seleccion: ";
    imprimir(b, tam_b);
    ///////////
    insertSort(c, c+tam);
    cout<< "Insercion: ";
    imprimir(c, tam_c);
}
