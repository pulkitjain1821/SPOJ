#include<iostream>
#include<utility>
 
using namespace std;
pair < char, char >complement(char first, char second)
{
    pair < char, char >r;
    if (first == 'A' && second == 'B') {
 r.first = 'C';
 r.second = 'D';
 return r;
    }
    if (first == 'A' && second == 'C') {
 r.first = 'B';
 r.second = 'D';
 return r;
    }
    if (first == 'A' && second == 'D') {
 r.first = 'C';
 r.second = 'B';
 return r;
    }
    if (first == 'B' && second == 'A') {
 r.first = 'C';
 r.second = 'D';
 return r;
    }
    if (first == 'B' && second == 'C') {
 r.first = 'A';
 r.second = 'D';
 return r;
    }
    if (first == 'B' && second == 'D') {
 r.first = 'C';
 r.second = 'A';
 return r;
    }
    if (first == 'C' && second == 'A') {
 r.first = 'B';
 r.second = 'D';
 return r;
    }
    if (first == 'C' && second == 'B') {
 r.first = 'A';
 r.second = 'D';
 return r;
    }
    if (first == 'C' && second == 'D') {
 r.first = 'A';
 r.second = 'B';
 return r;
    }
    if (first == 'D' && second == 'A') {
 r.first = 'B';
 r.second = 'C';
 return r;
    }
    if (first == 'D' && second == 'B') {
 r.first = 'A';
 r.second = 'C';
 return r;
    }
    if (first == 'D' && second == 'C') {
 r.first = 'A';
 r.second = 'B';
 return r;
    }
}
 
int main()
{
    long N;
    int i;
 
    pair < char, char >c;
    scanf("%d", &N);
    char arr[2][2 * N];
 
    scanf("%s", &arr[0]);
 
    c = complement(arr[0][0], arr[0][1]);
    arr[1][0] = c.first;
    arr[1][1] = c.second;
    for (i = 2; i < 2 * N - 1;) {
 pair < char, char >c;
 c = complement(arr[0][i], arr[0][i + 1]);
 arr[1][i] = c.first;
 arr[1][i + 1] = c.second;
 if (arr[1][i] == arr[1][i - 1])
     swap(arr[1][i], arr[1][i + 1]);
 i = i + 2;
 
    }
    for (i = 0; i < 2 * N; i++)
 printf("%c", arr[1][i]);
return 0;
 
}
