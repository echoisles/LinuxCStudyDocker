#include <stdio.h>
/* main: generate some simple output */
int main(void)
{
    printf("character: %c\ninteger: %d\nfloating point: %f\n", '}',
    34, 3.14);

    // char firstletter;
    int hour, minute;
    // firstletter = 'a'; /* give firstletter the value 'a' */
    hour = 11; /* assign the value 11 to hour */
    minute = 59; /* set minute to 59 */
    printf("Current time is %d:%d", hour, minute);
    return 0;
}