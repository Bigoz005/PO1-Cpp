#ifndef __CMATIRX_H__
#define __CMATRIX_H__
#include <math.h>
#include <fstream>
using namespace std;

class OutOfMem{};
class IndexOutOfRange{};
class WrongDim{};

class CMatrix{
private:

	struct rcmatrix;
	rcmatrix* block;

public:
	class Cref;
	class Cref_2;
	CMatrix();
	CMatrix(const CMatrix& cm);
	CMatrix(fstream& fs);
	CMatrix(unsigned int, unsigned int, const double);
	CMatrix(unsigned int, unsigned int, double, double);
	void write(unsigned int, unsigned int, double);
	double read(unsigned int, unsigned int ) const;
	// double* operator[](unsigned int i )const;
	CMatrix& operator=(const CMatrix& asOp);
	CMatrix& operator = (const double &num);
	~CMatrix();
	friend ostream & operator << (ostream & s, const CMatrix & matrix);
	friend CMatrix operator* (const CMatrix&, const CMatrix&);

	Cref operator[](unsigned int i);

};


struct CMatrix::rcmatrix
{
	double** data;
	unsigned int rows;
	unsigned int cols;
	unsigned int n;

	rcmatrix(){
		this->data=NULL;
		this->cols=0;
		this->rows=0;
		this->n=0;
	}

	rcmatrix(fstream& fs){
		fs >> this->rows;
		fs >> this->cols;

		try
		{
			this->data = new double*[this->rows];
			for(unsigned int i=0;i<this->rows;i++)
			this->data[i]=new double[this->cols];
		}
		catch(...)
		{
			throw OutOfMem();
		}

		for(unsigned int i=0;i<this->rows;i++)
		for(unsigned int j=0;j<this->cols;j++){
			fs >> this->data[i][j];
		}
		this->n=1;
	}

	rcmatrix(unsigned int nrows, unsigned int ncols, double var){
		try
		{
			this->data = new double*[nrows];
			for(unsigned int i=0;i<nrows;i++)
			this->data[i]=new double[ncols];
		}
		catch(...){
			throw OutOfMem();
		}

		for(unsigned int i=0;i<nrows;i++)
		for(unsigned int j=0;j<ncols;j++)
		if(i==j)this->data[i][j]=var;
		else this->data[i][j]=0.0;

		this->rows=nrows;
		this->cols=ncols;
		this->n=1;
	}

	rcmatrix(unsigned int nrows, unsigned int ncols, double var1, double var2){
		try
		{
			this->data = new double*[nrows];
			for(unsigned int i=0;i<nrows;i++)
			this->data[i]=new double[ncols];
		}
		catch(...){
			throw OutOfMem();
		}

		for(unsigned int i=0;i<nrows;i++)
		for(unsigned int j=0;j<ncols;j++)
		if(i==j)this->data[i][j]=var1;
		else this->data[i][j]=var2;

		this->rows=nrows;
		this->cols=ncols;
		this->n=1;
	};

	rcmatrix(unsigned int nrows, unsigned int ncols,double** lol){
		this->rows=nrows;
		this->cols=ncols;
		this->n=1;
		this->data = lol;
	}
	rcmatrix(const rcmatrix& lol){

		try
		{
			this->data = new double*[lol.rows];
			for(unsigned int i=0;i<lol.rows;i++)
			this->data[i]=new double[lol.cols];
		}
		catch(...){
			throw OutOfMem();
		}

		for(unsigned int i=0;i<lol.rows;i++)
		for(unsigned int j=0;j<lol.cols;j++)
		this->data[i][j]=lol.data[i][j];


		this->rows=lol.rows;
		this->cols=lol.cols;
		this->n=1;

	}

	~rcmatrix(){
		for(unsigned int i=0;i<this->rows;i++)
		delete[] data[i];
		delete[] data;
	}

	rcmatrix* detach(){
		if(n==1)
		return this;
		rcmatrix* t=new rcmatrix(*this);
		n--;
		return t;
	}

