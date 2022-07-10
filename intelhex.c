#include <stdio.h>
#include <math.h>
#include <string.h>

int prevodnik(char hex1, char hex2)
{
    long long decimal = 0;
    int i = 0, hodnota = 0, dlzka = 1;
    char hex[3] = {'\0'};

    hex[0] = hex1;
    hex[1] = hex2;

    for (i = 0; ((hex[i] != '\0') && (i < 2)); i++)
    {

        if (hex[i] >= '0' && hex[i] <= '9')
        {
            hodnota = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            hodnota = hex[i] - 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            hodnota = hex[i] - 65 + 10;
        }

        decimal += hodnota * pow(16, dlzka);
        dlzka--;
    }

    return decimal;
}

int main()
{
    int pozicia = 0;
    int counter = 0;
    char intelHex[100];
    int dlzka_dat = 0;
    int checksum = 0;

    printf("Zadaj intelHex: ");
    scanf("%s", intelHex);

    while (':' == intelHex[pozicia])
    {
        pozicia++;
    }

    dlzka_dat = prevodnik(intelHex[pozicia], intelHex[pozicia + 1]);
    checksum = dlzka_dat;
    pozicia += 2;
    checksum = checksum + prevodnik(intelHex[pozicia], intelHex[pozicia + 1]);
    pozicia += 2;
    checksum = checksum + prevodnik(intelHex[pozicia], intelHex[pozicia + 1]);
    pozicia += 2;
    checksum = checksum + prevodnik(intelHex[pozicia], intelHex[pozicia + 1]);
    pozicia += 2;

    while (counter < dlzka_dat)
    {
        counter++;
        checksum = checksum + prevodnik(intelHex[pozicia], intelHex[pozicia + 1]);
        pozicia += 2;
    }
    checksum = checksum & 255;
    checksum = 255 - checksum;
    checksum += 1;
    printf("checksum je: %x ", checksum);

    printf("\nZadane cislo je %s\n", intelHex);
    printf("\nCislo v desiatkovej sustave je  %lld", prevodnik(intelHex[0], intelHex[1]));

    return 0;
}