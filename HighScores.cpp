#include "HighScores.h"

HighScores::HighScores()
{
    size = 0;
    ifstream infile;
    infile.open("highscores.txt",ios::in);
    string dummy;
    while(infile.peek()!=EOF)
	{
		getline(infile,dummy);
		size++;
	}
    infile.close();
    names = new string[size];
    scores = new int[size];
    infile.open("highscores.txt",ios::in);
    for(int i=0 ; i<size ; i++)
		infile >> names[i] >> scores[i];
    infile.close();
}
void HighScores::sort()
{
    for(int i=0 ; i<size ; i++)
        for(int j=0 ; j<size-1-i ; j++)
            if(scores[j+1]>scores[j])
            {
                string temp_s = names[j];
                int temp_int = scores[j];
                scores[j] = scores[j+1];
                names[j] = names[j+1];
                names[j+1] = temp_s;
                scores[j+1] = temp_int;
            }
}
void HighScores::add(string name, int score)
{
    int i=0;
    while(name[i])
    {
        if(name[i] == ' ')
            name[i] = '_';
        i++;
    }
    bool found = false;
    for(int i=0 ; i<size ; i++)
    {
        if(names[i] == name)
        {
            found = true;
            if(score > scores[i])
                scores[i] = score;
            break;
        }
    }
    if(!found)
    {
        string* temp_s = names;
        int* temp_int = scores;
        size++;
        names = new string[size];
        scores = new int [size];
        for(int i=0 ; i<size-1 ; i++)
        {
            names[i] = temp_s[i];
            scores[i] = temp_int[i];
        }
        names[size-1] = name;
        scores[size-1] = score;
    }
    sort();
    ofstream outfile;
    outfile.open("highscores.txt",ios::out);
    if(size>10)
        size = 10;
    for(int i=0 ; i<size ; i++)
    {
        outfile << names[i] << "\t" << scores[i];
        if(i!=size-1)
            outfile << '\n';
    }
    outfile.close();
}