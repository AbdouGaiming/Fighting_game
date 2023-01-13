#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#include <time.h>
#include <stdlib.h>
#pragma region Functions


void Affichageetoile(int etoile_Nember = 60)
{
    for (int i = 0; i <etoile_Nember; i++)
    {
        printf("*");
        Sleep(5);
    }
}
void affichageHealth(char Player1_Name[20], char Player2_Name[20],int heath, int enmyHealth)
{
    const int progress = 219;
    printf("\n %s health is : \t",Player1_Name);
    for (int i = 0; i < heath; i++)
    {
        printf("%c", progress);
        Sleep(10);
    }
    printf(" %d\n\n", heath);
    printf(" %s health is : \t", Player2_Name);
    for (int i = 0; i < enmyHealth; i++)
    {
        printf("%c", progress);
        Sleep(10);
    }
    printf(" %d\n\n", enmyHealth);
}
#pragma endregion
int main()
{
    int Choice, Player1_Damage, Player2_Damage, Player1_Spell = 3, Player2_Spell = 3, Player1_Health = 50, Player2_Health = 50, Player1_Heal, Player2_Heal;
    char Player1_Name[20], Player2_Name[20];

    srand(time(NULL));
    printf(" Player(1) Put your name: ");
    scanf_s("%s", &Player1_Name, sizeof(Player1_Name));
    printf(" Player(2) Put your name: ");
    scanf_s("%s", &Player2_Name, sizeof(Player2_Name));
    printf("\n *** %s and %s bothe have %d points*** \n", Player1_Name, Player2_Name, Player1_Health);
    affichageHealth(Player1_Name, Player2_Name,Player1_Health, Player2_Health);

    while ((Player1_Health > 0) && (Player2_Health > 0))
    {
        #pragma region Player 1

        if (Player1_Spell > 0)
        {

            #pragma region Spell


            do
            {
                Affichageetoile();
                printf("\n %s Choose between (1) to ATTACKE Or (2) to HEAL: ", Player1_Name);
                scanf_s("%d", &Choice);
                if (Choice != 1 && Choice != 2)
                {
                    printf(" Note: %s Chose only between (1) and (2) ", Player1_Name);
                }
            } while (Choice != 1 && Choice != 2);

            switch (Choice)
            {

            case 1:
                Player1_Damage = (rand() % (15 - 5 + 1)) + 5;
                Player2_Health = Player2_Health - Player1_Damage;
                printf("\n Your attack on %s take away (%d) pointe \n", Player2_Name, Player1_Damage);

                break;
            case 2:
                Player1_Spell = Player1_Spell - 1;
                Player1_Heal = (rand() % (50 - 15 + 1)) + 15;
                Player1_Health = Player1_Health + Player1_Heal;
                printf("\n You have recovered :%d point, You have (%d) Heal rest \n", Player1_Heal, Player1_Spell);

                break;
            }

#pragma endregion
        }
        else
        {
            #pragma region No spell

            do
            {
                Affichageetoile();
                printf("\n Note: %s you have no heal, you must Chose only (1) ", Player1_Name);
                scanf_s("%d", &Choice);
                if (Choice != 1)
                {
                    printf("\n Note: %s you have no heal, you must Chose only (1) ", Player1_Name);
                }
            } while (Choice != 1);

            Player1_Damage = (rand() % (15 - 5 + 1)) + 5;
            Player2_Health = Player2_Health - Player1_Damage;
            printf("\n Your attack on %s take away (%d) points \n", Player1_Name, Player1_Damage);

        #pragma endregion
        }
        #pragma endregion
            
        if ((Player1_Health > 0) && (Player2_Health > 0))
        {
            affichageHealth(Player1_Name, Player2_Name, Player1_Health, Player2_Health);
        }

        if (Player2_Health > 0)
        {
            #pragma region Player 2
           
            if (Player2_Spell > 0)
            {
                #pragma region Spell

                do
                {
                    Affichageetoile();
                    printf("\n %s Choose between (1) to ATTACKE Or (2) to HEAL: ", Player2_Name);
                    scanf_s("%d", &Choice);

                    if (Choice != 1 && Choice != 2)
                    {
                        printf(" Note: %s Chose only between 1 and 2 ", Player2_Name);
                    }

                } while (Choice != 1 && Choice != 2);


                switch (Choice)
                {

                case 1:
                    Player1_Damage = (rand() % (15 - 5 + 1)) + 5;
                    Player1_Health = Player1_Health - Player1_Damage;
                    printf("\n Your attack on %s take away (%d) points \n", Player1_Name, Player1_Damage);

                    break;
                case 2:
                    Player2_Spell = Player2_Spell - 1;
                    Player2_Heal = (rand() % (50 - 15 + 1)) + 15;
                    Player2_Health = Player2_Health + Player2_Heal;
                    printf("\n You have recovered :%d point, You have (%d) Heal rest \n", Player2_Heal, Player2_Spell);

                    break;
                }

#pragma endregion
            }
            else
            {
                #pragma region No spell


                do
                {
                    Affichageetoile();
                    printf("\n Note: %s you have no heal, you must Chose only (1) ", Player2_Name);
                    scanf_s("%d", &Choice);
                    if (Choice != 1)
                    {
                        printf("\n Note: %s you have no heal, you must Chose only (1) ", Player2_Name);
                    }
                } while (Choice != 1);

                Player2_Damage = (rand() % (15 - 5 + 1)) + 5;
                Player1_Health = Player1_Health - Player2_Damage;
                printf("\n Your attack on %s take away (%d) points \n", Player1_Name, Player2_Damage);

#pragma endregion
            }

            #pragma endregion
        }

        if ((Player1_Health > 0) && (Player2_Health > 0))
        {
            affichageHealth(Player1_Name, Player2_Name, Player1_Health, Player2_Health);
        }

    }
    Affichageetoile();

    if (Player1_Health <= 0)
    {
        printf("\n %s WIN the game with %d left", Player2_Name,Player2_Health);
    }

    else
    {
        printf("\n %s WIN the game with %d left", Player1_Name,Player1_Health);
    }

    printf("\n GAME OVER..");
    return 0;
}
