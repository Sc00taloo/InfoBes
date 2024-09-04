#include <vector>  
#include <ctime>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;
//7 RLE. Компрессия RLE – это способ сжатия данных, в которых имеется
//много подряд идущих символов.При этом более одного вхождения символа
//заменяется на пару(количество вхождений - символ).В входном файле
//input.txt задан текст, состоящий из букв латинского алфавита.Примените к
//нему с помощью написанной программы преобразование RLE, т.е.замените N
//(N > 1) вхождений некоторого символа, которые подряд идут в строке на
//.Длина входной строки не более 10000 символов.Преобразованный текст
//программа должна поместить в текстовый файл output.txt.
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    ifstream f;
//    f.open("input.txt");
//    ofstream f2("output.txt");
//    if (!f.is_open()) {
//        cout << "Error";
//    }
//    else {
//        cout << "File open" << endl;
//        string str;
//        string result = "";
//        while (!f.eof()) {
//            str = "";
//            f >> str;
//            char first = str[0];
//            int k = 0;
//            for (int i = 0; i < str.size()+1; ++i) {
//                if (first == str[i]) {
//                    ++k;
//                }
//                else {
//                    string s1(1, first);
//                    string s2;
//                    s2 = to_string(k);
//                    if (k == 1) {
//                        result += s1;
//                    }
//                    else {
//                        result += s2 + s1;
//                    }
//                    k = 1;
//                    first = str[i];
//                }
//            }
//            f2 << result;
//        }
//        cout << result << endl;
//    }
//    f.close();
//    f2.close();
//    return 0;
//}

//8 Кодовый замок. Есть кодовый замок. На нём переключателей
//(1 ≤ N ≤ 26), промаркированных различными буквами.Каждый переключатель может быть или в положении ON, или в положении OFF.
//При установке замка владелец ставит в соответствие каждой из букв некоторый код – натуральное число.Различные буквы имеют различные коды C1, C2, …, Cn(1 ≤ Cj ≤ 64000, 1 ≤ j ≤ N).
//Для того, чтобы открыть замок, владелец устанавливает некоторые переключатели в положение ON, а оставшиеся – в положение OFF.
//Замок открывается, когда сумма всех чисел - кодов, соответствующих выключателям, находящимся в положении ON, 
//делится без остатка на N, т.е.существует некоторое подмножество кодов Cj1, Cj2, …, Cjk(k≤N), сумма всех членов которого делится на N.
//Взломщик не знает значений кодов и пытается открыть замок, перебирая некоторые комбинации букв и устанавливая соответствующие переключатели в положение ON.
//Требуется составить программу, которая должна определить, возможно ли открыть замок, т.е.существует ли такое подмножество букв, что сумма кодов, 
//соответствующих этим буквам, делится без остатка на(возможные ответы программы : YES или NO).В случае, если это возможно,
//программа должна выдать какое - то подмножество кодов Cj1, Cj2, …, Cjk и P – количество всех возможных комбинаций кодового замка, которые его открывают.
//Входные данные задаются в текстовом файле input.txt, а результаты – в текстовом файле output.txt.
void findSubsets(const vector<int>& codes, int N, vector<vector<int>>& results, vector<int>& currentSubset, int start, int currentSum) {
    if (currentSum % N == 0 && !currentSubset.empty()) {
        results.push_back(currentSubset);
    }

    for (int i = start; i < codes.size(); ++i) {
        currentSubset.push_back(codes[i]);
        findSubsets(codes, N, results, currentSubset, i + 1, currentSum + codes[i]);
        currentSubset.pop_back();
    }
}

int main() {
    ifstream f;
    f.open("input1.txt");
    ofstream f2("output1.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        int N;
        f >> N;
        vector<int> codes(N);
        for (int i = 0; i < N; ++i) {
            f >> codes[i];
        }
        vector<vector<int>> results;
        vector<int> currentSubset;
        findSubsets(codes, N, results, currentSubset, 0, 0);
        if (!results.empty()) {
            f2 << "YES\n";
            for (int num : results[0]) {
                f2 << num << " ";
            }
            f2 << "\n";
            f2 << results.size() << "\n";
        }
        else {
            f2 << "NO\n";
        }
    }
    f.close();
    f2.close();
    return 0;
}