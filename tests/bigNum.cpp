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


int main(){
    // ввод длины числа
    int n = 0;
    cin >> n;

    // создание динамического массива
    short* num1 = bigNum(n);

    // вывод числа
    for(int i = 0; i < n; i++) cout << num1[i];

    // освобождение памяти
    delete[] num1;
}