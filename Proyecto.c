/* Francisco Guillermo López, Eduardo Lafaire, Aitor Mancisidor*/
/*Proyecto FUNDAMENTOS DE PROGRAMACIÓN 		Blackjack */

#include<stdio.h>
#include<stdlib.h>
int nuevoJuego(int num);
void menu();
void reglas();
int sumas(int a[], int c );

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	FILE *ar;
	char p1;
	int numJugadores, elegir, ganador;

	do
	{
		menu();
		do
		{
			printf("Elige una opción del 1 al 5\n");
			scanf("%d", &elegir);
		}
		while(elegir!=1 && elegir!=2 && elegir!=3 && elegir!=4 && elegir!=5);
			switch(elegir)
			{
				case 1:
					do
					{
						printf("Escribe el número de computadoras del 1 al 4");
						scanf("%d", &numJugadores);
					}
					while(numJugadores <1 || numJugadores>4);
					
					ganador=nuevoJuego(numJugadores);

					switch(ganador)
					{
						case 0:
							printf("No hay ganador absoluto\n\n");
						break;
						case 1:
							printf("\nGanaste\n\n");
							ar=fopen("Registro.txt", "a");
							if(ar!=NULL)
							{
								fputs("Ganaste ", ar);
								fclose(ar);
							}
							else
								printf("ERROR FATAL EN EL ARCHIVO\n");
						break;
						case 2:
							printf("\nGana CP1 \n\n");
							ar=fopen("Registro.txt", "a");
							if(ar!=NULL)
							{
								fputs("Gana cp1 '\n'\n", ar);
								fclose(ar);
							}
							else
								printf("ERROR FATAL EN EL ARCHIVO\n");
						break;
						case 3:
							printf("\nGana CP2 \n\n");
							ar=fopen("Registro.txt", "a");
							if(ar!=NULL)
							{
								fputs("Gana cp2 '\n'\n", ar);
								fclose(ar);
							}
							else
								printf("ERROR FATAL EN EL ARCHIVO\n");
						break;
						case 4:
							printf("\nGana CP3\n\n");
							ar=fopen("Registro.txt", "a");
							if(ar!=NULL)
							{
								fputs("Gana cp3 '\n' ", ar);
								fclose(ar);
							}
							else
								printf("ERROR FATAL EN EL ARCHIVO\n");
							break;
						case 5:
							printf("\nGana CP4\n\n");
							ar=fopen("Registro.txt", "a");
							if(ar!=NULL)
							{
								fputs("Gana cp4 '\n'\n", ar);
								fclose(ar);
							}
							else
								printf("ERROR FATAL EN EL ARCHIVO\n");
						break;
					}
			break;
			case 2:
				reglas();
			break;
			case 3:		
				printf("Registro de partidas\n");
				ar=fopen("Registro.txt", "r");
				if(ar!=NULL)
				{
					while(!feof(ar))
					{
						p1=fgetc(ar);
						putchar(p1);
					}
					fclose(ar);
					printf("\n");
					printf("\n");
				}
				else
					printf("ERROR FATAL EN EL ARCHIVO\n");
			break;
			case 4:
				ar=fopen("Registro.txt", "w");
				if(ar!=NULL)
				{
					fclose(ar);
				}
				printf("Los archivos se han borrado con éxito");
			break;
		}
	}
	while (elegir!=5);
	return 0;
}

void menu()
{
	printf("1.-Nuevo Juego\n");
	printf("2.-Reglas\n");
	printf("3.-Registro actual\n");
	printf("4.-Borrar registro\n");
	printf("5.- Salir \n");
}
void reglas()
{
	printf("Bienvenido a 21\n\nEste es un juego de 21 tradicional donde juegas contra un número de computadoras\nEl objetivo del juego es que la suma de tus cartas dé 21 o se acerque pero no se pase.\nEn el juego a cada jugador se le reparten dos cartas, después tu podrás decidir si quieres tomar más sin pasarte de 21 (Solo puedes ver una de las cartas de tus oponentes\nSi te pasas de 21 es pérdida automática\nLas cartas J, Q, y K tienen valor de 10, el As puede valer 1 u 11 según tu situación\n\n");
}

