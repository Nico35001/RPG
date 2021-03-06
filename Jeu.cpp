#include "Jeu.h"

Jeu::Jeu()
{
    joueur1 = menu();
    joueur2 = menu();

    joueur1->afficherInfos();
    joueur2->afficherInfos();
}

Personnage* Jeu::menu()
{
    clear();
    printw("Choisissez votre personnage et appuyez sur E:\n");
    attron(A_BOLD);
    attron(A_STANDOUT);
    attron(A_UNDERLINE);
    printw("->1.Guerrier Leger\n");
    attroff(A_BOLD);
    attroff(A_STANDOUT);
    attroff(A_UNDERLINE);
    printw("  2. Guerrier Lourd\n");
    printw("  3. Mage\n");
    refresh();

    int retour = 1;
    int appuiFleches = 0;

    int ch = 0;

    do
    {
        ch = getch();

        if(ch == 0x102) //Key_down
        {

            if(appuiFleches == 2)
                appuiFleches = 2;

            else
                appuiFleches++;

            if(appuiFleches == 1)
            {
                clear();
                printw("Choisissez votre personnage et appuyez sur E:\n");
                printw("  1. Guerrier L�ger\n");
                attron(A_BOLD);
                attron(A_STANDOUT);
                attron(A_UNDERLINE);
                printw("->2.Guerrier Lourd\n");
                attroff(A_BOLD);
                attroff(A_STANDOUT);
                attroff(A_UNDERLINE);
                printw("  3. Mage\n");
                refresh();

                retour = 2;
            }

            else if(appuiFleches == 2)
            {
                clear();
                printw("Choisissez votre personnage et appuyez sur E:\n");
                printw("  1. Guerrier L�ger\n");
                printw("  2. Guerrier Lourd\n");
                attron(A_BOLD);
                attron(A_STANDOUT);
                attron(A_UNDERLINE);
                printw("->3.Mage\n");
                attroff(A_BOLD);
                attroff(A_STANDOUT);
                attroff(A_UNDERLINE);
                refresh();

                retour = 3;
            }

        }

        else if(ch == 0x103) //Key_up
        {


            if(appuiFleches == 1)
            {
                clear();
                printw("Choisissez votre personnage et appuyez sur E:\n");
                attron(A_BOLD);
                attron(A_STANDOUT);
                attron(A_UNDERLINE);
                printw("->1.Guerrier Leger\n");
                attroff(A_BOLD);
                attroff(A_STANDOUT);
                attroff(A_UNDERLINE);
                printw("  2. Guerrier Lourd\n");
                printw("  3. Mage\n");
                refresh();

                retour = 1;
            }

            else if(appuiFleches == 2)
            {
                clear();
                printw("Choisissez votre personnage et appuyez sur E:\n");
                printw("  1. Guerrier L�ger\n");
                attron(A_BOLD);
                attron(A_STANDOUT);
                attron(A_UNDERLINE);
                printw("->2.Guerrier Lourd\n");
                attroff(A_BOLD);
                attroff(A_STANDOUT);
                attroff(A_UNDERLINE);
                printw("  3. Mage\n");
                refresh();

                retour = 2;
            }

            if(appuiFleches == 0)
                appuiFleches = 0;

            else
                appuiFleches--;
        }

        //ch = getch();

    }while(ch != 0x65); //0x65 -> ASCII Code for e (code is 65, just append 0x)

    if(retour == 1)
        return new GuerrierLeger;

    else if(retour == 2)
        return new GuerrierLourd;

    else if(retour == 3)
        return new Magicien;
}
