// Сложение и вычитание в столбик с ручным вводом чисел


#include <iostream>

using namespace std;


// Ввод большого числа длины n
short* inputBigNum(int n){
    // создание динамического массива
    short* num = new short[n];
    string line;

    // считывание строки
    cout << "Введите число:\n";
    cin >> ws;
    getline(cin, line);
    
    // цикл создания числа
    for(int i = 0; i < n; i++){
        short m = line[i] - '0';
        num[i] = m;
    }

    return num;
}

// Сравнение больших чисел
int isBigger(short* num1, short* num2, int n1, int n2){
    // числа разной длины
    if(n1 != n2){
        return(n1 > n2 ? 1 : 0);
    }

    // числа одной длины
    else{
        bool equal = true;

        for(int i = 0; i < n1; i++){
            if(num1[i] > num2[i]){
                return 1;
                equal = false;
                break;
            }
            
            else if(num2[i] > num1[i]){
                return 0;
                equal = false;
                break;
            }
        }

        if(equal) return -1;
    }
    
    return 0;
}

// Сложение больших чисел
int cornerFix;
short* addNums(short* numt, short* numz, int n1, int n2){
    // длина максимального и минимального числа
    int maxLen = max(n1, n2);
    int minLen = min(n1, n2);
    
    // создание массивов для чисел
    short* number1 = numt;
    short* number2temp = numz;


    // замена массивов местами, чтобы number1 был б`ольшим числом
    short* temp = number1;

    if(isBigger(number2temp, number1, n2, n1)){
        number1 = number2temp;
        number2temp = temp;
    }


    // Формирование меньшего числа
    short* number2 = new short[maxLen];

    // запись цифр числа в отдельный массив
    int diff = maxLen - minLen; 

    for(int i = maxLen - 1; i >= diff; i--){
        number2[i] = number2temp[i - diff];
    }

    // добавление ведущих нулей, если это необходимо
    for(int i = 0; i < maxLen - minLen; i++){
        number2[i] = 0;
    }


    int ansLen = maxLen + 1;

    cornerFix = ((ansLen > maxLen ? 1 : 0));

    short* summ = new short[ansLen];

    // Обнуление ответа
    for(int i = 0; i < ansLen; i++){
        summ[i] = 0;
    }


    // Переменная для переноса
    int p = 0;

    // Цикл сложения с конца
    for(int i = maxLen - 1; i >= 0; i--){
        // s - сумма цифр
        int s = 0;

        s = number1[i] + number2[i] + p;
        
        // Разделение суммы для переноса и записи
        // p - десятки; s - единицы
        p = s / 10;
        s %= 10; 

        summ[i + cornerFix] = s;
    }

    if(p > 0){
        summ[0] += p;
    }


    // очистка памяти и вывод
    number1 = NULL;
    number2temp = NULL;
    number2 = NULL;
    temp = NULL;
    delete[] number1, number2temp, number2, temp;

    return summ;
}

// Вычитание больших чисел
short* subtNums(short* numt, short* numz, int n1, int n2){
    // длина максимального и минимального числа
    int maxLen = max(n1, n2);
    int minLen = min(n1, n2);
    
    // создание массивов для чисел
    short* number1 = numt;
    short* number2temp = numz;


    // замена массивов местами, чтобы number1 был б`ольшим числом
    short* temp = number1;

    if(isBigger(number2temp, number1, n2, n1)){
        number1 = number2temp;
        number2temp = temp;
    }


    // Формирование меньшего числа
    short* number2 = new short[maxLen];

    // запись цифр числа в отдельный массив
    int diff = maxLen - minLen; 

    for(int i = maxLen - 1; i >= diff; i--){
        number2[i] = number2temp[i - diff];
    }

    // добавление ведущих нулей, если это необходимо
    for(int i = 0; i < maxLen - minLen; i++){
        number2[i] = 0;
    }

    // Теперь number1 - б`ольшое число, number2 - меньшее число (с ведущими нулями)

    // создание итогового массива 
    int ansLen = maxLen;
    short* answer = new short[ansLen];


    // цикл вычитания
    for(int i = maxLen; i >= 0; i--){
        short a = number1[i] - number2[i];
        
        if(a < 0){
            a += 10;
            number1[i - 1] -= 1;
        }

        answer[i] = a;
    }


    // очистка памяти 
    number1 = NULL;
    number2temp = NULL;
    number2 = NULL;
    temp = NULL;
    delete[] number1, number2temp, number2, temp;

    return answer;
}

int main(){
    // создание чисел
    int n1, n2;
    
    // Ввод первого числа
    cout << "Введите длину первого числа:\n";
    cin >> n1;
    short* num1 = inputBigNum(n1);

    // Ввод второго числа
    cout << "Введите длину второго числа:\n";
    cin >> n2;
    short* num2 = inputBigNum(n2);
    

    // вывод чисел
    cout << "Число 1:\n";
    for(int i = 0; i < n1; i++) cout << num1[i];

    cout << '\n';

    cout << "Число 2:\n";
    for(int i = 0; i < n2; i++) cout << num2[i];
     
    cout << '\n';


    // сложение
    short* addResult = addNums(num1, num2, n1, n2);
    cout << "Результат сложения:\n";

    // вывод результата сложения
    for(int i = 0; i < max(n1, n2) + cornerFix; i++){
        if (!(i == 0 && addResult[0] == 0)){
            cout << addResult[i];
        }
    }

    cout << '\n';


    // вычитание
    short* subtResult = subtNums(num1, num2, n1, n2);
    cout << "Результат вычитания:\n";

    // вывод результата вычитания
    for(int i = 0; i < max(n1, n2); i++){
        cout << subtResult[i];
    }

    cout << '\n';


    // освобождение памяти
    delete[] addResult, subtResult;
    delete[] num1, num2;
}