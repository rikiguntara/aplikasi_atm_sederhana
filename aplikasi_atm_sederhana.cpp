#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(char names[][50], char banks[][50], int pin[], int *currentUser)
{
    int enteredPin;
    char name[50];
    int isLoginSuccess = 0;

    do
    {
        printf("Masukkan PIN (6 Digit): ");
        scanf("%d", &enteredPin);
        if (enteredPin >= 100000 && enteredPin <= 999999)
        {
            int isPinCorrect = 0;
            for (int i = 0; i < 3; i++)
            {
                if (enteredPin == pin[i])
                {
                    isPinCorrect = 1;
                    if (strcmp(banks[i], "BCA") == 0)
                    {
                        strcpy(name, names[i]);
                        *currentUser = i;
                        system("clear");
                        printf("Selamat datang %s\n", name);
                        isLoginSuccess = 1;
                        break;
                    }
                    else
                    {
                        printf("Mohon maaf, hanya pengguna BCA yang dapat menggunakan ATM ini.\n");
                        *currentUser = -1;
                    }
                }
            }
            if (!isPinCorrect)
            {
                printf("PIN salah!\n");
            }
        }
        else
        {
            printf("PIN harus 6 digit!\n");
        }
    } while (!isLoginSuccess);
}

void checkBalance(char names[][50], double balances[], int currentUser)
{
    system("clear");
    printf("Saldo Anda: Rp. %.2f\n", balances[currentUser]);
    printf("\n\nKetuk apapun untuk kembali.");
    getchar();
    getchar();
    system("clear");
}

void deposit(double balances[], int currentUser)
{
    double amount;
    printf("Masukkan jumlah setoran: Rp. ");
    scanf("%lf", &amount);
    balances[currentUser] += amount;
    printf("Setoran berhasil! Saldo Anda sekarang: Rp. %.2f\n", balances[currentUser]);
    printf("\n\nKetuk apapun untuk kembali.");
    getchar();
    getchar();
    system("clear");
}

void changePin(int pin[], int currentUser)
{
    int newPin;
    printf("Masukkan PIN baru (6 Digit): ");
    scanf("%d", &newPin);
    if (newPin >= 100000 && newPin <= 999999)
    {
        pin[currentUser] = newPin;
        printf("PIN berhasil diubah!\n");
    }
    else
    {
        printf("PIN harus 6 digit!\n");
    }
    printf("\n\nKetuk apapun untuk kembali.");
    getchar();
    getchar();
    system("clear");
}

int main()
{
    char names[3][50] = {"Giri", "Riki", "Hilmi"};
    char banks[3][50] = {"BCA", "BRI", "BCA"};
    double balances[3] = {3500000, 2500000, 10000000};
    int pin[3] = {111111, 222222, 333333};
    int currentUser = -1;
    int choice;
    bool isExit = false;

    login(names, banks, pin, &currentUser);

    if (currentUser == -1)
    {
        printf("Program diberhentikan.\n");
        return 0;
    }

    while (isExit == false)
    {
        printf("Pilih yang Anda ingin lakukan:\n");
        printf("1. Cek Saldo\n");
        printf("2. Tarik Tunai\n");
        printf("3. Setor Tunai\n");
        printf("4. Transfer\n");
        printf("5. Ubah PIN\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            checkBalance(names, balances, currentUser);
        }
        else if (choice == 2)
        {
            // TARIK TUNAI
        }
        else if (choice == 3)
        {
            // SETOR TUNAI
            deposit(balances, currentUser);
        }
        else if (choice == 4)
        {
            // TRANSFER
        }
        else if (choice == 5)
        {
            // UBAH PIN
            changePin(pin, currentUser);
        }
        else if (choice == 6)
        {
            printf("Terima kasih telah menggunakan ATM ini!\n");
            isExit = true;
        }
        else
        {
            printf("Input tidak valid!\n");
        }
    }

    return 0;
}
