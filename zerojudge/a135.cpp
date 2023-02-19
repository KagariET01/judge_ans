#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<string,string> translate;
	translate["HELLO"]="ENGLISH";
	translate["HOLA"]="SPANISH";
	translate["HALLO"]="GERMAN";
	translate["BONJOUR"]="FRENCH";
	translate["CIAO"]="ITALIAN";
	translate["ZDRAVSTVUJTE"]="RUSSIAN";
	int i=1;
	while(true){
		string intext;
		cin>>intext;
		if(intext=="#"){break;}
		if(translate.count(intext)){cout<<"Case "<<i<<": "<<translate[intext]<<"\n";}
		else{cout<<"Case "<<i<<": "<<"UNKNOWN"<<"\n";}
		i++;
	}
	
	
	return 0;
}


/*
[sample input 1]
HELLO
HOLA
HALLO
BONJOUR
CIAO
ZDRAVSTVUJTE
#
[sample output 1]
Case 1: ENGLISH
Case 2: SPANISH
Case 3: GERMAN
Case 4: FRENCH
Case 5: ITALIAN
Case 6: RUSSIAN
*/