#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
double func (double x);
double half(double x1,double x2);
double hord(double x1,double x2);
//приблизні корні:-36;42;244
int main()
 {
     double x1,x2,root;
     unsigned int met;
     printf("Your's function:-pow(x,3)/25+10*pow(x,2)-15000\n");
     printf("Choose method:\n1)half\n2)hord\n");
     scanf("%u",&met);
      while(met!=1 && met!=2)
          {
            printf(" Enter method again:");
            scanf("%u",&met);
          }
    if(met==1){
    do{
        printf("x1=");
        scanf("%lf",&x1);
        printf("x2=");
        scanf("%lf",&x2);
        system ("cls");
        while(x1>=x2){
            printf("Invalid values of x1 and x2");
            printf("\nx1=");
            scanf("%lf",&x1);
            printf("x2=");
            scanf("%lf",&x2);
            system ("cls");
        }
    }while(func(x1)*func(x2)>0);
    root=half(x1,x2);
    }


    if(met==2){
    do{
        printf("x1=");
        scanf("%lf",&x1);
        printf("x2=");
        scanf("%lf",&x2);
        system ("cls");
        while(x1>=x2){
            printf("Invalid values of x1 and x2");
            printf("\nx1=");
            scanf("%lf",&x1);
            printf("x2=");
            scanf("%lf",&x2);
            system ("cls");
        }
    }while(func(x1)*func(x2)>0);
    root=hord(x1,x2);
    }
    printf("\nroot=%lf\n",root);
    return 0;
 }

 /*-------------------------------------------------------------------------------------------------------------------------------------



 ---------------------------------------------------------------------------------------------------------------------------------------*/


double func (double x)
{
    double y;
    y=-pow(x,3)/25+10*pow(x,2)-15000;
    return y;
}


double half(double x1,double x2)
{
    double eps;
    unsigned int N;
    double xi;
    unsigned int answer;
    unsigned int count=0;
    printf("eps=");
    scanf("%lf",&eps);
    printf("N=");
    scanf("%u",&N);
    clock_t start, end;
    double delta_t;
    start = clock();
    do{
        count++;
        xi=(x1+x2)/2;
        if(func(xi)*func(x1)>0)
            x1=xi;
        if(func(xi)*func(x1)<0)
            x2=xi;
        if(count%N==0){
            printf("%d iterations done",count);
            printf("\nf(x)=%lf\nxi=%lf",func(xi),xi);
            printf("\nChoose variant\n1-exit\n2-continue\n");
            scanf("%u",&answer);
            while(answer!=1 && answer!=2)
          {
            printf(" Enter variant again:");
            scanf("%d",&answer);

          }
            if(answer==1){
                exit(0);
            }

            }
        }
    while(fabs(x1-x2)>=eps);
    end = clock();
    printf("\n\n\nNumber of iterations=%u",count);
    delta_t =(double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime to calculate = %lf\n\n", delta_t);
    return xi;
    }


double hord(double x1,double x2)
{
    double xi;
    double eps;
    unsigned int N;
    unsigned int count=0;
    unsigned int answer;
    clock_t start, end;
    double delta_t;
    printf("eps=");
    scanf("%lf",&eps);
    printf("N=");
    scanf("%u",&N);
    start = clock();
    do{
        count++;
        xi=(func(x2)*x1-func(x1)*x2)/(func(x2)-func(x1));
            if(func(x1)*func(xi)>0)
        x1=xi;
            else
        x2=xi;
            if(count%N==0){
            printf("%d iterations done",count);
            printf("\nf(x)=%lf\nxi=%lf",func(xi),xi);
            printf("\nChoose variant\n1-exit\n2-continue\n");
            scanf("%u",&answer);
            while(answer!=1 && answer!=2)
          {
            printf(" Enter variant again:");
            scanf("%d",&answer);

          }
            if(answer==1){
                exit(0);
            }

            }
    }while(fabs(func(xi))>=eps
           );
    end = clock();
    printf("\n\n\nNumber of iterations=%u",count);
    delta_t =(double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime to calculate = %lf\n\n", delta_t);
    return xi;
}

