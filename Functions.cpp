#include "Header.h"

void printEl(int a, bool b) {
   /// b = true;
    if (b && (a == -2 || a == 10)) //10 zastava, mina
        printf("@\t");
    else if (a < 0)
        printf("#\t");
    else if (a > 8) //9 zastava, nema mine
        printf("/\t");
    else 
        printf("%d\t", a);
}

void printMatrix(int a[][DIM], bool b) {
    int i, j;
    for (i = 0; i <= DIM; i++)
    {
        for (j = 0; j <= DIM; j++)
        {
            if (i == 0)
                j == 0 ? printf("i/j\t") : printf("j=%d\t", j - 1);
            else
            {
                if (j == 0)
                    printf("i=%d\t", i - 1);
                else
                    printEl(a[i - 1][j - 1], b);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void guess(int a[][DIM], int* f) {
    printf("p - probaj, z - zastava\n");
    char c;
    char s1, s2;
    int i, j;
    cin >>c >> i >> j;
    if (!cin)
        return;

   /* scanf_s("%c", &c);
    scanf_s("%c", &s1);
    scanf_s("%c", &s2);
    //printf("%c %i %i", c, i, j);
    if (!(isdigit(s1) && isdigit(s2)))
    {
        printf(";mao=\n");
        return;
    }
    i = s1 - '0', j = s2 - '0';*/
    //int i1 = i - '0', j1 = j - '0';
    if (i >= DIM || i < 0 || j < 0 || j >= DIM || (c != 'z' && c != 'p') )
    {
        printf("ne moze :( \n");
        return;
    }
    
    if (c == 'z')
        a[i][j] = a[i][j] == -2 ? 10 : 9;
    else
    {
        if (a[i][j] == -2)
            gameOver(a);
        surroundingEl(a, i, j, f);
    }
    }

void gameOver(int a[][DIM]) {
    printMatrix(a, true);
    fprintf(stderr, ":( poraz\n");
    cin.ignore();
    cin.ignore();
    exit(EXIT_FAILURE);
}

void initializeMatrix(int a[][DIM], int m) {
    int i, j;
    fill(*a, *a + DIM * DIM, -1);
    while (m--)
    {
        
        i = rand() % DIM,  j = rand() % DIM;
        //printf("%d %d\n", i, j);
        if (a[i][j] == -2)
            m++;
        a[i][j] = -2;
    }
}

void surroundingEl(int a[][DIM], int i, int j, int *f) {
    int s = 0;
    for(int p = i - 1; p <= i + 1; p++)
        for (int q = j - 1; q <= j + 1; q++)
            if (!(p < 0 || q < 0 || q >= DIM || p >= DIM) && (a[p][q] == -2 || a[p][q] == 10))     
                s++;

   a[i][j] = s;

   if (a[i][j] == 0)
   {
       for (int p = i - 1; p <= i + 1; p++)
           for (int q = j - 1; q <= j + 1; q++)
               if (!(p < 0 || q < 0 || p >= DIM || q >= DIM || (p == i && q == j) || a[p][q] >= 0))       
                   surroundingEl(a, p, q, f);
   }
   (*f)--;
  // printf("lmao evo ga f %d\n", *f);
}

/*int remaining(int a[][DIM]) {
    int r = 0;
    for (int i = 0; i <= DIM; i++)
        for (int j = 0; j <= DIM; j++)
            if (a[i][j] == -1 || a[i][j] == 9)
                r++;
    return r;
}*/