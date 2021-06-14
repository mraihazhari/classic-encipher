//Made by GreyWard
#include <stdio.h>
#include <math.h>
#include <string.h>
int mod(int a,int b);
int special(int a, int b);
int main(){
	char str[100],key[100];
	int i,j;
	strcpy(str,"Quick fox jumps over the lazy brown dog.");
	strcpy(key,"thekey");
	printf("plain: %s",str);
	for(i=0;i<strlen(str);i+=strlen(key)){ //vigenere encipher
		for (j=0;j<strlen(key);j++){
			if ((i+j)<strlen(str)){
				str[i+j]=mod((str[i+j]+key[j]),256);
			}
		}
	}
	printf("\nEnciphered text: %s",str);
	for(i=0;i<strlen(str);i+=strlen(key)){ //vigenere decipher
		for (j=0;j<strlen(key);j++){
			if ((i+j)<strlen(str)){
				str[i+j]=mod((str[i+j]-key[j]),256);
			}
		}
	}
	printf("\nDeciphered text: %s",str);
	return 0;
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
