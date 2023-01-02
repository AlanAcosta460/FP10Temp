//Calculadora de vectores y matrices

#include <stdio.h> //Biblioteca estandar
#include <stdlib.h> //Para usar la funcion system()
#include <math.h>

//Menus
int pedirOpcion(int opMax)
{
    int op;
    
    fflush(stdin);
    do
    { 
        printf("-> "); scanf("%d", &op);
        if (op < 1)
            printf("Opcion invalida");
        else if (op > opMax)
            printf("Opcion invalida. El maximo es %d\n", opMax);
        printf("\n");
    } while (op < 1 || op > opMax);
    fflush(stdin);

    return op;
}
int menuPrincipal()
{
    system("cls");
    printf("***************MENU PRINCIPAL***************\n");
    printf(".:Operaciones con Vectores:.\n");
    printf("1)  Suma de vectores\n");
    printf("2)  Resta de vectores\n");
    printf("3)  Producto de un vector por un escalar\n");
    printf("4)  Producto escalar\n");
    printf("5)  Producto vectorial\n");
    printf("6)  Producto mixto\n\n");
    printf(".:Operaciones con Matrices:.\n");
    printf("7)  Suma de matrices\n");
    printf("8)  Resta de matrices\n");
    printf("9)  Producto de una matriz por un escalar\n");
    printf("10) Producto de matrices\n");
    printf("11) Traza de una matriz\n");
    printf("12) Transpuesta de una matriz\n");
    printf("13) Inversa de una matriz\n\n");
    printf("14) Mostrar Caratula\n");
    printf("15) Salir\n\n");

    printf(".:Seleccione una opcion:.\n");
    return pedirOpcion(15);
}
int menuRetorno()
{
    printf("\n\n***************MENU DE RETORNO***************\n");
    printf("1)  Repetir operacion\n");
    printf("2)  Volver al menu principal\n");
    printf("3)  Salir\n\n");

    printf(".:Seleccione una opcion:.\n");
    return pedirOpcion(3);
}

//Caratula
void caratula()
{
    FILE *archivo;
    char caracter;

    archivo = fopen("Caratula.txt", "r");
    if (archivo == NULL)
        printf("Error al abrir el archivo");
    else
    {
        while ((caracter = fgetc(archivo)) != EOF)
            printf("%c", caracter);
        fclose(archivo);
    }
}

//Pedir y Mostrar Datos
void pedirVec(float vec[], int tam)
{
    printf(".:Ingrese los valores:.\n");
    for (int i = 0; i < tam; i ++)
    {
        printf("%d: ", i + 1);
        scanf("%f", &vec[i]);
    }
}
void mostrarVec(float vec[], int tam)
{
    printf("\n.:Resultado:.\n");
    for (int i = 0; i < tam; i++)
        printf("%.1f\t", vec[i]);
    printf("\n");
}
void pedirMat(float mat[][10], int fil, int col)
{
    printf(".:Ingrese los valores:.\n");
    for (int i = 0; i < fil; i ++)
    {
        for (int j = 0; j < col; j ++)
        {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
        printf("\n");
    }
}
void mostrarMat(float mat[][10], int fil, int col)
{
    printf(".:Resultado:.\n");
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j ++)
        {
            printf("%.1f\t", mat[i][j]);
        }
        printf("\n");
    }
}

