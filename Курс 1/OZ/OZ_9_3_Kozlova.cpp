#include <iostream>
using namespace std;

int main() {
    unsigned short X;
    int n;
    int vybor;
    
    cout << "введите число (0..65535): ";
    cin >> X;
    
    cout << "введите степень n (0..15): ";
    cin >> n;
    
    // проверка ввода
    if (n < 0 || n > 15) {
        cout << "ошибка: n должно быть от 0 до 15" << endl;
        return 1;
    }
    
    cout << endl << "выберите действие:" << endl;
    cout << "1 - увеличить X в 2^" << n << " раз (умножение)" << endl;
    cout << "2 - уменьшить X в 2^" << n << " раз (деление)" << endl;
    cout << "ваш выбор: ";
    cin >> vybor;
    
    // исходное число в двоичном виде (старший бит слева)
    cout << endl << "исходное число X = " << X << endl;
    cout << "двоичное (старший бит слева): ";
    for (int i = 15; i >= 0; i--) {
        cout << ((X >> i) & 1);
    }
    cout << endl;
    
    unsigned short rezult;
    
    if (vybor == 1) {
        // увеличение в 2^n раз (умножение) - сдвиг влево
        rezult = X << n;
        cout << endl << "увеличение X в 2^" << n << " раз:" << endl;
        cout << X << " * 2^" << n << " = " << rezult << endl;
    }
    else if (vybor == 2) {
        // уменьшение в 2^n раз (деление) - сдвиг вправо
        rezult = X >> n;
        cout << endl << "уменьшение X в 2^" << n << " раз:" << endl;
        cout << X << " / 2^" << n << " = " << rezult << endl;
    }
    else {
        cout << "ошибка: неверный выбор" << endl;
        return 1;
    }
    
    // результат в двоичном виде
    cout << "двоичное (старший бит слева): ";
    for (int i = 15; i >= 0; i--) {
        cout << ((rezult >> i) & 1);
    }
    cout << endl;
    
    return 0;
}