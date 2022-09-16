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
	
	printf("TRAPEZ YONTEMI\n\n");
	
	int i,j,n,aralik;
	float katsayi[MAX],a,b,h,x;
	float alan=0;
	
	printf("fonksiyonunuz kacinci dereceden?\n");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		if(i==0){
			printf("sabit sayiyi giriniz:\n",i);
			scanf("%f",&katsayi[i]);
		}
		else{
			printf(" x^%d elemaninin katsayisini giriniz:\n",i);
			scanf("%f",&katsayi[i]);
		}
	}
	
	printf("integralin baslangic degeri:\n");
	scanf("%f",&a);
	printf("integralin bitis degeri:\n");
	scanf("%f",&b);
	printf("integrali kac dikdortgene bolerek hesaplatmak istiyorsunuz?\n");
	scanf("%d",&aralik);
	
	h=(b-a)/aralik;
	
	for(i=0;i<=n;i++){	
		alan += (ustalma(a,i)*katsayi[i] + ustalma(b,i)*katsayi[i]);
	}
	alan /= 2;
	//printf("%f\n",alan);
	x=a;
	for(i=1;i<aralik;i++){
		x+=h;
		for(j=0;j<=n;j++){
			alan+= ustalma(x,j)*katsayi[j];
		}
}
	alan *= h;
	
	printf("integralin yaklasik sonucu:%f",alan);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
