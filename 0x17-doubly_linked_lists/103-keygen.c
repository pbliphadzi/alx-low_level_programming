#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 6
#define XOR_CONSTANT 14
#define USERNAME_MAGIC 59
#define ADDITION_MAGIC 79
#define MULTIPLICATION_MAGIC 85
#define MAX_USERNAME_LENGTH 100

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    unsigned int i;
    size_t len, add, b;
    char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
    char key[KEY_LENGTH + 1]; // +1 for the null-terminator

    len = strlen(argv[1]);
    add = 0;
    b = 1;

    for (i = 0; i < len; i++)
    {
        add += argv[1][i];
        b *= argv[1][i];
    }

    char max_char = argv[1][0];
    for (i = 0; i < len; i++)
    {
        if (max_char <= argv[1][i])
        {
            max_char = argv[1][i];
        }
    }

    srand(max_char ^ XOR_CONSTANT);

    unsigned int square_sum = 0;
    for (i = 0; i < len; i++)
    {
        square_sum += argv[1][i] * argv[1][i];
    }

    snprintf(key, sizeof(key), "%c%c%c%c%c%c",
             charset[(len ^ USERNAME_MAGIC) & 63],
             charset[(add ^ ADDITION_MAGIC) & 63],
             charset[(b ^ MULTIPLICATION_MAGIC) & 63],
             charset[rand() & 63],
             charset[(square_sum ^ 239) & 63],
             charset[(rand() ^ 229) & 63]);

    printf("%s\n", key);

    return 0;
}
