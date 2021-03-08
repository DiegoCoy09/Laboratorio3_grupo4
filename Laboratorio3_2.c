/* Laboratorio versión 3.0.1
 * ALSE
 * Integrantes: Alejandra Forero, Diego Coy, Juan Andres Riapira
 *Este codigo se realiza con el objetivo de poner en practica nuestras habilidades y conocimientos en programación en lenguaje C.
 El programa lee valores de un archivo .csv con un formato especifico, con el fin de obtener el valor promedio, la desviacion estandar y los valores máximos y mínimos de los números ingresados
 para luego guardar estos datos en otro archivo .csv*/

// se incluye las librerias y se define las constantes a usar

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# define Max_tan 300
# define maxq 15

# define TAM_BUFF 100000
//"/home/alse/Documents/Laboratorio3_grupo4/test_vector1_ints.csv"
# define PATH2 "/home/alse/Documents/Laboratorio3_grupo4/Datos_salida.txt"
//"/home/alse/Documents/Laboratorio3_grupo4/test_vector1_floats_2.csv"


// se inicializan las funciones a usar a lo largo del codigo

int menu (char *cadena1, char *cadena2);
int opciones (char *cadena1, char *cadena2);
float ingresar (char *cadena1);
float promedio (char *cadena1);
float desviacion(char *cadena1);
float max_min (char *cadena1);
float sumav (char *cadena,float sum);
float sum2_vectores (char *cadena1,char *cadena2);
float Recorre (char *cadena1, char *cadena2);
float ingresar2 (char *cadena2);

void salir();

//Se define la función principal
int main (void)
{
    printf ("\n--------------------------BIENVENIDO A NUESTRA APLICACIÓN----------------------------------\n ");
        char cadena1 [Max_tan];
        char cadena2 [Max_tan];
        int result1 [Max_tan];
        menu (cadena1, cadena2);
        opciones(cadena1, cadena2);
        return 0;
}
// la función menu se esncarga de mostrar el menu y dirigir al usuario a la función opciones
int menu(char *cadena1, char *cadena2)
{
		printf("\n-------------------------------MENU DE OPCIONES--------------------------------------------\n");
		printf ("\n 1. Ingresar dirección de archivo de texto con valores. \n 2. Mostrar promedio, desviación y valores maximos y minimos. \n 3. Ingresar un segundo arreglo y comparar la suma total entre los dos arreglos. \n 4. Comparación compenente a componente entre dos arreglos. \n 5. Salir. \n");
		opciones(&cadena1[0],&cadena2[0]);
}
// La función ociones toma el valor indicado por el usuario y lo dirige a la accion solicitada por este
int opciones (char *cadena1, char *cadena2)
{
        int variable1;
        char *dirr;
		char *dirr2;
        char valor1[Max_tan];
        char valor2[Max_tan];
        char valor3[Max_tan];
        char valor1_1[Max_tan];
        dirr=cadena1;
		dirr2=cadena2;
        strcpy(valor1, cadena1);
        strcpy(valor2, cadena1);
        strcpy(valor3, cadena1);
        strcpy(valor1_1,cadena2);
		
		printf("\n Introduce el número de la opción que desees: \n ");
        scanf ("%d", &variable1);
		
		
        switch (variable1)
        {
                case 1:
                        ingresar(cadena1);
                        menu(cadena1, cadena2);
                        break;
				case 2:
						if (valor1[0]=='\0')
						{
							printf("\n-----------------------------Por favor ingrese valores para realizar las operaciones-------------------------------\n");
							break;
						}
						else
						{
							promedio(valor1);
							max_min(valor2);
							desviacion(valor3);
							menu(cadena1, cadena2);
							break;
						}						
				case 3:
						if (valor1[0]=='\0')
						{
							printf("\n-----------------------------Por favor ingrese valores para realizar las operaciones-------------------------------\n");
							break;
						}
						else
						{
							ingresar2(cadena2);
							sum2_vectores (valor1,dirr2);
							menu(cadena1,cadena2);
							break;
						}	
				case 4:						
						if (valor1_1[0]=='\0')
						{
							printf("\n-----------------------------Por favor ingrese valores para realizar las operaciones-------------------------------\n");
							break;
						}
						else
						{
							Recorre (cadena1,dirr2);
							menu(cadena1,cadena2);
							break;
						}							
                case 5:
                        printf("\n\n------------------Gracias por usar nuestra aplicación------------------- \n\n");
                        salir();
                        break;
                default:
                        printf("\n--------------------Por favor, ingrese un valor válido-------------------- \n\n");
                        menu(cadena1, cadena2);
                        break;
        }
		return 0;
}

