#include <iostream>

using namespace std;

int main(){

    int T;
    cin >> T;

    int M, x, y;
    int ar[101];

    for (int _ = 0; _ < T; _++){
        cin >> M >> x >> y;

        for (int ___ = 1; ___ < 101; ___++)
            ar[___] = 0;

        int pos;
        int max_houses = x * y;
        int left_pos, right_pos;

        for (int __ = 0; __ < M; __++){
         
            cin >> pos;
            ar[pos] = 1;
            
            if (pos - max_houses < 1)
                left_pos = 1;
            else
                left_pos = pos - max_houses;

            for (int i = left_pos; i <= pos; i++)
                ar[i] = 1;

            if (pos + max_houses > 100)
                right_pos = 100;
            else
                right_pos = pos + max_houses;

            for (int i = pos; i <= right_pos; i++)
                ar[i] = 1;
        }

        int safe_places = 0;

        // cout << "Going to print the complete Array" << endl;
        //
        // for (int _ = 0; _ < 101; _++)
        //     cout << ar[_] << " ";
        //
        // cout << endl;
        //
        // cout << "***** Printing Array Done *****" << endl;

        for (int i = 1; i < 101; i++)
            if (ar[i] == 0)
                safe_places++;

        cout << safe_places << endl;
    }

    return 0;
}
