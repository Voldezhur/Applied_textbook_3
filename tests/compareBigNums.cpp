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

int isBigger(short* num1, short* num2){

    int n1 = sizeof(num1);
    int n2 = sizeof(num2); 

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


    // сравнение
    int result = isBigger(num1, num2);
    cout << (result == 1 ? "Первое число больше второго" : result == 0 ? "Второе число больше первого" : "Числа равны");


    // освобождение памяти
    delete[] num1, num2;
}