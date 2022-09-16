#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

int main(){
	
	int i,j,k,l,n;
	float a[MAX][MAX],kokler[MAX],temp1,temp2,deger=0;
	
	printf("GAUSS ELIMINASYON YONTEMI\n\n");
	
	printf("degisken sayisini giriniz: ");
	scanf("%d",&n);
	printf("\n");

	
	for(i=0;i<n;i++){
		printf("%d. denklem icin\n",i+1);
		for(j=0;j<=n;j++){
			if(j!=n){
				printf("x%d. degiskenin katsayisini giriniz:",j+1);
				scanf("%f",&a[i][j]);
			}
			else{
				printf("%d. denklemin sonucunu giriniz:",i+1);
				scanf("%f",&a[i][j]);
				printf("\n");
			}
		}
	}
	
	printf("olusan denklem sistemi:\n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0;i<n;i++){
		temp1=a[i][i];
		for(j=0;j<=n;j++){
			a[i][j]/=temp1;
		}
		for(k=i+1;k<n;k++){
			temp2=a[k][i];
			for(l=0;l<=n;l++){
				a[k][l]/=temp2;
				a[k][l]-=a[i][l];
				a[k][l]*=temp2;
			}
		}
	}
	
	
	
	printf("islemler sonrasinda denklem sisteminin durumu:\n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	kokler[n-1]=a[n-1][n];
	
	for(i=n-2;i>=0;i--){
		for(j=i;j<n-1;j++){
			deger -=(a[i][j+1]*kokler[j+1]);
			
		}
		deger += a[i][n];
		kokler[i]=deger;
		deger=0;
	}
	for(i=0;i<n;i++){
		printf("x%d. kok : %f\n",i+1,kokler[i]);
	}
	return 0;
}
