//made by GreyWard
#include <stdio.h>
#include <math.h>
#include <string.h>
// key1 (multiplicative) is 11, and key2(additive) is 17.
int extended_gcd(int a, int b, int *x, int *y);
int mod(int a, int b);
int special (int a, int b);
int print(char str[100],int length);
int main(){
	char str[100];
	int flag[100]={0};
	int i=0,multDec,x,y,strLength;
	strcpy(str,"Quick fox jumps over the lazy brown dog.");
	printf("plain: %s",str);
	strLength=strlen(str);
	while(i != strLength){ //Affine encipher with 255 ASCII codes
		str[i]= mod((str[i]*11+17),256);
		if (str[i]<32&&str[i]>=0){
			flag[i]=1;
			str[i]+=31;
		}
		i++;
	}
	printf("\nAffine encrypted: ");
	print(str,strLength);
	i=0;
	multDec=extended_gcd(11,256,&x,&y); //taking Bézout coefficients
	while(i != strLength){ //Affine decipher
		if (flag[i]==1){
			str[i]-=31;
			flag[i]=0;
		}
		str[i]=mod(((str[i]-17)*x),256);
		i++;
	}
	printf("\nAffine decrypted: ");
	print(str,strLength);
	return 0;
}
int extended_gcd(int a, int b, int *x, int *y){ //Extended GCD (greatest common divisor) using euler theorem with Bézout coefficients
    if (a == 0){                                //Bézout coefficients: ax + by = multDec (multDec is the gcd result)
        *x = 0;									//x can be used for inverse multiplication if multDec is 1.
        *y = 1;
        return b;
    }
    int _x, _y;
    int gcd = extended_gcd(b % a, a, &_x, &_y); //Recursively
    *x = _y - (b/a) * _x;
    *y = _x;
    return gcd;
}
int mod(int a,int b){ //function for modulo, since C can't moduled negative numbers
	if (a<0){
		return special(a+b,b);
	}
	else{
		return a%b;
	}
}
int special(int a, int b){ //function for negative numbers of modulo, recursively
	if(a>=0){
		return a;
	}
	else{
		return special(a+b,b);
	}
}
int print(char str[100],int length){ //function for printing strings without change in length (an error handling)
	int i=0;
	while (i != length){
		printf("%c",str[i]);
		i++;
	}
}
