
#include <bits/stdc++.h>
using namespace std;
using llf = long double;
using PTF = complex<llf>;

llf dot(PTF a, PTF b) { return real(conj(a) * b); }
PTF project(PTF p, PTF q) { return dot(p, q) * q / dot(q, q); }
int main(){
	int x1=0;
	int y1=0;
	int x2=0;
	int y2=0;
	int x0=1;
	int y0=1;
	int r=1;
	PTF a=PTF(x1,y1),b=PTF(x2,y2),dir=(a-b);

	cout<<project(a,b);
}

/*
0 0 0 0 
*/