//Operaciones con Vectores
void sumaVec()
{
    float vec1[100], vec2[100];
    int tam;

    system("cls");
    printf("***************SUMA DE VECTORES***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de elementos de los vectores:.\n"); 
    tam = pedirOpcion(100);
    printf(".:Vector 1:.\n");
    pedirVec(vec1, tam);
    printf("\n.:Vector 2:.\n");
    pedirVec(vec2, tam);

    //el resultado se guardara en el vector 1
    for (int i = 0; i < tam; i ++)
        vec1[i] += vec2[i];
    
    //mostrando el resultado
    mostrarVec(vec1, tam);
}
void restaVect()
{
    float vec1[100], vec2[100];
    int tam;

    system("cls");
    printf("***************RESTA DE VECTORES***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de elementos de los vectores:.\n"); 
    tam = pedirOpcion(100);
    printf(".:Vector 1:.\n");
    pedirVec(vec1, tam);
    printf("\n.:Vector 2:.\n");
    pedirVec(vec2, tam);
    
    printf("\n1. Vector 1 - Vector 2\n");
    printf("2. Vector 2 - Vector 1\n\n");
    printf(".:Seleccione una opcion:.\n");
    
    if (pedirOpcion(2) == 1)
    {
        //el resultado se guardara en el vector 1
        for (int i = 0; i < tam; i ++)
            vec1[i] -= vec2[i];
        //mostrando el resultado
        mostrarVec(vec1, tam);
    }
    else
    {
        //el resultado se guardara en el vector 2
        for (int i = 0; i < tam; i ++)
            vec2[i] -= vec1[i];
        //mostrando el resultado
        mostrarVec(vec2, tam);
    }
}
void vecPorEscalar()
{
    float vec[100], escalar;
    int tam;

    system("cls");
    printf("***************VECTOR POR ESCALAR***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de elementos de del vector:.\n"); 
    tam = pedirOpcion(100);
    printf(".:Vector:.\n");
    pedirVec(vec, tam);
    
    printf("\n.:Escalar.:\n -> ");
    scanf("%f", &escalar);
    
    //multiplicacion
    for (int i = 0; i < tam; i++)
        vec[i] *= escalar;

    //mostrando el resultado
    mostrarVec(vec, tam);
}
void proEscalar()
{
    float vec1[100], vec2[100], resultado = 0;
    int tam;

    system("cls");
    printf("***************PRODUCTO ESCALAR***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de elementos de los vectores:.\n"); 
    tam = pedirOpcion(100);
    printf(".:Vector 1:.\n");
    pedirVec(vec1, tam);
    printf("\n.:Vector 2:.\n");
    pedirVec(vec2, tam);

    //prducto escalar
    for (int i = 0; i < tam; i ++)
        resultado += vec1[i] * vec2[i];
    
    //mostrando el resultado
    printf("\n\n.:Resultado:.\n%.1f", resultado);
}
void proVectorial()
{
    float vec1[3], vec2[3], vecRes[3];

    system("cls");
    printf("***************PRODUCTO VECTORIAL EN TRES DIMENSIONES***************\n\n");
    //pidiendo datos
    printf(".:Vector 1:.\n");
    pedirVec(vec1, 3);
    printf("\n.:Vector 2:.\n");
    pedirVec(vec2, 3);

    //prducto vectorial
    vecRes[0] = (vec1[1] * vec2[2]) - (vec1[2] * vec1[1]);
    vecRes[1] = (- 1) * ((vec1[0] * vec2[2]) - (vec1[2] * vec2[0]));
    vecRes[2] = (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]);
    
    //mostrando el resultado
    mostrarVec(vecRes, 3);
}
void proMixto()
{
    float vec1[3], vec2[3], vec3[3], vecAux[3], resultado = 0;

    system("cls");
    printf("***************PRODUCTO MIXTO EN TRES DIMENSIONES***************\n\n");
    //pidiendo datos
    printf(".:Vector 1:.\n");
    pedirVec(vec1, 3);
    printf("\n.:Vector 2:.\n");
    pedirVec(vec2, 3);
    printf("\n.:Vector 3:.\n");
    pedirVec(vec3, 3);

    //prducto vectorial
    vecAux[0] = (vec2[1] * vec2[2]) - (vec2[2] * vec3[1]);
    vecAux[1] = (- 1) * ((vec2[0] * vec3[2]) - (vec2[2] * vec3[0]));
    vecAux[2] = (vec2[0] * vec3[1]) - (vec2[1] * vec3[0]);
    
    //producto escalar
    for (int i = 0; i < 3; i ++)
        resultado += vec1[i] * vecAux[i];
    
    //mostrando el resultado
    printf("\n\n.:Resultado:.\n%.1f", resultado);
}

