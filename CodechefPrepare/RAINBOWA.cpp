#include <iostream>

using namespace std;

int main(){
    int T;

    cin >> T;

    for (int _ = 0; _ < T; _++){
        int N;
        cin >> N;

        int rainbow[N + 1];

        for (int i = 0; i < N; i++){
            cin >> rainbow[i];
        }

        int middle_index;
        int seven_count = 0;

        if (N % 2 == 0)
            middle_index = N / 2;
        else
            middle_index = N / 2 + 1;

        bool is_rainbow = true;

        if (rainbow[0] != rainbow[N - 1] || rainbow[0] != 1)
            is_rainbow = false;

        for (int i = 1; i < middle_index; i++){
            if (rainbow[i] != rainbow[N - i - 1] || ((rainbow[i] - rainbow[i - 1]) > 1) || rainbow[i] > 7)
                is_rainbow = false;

            if (is_rainbow == false)
                break;

            if (rainbow[i] == 7)
                seven_count += 1;
        }

        if (seven_count == 0)
            is_rainbow = false;

        if (is_rainbow == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
