#include "Sort.h"

Sort::Sort() : Arme()
{
    m_degats = nombreAleatoire(45, 60);
    m_nom = attribuerNom();
}

Sort::Sort(int nbDegatsMax, int nbDegatsMin) : Arme()
{
    m_nom = attribuerNom();
    m_degats = nombreAleatoire(nbDegatsMax, nbDegatsMin);
}

std::string Sort::attribuerNom()
{
    std::string retourNom = "Sort name attribution malfunction";
    int retourNomEpee = nombreAleatoire(6,1);

    switch(retourNomEpee)
    {
        case 1:
            retourNom = "Iiz Slen Nus";
        break;

        case 2:
            retourNom = "Yol Toor Shul";
        break;

        case 3:
            retourNom = "Hun Kaal Zoor";
        break;

        case 4:
            retourNom = "Joor Zah Frul";
        break;

        case 5:
            retourNom = "Od Ah Viing";
        break;

        case 6:
            retourNom = "Fus Roh Dah";
        break;

        default:
            retourNom = "Sort name attribution malfunction";
        break;
    }

    return retourNom;
}
