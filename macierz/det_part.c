double det(double ** matrix, int n)
{
	double** minor;
	double sum=0.0;
	double sign=1.0;
	int i, ...;

	/* rozpatrz przypadki szczególne */
	if(n==1) ...
	if(n==2) ...

	minor=matrix_alloc(n-1);

	for(i=0;i<n;i++)
	{
		/* skopiuj odp. podmacierz do minor */
		...

		/* wylicz wyznacznik podmiacierzy */
		sum+=sign*matrix[0][i]*det(minor,n-1);
		sign = -sign;
	};

	matrix_free(minor);

	return sum;
};
