#include <iostream>
#include <algorithm>

using namespace std;

int func(string s1, string s2, int n1, int n2, int **mem)
{
    int max_len = 0;
    if(n1 == 0 or n2 == 0)
    {
        return 0;
    }
    else if(s1[n1 - 1] == s2[n2 - 1])
    {
        if(mem[n1][n2] == 0)
            mem[n1][n2] = func(s1, s2, n1 - 1, n2 - 1, mem);
        max_len = 1 + mem[n1][n2];
    }
    else
    {
        if(mem[n1][n2 + 1] == 0)
            mem[n1][n2 + 1] = func(s1, s2, n1 - 1, n2, mem);
        if(mem[n1 + 1][n2] == 0)
            mem[n1 + 1][n2] = func(s1, s2, n1, n2 - 1, mem);
        max_len = max(mem[n1][n2 + 1], mem[n1 + 1][n2]);
    }
    return max_len;
}

int main()
{
    string s1;
    string s2;
    //cin >> s1 >> s2;
    s1 = "GACTTTAAATTATTGGTGCCCGCGTTGTTCTAGGTTCTCAGTTTCCAGTTAAACGGACTGCTGCGGACGTGCATTCTCACAACCAATAGTATTGCGTGCGATCAAGCGCAGAGCCGGCCTTTGTGGTGGCACCCTAAGGGACTTTCTAGTATTCTGGCGATAACACGTGATACGTGGCTCGTTGAGGAGATTCCTGATAGGACCAGCGAGCTAGTCGACCATTAACTATCC";
    s2 = "CGACTGTCAGCAATGTAGTAGCTATTCGGTGTTCTCAGAATGCCAACCAGCAGCGACACTACTGTCTGTGGTATTGGAACTCTTAACTAAGATAAAAATCCTTCACCTCGTTCCCACTGGGCTTCCGATCTCTAAAGGAACGCTAATGCTGCCTGGAGGAATATAGCGCGTGCGAGTAGTCCTGGGTCATATGGTAGGTGACCACTCGATTATTAGCATCTGTTTGTGACAGGAATCAGGCGCGCTTTAGGAACAGTGCATCGCAACATTGAACAGTGCTTACGAGCGTCCGTCATGTGTAGTTACTACAAAGTGACTTACGAAGTGACACTGGTCGCAATGTAGTGGGGCCGGGAGAGGCCAAGGTTCG";
    int min;
    //cout << s1.size() << endl;
    //cout << s2.size() << endl;
    if(s1.size() < s2.size())
        min = s1.size();
    else
        min = s2.size();
    int const N1 = s1.size();
    int const N2 = s2.size();
    int **mem = new int*[N1 + 2];
    for(int i = 0; i < N1 + 2; ++i)
    {
        mem[i] = new int[N2 + 2];
        for(int j = 0; j < N2 + 2; ++j)
        {
            mem[i][j] = 0;
        }
    }
    int l = func(s1, s2, s1.size(), s2.size(), mem);
    int p = (l * 100)/min;
    cout << p << endl;
    for(int i = 0; i < N1 + 2; ++i)
    {
        delete [] mem[i];
    }
    delete [] mem;
    return 0;
}