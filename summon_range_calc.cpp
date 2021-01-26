#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int getTier(double sm, int *tierArray, double *lower, double *upper)
{
    int tier;

    for (int i = 0; i < 45; i++)
    {
        // cout << std::setprecision(15) << lower[i] << endl
        //      << upper[i] << endl;
        if (sm <= upper[i] && sm >= lower[i])
        {
            return tierArray[i];
        }
    }

    return -1;
}

double *getSM(int tier, int lBound, int uBound, double *lower, double *upper)
{
    double *smRange = new double[2];
    int lTier, uTier;

    lTier = tier - lBound;
    uTier = tier + uBound;

    if (lTier < 1)
    {
        lTier = 1;
    }
    if (uTier > 45)
    {
        uTier = 45;
    }

    smRange[0] = lower[lTier - 1];
    smRange[1] = upper[uTier - 1];
    return smRange;
}

bool nameEngravedCheck(int item)
{
    if (item == 1 || item == 2)
    {
        int option;
        cout << "Name-engraved?" << endl;
        cout << "0. No." << endl;
        cout << "1. Yes." << endl;
        cin >> option;
        if (option != 0 && option != 1)
        {
            cout << "Invalid option." << endl;
            return false;
        }
        else
        {
            if (option == 1)
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

void printSMRange(int lowerRange, int upperRange)
{
    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
    cout << "SM ranges: " << setprecision(30) << lowerRange << "-" << upperRange << endl;
    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
}

int main()
{
    //map<double, int> map = {{, }, {}};
    int item, tier, lBound, uBound, c;
    double sm, lowerRange, upperRange;
    bool isNameEngraved = false;

    c = 1;
    int *tierArray = new int[45];
    for (int i = 0; i < 45; i++)
    {
        tierArray[i] = c;
        c++;
    }
    double lower[] = {0, 10000, 20000, 30000, 40000, 50000, 70000, 90000, 110000, 130000,
                      150000, 180000, 210000, 240000, 270000, 300000, 350000, 400000, 450000, 500000, 600000,
                      700000, 800000, 900000, 1000000, 1100000, 1200000, 1300000, 1400000, 1500000, 1750000,
                      2000000, 2250000, 2500000, 2750000, 3000000, 5000000, 7000000, 9000000, 12000000, 15000000,
                      20000000, 30000000, 45000000, 360000000};
    double upper[] = {10000, 20000, 30000, 40000, 50000, 70000, 90000, 110000, 130000,
                      150000, 180000, 210000, 240000, 270000, 300000, 350000, 400000, 450000, 500000, 600000,
                      700000, 800000, 900000, 1000000, 1100000, 1200000, 1300000, 1400000, 1500000, 1750000,
                      2000000, 2250000, 2500000, 2750000, 3000000, 5000000, 7000000, 9000000, 12000000, 15000000,
                      20000000, 30000000, 45000000, 360000000, 1000000000};
    for (int i = 0; i < 45; i++)
    {
        upper[i] = upper[i] - 1;
    }

    cout << "Input current Soul Memory:" << endl;
    cin >> sm;
    cout << "************************************************************************" << endl;
    cout << "Choose the Multiplayer item:" << endl;
    cout << "1. White Sign Soapstone." << endl;
    cout << "2. Small White Sign Soapstone." << endl;
    cout << "3. Red Sign Soapstone." << endl;
    cout << "4. Dragon eye." << endl;
    cout << "5. Cracked red eye orb." << endl;
    cout << "6. Cracked blue eye orb." << endl;
    cout << "7. Bell keeper's seal." << endl;
    cout << "8. Crest of the Rat." << endl;
    cout << "9. Guardian's seal." << endl;
    cout << "10. Dark chasm invasions(CREO)." << endl;
    cout << "11. Looking Glass Knight Spear(RSS)." << endl;
    cout << "12. Looking Glass Knight Spear(CREO)." << endl;
    cout << "************************************************************************" << endl;

    cin >> item;

    isNameEngraved = nameEngravedCheck(item);

    tier = getTier(sm, tierArray, lower, upper);

    if (tier < 0 || tier > 45)
    {
        cout << tier << endl;
        cout << "Invalid SM.";
        return 0;
    }

    switch (item)
    {
    //WSS
    case 1:
        if (isNameEngraved)
        {
            lBound = 6;
            uBound = 4;
            double *smRange = getSM(tier, lBound, uBound, lower, upper);
            lowerRange = smRange[0];
            upperRange = smRange[1];
        }
        else
        {
            lBound = 3;
            uBound = 1;
            double *smRange = getSM(tier, lBound, uBound, lower, upper);
            lowerRange = smRange[0];
            upperRange = smRange[1];
        }

        printSMRange(lowerRange, upperRange);
        break;
    //SWSS
    case 2:
        if (isNameEngraved)
        {
            lBound = 7;
            uBound = 5;
            double *smRange = getSM(tier, lBound, uBound, lower, upper);
            lowerRange = smRange[0];
            upperRange = smRange[1];
        }
        else
        {
            lBound = 4;
            uBound = 2;
            double *smRange = getSM(tier, lBound, uBound, lower, upper);
            lowerRange = smRange[0];
            upperRange = smRange[1];
        }

        printSMRange(lowerRange, upperRange);
        break;

    //RSS
    case 3:
    {
        lBound = 5;
        uBound = 2;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //DE
    case 4:
    {
        lBound = 5;
        uBound = 5;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //CREO
    case 5:
    {
        lBound = 0;
        uBound = 4;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //CBEO
    case 6:
    {
        lBound = 3;
        uBound = 3;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //BK'S
    case 7:
    {
        lBound = 1;
        uBound = 3;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //COTR
    case 8:
    {
        lBound = 1;
        uBound = 3;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //G'S
    case 9:
    {
        lBound = 7;
        uBound = 6;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //DCOO
    case 10:
    {
        lBound = 0;
        uBound = 8;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //LGK (RSS)
    case 11:
    {
        lBound = 0;
        uBound = 6;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    //LGK (CREO)
    case 12:
    {
        lBound = 0;
        uBound = 5;
        double *smRange = getSM(tier, lBound, uBound, lower, upper);
        lowerRange = smRange[0];
        upperRange = smRange[1];
        printSMRange(lowerRange, upperRange);
        break;
    }

    default:
        cout << "Invalid item" << endl;
    }
}