#include <bits/stdc++.h>
using namespace std;

#define d 256

vector<int> rabin_karp_search(string text, string pattern, int q){
    int h = 1;
    int hash_for_pattern = 0, hash_for_text = 0;
    int i, j;
    int M = pattern.size();
    int N = text.size();

    for ( i = 0; i < M-1; ++ i)
        h = ( h * d ) % q;

    for ( i = 0; i < M; ++i ){
        hash_for_pattern = (hash_for_pattern * d + pattern[i]) % q;
        hash_for_text = ( (hash_for_text * d ) + text[i]) % q;
    }
    vector<int> indexes;

    for ( i = 0; i <= N-M; ++ i ){

        if ( hash_for_pattern == hash_for_text ){
            for ( j = 0; j < M; ++ j ){
                if ( pattern[j] != text[i+j] )
                    break;
            }
            if ( j == M )
                indexes.push_back(i);
        }

        if ( i < N-M ){

            hash_for_text = ( d * ( hash_for_text - text[i] * h ) + text[i + M] ) % q;
            if ( hash_for_text < q )
                hash_for_text += q;
        }

    }
    cout << indexes.size();
    return indexes;
}


int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    int q = 101; /// a sufficiently large prime number
    vector<int> indexes = rabin_karp_search(text, pattern, q);
    for ( vector<int>::iterator it = indexes.begin(); it != indexes.end(); ++ it)
        cout << *it << " ";
    return 0;
}
