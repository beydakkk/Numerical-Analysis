#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

int main(){
	
	printf("GAUSS SEIDEL ITERASYON YONTEMI\n\n");
	
	int i,j;
	int n,iterasyon=0;
	float hata,a[MAX][MAX];
	
	printf("degisken sayisini giriniz:\n");
	scanf("%d",&n);
	printf("tolere edilebilecek hata degerini giriniz:\n");
	scanf("%f",&hata);
	
	float curr[n],yeni[n],fark[n];
	
	for(i=0;i<n;i++){
		fark[i]=10;
		yeni[i]=0;
		
	}
	
	printf("KATSAYILAR MATRISININ KOSEGENINDEKI ELEMANLAR CARPIMI MAX OLACAK SEKILDE DENKLEMLER GIRINIZ");
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
	
	for(i=0;i<n;i++){
		printf("x%d icin baslangic degeri giriniz:",i+1);
		scanf("%f",&curr[i]);
	}
	while(fark[0]>hata || fark[1]>hata || fark[2]>hata){
		
		for(i=0;i<n;i++){
			yeni[i]+=a[i][n];
			
			for(j=0;j<=n-1;j++){
				if(i!=j){
					yeni[i]-= a[i][j]*curr[j];
				}
			}
			yeni[i] /= a[i][i];
			fark[i] = fabs(yeni[i]-curr[i]);
			curr[i] = yeni[i];
			printf("%d %f\n",i,yeni[i]);
			yeni[i]=0;
			iterasyon++;
		}
		
	}
	
	
	printf("iterasyon sayisi:%d\n",iterasyon);
	
	for(i=0;i<n;i++){
		printf("x%d icin yaklasik deger:%f\n",i+1,curr[i]);
		
	}

	
	return 0;
}
