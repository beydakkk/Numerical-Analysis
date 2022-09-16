#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

	float ustalma(float taban,float ust)
	{
		int i;
		float sonuc=1;
		
		for(i=0;i<ust;i++){
			sonuc = sonuc*taban;
		}
		return sonuc;
	}


int main(){
	
	int i,islem,n,katsayi[MAX];
	float h,nokta,x1,x2,turev;
	float sonuc1=0,sonuc2=0;
	
	printf("Islemler\n1:Ileri fark ile turev\n2:Geri fark ile turev\n3:Merkezi farklar ile turev\n");
	printf("Islemi seciniz\n");
	scanf("%d",&islem);
	
	printf("fonksiyonunuz kacinci dereceden?\n");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		if(i==0){
			printf("sabit sayiyi giriniz:\n",i);
			scanf("%d",&katsayi[i]);
		}
		else{
			printf(" x^%d elemaninin katsayisini giriniz:\n",i);
			scanf("%d",&katsayi[i]);
		}
	}
	
	printf("hangi noktadaki turevi almak istiyorsunuz?\n");
	scanf("%f",&nokta);
	printf("artis degerini giriniz:\n");
	scanf("%f",&h);
	
	switch(islem){
		
		case 1:
			x1=nokta+h;
			for(i=0;i<=n;i++){
				sonuc1+= ustalma(x1,i)*katsayi[i];
			}
			for(i=0;i<=n;i++){
				sonuc2+= ustalma(nokta,i)*katsayi[i];
			}
			turev=(sonuc1-sonuc2)/h;
			
			printf("Ileri fark ile alinan turev:%f",turev);
			
			break;
		
		case 2:
			x1=nokta-h;
			for(i=0;i<=n;i++){
				sonuc1+= ustalma(nokta,i)*katsayi[i];
			}
			for(i=0;i<=n;i++){
				sonuc2+= ustalma(x1,i)*katsayi[i];
			}
			turev=(sonuc1-sonuc2)/h;
			
			printf("Geri fark ile alinan turev:%f",turev);
			
			
			break;
			
		case 3:
			x1=nokta+h;
			x2=nokta-h;
			
			for(i=0;i<=n;i++){
				sonuc1+= ustalma(x1,i)*katsayi[i];
			}
			for(i=0;i<=n;i++){
				sonuc2+= ustalma(x2,i)*katsayi[i];
			}
			turev=(sonuc1-sonuc2)/(2*h);
			
			printf("Merkezi fark ile alinan turev:%f",turev);
			
			break;
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
