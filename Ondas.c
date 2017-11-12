
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int numFilas(FILE *in);
void Datos(int nfilas, FILE *in, float *x, float *y);



#define L 0.640

#define c2 62500.0
#define cc 250.0

#define dx 0.005000
#define dt 0.00001
#define pi 3.14159265358979323846
#define t_max 1 //1 segundo 


int main()
{
	//cuerda fija.
	int j;
	float jmax=t_max/dt;
	FILE *in = fopen("cond_ini_cuerda.dat", "r");
	int n = numFilas(in);
	in = fopen("cond_ini_cuerda.dat", "r");
    	float *x;
	float *U_ini;
	float *U_pas;
	float *U_pre;
	x = malloc((129)*sizeof(float));
	U_ini = malloc((129)*sizeof(float));
	U_pas = malloc((129)*sizeof(float));
	U_pre = malloc((129)*sizeof(float));
	float *U_fut = malloc((129)*sizeof(float));
	float *puntomedio = malloc((jmax)*sizeof(float));

	int i ;
	Datos(n, in, x , U_ini);
	



	float r;
	int nu=129;
	
	r=cc*dt/dx;
	
	U_ini[0] = 0.0;
	U_ini[nu-1] = 0.0;
	
	U_fut[0] = 0;
	U_fut[129-1] = 0;
	//primer iteracion especial
	
	for(i=1;i<nu-1;i++)
	{
    	U_fut[i] = U_ini[i] + (pow(r,2)/2.0) * (U_ini[i+1] - 2.0 * U_ini[i] + U_ini[i-1]);
	}
	
	//para los demas 
	for(i=0;i<nu;i++)
	{
	U_pas[i]= U_ini[i];
	}	

	for(i=0;i<nu;i++)
	{
	U_pre[i]= U_fut[i];
	}

	int T =521;
	
	for(j=0;j<jmax;j++)
	{
		
    		for(i=1;i<nu-1;i++)
		{
        		U_fut[i] = (2.0*(1.0-pow(r,2)))*U_pre[i] - U_pas[i] + (pow(r,2))*(U_pre[i+1] +  U_pre[i-1]);
		}
	
    		for(i=0;i<nu;i++)
		{
		U_pas[i]= U_pre[i];
		}
    		for(i=0;i<nu;i++)
		{
		U_pre[i]= U_fut[i];
		}
		
		if(j==0)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut[i-1]);
	
		}
		}
		else if(j==T/8)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut[i-1]);
		}
		}
		
		else if(j==T/4)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut[i-1]);
		}
		}
		else if(j==T/2)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut[i-1]);
		}
		}
		
		if(j==0||j==T/8||j==T/4||j==T/2)
		{				
		printf(" %f \n",U_fut[i-1]);
		}
		puntomedio[j]=U_fut[65];
		
    	
	}
	
	
	float *U_ini1;
	float *U_pas1;
	float *U_pre1;
	U_ini1 = malloc((129)*sizeof(float));
	U_pas1 = malloc((129)*sizeof(float));
	U_pre1 = malloc((129)*sizeof(float));
	
	float *U_fut1 = malloc((129)*sizeof(float));


	for(i=1;i<nu-1;i++)
 	{
	U_ini1[i]=0;
	}
	




	
	U_ini1[0] = 0;
	U_ini1[nu-1] = 0.0;
	
	U_fut1[0] = 0;
	U_fut1[129-1] = 0;
	//primer iteracion especial
	
	for(i=1;i<nu-1;i++)
	{
    	U_fut1[i] = U_ini1[i] + (pow(r,2)/2.0) * (U_ini1[i+1] - 2.0 * U_ini1[i] + U_ini1[i-1]);
	}
	
	//para los demas 
	for(i=0;i<nu;i++)
	{
	U_pas1[i]= U_ini1[i];
	}	

	for(i=0;i<nu;i++)
	{
	U_pre1[i]= U_fut1[i];
	}

	int T1 =520;

	for(j=0;j<jmax;j++)
	{
		U_fut1[128]=sin(2*pi*cc/L *j*dt);
		
    		for(i=1;i<nu-1;i++)
		{
        		U_fut1[i] = (2.0*(1.0-pow(r,2)))*U_pre1[i] - U_pas1[i] + (pow(r,2))*(U_pre1[i+1] +  U_pre1[i-1]);
		}
	
    		for(i=0;i<nu;i++)
		{
		U_pas1[i]= U_pre1[i];
		}
    		for(i=0;i<nu;i++)
		{
		U_pre1[i]= U_fut1[i];
		}
		
		if(j==0)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut1[i-1]);
		}
		}
		else if(j==T1/8)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut1[i-1]);
		}
		}
		
		else if(j==T1/4)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut1[i-1]);
		}
		}
		else if(j==T1/2)
		{
		for(i=0;i<nu;i++)
		{
		printf(" %f ",U_fut1[i-1]);
		}
		}
		
		if(j==0||j==T1/8||j==T1/4||j==T1/2)
		{				
		printf(" %f \n",U_fut1[nu]);
		}
    	
	}
	

    	// 
	FILE *result=fopen("datos1.dat","w");
	for(i=0;i<jmax;i++)
	{
	fprintf(result," %f ",puntomedio[i]);
	}
	fclose(result);
}




int numFilas(FILE *in)
{ 
	float c;
	int n=0;
	
	while(!feof(in))
	{
		fscanf(in, "%f \n", &c);
		n++;
	}
	fclose(in);

	return n;
}

void Datos(int nfilas, FILE *in, float *x, float *y)
{
	int i;
	int nx;
	int ny;
	for(i=0; i < nfilas; i++)
	{	
		if((i%2)==0)
        	{
			fscanf(in, "%f \n", &x[nx]);
        		nx++;
        	}
                                        
        	else
        	{
        		fscanf(in, "%f \n", &y[ny]);
			ny++;
		}
	
	}
	
}
