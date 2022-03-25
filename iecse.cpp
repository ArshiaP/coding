#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

ios_base::sync_with_stdio(false); //line1
cin.tie(NULL);                    //line2
using namespace std;

int main(){
    int numtestcases, indice[100], i,j, numcase,output=0;
    // cout << "number of test cases: ";
    scanf("%d", &numtestcases);
    // cin >> numtestcases;
    for (;numtestcases>0;numtestcases--){
        output = 0;
        // cout << "number of letters in this testcase: ";
        scanf("%d", &numcase);
        // cin >> indice[i];
        for (i=0;i<numcase;i++){
            scanf("%d", &indice[i]);
            // cin >> indice[i];
        }

        // for (i=0;i<numcase;i++){
        //     cout << indice[i] << " ";
        // }
        for (i=0;i<numcase-1;i++){
            for (j=i+1;j<numcase;j++){
                if ((j-i)==(indice[j]-indice[i])){
                    // cout << indice[j] << " " << indice[i] << "  ";
                    output = output+1;
                }
            }
        }
        // printf("%d", &)
        cout << output << endl;  
    }
    return 0;
}