	// void assign(double** p){
	// 	data = p;
	// }
	void assign(int r,int c, const double &num)
	{
	     r=rows;
	     c=cols;
	     double **temp_mat;

		temp_mat= new double *[r];

		for(int i=0;i<r;i++)
		{
                  temp_mat[i]=new double[c];
		   delete []data[i];
		}

		delete []data;

	      for(int j=0;j<r;j++)
	      {
		for(int k=0;k<c;k++)
		  temp_mat[j][k]=num;
	      }

	      data=temp_mat;
	}
};

CMatrix::CMatrix(fstream& fs){
	block = new rcmatrix(fs);
}

CMatrix::CMatrix(const CMatrix& cm){
	cm.block->n++;
	block = cm.block;
}

CMatrix::~CMatrix(){
	if(--block->n==0)
	delete block;
}

CMatrix::CMatrix(){
	block = new rcmatrix();
}

CMatrix::CMatrix(unsigned int nrows, unsigned int ncols, double var){
	block = new rcmatrix(nrows,ncols,var);
}

CMatrix::CMatrix(unsigned int nrows, unsigned int ncols, double var1, double var2){
	block = new rcmatrix(nrows,ncols,var1,var2);
}

CMatrix& CMatrix::operator = (const CMatrix& asOp){
	asOp.block->n++;
	if(--block->n == 0)
		delete block;

	block=asOp.block;
	block=block->detach();
	return *this;
}

CMatrix & CMatrix::operator=(const double &num)
{
	if(block->n==1)
	  block->assign(block->rows,block->cols,num);

        else
	{
	  rcmatrix *temp= new rcmatrix(block->rows,block->cols,num);
	  block->n--;
	  block=temp;
	}
	return *this;
}

ostream & operator << (ostream & s, const CMatrix & matrix){
	s << "[";
	for(unsigned int i=0;i<matrix.block->rows;i++)
	for(unsigned int j=0;j<matrix.block->cols;j++){

		s << matrix.block->data[i][j];

		if(((j+1) % matrix.block->cols) == 0 && j!=0 && i!=matrix.block->rows-1)
		s << endl ; // Tu trzeba cos wykombibnowac xd

		if(!(i==matrix.block->rows-1 && j==matrix.block->cols-1) && j!=matrix.block->cols-1)
		s << "\", \"";
	}
	s << "]";
	return s;
}

inline CMatrix operator * (const CMatrix& m1, const CMatrix& m2)
{

	if(m1.block->cols != m2.block->rows)throw WrongDim();

	CMatrix newMatrix(m1.block->rows, m2.block->cols,0.0);

	for(unsigned int i=0;i<newMatrix.block->rows;i++)
	for(unsigned int j=0;j<newMatrix.block->cols;j++)
	{
		double var=0.0;

		for(unsigned int lol=0;lol<m1.block->cols;lol++)
		var += m1.block->data[i][lol]*m2.block->data[lol][j];

		newMatrix.block->data[i][j] = var;
	}

	return newMatrix;
}

double CMatrix::read(unsigned int i, unsigned int j) const{
	try{
		return block->data[i][j];
	}
	catch(...){
		throw IndexOutOfRange();
	}
}

void CMatrix::write(unsigned int i, unsigned int j, double c){
	block = block->detach();
	try{
		block->data[i][j] = c;
	}
	catch(...){
		throw IndexOutOfRange();
	}
}
class CMatrix::Cref_2{
	friend class CMatrix;
	CMatrix& s;
	unsigned int i,j;

	Cref_2 (CMatrix& ss, unsigned int ii, unsigned int jj): s(ss), i(ii), j(jj){
	};

public:

	operator double() const{
		return s.read(i,j);
	};

	void operator = (double c){
		s.write(i,j,c);
	};

};
class CMatrix::Cref
{
	friend class CMatrix;
	CMatrix& s;
	unsigned int i;

	Cref (CMatrix& ss, unsigned int ii): s(ss), i(ii){
	};
	public:
		Cref_2 operator[](unsigned int j){
			return Cref_2(s,i,j);
		}
};

CMatrix::Cref CMatrix::operator[](unsigned int i)
{
	return Cref(*this,i);
}

#endif
