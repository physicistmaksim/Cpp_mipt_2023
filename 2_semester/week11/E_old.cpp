#include <iostream>
#include <algorithm>

using namespace std;

int func(string s1, string s2, int n1, int n2)
{
    int max_len = 0;
    if(n1 == 0 or n2 == 0)
    {
        return 0;
    }
    else if(s1[n1 - 1] == s2[n2 - 1])
    {
        max_len = 1 + func(s1, s2, n1 - 1, n2 - 1);
    }
    else
    {
        max_len = max(func(s1, s2, n1 - 1, n2), func(s1, s2, n1, n2 - 1));
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
    if(s1.size() < s2.size())
        min = s1.size();
    else
        min = s2.size();
    int l = func(s1, s2, s1.size(), s2.size());
    int p = (l * 100)/min;
    cout << p << endl;
    return 0;
}