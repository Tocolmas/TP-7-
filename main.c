# include <stdio.h>
# include <conio.h>
#include <string.h>
# include <stdlib.h>



/* Exercice 1 */

all : main()

void main ()
{
    int a;
    int b;
    printf ("enter the first number\n");
    scanf("%d",&a);
    printf("enter the second number\n");
    scanf("%d", &b);

    if (a < b)
    {
        int temp;
        temp = a;
        a = b;
    }

    int r;
    int q;
    int result;

    if (a%b == 0)
    {
        result = b;
    }
    else
    {
        while (r != 0)
        {
            result = r;
            q = a/b;
            r= a%b;
            printf ("%d // %d = %d reste %d\n", a,b,q,r);
            a = b;
            b = r;
        }
    }
    printf("result :%d = %d reste %d\n", a,b,q,r);
}

/* Exercice 2 */


void main (void) {

    int number;
    int sum;
    printf ("Choose a number\n",);
    scanf ("´%d", &number);

    if (number <= 0)
    {
        sum = 0;
        printf ("Sum is %d\n", sum);
    }
    else
    {
        if (number%%2 == 0)
        {
            number = number - 1;
        }
        sum = 0;

        while (number > 0)
        {
            sum = sum + number;
            number = number - 2;
        }
    }
    printf ("Sum is %d\n", sum);
}


/* Exercice 3 */

int main() {

    int terms
    int number1
    int number2
    int next
    int i

    printf ("Entrez le nombres de termes souhaités\n");
    scanf ("%d, &n");

    printf ("Les %d premiers termes de la série de Fibonacci sont :\n",n);

    for (i =0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = number1 + number2;
            number1 = number2;
            number2 = next
        }
    }
    printf ("%d\n", next);
}

/* Exercice 4 */

main () {

    int b, Facto, i;

    printf ("Enter a number\n");
    scanf("%d", &b);

    Facto = 1;

    for (i=1; i<=b; i+=1)
    {
        Facto = Facto*i;
    }
    printf ("Le factoriel de %d est %d\n", b,Facto)
}

/* Exercice 5 */

int pgcd(int number1, int number2) {

    if (number2 != 0)
        return pgcd(number2, number1%number2);
    else
        return number1;
}

int main() {

    int number1, number2;

    printf ("Entrez deux entiers : ");
    scanf ("%d %d", &number1, &number2);

    printf ("Le PGCD de %d et %d = %d", number1, number2);
pgcd(number1, number2);
    return 0;
}

/* Exercice 6 */

int length(char * s)
// Check the legnth of a string and returns the length
{
    int len;
    length = 0;

    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

int palin(char * s, int 1)
// Check whether a sting of a given length is a palindrome or not. If it's true then returns 1, else returns 0
{
    int head, tail;
    int i;

    for (i=0; i<1/2; i++)
    {
        head = i;
        tail = l-i-1;

        if (s[head] != s[tail])
        {
            return 0;
        }
    }
    return 1;
}

int main (void)
{
    int length, is_palin;
    char string[256]

    printf ("Enter a sting : \n");
    scanf ("%s", string);
    length = len(sting);
    printf ("Length is %d\n", length);
    is_palin = pal(string, length);

    if (is_palin == 1)
    {
        printf ("String : '%s', is a palindrome\n", string);
    }
    else
    {
        printf ("String : '%s', is not a palindrome\n", string);
    }
    return is_palin;
}

/* Exercice 7 */

int strlen(char s[])
{
    int i;
    i=0;

    while(s[i] != '\0')
        ++i;
        return i;
}

int num_occur (char* chaine? char car)
{
    int c, num_occur = 0;
    size = strlen(chaine);

    for (c = 0; c < size; c++)
    {
        if (chaine[c] == car)
        num_occur ++;
    }
    return num_occur;
}

int main ()
{
    int result = strlen("jnfrjnergned");
    printf ("the length of the word is %i\n,"result);
    return 0;
}

int main(void)
{
    char maChaine[] : "Bonjour tout le monde";
    int number = num_occur(maChaine, 's');
    printf("La chaine : 's' contient %d fois le caractère 's'.\n", maChaine, number);
    return 0;
}

/* Exercice 8 */

int main()
{
    char string[1000], sub[1000];
    int position, length, c = 0;

    printf ("Enter a string\n");
    gets(string);

    printf ("Enter the length and position of substring\n");
    scanf ("%d%d", &postion, &length);

    while (c < length)
    {
        sub[c] = string[position+c-1];
        c++;
    }
    sub[c] = '\0';
    printf ("Requested substring is \"%s\"\n", sub);
    return 0
}
