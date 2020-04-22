#include <iostream>
#include<fstream>

using namespace std;

bool rules (bool a, bool b, bool c, bool ruleSetup[8]);//will give the state of the next square
bool * setRules(bool inRules[8], int inNum);

int main()
{
    int size;

    ofstream output;
    output.open("automata.txt");

    cin>>size;

    bool automata[size], ruleBase[8];
    bool next[size];
    bool *rulesS;

    for(int i=0; i<8; i++)
        ruleBase[i]=1;




    for (int sec=0; sec<256; sec++)
    {

    for(int i=0; i<8; i++)
        ruleBase[i]=1;

    *ruleBase = setRules(ruleBase, sec);


    for (int i=0; i<size; i++) // initializes the automata
    {
        if (i == int (float(size)/2)) // this puts the seed at the middle for 1d automata
            automata[i] = 1;
        else
            automata[i] = 0;
    }
    for (int i=0; i<size; i++)
    {
        if (automata[i])
            cout<<"X";
        else if (!automata[i])
            cout<<"0";
    }

    cout<<endl;

    for (int run = 0; run < size/2 ; run++)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                next[i] = rules(0, automata[0], automata[1], ruleBase);
                cout << automata[i];
                output << automata[i];
            }
            if (i+1 == size)
            {
                next[i] = rules(automata[i-1], automata[i], 0, ruleBase);
                cout << automata [i];
                output << automata[i];
            }
            else
            {
                next[i] = rules(automata[i-1], automata[i], automata[i+1], ruleBase);
                cout<< automata[i];
                output << automata[i];
            }


        }
        for (int i=0; i < size; i++)
        {
            automata[i] = next[i];
        }

        cout<<"           "<<run<<endl;
        output << "           "<<run<<endl;


    }
    cout<<endl<<"            "<<sec<<endl;
    }





    return 0;
}

bool rules (bool a, bool b, bool c, bool ruleSetup[8])
    {
    if (a == 1 && b == 1 && c == 1)
        return ruleSetup[0];
    if (a == 1 && b == 1 && c == 0)
        return ruleSetup[1];
    if (a == 1 && b == 0 && c == 1)
        return ruleSetup[2];
    if (a == 1 && b == 0 && c == 0)
        return ruleSetup[3];
    if (a == 0 && b == 1 && c == 1)
        return ruleSetup[4];
    if (a == 0 && b == 1 && c == 0)
        return ruleSetup[5];
    if (a == 0 && b == 0 && c == 1)
        return ruleSetup[6];
    if (a == 0 && b == 0 && c== 0)
        return ruleSetup[7];
    else
        return 0;
    }

    bool * setRules(bool inRules[8], int inNum)
{

    int ii=0, r;

    while (inNum != 0)
    {
        r = inNum%2;
        inRules[ii++]=r;
        inNum /= 2;
        if (ii == 8)
            inNum = 0;
    }

    for (int i=0; i<8; i++)
    {
        //cout << inRules[i];
    }

    return inRules;


}

