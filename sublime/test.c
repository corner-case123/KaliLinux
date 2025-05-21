#include<stdio.h>

int main(){
	int a , b , c ; 
	scanf("%d %d %d",&a,&b,&c) ;
	double root1 = (-b + sqrt(b*b-4*a*c) )/2*a; 
	double root2 = (-b - sqrt(b*b-4*a*c) )/2*a; 
	printf("%f %f"root1,root2) ;
	return 0 ; 
}