//La función ingresar se encarga de tomar la información dada por el usuario y cinvertirla en enteros para que con esta información se pueda proceder a ejecutar las otras funciones
float ingresar (char *cadena1)
{
        char PATH1 [Max_tan];
		FILE *Arch1;
		unsigned int tam_arch = 0;
		char buffer[TAM_BUFF];
		float resultf;
		
		printf("\n Por favor ingrese la ruta del archivo de texto: \n ");
        scanf ("%s", PATH1);
		
		printf ("\n-----------Lectura de los datos ingresados en el archivo de texto------------\n");

		//Lectura del archivo de texto
		
		Arch1 = fopen(PATH1,"r+");
		if (Arch1 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch1,0,SEEK_END);
		tam_arch = ftell(Arch1);
		rewind(Arch1);
		resultf = fread(buffer, 1, tam_arch, Arch1);
		if (resultf != tam_arch)
		{
			printf("\n Error de lectura \n");
		}
		fclose(Arch1);
		
		strcpy(cadena1, buffer);
		printf("\n El valor ingresado corresponde a: %s \n", cadena1);
		
		return 0;
}

float ingresar2 (char *cadena2)
{
		char PATH2v [Max_tan];
		FILE *Arch5;
		unsigned int tam_arch = 0;
		char buffer[TAM_BUFF];
		float resultf;
		
		printf("\n Por favor ingrese la ruta del archivo de texto del segundo arreglo: \n");
        scanf ("%s", PATH2v);
		printf ("\n-----------Lectura de los datos ingresados en el archivo de texto------------\n");

		Arch5 = fopen(PATH2v,"r+");
		if (Arch5 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch5,0,SEEK_END);
		tam_arch = ftell(Arch5);
		rewind(Arch5);
		resultf = fread(buffer, 1, tam_arch, Arch5);
		if (resultf != tam_arch)
		{
			printf("\n Error de lectura \n");
		}
		fclose(Arch5);
		strcpy(cadena2, buffer);
		printf("\n El valor ingresado corresponde a: %s \n", cadena2);
	
		return 0;
}

// La función promedio toma los datos resultantes de la función ingreso y halla el promedioo de este
float promedio (char *cadena1)
{
		char *dirr2;
		dirr2=cadena1;

		char promedio1[Max_tan];
		strcpy(promedio1,dirr2);
		
        float cont=0;
        float sum=0;
        float prom;
        char delimitador [] = ";";
        char *token = strtok (promedio1, delimitador);
        do
        {
                sum=atof(token)+sum;
                cont++;
                token=strtok (NULL, delimitador);
        }
        while(token != NULL);
        prom = (sum+0.0)/cont;
        printf("\n El promedio es igual a: %1.3f \n", prom);
		
		//Se guarda en un archivo de texto
		unsigned int tam_arch = 0;
		char buffer[TAM_BUFF];
		float resultf;
		
		FILE *Arch2;

		Arch2 = fopen(PATH2,"a");
		if (Arch2 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch2,0,SEEK_END);
		tam_arch = ftell(Arch2);
		rewind(Arch2);
		
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
		fprintf(Arch2, "\nDatos tomados en la fecha: %s \n",output);
		
		fprintf(Arch2, "EL promedio es igual a: %1.3f \n", prom);
		fclose(Arch2);
		
		return 0;
}

// La función desviación se encarga de calcular la desviacion estandar del arreglo

float desviacion(char *cadena1)
{
        float cont=0;
        float sum=0;
        float prom;
        char delimitador [] = ";";
        char cadena3[Max_tan];
        strcpy(cadena3,cadena1);
        char *token = strtok (cadena1, delimitador);
        float desviacion=0;
        float suma=0;
        float cuadrado=0;
        float diferencia=0;

        do
        {
                sum=atof(token)+sum;
                cont++;
                token=strtok (NULL, delimitador);
        }
        while(token != NULL);
        prom=(sum+0.0)/cont;

        char delimitador2 [] = ";";
        char *token2 = strtok (cadena3, delimitador2);

        while (token2 != NULL)
        {
                diferencia=atof(token2)-prom;
               	cuadrado=pow(diferencia,2);
                suma=suma+cuadrado;
                token2=strtok (NULL, delimitador2);
                //printf("\n %s", token2);
        }

        desviacion=sqrt((suma+0.0)/cont);
        printf("\n La desviación es igual a:  %1.3f \n\n", desviacion);
		
		//Se guarda en un archivo de texto
		unsigned int tam_arch = 0;
		char buffer[TAM_BUFF];
		float resultf;
		
		FILE *Arch3;

		Arch3 = fopen(PATH2,"a");
		if (Arch3 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch3,0,SEEK_END);
		tam_arch = ftell(Arch3);
		rewind(Arch3);
		fprintf(Arch3, "La desviación es igual a: %1.3f \n", desviacion);
		fclose(Arch3);

        return 0;

}


