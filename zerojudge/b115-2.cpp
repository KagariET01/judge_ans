#include<iostream>
#include<list>
#include<string>
using namespace std;
void print(int* lista,int b){
    for(int i=0;i<b-1;i++){
        cout<<*(lista+i);
    }
    cout<<*(lista+b-1)<<endl;
}
void list_0(int* lista,int b,int data){
    for(int i=0;i<b;i++){
        *(lista+i)=data;
    }
}
void sti(string a,int* b,int c){
    int tf=1;
    for(int i=0;i<c;i++){
        if(a[i]=='\0'||tf==0){
            tf=0;
            *(b+i)=0;
            continue;
        }else{
            *(b+i)=int(a[i])-int('0');
        }
    }
}
void list_copy(int* lista,int a_long,int* listb){
    for(int i=0;i<a_long;i++){
        *(listb+i)=*(lista+i);
    }
}
int filp(int* lista,int a,int zero=0){
    int b[a];
    list_0(b,a,0);
    for(int i=0;i<a;i++){
        b[i]=*(lista+i);
    }
    int tf1=0;
    for(int i=a-1;i>=0;i--){
        if((tf1!=0||*(lista+i)!=0||zero==0||i==0)){
            *(lista+tf1)=b[i];
            tf1+=1;
        }
    }
    return tf1;
}
void filp_print(int* lista,int a){
    int tf1=0;
    for(int i=a-1;i>=0;i--){
        if(tf1==1||*(lista+i)!=0){
            cout<<*(lista+i);
            tf1=1;
        }
    }
}
void in(int* listc,int c){
    for(int i=0;i<c;i++){
        if((*(listc+i))>=10){
            int aa=*(listc+i)/10;
            *(listc+i)=*(listc+i)%10;
            *(listc+i+1)+=aa;
        }
        if((*(listc+i))<0){
            int aa=abs(*(listc+i))/10+1;
            *(listc+i)=(aa*10)+*(listc+i);
            *(listc+i+1)-=aa;
        }
    }
}
void ab(int* lista,int a,int* listb,int b,int* listc,int c){
    for(int i=0;i<a;i++){
        int aa=*(lista+i);
        if(aa==0){continue;}
        for(int j=0;j<b;j++){
            int bb=*(listb+j);
            if(bb==0){continue;}
            *(listc+i+j)+=aa*bb;
        }
    }
    in(listc,c);
}
void a_b(int* lista,int a,int* listb,int b,int* listc,int c){
    for(int i=0;i<max(a,b);i++){
        *(listc+i)=*(lista+i)-*(listb+i);
    }
    in(listc,c);
}
void ad(int* lista,int a,int* listb,int b,int* listc,int c){
    for(int i=0;i<max(a,b);i++){
        *(listc+i)=*(lista+i)+*(listb+i);
    }
    in(listc,c);
}
int big(int* lista,int a,int* listb,int b){
    int bigger=0;
    for(int i=0;i<max(a,b);i++){
        int aa=*(lista+i);
        int bb=*(listb+i);
        if(aa>bb){bigger=1;}
        if(bb>aa){bigger=2;}
    }
    return bigger;
}
void anob(int* lista,int a,int* listb,int b,int* listc,int c,int addon){
    int i[c];
    list_0(i,c,0);
    i[addon]=1;
    while(big(lista,a,listb,b)!=2){
        ad(listc,c,i,c,listc,c);
        a_b(lista,a,listb,b,lista,a);
        if(big(lista,a,listb,b)==2){break;}
    }
}
void anb(int* lista,int a,int atrue,int* listb,int b,int btrue,int* listc,int c){
    if(*listb==1){
        int tf1=1;
        for(int i=1;i<b;i++){
            if(*(listb+i)!=0){tf1=0;break;}
        }
        if(tf1==1){list_copy(lista,atrue,listc);return;}
    }
    if(big(lista,atrue,listb,btrue)==2){list_0(listc,c,0);return;}
    if(big(lista,atrue,listb,btrue)==0){list_0(listc,c,0);*listc=1;return;}
    int z[b];
    list_0(z,b,0);
    for(int i=(atrue-btrue);i>=0;i--){
        if(i!=0){
            //cout<<"[anb]i="<<i<<endl;
            int y[b];
            list_0(y,b,0);
            int x[b];
            list_0(x,b,0);
            y[i]=1;
            ab(listb,b,y,b,x,b);
            //cout<<"[anb]x=";
            //print(x,b);
            anob(lista,a,x,b,listc,c,i);
            //cout<<"[anb]listc=";
            //print(listc,c);
        }else if(i==0){
            anob(lista,a,listb,b,listc,c,i);
        }
    }
}
int main(){

    string str_a;
    char a;
    string str_b;
    cin>>str_a>>a>>str_b;
    int int_list_a[str_a.size()],int_list_b[str_b.size()];
    list_0(int_list_a,str_a.size(),0);
    list_0(int_list_a,str_a.size(),0);
    sti(str_a,int_list_a,str_a.size());
    sti(str_b,int_list_b,str_b.size());
    if(a=='*'){
        filp(int_list_a,str_a.size());
        filp(int_list_b,str_b.size());
        int int_list_a_50[50],int_list_b_50[50];
        list_0(int_list_a_50,50,0);
        list_0(int_list_b_50,50,0);
        list_copy(int_list_a,str_a.size(),int_list_a_50);
        list_copy(int_list_b,str_b.size(),int_list_b_50);
        int int_list_c[100];
        list_0(int_list_c,100,0);
        ab(int_list_a_50,50,int_list_b_50,50,int_list_c,100);
        print(int_list_c,filp(int_list_c,100,1));
    }
    if(a=='+'){
        filp(int_list_a,str_a.size());
        filp(int_list_b,str_b.size());
        int int_list_a_50[50],int_list_b_50[50];
        list_0(int_list_a_50,50,0);
        list_0(int_list_b_50,50,0);
        list_copy(int_list_a,str_a.size(),int_list_a_50);
        list_copy(int_list_b,str_b.size(),int_list_b_50);
        int int_list_c[100];
        list_0(int_list_c,100,0);
        ad(int_list_a_50,50,int_list_b_50,50,int_list_c,100);
        print(int_list_c,filp(int_list_c,100,1));
    }
    if(a=='-'){
        filp(int_list_a,str_a.size());
        filp(int_list_b,str_b.size());
        int int_list_a_50[50],int_list_b_50[50];
        list_0(int_list_a_50,50,0);
        list_0(int_list_b_50,50,0);
        list_copy(int_list_a,str_a.size(),int_list_a_50);
        list_copy(int_list_b,str_b.size(),int_list_b_50);
        int int_list_c[100];
        list_0(int_list_c,100,0);
        a_b(int_list_a_50,50,int_list_b_50,50,int_list_c,100);
        print(int_list_c,filp(int_list_c,100,1));
    }
    if(a=='/'){
        filp(int_list_a,str_a.size());
        filp(int_list_b,str_b.size());
        int int_list_a_50[50],int_list_b_50[50];
        list_0(int_list_a_50,50,0);
        list_0(int_list_b_50,50,0);
        list_copy(int_list_a,str_a.size(),int_list_a_50);
        list_copy(int_list_b,str_b.size(),int_list_b_50);
        int int_list_c[100];
        list_0(int_list_c,100,0);
        anb(int_list_a_50,50,str_a.size(),int_list_b_50,50,str_b.size(),int_list_c,100);
        print(int_list_c,filp(int_list_c,100,1));
    }
    return 0;
}
