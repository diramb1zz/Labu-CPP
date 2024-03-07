#include <iostream>
using namespace std;

int main()
{ int rows;
 cout << "Enter rows of pyramid: ";
 cin >> rows;
 for (int i = rows - 1; i >= 0; --i) {
 // Пробіли перед цифрами
 for (int j = 0; j < rows - i - 1; ++j) {
 cout << " ";
 }
 // Ліва сторона піраміди
 for (int k = 0; k <= i; ++k) {
 cout << rows - 1 - i;
 }
 // Права сторона піраміди
 for (int l = i - 1; l >= 0; --l) {
 cout << rows - 1 - i;
 }
 cout << endl;
 }
 return 0;

}