// Esta función se encarga de hallar el valor maximo y minimo del arreglo
float max_min (char *cadena1)
{
        float cont=0;
        float valor=0;
        float max=0;
        float min=0;
        char delimitador [] = ";";
        char *token = strtok(cadena1, delimitador);
        do
        {
                if (cont==0)
                {
                        max=atof(token);
                        min=atof(token);
                }
                cont++;
                valor=atof(token);
                if (max<valor)
                {
                        max=valor;
                }
                else if (min>valor)
                {
                        min=valor;
                }
                token= strtok(NULL, delimitador);
        }
        while (token != NULL);
        printf("\n El valor máximo es: %1.3f \n", max);
        printf("\n El valor mínimo es: %1.3f \n", min);
		
		//Se guarda en un archivo de texto
		unsigned int tam_arch = 0;
		char buffer[TAM_BUFF];
		float resultf;
		
		FILE *Arch4;

		Arch4 = fopen(PATH2,"a");
		if (Arch4 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch4,0,SEEK_END);
		tam_arch = ftell(Arch4);
		rewind(Arch4);
		//fwrite(desviacion, sizeof(char), sizeof(desviacion), Arch3);
		fprintf(Arch4, "El valor máximo es igual a: %1.3f \n", max);
		fprintf(Arch4, "El valor mínimo es igual a: %1.3f \n", min);
		fclose(Arch4);
		return 0;
}

// Esta función se encarga de realizar la suma y comparacion entre los dos arreglos
float sum2_vectores (char *cadena1,char *cadena2)
{
        char copia1[Max_tan];
		char copia2[Max_tan];
        strcpy(copia1,cadena1);
		strcpy(copia2,cadena2);
		
        float sum1;
        float sum2;
        char delimitador [] = ";";
        sum1=sumav(copia1,sum1);
        sum2=sumav(copia2,sum2);
        printf("\n La suma de los componentes del vector 1: %1.3f \n La suma de los componentes del vector 2: %1.3f\n",sum1,sum2);

		
		//Se guarda en un archivo de texto
		unsigned int tam_arch1 = 0;
		
		FILE *Arch6;

		Arch6 = fopen(PATH2,"a");
		if (Arch6 == NULL)
		{
			printf("\n Error al abrir archivo \n");
		}
		fseek(Arch6,0,SEEK_END);
		tam_arch1 = ftell(Arch6);
		rewind(Arch6);
		
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
		fprintf(Arch6, "\nDatos tomados en la fecha: %s \n",output);
		
		fprintf(Arch6,"La suma de los componentes del vector 1: %1.3f \nLa suma de los componentes del vector 2: %1.3f\n",sum1,sum2);
		
		if (sum1>sum2)
		{
                printf("\nLa suma de los componentes en el vector 1, es mayor que el vector 2\n");
				fprintf(Arch6,"La suma de los componentes en el vector 1, es mayor que el vector 2\n");
				
        }
		else if (sum2>sum1 )
		{
                printf("\nLa suma de los componentes en el vector 2, es mayor que el vector 1\n");
				fprintf(Arch6, "La suma de los componentes en el vector 2, es mayor que el vector 1\n");
        }
		else
		{
                printf("\nLa suma de los componentes de los dos vectores son iguales\n");
				fprintf(Arch6, "La suma de los componentes de los dos vectores son iguales\n");
        }
		
		fclose(Arch6);
		return 0;
}

float sumav (char *cadena,float sum){
        sum=0;
        int cont=0;
        char delimitador [] = ";";
        char *token = strtok (cadena, delimitador);
        do {//copia-------------------------------
                sum=atof(token)+sum;//la prueba
                cont++;
                token = strtok (NULL, delimitador);
                }
        while (token != NULL);//copia-------------
        return sum;
}

float Recorre (char *cadena1, char *cadena2)
{
    float val1=0;
	float val2=0;
    int cont=0;
	char *token1;
	char *token2;
	char *derr=cadena1;
	char *derr1=cadena2;
    char delimitador [] = ";";
	char lista[1000];
	
	printf("\n cadena1 en recorre: %s\n",derr);
	printf("\n cadena2 en recorre: %s\n",derr1);
	
	
    do {
	
		if (token1 != NULL)
		{
			val1=atof(token1);
			val2=atof(token2);	 
			printf("Val1 %s ",token1);
			printf("Val2 %s ",token2);
			
			if (val1>val2)
			{
				printf("\n El componente en la cadena1, es mayor que el componente del vector 2\n");
				char m[50]="mayor ";
				strcat(lista,m);

			}else if (val1<val2 ){
				printf("\nEl componente en la cadena1, es menor que el componente del vector 2\n");
				char m[50]="menor ";
				strcat(lista,m);
			}else {
				printf("\nEl componente en la cadena1, es igual que el componente del vector 2\n");
				char m[50]="igual ";
				strcat(lista,m);
			}
				
		}
		
    }
    while ((token1 = strtok_r(derr,delimitador, &derr)) && (token2 = strtok_r(derr1,delimitador, &derr1)));
		
	//Se guarda en un archivo de texto
	unsigned int tam_arch = 0;
	char buffer[TAM_BUFF];
	float resultf;
		
	FILE *Arch7;

	Arch7 = fopen(PATH2,"a");
	if (Arch7 == NULL)
	{
		printf("\n Error al abrir archivo \n");
	}
	fseek(Arch7,0,SEEK_END);
	tam_arch = ftell(Arch7);
	rewind(Arch7);
	
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
	fprintf(Arch7, "\nDatos tomados en la fecha: %s \n",output);
	
	fprintf(Arch7, "\n La comparación componente a componente es: %s \n", lista);
	fclose(Arch7);
				
		
	return 0;
}

// Esta saca al usuario de la aplicación
void salir()
{
        exit(-1);
}