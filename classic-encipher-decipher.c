#include <stdio.h>
#include <math.h>
#include <string.h>
int extended_gcd(int a, int b, int *x, int *y);
int main(){
	char str[100];
	int flag[100]={0};
	int i=0,multDec,x,y;
	strcpy(str,"Quick fox jumps over the lazy brown dog.");
	printf("plain: %s",str);
	while(str[i] != '\0'){ //Additive encipher with 255 ASCII codes
		str[i]=(str[i]+17)%255;
		if (str[i]<32||str[i]>=0){
			flag[i]=1;
			str[i]+=31;
		}
		i++;
	}
	printf("\nAdditive encrypted: %s",str);
	i=0;
	while(str[i] != '\0'){ //Additive decipher
		if (flag[i]=1){
			str[i]-=31;
			flag[i]=0;
		}
		str[i]=(str[i]-17)%255;
		i++;
	}
	printf("\nAdditive decrypted: %s",str);
	
	i=0;
	while(str[i] != '\0'){ //Multiplicative encipher with 127 ASCII codes
		str[i]=(str[i]*5)%127;
		if (str[i]<32&&str[i]>=0){
			flag[i]=1;
			str[i]=(str[i]+31)%127;
		}
		i++;
	}
	printf("\nMultiplicative encrypted: %s",str);
	multDec=extended_gcd(5,127,&x,&y); //taking Bézout coefficients
	i=0;
	while(str[i] != '\0'){ //Multiplicative decipher with 127 ASCII codes
		if (flag[i]==1){
			str[i]=(str[i]-31)%127;
			flag[i]=0;
		}
		str[i]=(str[i]*x)%127;
		i++;
	}
	printf("\nMultiplicative decrypted: %s",str);
	return 0;
}
int extended_gcd(int a, int b, int *x, int *y){ //Extended GCD (greatest common divisor) using euler theorem with Bézout coefficients
    if (a == 0)                                 //Bézout coefficients: ax + by = multDec (multDec is the gcd result), x can be used for inverse multiplication if multDec is 1.
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int _x, _y;
    int gcd = extended_gcd(b % a, a, &_x, &_y); //Recursively
    *x = _y - (b/a) * _x;
    *y = _x;
    return gcd;
}