//Operacions con Matrices
void sumaMat()
{
    float mat1[10][10], mat2[10][10];
    int fil, col;

    system("cls");
    printf("***************SUMA DE MATRICES***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de filas de las matrices:.\n");
    fil = pedirOpcion(10);
    printf(".:Ingrese el numero de columnas de las matrices:.\n");
    col = pedirOpcion(10);
    printf(".:Matriz 1:.\n");
    pedirMat(mat1, fil, col);
    printf(".:Matriz 2:.\n");
    pedirMat(mat2, fil, col);

    //el resultado de la suma se guarda en la matriz 1
    for (int i = 0; i < fil; i ++)
    {
        for (int j = 0; j < col; j ++)
            mat1[i][j] += mat2[i][j];
    }

    //mostrando el resultado
    mostrarMat(mat1, fil, col);
}
void restaMat()
{
    float mat1[10][10], mat2[10][10];
    int fil, col;

    system("cls");
    printf("***************RESTA DE MATRICES***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de filas de las matrices:.\n");
    fil = pedirOpcion(10);
    printf(".:Ingrese el numero de columnas de las matrices:.\n");
    col = pedirOpcion(10);
    printf(".:Matriz 1:.\n");
    pedirMat(mat1, fil, col);
    printf(".:Matriz 2:.\n");
    pedirMat(mat2, fil, col);
    
    printf("1. Matriz 1 - Matriz 2\n");
    printf("2. Matriz 2 - Matriz 1\n\n");
    printf(".:Seleccione una opcion:.\n");
    
    if (pedirOpcion(2) == 1)
    {
        //el resultado se guardara en la matriz 1
        for (int i = 0; i < fil; i ++)
        {
            for (int j = 0; i < col; i ++)
                mat1[i][j] -= mat2[i][j];
        }  
        //mostrando el resultado
        mostrarMat(mat1, fil, col);
    }
    else
    {
        //el resultado se guardara en la matriz 2
        for (int i = 0; i < fil; i ++)
        {
            for (int j = 0; i < col; i ++)
                mat2[i][j] -= mat1[i][j];
        }  
        //mostrando el resultado
        mostrarMat(mat2, fil, col);
    }
}
void matPorEscalar()
{
    float mat[10][10], escalar;
    int fil, col;

    system("cls");
    printf("***************MATRIZ POR ESCALAR***************\n\n");
    //pidiendo datos
    printf(".:Ingrese el numero de filas de la matriz:.\n");
    fil = pedirOpcion(10);
    printf(".:Ingrese el numero de columnas de la matriz:.\n");
    col = pedirOpcion(10);
    printf(".:Matriz:.\n");
    pedirMat(mat, fil, col);
    printf(".:Escalar.:\n -> ");
    scanf("%f", &escalar);
    
    //multiplicacion
    for (int i = 0; i < fil; i ++)
    {
        for (int j = 0; j < col; j ++)
            mat[i][j] *= escalar;
    }

    //mostrando el resultado
    mostrarMat(mat, fil, col);
}
void productoMat()
{
    float mat1[10][10], mat2[10][10], matRes[10][10];
    int fil1, col1, fil2, col2;

    system("cls");
    printf("***************PRODUCTO DE MATRICES***************\n\n");
    //pidiendo datos
    do
    {    
        printf(".:Ingrese el numero de filas de la matriz 1:.\n");
        fil1 = pedirOpcion(10);
        printf(".:Ingrese el numero de columnas de la matriz 1:.\n");
        col1 = pedirOpcion(10);
        printf("\n.:Ingrese el numero de filas de la matriz 2:.\n");
        fil2 = pedirOpcion(10);
        printf(".:Ingrese el numero de columnas de la matriz 2:.\n");
        col2 = pedirOpcion(10);
        if (col1 != fil2)
            printf("\nEl no. de columnas de la matriz 1 debe ser igual al no. de filas de la matriz 2\n");
        printf("\n");
    } while (col1 != fil2);

    printf(".:Matriz 1:.\n");
    pedirMat(mat1, fil1, col1);
    printf(".:Matriz 2:.\n");
    pedirMat(mat2, fil2, col2);

    // el resultado se guardara en matRes
    for (int i = 0; i < fil1; i++)
    {
        for (int j = 0; i < col2; i++)
            matRes[i][j] = mat1[i][j] * mat2[j][i];
    }

    // mostrando el resultado
    mostrarMat(matRes, fil2, col2);
}
void traza()
{
    float mat[10][10], traza = 0;
    int tam;

    system("cls");
    printf("***************TRAZA DE UNA MATRIZ CUADRADA***************\n\n");
    printf(".:Ingrese el numero de filas y columnas de la matriz cuadrada:.\n");
    tam = pedirOpcion(10);
    printf(".:Matriz:.\n");
    pedirMat(mat, tam, tam);

    for (int i = 0; i < tam; i ++)
    {
        for (int j = 0; j < tam; j ++)
        {
            if (i == j)
                traza += mat[i][j];
        }
    }

    printf("\n.:Resultado:.\n%.1f", traza);
}
void transpuesta()
{
    float mat[10][10];
    int fil, col;

    system("cls");
    printf("***************TRANSPUESTA DE UNA MATRIZ***************\n\n");
    printf(".:Ingrese el numero de filas de la matriz:.\n");
    fil = pedirOpcion(10);
    printf(".:Ingrese el numero de columnas de la matriz:.\n");
    col = pedirOpcion(10);
    printf(".:Matriz:.\n");
    pedirMat(mat, fil, col);

    printf("\n.:Resultado:.\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < fil; j ++)
        {
            printf("%.1f\t", mat[j][i]);
        }
        printf("\n");
    }
}
//funcion recursiva para sacar el determinante
float determinante(float mat[10][10], int tam)
{
    float det = 0;
    if (tam == 2)
    {
        det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else
    {
        for (int i = 0; i < tam; i ++)
        {
            det += pow(- 1, i) * mat[0][i] * determinante(mat, tam - 1);
        }
    }

    return det;
}
void inversa()
{
    //inversa de una matriz cuadrada
    float mat[10][10], det;
    int tam;

    system("cls");
    printf("***************INVERSA DE UNA MATRIZ CUADRADA***************\n\n");
    printf(".:Ingrese el numero de filas y columnas de la matriz cuadrada:.\n");
    tam = pedirOpcion(10);
    printf(".:Matriz:.\n");
    pedirMat(mat, tam, tam);

    
}

int main()
{
    int opcion;
    
    inicio:
    opcion = menuPrincipal();

    seleccion:
    switch (opcion)
    {
        case 1: sumaVec(); break;
        case 2: restaVect(); break;
        case 3: vecPorEscalar(); break;
        case 4: proEscalar(); break;
        case 5: proVectorial(); break;
        case 6: proMixto(); break;
        case 7: sumaMat(); break;
        case 8: restaMat(); break;
        case 9: matPorEscalar(); break;
        case 10: productoMat(); break;
        case 11: traza(); break;
        case 12: transpuesta(); break;
        case 13: inversa(); break;
        case 14: caratula(); break;
        default: goto salir; break;
    }

    switch (menuRetorno())
    {
        case 1: goto seleccion; break;
        case 2: goto inicio; break;
        default: break;
    }

    salir:
    printf("\nGracias por usar el programa!!!\n\n");
    system("pause");

    return 0;
}