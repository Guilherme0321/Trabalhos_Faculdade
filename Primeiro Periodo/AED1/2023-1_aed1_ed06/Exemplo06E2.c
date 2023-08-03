#include <stdio.h>
int fatorial(){
    int q=0;
    scanf("%d",&q);
    printf("%d/%d",cima(1,q,1),baixo(1,q,0)-1);
}
int cima(int nn,int q,int rcima){
    int x=0;
    x=rcima;
    if(q!=0){
    rcima = nn-2;

    rcima = cima(nn+2,q-1,rcima);
    x+=rcima;
    }
    return x;
}
int baixo(int dn, int q,int r){
    int x=0;
    x=r;
    if(q==0){
        return x;
    }else{
    r = fat(dn);

    r= baixo(dn+1,q-1,r);
    x+=r;
    return x;
    }
}
int fat(int dn){
    if(dn==1){
            return 1;
    }else{
        return dn * fat(dn-1);
    }
}

int main(){
    fatorial();
    return 0;
}//cima(1,q,1),
