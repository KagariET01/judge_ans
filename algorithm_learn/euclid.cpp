#include<bits/stdc++.h>
#define LLI long long int
#define INT LLI

struct euclid_list{
	INT l[3][2]={{0,0},{0,0},{0,0}};
};

euclid_list call_euclid(INT a,INT b){
	euclid_list lst;
	lst.l[1][0]=1;
	lst.l[2][1]=1;
	if(a<b){
		lst.l[0][0]=b;
		lst.l[0][1]=a;
	}else{
		lst.l[0][0]=a;
		lst.l[0][1]=a;
	}
	return euclid(lst);
}

euclid_list euclid(euclid_list a){
	if(a.l[0][1]==0)return a;
	else{
		euclid_list lst;
		INT xx=a.l[0][0]/a.l[0][1];
		lst.l[0][0]=a.l[0][1];
		lst.l[1][0]=a.l[1][1];
		lst.l[2][0]=a.l[2][1];
		lst.l[0][1]=a.l[0][0]-(a.l[0][1]*xx);
		lst.l[1][1]=a.l[1][0]-(a.l[1][1]*xx);
		lst.l[2][1]=a.l[2][0]-(a.l[2][1]*xx);
		return euclid(lst);
	}
}