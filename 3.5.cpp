// Метод Карацубы

// Сделать так, чтобы всегда было четное количество разрядов
// Сделать рекурсию

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

// Ускоренное сложение (вывод числа без ведущих нулей)
short* quickAddNums(short* num1, short* num2, int n1, int n2){
    // длина максимального и минимального числа
    int maxLen = max(n1, n2);
    int minLen = min(n1, n2);
    
    // создание массивов для чисел
    short* number1 = num1;
    short* number2temp = num2;


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
    
    // number1 - б`ольшее число, number2 - меньшее число с ведущими нулями



    // создание массивов для промежуточной суммы и переносов
    int ansLen = maxLen + 1;

    // промежуточная сумма
    short* sum = new short[ansLen];

    for(int i = maxLen - 1; i >= 0; i--){
        sum[i + 1] = number1[i];
    }
    sum[0] = 0;

    // переносы
    short* p = new short[ansLen];
    for(int i = maxLen - 1; i >= 0; i--){
        p[i + 1] = number2[i];
    }
    p[0] = 0;


    bool loop = true;

    while(loop){
        // проверка, обнулены ли все остатки
        loop = false;

        for(int i = 0; i < ansLen; i++){
            if(p[i] != 0){
                loop = true;
                break;
            }
        }

        if(!loop){
            break;
        }
        
        // Создание временной переменной для переноса 
        short* peren = new short[ansLen];

        // Итерация сложения
        for(int i = ansLen - 1;  i >= 0; i--){
            int a = p[i] + sum[i];
            
            if(a < 10){
                sum[i] = a;
            }

            else{
                sum[i] = a % 10;
                peren[i - 1] = a / 10;
            }
        }

        p = peren;
        peren = NULL;
        delete[] peren;
    }


    p = NULL;
    number1 = NULL;
    number2temp = NULL;
    number2 = NULL;
    temp = NULL;
    delete[] number1, number2temp, number2, temp, p;

    // если первый элемент числа - ноль
    if(sum[0] == 0){
        short* sum2 = new short[ansLen - 1];

        for(int i = 1; i <= ansLen; i++){
            sum2[i - 1] = sum[i];
        }
        
        delete[] sum;
        return sum2;
    }

    return sum;
}

short* Karatsuba(short* num1, short* num2, int n1, int n2){
    // длина максимального и минимального числа
    int maxLen = max(n1, n2);
    int minLen = min(n1, n2);
    
    // создание массивов для чисел
    short* number1 = num1;
    short* number2temp = num2;

    
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
    
    // number1 - б`ольшее число, number2 - меньшее число с ведущими нулями


    // Массив для ответа
    int ansLen = n1 + n2;
    short* sum = new short[ansLen];
    
    // Обнуление ответа
    for(int i = 0; i < ansLen; i++){
        sum[i] = 0;
    }


    // Создание промежуточных чисел
    short* A = new short[n1];
    short* B = new short[n2];
    short* C = new short[ansLen];

    // Если числа длиннее двух символов
    if(maxLen > 2){
        // Рекурсия
    }

    else{
    }


    // Очистка памяти
    A = NULL;
    B = NULL;
    C = NULL;
    number1 = NULL;
    number2temp = NULL;
    number2 = NULL;
    temp = NULL;
    delete[] number1, number2temp, number2, temp, A, B, C;

    return sum;
}


int main(){

}