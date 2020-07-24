#pragma GCC optimize("O0")
#include <stdio.h>
#include <unistd.h>

int
main()
{
    fprintf(stderr, "Welcome to echo, live edition!\n");
    fprintf(stderr, "Enter something and this program will repeat it.\n");
    char something_secret[64] = "Testing test";
    // FILE *f = fopen("flag", "r");
    // if (f == NULL)
    //   {
    //     fprintf(stderr, "Failed to open flag file.\n");
    //     return 1;
    //   }
    // fgets(something_secret, 64, f);

    char data[64] = {0};
    ll
    printf("flag address: %d\n", something_secret);
    printf("data address: %d\n", data);
    
    read(0, data, 63);

    // printf("Testing: %c%c%c%c%c%c\n", data[64],data[65],data[66],data[67],data[68],data[69]);

    // printf("Testing: %c%c%c%c%c%c\n", data[0],data[1],data[2],data[3],data[4],data[5]);
    fprintf(stderr, data);

    scanf("%d");
    return 0;
}
