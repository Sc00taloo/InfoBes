﻿#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool checkBellLaPadula(int n, int m, const vector<vector<string>>& A, const vector<int>& LS, const vector<int>& LO) {
    char read = 'r';
    char write = 'w';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string permissions = A[i][j];
            for (char permission : permissions) {
                if (permission == read) {
                    if (LS[i] < LO[j]) {
                        cout << "Violation of the reading rule!" << endl;
                        return false;
                    }
                }
                else if (permission == write) {
                    if (LS[i] >= LO[j]) {
                        cout << "Violation of the recording rule!" << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//int main() {
//    int n, m;
//    cout << "Enter n (number sub): ";
//    cin >> n;
//    cout << "Enter m (number ob):  ";
//    cin >> m;
//
//    vector<vector<string>> A(n, vector<string>(m));
//    vector<int> LS(n), LO(m);
//
//    cout << "Enter matrix A: "<< endl;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> A[i][j];
//        }
//    }
//
//    cout << "Enter LS subject clearance levels size n: " << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "LS[" << (i + 1) << "]: ";
//        cin >> LS[i];
//    }
//    cout << "Enter LO object security levels size m: " << endl;
//    for (int j = 0; j < m; ++j) {
//        cout << "LO[" << (j + 1) << "]: ";
//        cin >> LO[j];
//    }
//
//    if (checkBellLaPadula(n, m, A, LS, LO)) {
//        cout << "True" << endl;
//    }
//    else {
//        cout << "False" << endl;
//    }
//
//    return 0;
//}


bool checkBellLaPadulaLOandLS(int n, int m, const vector<vector<string>>& A) {
    char read = 'r';
    char write = 'w';
    vector<int> LS(n, 0);
    vector<int> LO(m, 0);

    // Подбор уровней допуска и секретности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string permissions = A[i][j];
            for (char permission : permissions) {
                if (permission == read) {
                    LS[i] = max(LS[i], LO[j]);
                }
                else if (permission == write) {
                    LO[j] = max(LO[j], LS[i] + 1);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string permissions = A[i][j];
            for (char permission : permissions) {
                if (permission == read) {
                    LS[i] = max(LS[i], LO[j]);
                }
                else if (permission == write) {
                    LO[j] = max(LO[j], LS[i] + 1);
                }
            }
        }
    }
    cout << "LS: ";
    for (int i = 0; i < n; ++i) {
        cout << LS[i] << " ";
    }
    cout << endl;
    cout << "LO: ";
    for (int j = 0; j < m; ++j) {
        cout << LO[j] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string permissions = A[i][j];
            for (char permission : permissions) {
                if (permission == read) {
                    if (LS[i] < LO[j]) {
                        cout << "Violation of the reading rule!" << endl;
                        return false;
                    }
                }
                else if (permission == write) {
                    if (LS[i] >= LO[j]) {
                        cout << "Violation of the recording rule!" << endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int main() {
    int n, m;
    cout << "Enter n (number sub): ";
    cin >> n;
    cout << "Enter m (number ob):  ";
    cin >> m;

    vector<vector<string>> A(n, vector<string>(m));

    cout << "Enter matrix A: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    if (checkBellLaPadulaLOandLS(n, m, A)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}