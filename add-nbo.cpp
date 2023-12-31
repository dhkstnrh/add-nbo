#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

FILE *fp1, *fp2;
uint32_t num1, num2;

int main(int argc, char *argv[]) {

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    fread(&num1, sizeof(num1), 1, fp1);
    fread(&num2, sizeof(num2), 1, fp2);

    num1 = ntohl(num1); 
    num2 = ntohl(num2);  

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}


