// Известные проблемы:
// Функция сложения выглядит отвратно

#include <iostream>

using namespace std;


// Генератор чисел фон Неймана длины x без проверки на первый ноль
short fonNeyman(unsigned int x){
    if(x < 8){
        // seed
        static double A = 8691454555;

        // get the number from which to get the random value
        string B = to_string(A*A);
        string num = "";

        // index to start building randomized value from
        int n = 10;
        

        // build randomized value with numbers taken from the middle of the original number (from 5th to (x-1)th)
        for(int i = n; i <= n + x - 1; i++){
            // check if value starts with 0 and if it does replace 0  with 1
            /*if(i == n && B[i] == '0'){
                num += '1';
            }

            else{
                num += B[i];
            }*/
            num += B[i];
        }


        // replace A with B for different results, checking if the first number is 0 and replacing it with 1 in that case
        if(B[4] == '0'){
            B[4] = '1';
        }

        A = stod(B.substr(4, 11));
    

        // return final randomized value
        int out = stoi(num);
        
        return(out);
    }


    else{
        cout << "x must be less than 8";
    }
    
    return 0;
}

// Создание большого числа длины n
short* bigNum(int n){
    // создание динамического массива
    short* num = new short[n];

    // цикл создания и вывода числа
    for(int i = 0; i < n; i++){
        // проверка, чтобы первая цифра не была равна нулю
        if(i == 0){
            num[i] = (num[i] == 0 ? 1 : num[i]);
        }
        
        // создание и вывод случайной цифры
        num[i] = fonNeyman(1);
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

        for(int i = max(n1, n2); i >= 0; i--){

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

// Сложение больших чисел (Удалить массив по указателю после использования)
short* addNums(short* numt, short* numz, int n1, int n2){
    int maxLen = max(n1, n2);
    int minLen = min(n1, n2);
    
    short* number1 = numt;
    short* number2 = numz;

    // замена массивов местами, чтобы number1 был б`ольшим числом
    short* temp = number1;

    if(isBigger(number2, number1, n1, n2)){
        number1 = number2;
        number2 = temp;
    }


    int ansLen = (((maxLen == minLen) && (number1[0] + number2[0] > 9)) ? maxLen + 1 : maxLen); 

    short* summ = new short[ansLen];

    // Обнуление ответа
    for(int i = 0; i < ansLen; i++){
        summ[i] = 0;
    }


    // Переменная для переноса
    int p = 0;

    // Цикл сложения с конца до начала меньшего числа
    for(int i = maxLen - 1; i >= maxLen - minLen; i--){
        // s - сумма цифр
        int s = 0;

        s = number1[i] + number2[i] + p;
        
        // Разделение суммы для переноса и записи
        // p - десятки; s - единицы
        p = s / 10;
        s %= 10; 

        summ[i] = s;
    }

    // Добавление оставшихся цифр большего числа
    if(p > 0){
        summ[maxLen - minLen - 1] += p;
    }

    for(int i = 0; i < maxLen - minLen - 1; i++){
        summ[i] = number1[i];
    }

    // очистка памяти и вывод
    temp = NULL;
    number1 = NULL;
    number2 = NULL;

    delete[] temp, number1, number2;

    return summ;
}


int main(){
    // создание чисел
    int n1, n2;
    cin >> n1;

    short* num1 = bigNum(n1);

    cin >> n2;

    short* num2 = bigNum(n2);
    

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
    for(int i = 0; i < max(n1, n2); i++){
        cout << addResult[i];
    }


    // освобождение памяти
    delete[] addResult;
    delete[] num1, num2;
}