int nuevoJuego( int num)
{
//Contador de cartas
	int a=4, dos=4, tres=4, cuatro=4, cinco=4, seis=4, siete=4, ocho=4, nueve=4, diez=4, j=4, q=4, k=4;
//Arreglos de los jugadores
	int p[5], cp1[5], cp2[5], cp3[5], cp4[5];
//Sumatoria
	int sumap=0, sumacp1=0, sumacp2=0, sumacp3=0, sumacp4=0;
//Checks
	int set=0, set1=0, set2=0, set3=0, set4=0, flag=0;
//Contadores
	int c=0, c1=0, c2=0, c3=0, c4=0, ronda=1, cpr;

	switch(num)
	{
		case 1:
			set2=1; set3=1; set4=1;
		break;
		case 2:
			set3=1; set4=1;
		break;
		case 3:
			set4=1;
		break;
	}
	do
	{
		switch(num) //cuenta de cartas según número de jugadores
		{
			case 4:
				if (sumacp4<=17 || c4==5)
				{
					do
					{
						cp4[c4]= 1 + rand() % 13;
						flag =0;
						switch(cp4[c4])
						{
							case 1:
								if (a==0)
								{
									flag=1;
									break;
								}
								a--;
							break;
							case 2:
								if (dos==0)
								{
									flag=1;
									break;
								}
								dos--;
							break;
							case 3:
								if (tres==0)
								{
									flag=1;
									break;
								}
								tres--;
							break;
							case 4:
								if (cuatro==0)
								{
									flag=1;
									break;
								}
								cuatro--;
							break;
							case 5:
								if (cinco==0)
								{
									flag=1;
									break;
								}
								cinco--;
							break;
							case 6:
								if (seis==0)
								{
									flag=1;
									break;
								}
								seis--;
							break;
							case 7:
								if (siete==0)
								{
									flag=1;
									break;
								}
								siete--;
							break;
							case 8:
								if (ocho==0)
								{
									flag=1;
									break;
								}
								ocho--;
							break;
							case 9:
								if (nueve==0)
								{
									flag=1;
									break;
								}
								nueve--;
							break;
							case 10:
								if (diez==0)
								{
									flag=1;
									break;
								}
								diez--;
							break;
							case 11:
								if (j==0)
								{
									flag=1;
									break;
								}
								j--;
							break;
							case 12:
								if (q==0)
								{
									flag=1;
									break;
								}
								q--;
							break;
							case 13:
								if (k==0)
								{
									flag=1;
									break;
								}
								k--;
							break;
						}
					}
					while(flag==1);
					c4++;
				}
				else
					set4=1;

			case 3:
				if (sumacp3<=17 || c3==5)
				{
					do
					{
						cp3[c3]= 1 + rand() % 13;
						flag=0;
						switch(cp3[c3])
						{
							case 1:
								if (a==0)
								{
									flag=1;
									break;
								}
								a--;
							break;
							case 2:
								if (dos==0)
								{
									flag=1;
									break;
								}
								dos--;
							break;
							case 3:
								if (tres==0)
								{
									flag=1;
									break;
								}
								tres--;
							break;
							case 4:
								if (cuatro==0)
								{
									flag=1;
									break;
								}
								cuatro--;
							break;
							case 5:
								if (cinco==0)
								{
									flag=1;
									break;
								}
								cinco--;
							break;
							case 6:
								if (seis==0)
								{
									flag=1;
									break;
								}
								seis--;
							break;
							case 7:
								if (siete==0)
								{
									flag=1;
									break;
								}
								siete--;
							break;
							case 8:
								if (ocho==0)
								{
									flag=1;
									break;
								}
								ocho--;
							break;
							case 9:
								if (nueve==0)
								{
									flag=1;
									break;
								}
								nueve--;
							break;
							case 10:
								if (diez==0)
								{
									flag=1;
									break;
								}
								diez--;
							break;
							case 11:
								if (j==0)
								{
									flag=1;
									break;
								}
								j--;
							break;
							case 12:
								if (q==0)
								{
									flag=1;
									break;
								}
								q--;
							break;
							case 13:
								if (k==0)
								{
									flag=1;
									break;
								}
								k--;
							break;
						}
					}
					while(flag==1);
					c3++;
				}
				set3=1;

			case 2:
				if (sumacp2<=17 || sumacp2)
				{
					do
					{
						cp2[c2]= 1 + rand() % 13;
						flag =0;
						switch(cp2[c2])
						{
							case 1:
								if (a==0)
								{
									flag=1;
									break;
								}
								a--;
							break;
							case 2:
								if (dos==0)
								{
									flag=1;
									break;
								}
								dos--;
							break;
							case 3:
								if (tres==0)
								{
									flag=1;
									break;
								}
								tres--;
							break;
							case 4:
								if (cuatro==0)
								{
									flag=1;
									break;
								}
								cuatro--;
							break;
							case 5:
								if (cinco==0)
								{
									flag=1;
									break;
								}
								cinco--;
							break;
							case 6:
								if (seis==0)
								{
									flag=1;
									break;
								}
								seis--;
							break;
							case 7:
								if (siete==0)
								{
									flag=1;
									break;
								}
								siete--;
							break;
							case 8:
								if (ocho==0)
								{
									flag=1;
									break;
								}
								ocho--;
							break;
							case 9:
								if (nueve==0)
								{
									flag=1;
									break;
								}
								nueve--;
							break;
							case 10:
								if (diez==0)
								{
									flag=1;
									break;
								}
								diez--;
							break;
							case 11:
								if (j==0)
								{
									flag=1;
									break;
								}
								j--;
							break;
							case 12:
								if (q==0)
								{
									flag=1;
									break;
								}
								q--;
							break;
							case 13:
								if (k==0)
								{
									flag=1;
									break;
								}
								k--;
							break;
						}
					}
					while(flag==1);
					c2++;
				}
				set2=1;
			//break;
			case 1:
				if (sumacp1<=17 || cp1==5)
				{
					do
					{
						cp1[c1]= 1 + rand() % 13;
						flag =0;
						switch(cp1[c1])
						{
							case 1:
								if (a==0)
								{
									flag=1;
									break;
								}
								a--;
							break;
							case 2:
								if (dos==0)
								{
									flag=1;
									break;
								}
								dos--;
							break;
							case 3:
								if (tres==0)
								{
									flag=1;
									break;
								}
								tres--;
							break;
							case 4:
								if (cuatro==0)
								{
									flag=1;
									break;
								}
								cuatro--;
							break;
							case 5:
								if (cinco==0)
								{
									flag=1;
									break;
								}
								cinco--;
							break;
							case 6:
								if (seis==0)
								{
									flag=1;
									break;
								}
								seis--;
							break;
							case 7:
								if (siete==0)
								{
									flag=1;
									break;
								}
								siete--;
							break;
							case 8:
								if (ocho==0)
								{
									flag=1;
									break;
								}
								ocho--;
							break;
							case 9:
								if (nueve==0)
								{
									flag=1;
									break;
								}
								nueve--;
							break;
							case 10:
								if (diez==0)
								{
									flag=1;
									break;
								}
								diez--;
							break;
							case 11:
								if (j==0)
								{
									flag=1;
									break;
								}
								j--;
							break;
							case 12:
								if (q==0)
								{
									flag=1;
									break;
								}
								q--;
							break;
							case 13:
								if (k==0)
								{
									flag=1;
									break;
								}
								k--;
							break;
						}
					}
					while(flag==1);
					c1++;
				}
				else
					set1=1;				
				if(set!=1 || c==5)
				{
					if(ronda>2) //Selección de carta
					{
						do
						{
							printf("¿Quieres otra carta? \n0.-Si\n1.-No");
							scanf("%d", &set);
						}
						while(set!=1 && set!=0);
					}
					if (set==0)
					{
						do
						{
							p[c]= 1 + rand() % 13;
							flag=0;
							switch(p[c])
							{
								case 1:
									if (a==0)
									{
										flag=1;
										break;
									}
									a--;
								break;
								case 2:
									if (dos==0)
									{
										flag=1;
										break;
									}
									dos--;
								break;
								case 3:
									if (tres==0)
									{
										flag=1;
										break;
									}
									tres--;
								break;
								case 4:
									if (cuatro==0)
									{
										flag=1;
										break;
									}
									cuatro--;
								break;
								case 5:
									if (cinco==0)
									{
										flag=1;
										break;
									}
									cinco--;
								break;
								case 6:
									if (seis==0)
									{
										flag=1;
										break;
									}
									seis--;
								break;
								case 7:
									if (siete==0)
									{
										flag=1;
										break;
									}
									siete--;
								break;
								case 8:
									if (ocho==0)
									{
										flag=1;
										break;
									}
									ocho--;
								break;
								case 9:
									if (nueve==0)
									{
										flag=1;
										break;
									}
									nueve--;
								break;
								case 10:
									if (diez==0)
									{
										flag=1;
										break;
									}
									diez--;
								break;
								case 11:
									if (j==0)
									{
										flag=1;
										break;
									}
									j--;
								break;
								case 12:
									if (q==0)
									{
										flag=1;
										break;
									}
									q--;
								break;
								case 13:
									if (k==0)
									{
										flag=1;
										break;
									}
									k--;
								break;
							}
						}
						while(flag==1);
						c++;
					}
				}
		}
		if(ronda>=2) //Imprimir cartas
		{
			printf ("\nJugador\n");
			for (cpr=0; cpr<c;cpr++)
			{
				switch(p[cpr])
				{
					case 1:
						printf("A ");
					break;
					case 11:
						printf("J ");
					break;
					case 12:
						printf ("Q ");
					break;
					case 13:
						printf("K ");
					break;
					default:
						printf("%d ", p[cpr]);
					break;
				}
			}		//mano cp1
			printf ("\nCP1\n");
			for (cpr=1; cpr<c1;cpr++)
			{
				switch(cp1[cpr])
				{
					case 1:
						printf("A ");
					break;
					case 11:
						printf("J ");
					break;
					case 12:
						printf ("Q ");
					break;
					case 13:
						printf("K ");
					break;
					default:
						printf("%d ", cp1[cpr]);
					break;
				}
			}
			printf("?");
			printf ("\nCP2\n");
			for (cpr=1; cpr<c2;cpr++)
			{
				switch(cp2[cpr])
				{
					case 1:
						printf("A ");
					break;
					case 11:
						printf("J ");
					break;
					case 12:
						printf ("Q ");
					break;
					case 13:
						printf("K ");
					break;
					default:
						printf("%d ", cp2[cpr]);
					break;
				}
			}
			printf("?");
			printf ("\nCP3\n");
			for (cpr=1; cpr<c3;cpr++)
			{
				switch(cp3[cpr])
				{
					case 1:
						printf("A ");
						break;
					case 11:
						printf("J ");
						break;
					case 12:
						printf ("Q ");
						break;
					case 13:
						printf("K ");
						break;
					default:
						printf("%d ", cp3[cpr]);
					break;
				}
			}
			printf("?");
			printf ("\nCP4\n");
			for (cpr=1; cpr<c4;cpr++)
			{
				switch(cp4[cpr])
				{
					case 1:
						printf("A");
					break;
					case 11:
						printf("J");
					break;
					case 12:
						printf ("Q");
					break;
					case 13:
						printf("K");
					break;
					default:
						printf("%d ", cp4[cpr]);
					break;
				}
			}
			printf("?");
		}
		ronda++;
		sumap=sumas(p, c);
		sumacp1=sumas(cp1, c1);
		sumacp2=sumas(cp2, c2);
		sumacp3=sumas(cp3, c3);
		sumacp4=sumas(cp4, c4);
	}
	while(set!=1 || set1!=1 || set2!=1 || set3!=1 || set4!=1 );

	printf ("\nJugador\n");
	for (cpr=0; cpr<c;cpr++)
	{
		switch(p[cpr])
		{
			case 1:
				printf("A ");
			break;
			case 11:
				printf("J ");
			break;
			case 12:
				printf ("Q ");
			break;
			case 13:
				printf("K ");
			break;
			default:
				printf("%d ", p[cpr]);
				break;
		}
	}
	printf ("\nCP1\n");
	for (cpr=0; cpr<c1;cpr++)
	{
		switch(cp1[cpr])
		{
			case 1:
				printf("A ");
			break;
			case 11:
				printf("J ");
			break;
			case 12:
				printf ("Q ");
			break;
			case 13:
				printf("K ");
			break;
			default:
				printf("%d ", cp1[cpr]);
			break;
		}
	}
	printf ("\nCP2\n");
	for (cpr=0; cpr<c2;cpr++)
	{
		switch(cp2[cpr])
		{
			case 1:
				printf("A ");
			break;
			case 11:
				printf("J ");
			break;
			case 12:
				printf ("Q ");
			break;
			case 13:
				printf("K ");
			break;
			default:
				printf("%d ", cp2[cpr]);
			break;
		}
	}
	printf ("\nCP3\n");
	for (cpr=0; cpr<c3;cpr++)
	{
		switch(cp3[cpr])
		{
			case 1:
				printf("A ");
			break;
			case 11:
				printf("J ");
			break;
			case 12:
				printf ("Q ");
			break;
			case 13:
				printf("K ");
			break;
			default:
				printf("%d ", cp3[cpr]);
			break;
		}
	}
	printf ("\nCP4\n");
	for (cpr=0; cpr<c4;cpr++)
	{
		switch(cp4[cpr])
		{
			case 1:
				printf("A");
			break;
			case 11:
				printf("J");
			break;
			case 12:
				printf ("Q");
			break;
			case 13:
				printf("K");
			break;
			default:
				printf("%d ", cp4[cpr]);
			break;
		}
	}

	printf("Jugador: %d\nCP1: %d\nCP2: %d\nCP3: %d\nCP4: %d\n", sumap, sumacp1, sumacp2, sumacp3, sumacp4);
	if(sumap>21)
		sumap=0;
	if(sumacp1>21)
		sumacp1=0;
	if(sumacp2>21)
		sumacp2=0;
	if(sumacp3>21)
		sumacp3=0;
	if(sumacp4>21)
		sumacp4=0;

	if(sumap>sumacp1 && sumap>sumacp2 && sumap>sumacp3 && sumap>sumacp4 && sumap<=21)
		return 1;
	if(sumacp1>sumap && sumacp1>sumacp2 && sumacp1>sumacp3 && sumacp1>sumacp4 && sumacp1<=21)
		return 2;
	if(sumacp2>sumap && sumacp2>sumacp1 && sumacp2>sumacp3 && sumacp2>sumacp4 && sumacp2<=21)
		return 3;
	if(sumacp3>sumap && sumacp3>sumacp2 && sumacp3>sumacp1 && sumacp3>sumacp4 && sumacp3<=21)
		return 4;
	if(sumacp4>(sumap<=21) && sumacp4>sumacp2 && sumacp4>sumacp3 && sumacp4>sumacp1 && sumacp4<=21)
		return 5;
	else
		return 0;
}
int sumas(int a[5], int c)
{
	int suma=0, i, j, ca=0;
	for (j=0;j<c;j++)
	{					//Para ver si hay As;
		if (a[j]==1)
			ca++;
	}
	if(ca)
	{
		for(i=0;i<c;i++)
		{
			if (a[i]>10)
			{
			suma+=10;
			}
			else
				suma+=a[i];
		}
		suma-=ca;
		switch(ca)
		{
			case 1:
				if (suma<=10)
					suma+=11;
				else
					suma+=ca;
			break;
			case 2:
				if (suma<=9)
				{
					suma+=11;
					suma+=1;
				}
				else
					suma+=ca;
			break;
			case 3:
				if (suma<=8)
				{
					suma+=11;
					suma+=2;
				}
				else
					suma+=ca;
			break;
			case 4:
				if (suma<=7)
				{
					suma+=11;
					suma+=3;
				}
				else
					suma+=ca;
			break;
		}
	}
	else
	{
		for(i=0;i<c;i++)
		{
			if (a[i]>10)
			{
				suma+=10;
			}
			else
				suma+=a[i];
		}
	}
	return suma;
}

