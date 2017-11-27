#ifndef __RCSTRING_H__
#define __RCSTRING_H__
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class BadAlloc{};
class BadMem{};


class rcstring{
  struct rctext;
  rctext* data;
public:
class Range{};
class Cref;
rcstring();
rcstring(const char*);
rcstring(const rcstring&);
~rcstring();
rcstring& operator=(const char*);
rcstring& operator=(const rcstring&);
rcstring& operator+=(const rcstring &);
rcstring operator+(const rcstring &) const;
friend ostream& operator<<(ostream&, const rcstring&);
void check (unsigned int i) const;
char read(unsigned int i) const;
void write(unsigned int i, char c);
int myatoi();
rcstring& tolower2();
rcstring Left(unsigned int n);
char operator[](unsigned int i) const;
Cref operator[](unsigned int i);
};

struct rcstring::rctext
{
  char* s;
  unsigned int size;
  unsigned int n;

  rctext(unsigned int nsize, const char* p)
  {
    try{
      n=1;
    size=nsize;
    s=new char[size+1];
    strncpy(s,p,size);
    s[size]='\0';
}
catch(...)
{
  throw ;
  cout<<"Bad Allocation";
}
  };
  ~rctext()
  {
    delete [] s;
  };
  rctext* detach()
  {
    if(n==1)
      return this;
try{
    rctext* t=new rctext(size, s);
    n--;
    return t;
   }


catch(bad_alloc)
{
throw BadAlloc();
cout<<"Bad Allocation";
}
  };

  void assign(unsigned int nsize, const char *p)
  {
    if(size!=nsize)
    {
      try{
      char* ns=new char[nsize+1];
      size = nsize;
      strncpy(ns,p,size);
      //delete [] s;

      s = ns;

    }
    catch(bad_alloc)
    {
      throw BadAlloc();
      cout<<"Bad Allocation";
    }
    }
    else
      strncpy(s,p,size);
    s[size]='\0';
  }
private:
  rctext(const rctext&);
  rctext& operator=(const rctext&);
};

class rcstring::Cref
{
  friend class rcstring;
  rcstring& s;
  int i;
  Cref (rcstring& ss, unsigned int ii): s(ss), i(ii) {};
public:
  operator char() const
  {
    cout << "operator char() const"<<endl;
    return s.read(i);
  }
  rcstring::Cref& operator = (char c)
  {
    cout << "void operator = (char c)"<<endl;
    s.write(i,c);
    return *this;
  }
  rcstring::Cref& operator = (const Cref& ref)
  {
    return operator= ((char)ref);
  }
};
inline rcstring::rcstring()
  {
    try{
    data = new rctext(0,"");
  }
  catch(bad_alloc)
  {
    throw BadAlloc();
cout<<" Bad Allocation";
  }
}
inline rcstring::rcstring(const rcstring& x)
  {
    x.data->n++;
    data=x.data;
  }
inline rcstring::~rcstring()
{
  if(--data->n==0)
    delete data;
}

rcstring& rcstring::operator=(const rcstring & x)
{
  x.data->n++;
  if(--data->n == 0)
    delete data;
  data=x.data;
  return *this;
}

rcstring::rcstring(const char* s)
{
  try
  {
 data=new rctext(strlen(s),s);
}
catch(bad_alloc)
{
  throw BadAlloc();
  cout <<"Bad Allocation";
}
}

rcstring& rcstring::operator=(const char* s)
{
  try{
    if(data->n==1)
    data->assign(strlen(s),s);
    else
    {

      rctext* t = new rctext(strlen(s),s);
      data->n--;
      data= t;
    };
    return *this;
  }
  catch(...)
  {
    throw BadAlloc();
    cout<<"Bad Allocation";
  }
  delete data;
}

ostream& operator << (ostream& o, const rcstring& s)
{
  return o<<s.data->s;
}

rcstring& rcstring::operator+=(const rcstring & s)
{
unsigned int newsize=data->size+s.data->size;
try{
rctext *newdata=new rctext(newsize,data->s);
strcat(newdata->s,s.data->s);
if(--data->n==0)
  delete data;
data = newdata;
return *this;
}
catch(bad_alloc)
{
  throw BadAlloc();
  //cout<<"Bad Allocation";
}
delete data;
}

rcstring rcstring::operator+(const rcstring & s) const
{
  return rcstring(*this)+=s;
}

inline void rcstring::check (unsigned int i) const
{
if(data->size<=i)
  throw Range();
}
inline char rcstring::read(unsigned int i) const
{
 return data->s[i];
}
inline void rcstring::write(unsigned int i, char c)
{
  data = data->detach();
  data->s[i] = c;
}

char rcstring::operator[](unsigned int i) const
{
  cout << "char rcstring::operator[](unsigned int i) const"<<endl;
  check(i);
  return data->s[i];
}

rcstring::Cref rcstring::operator[](unsigned int i)
{
  cout << "Cref rcstring::operator[](unsigned int i)"<<endl;
  check(i);
  return Cref(*this,i);
}

int rcstring::myatoi(){
  return ::atoi(data->s);
}

rcstring & rcstring::tolower2(){
    unsigned int i=0;
    char s=0;
    while(i<data->size){
        s = read(i);
       if(!islower(s)) write (i, tolower (s));
        i++;
        }
  return *this;
}


 rcstring rcstring::Left(unsigned int n)
  {
    if(n>data->size)
    {
      cout << "Size smaller than n!" << endl;
      throw Range();
    }
    char *newChar;
    try
    {
     newChar = new char [n+1];
    }
    catch(...)
    {
      cout << "BadAlloc!";
      throw BadAlloc();
    }
    strncpy(newChar, data->s, n);
    newChar[n] = '\0';
    rcstring x(newChar);
    delete [] newChar;
    return x;
}

  /*    rcstring leftstring=data->s;
      strncpy((leftstring.data->s), (data->s), n);
      strcpy( (leftstring.data->s+n), '\0'); //blad z konewrsja
      return leftstring;


}*/



#endif /* __RCSTRING_H__ */
