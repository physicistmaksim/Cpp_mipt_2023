#include <iostream>
#include <algorithm>

using namespace std;

int func(string s1, string s2, int n1, int n2, int **mem)
{
    for(int i = 0; i <= n1; ++i)
        mem[i][0] = 0;
    for(int i = 0; i <= n2; ++i)
        mem[0][i] = 0;
    for(int i = 1; i <= n1; ++i)
    {
        for(int j = 1; j <= n2; ++j)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                mem[i][j] = mem[i - 1][j - 1] + 1;
            }
            else
            {
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }
    }
    return mem[n1][n2];
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
    int const N1 = s1.size();
    int const N2 = s2.size();
    if(N1 < N2)
        min = N1;
    else 
        min = N2;
    int **mem = new int*[N1 + 1];
    for(int i = 0; i < N1 + 1; ++i)
    {
        mem[i] = new int[N2 + 1];
        for(int j = 0; j < N2 + 1; ++j)
        {
            mem[i][j] = -1;
        }
    }
    int l = func(s1, s2, N1, N2, mem);
    int p = (l * 100)/min;
    cout << p << endl;
    for(int i = 0; i < N1 + 1; ++i)
    {
        delete [] mem[i];
    }
    delete [] mem;
    return 0;
}