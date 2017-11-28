#include "rcstring.h"

int main()
{
rcstring a,b,c,e;
e="  -231aCDd789";
a="10";
b="ALA ma kota";
cout << a << " " << b << endl; // 10 ala ma ma kota
c=a+b;
cout << c<<endl; // 10ala ma kota
c=a+rcstring(" ")+b;
cout << c << endl; //10 ala ma kota
rcstring d("a");
cout << d <<endl; //a
d+="ula";
cout << d << endl; //aula
d+="15";
cout << d << endl; //aula15
cout << d[3]<<endl; //a
d[3]='b';
cout << d << endl; //aulb15
d[2]=d[1]=d[0];

cout << d << endl; //aaab15
cout<<"atoi: "<< e.myatoi()<< endl;
cout<<"atoi: "<< a.myatoi()<< endl;
cout<<"lower: "<<b.tolower2()<<endl;
cout<<"lower: "<<e.tolower2()<<endl;
rcstring x=b;
cout<<"b przed left: "<<x<<endl;
try
{
a=b.Left(9);
cout<<"left: "<<a<<endl;
}
catch(...)
{
cout<<"error";
}

cout<<b<<"\n"<<x<<"\n";
return 0;
}
