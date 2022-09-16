#include <stdio.h>
#include <conio.h>
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
	
	int n,i,katsayi[MAX];
	int iterasyon=0;
	float a,b,hata,x;
	float fa=0,fb=0,fx=0;
	// a araligin baslangic,b bitis degeri
	
	printf("fonksiyonunuz kacinci dereceden\n");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		katsayi[i]=0;
	}
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
	
	printf("incelemek istediginiz araligin baslangicini giriniz:");
	scanf("%f",&a);
	printf("incelemek istediginiz araligin bitisini giriniz:");
	scanf("%f",&b);
	printf("islemlerinizde tolere edilebilecek hata degerini giriniz:");
	scanf("%f",&hata);
	
	while((b-a)> hata){
	
		for(i=0;i<=n;i++){
			fa+= ustalma(a,i)*katsayi[i];
		}
		for(i=0;i<=n;i++){
			fb+= ustalma(b,i)*katsayi[i];
		}
		if(fa*fb>0){
			printf("uygun olmayan bir aralik girdiniz");
		}
		
		x = (b*fa - a*fb)/(fa-fb);
		iterasyon += 1;
		for(i=0;i<=n;i++){
			fx+= ustalma(x,i)*katsayi[i];
		}
		if(fa*fx <0){
			b=x;
		}
		else a=x;
		printf("fa:%f fb=%f fx=%f x=%f a=%f b=%f\n",fa,fb,fx,x,a,b);
		fa=0;
		fb=0;
		fx=0;
	}

	printf("iterasyon sayisi:%d , yaklasik kok:%f",iterasyon,x);

	return 0;
}
