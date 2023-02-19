#include<bits/stdc++.h>
#define LLI long long int
#define INT LLI

INT fn_gcd(INT a,INT b){
	if(b>a)return fn_gcd(b,a);
	else if(b==0)return a;
	else return fn_gcd(b,a%b);
}