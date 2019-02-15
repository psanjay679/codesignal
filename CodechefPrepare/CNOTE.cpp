#include <iostream>

using namespace std;

int main(){
    int T;
    int X, Y, K, N;
    int Pi, Ci;
    bool ans;
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> X >> Y >> K >> N;
        ans = false;
        for (int j = 0; j < N; j++){
            cin >> Pi >> Ci;

            // cout << "Pages Left: " << Y << endl;
            // cout << "Money Left: " << K << endl;
            // cout << "Pages In Notebook: " << Pi << endl;
            // cout << "Price Of Notebook: " << Ci << endl;

            if (Ci <= K && Pi >= (X - Y)){
                ans = true;
            }
        }

        if (ans == true)
            cout << "LuckyChef\n";
        else
            cout << "UnluckyChef\n";
    }
    return 0;
}
