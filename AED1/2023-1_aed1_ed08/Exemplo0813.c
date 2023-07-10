#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N(int li,int lf,int q){
    int Ns;
    srand(time(NULL));
    FILE *a = fopen("DADOS03.txt","wt");
    fprintf(a,"Quantidade = %d\n",q);
    for(int i = 0; i < q; i++){
        Ns = li + (rand() % (lf - li + 1));
        fprintf(a,"%d\n",Ns);
    }
    fclose(a);
    return Ns;
}

int main(){
    int li = 0, lf = 0, q = 0;
    printf("Digite dois numeros: ");
    scanf("%d",&li);getchar();
    scanf("%d",&lf);getchar();
    printf("Digite quantos valores irao aparecer: ");
    scanf("%d",&q);getchar();

    N(li,lf,q);
    return 0;
}
