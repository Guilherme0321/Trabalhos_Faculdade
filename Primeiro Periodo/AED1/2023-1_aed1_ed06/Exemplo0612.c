#include <stdio.h>
int multplos(ini){
    int resul = 0;
    if(ini > 0){
        resul = 6 * ini;
        printf("%d ",resul);
        multplos(ini-1);
    }
    return resul;
}
int main(){
    int Qm = 0, resul=0;
    int multplos(int ini);
    scanf("%d",&Qm);
    multplos(Qm);
}
