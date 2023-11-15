#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// спрашивать продолжать ли операции после каждого шага

// Калькулятор по основам программирования должен быть консольным, 
// включать в себя действия (с числами) +-*/^ (защита от деления на 0) 
// и действия с матрицами од ного формата +-. а также должен повторять действие, 
// т.е. должна быть возможность продолжить работать в калькуляторе, не закрывая его. 
// Все действия должны быть представлены в виде функций. готовый результат надо загрузить на GitHub
// и в лс в телеграмм прислать преподавателю, указав свое ФИО, группу и название предмета. 
// Сделать по возможности до следующей недели.


void num_plus(double a, double b) {
    cout << a+b << "\n";
    return;
}

void num_minus(double a, double b) {
    cout << a-b << "\n";
    return;
}

void num_mult(double a, double b) {
    cout << a*b << "\n";
    return;
}

void num_pow(double a, double b) {
    cout << pow(a, b) << "\n";
    return;
}

void num_div(double a, double b) {
    if (b == 0) {
        cout << "Divizion by zero\n";
    } else {
        cout << a/b << "\n";
    }
    return;
}

int calc_num() {
    double a, b;
    char operation;
    cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b | a^b\n";
    cin >> a >> operation >> b;
    while(cin.fail()) {
        cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b | a^b\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> a >> operation >> b;
    }
    switch (operation) {
        case '+':
            num_plus(a, b);
            break;
        case '-':
            num_minus(a, b);
            break;
        case '*':
            num_mult(a, b);
            break;
        case '/':
            num_div(a, b);
            break;
        default:
            cout << "Wrong operation\n";
            break;
    }

    return 0;
}

void print_matrix(vector<vector<double>> A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void sum_matrix(vector<vector<double>> A, vector<vector<double>> B) {
  if (A.size() != B.size() || A[0].size() != B[0].size()) {
    cout << "Calculation error\n";
    return;
  }
  vector<vector<double>> result(A.size(), vector<double> (A[0].size(), 0));
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  }
  cout << "Result:\n";
  print_matrix(result);
  return;
}

void minus_matrix(vector<vector<double>> A, vector<vector<double>> B) {
  if (A.size() != B.size() || A[0].size() != B[0].size()) {
    cout << "Calculation error\n";
    return;
  }
  vector<vector<double>> result(A.size(), vector<double> (A[0].size(), 0));
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      result[i][j] = A[i][j] - B[i][j];
    }
  }
  cout << "Result:\n";
  print_matrix(result);
  return;
}

int calc_matrix() {
    int a_r, a_c, b_r, b_c;
    cout << "Enter number of rows of the first matrix\n";
    cin >> a_r;
    while(cin.fail()) {
        cout << "Incorrect input. Enter number of rows of the first matrix\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> a_r;
    }
    cout << "Enter number of columns of the first matrix\n";
    cin >> a_c;
    while(cin.fail()) {
        cout << "Incorrect input. Enter number of columns of the first matrix\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> a_c;
    }
    while (a_r <= 0 || a_c <= 0) {
        cout << "Incorrect input\n";
        cout << "Enter number of rows of the first matrix\n";
        cin >> a_r;
        cout << "Enter number of columns of the first matrix\n";
        cin >> a_c;
    }
    vector<vector<double>> a(a_r, vector<double> (a_c, 0));;
    for (int i = 0; i < a_r; i++) {
        for (int j = 0; j < a_c; j++) {
            cout << "Enter a[" << i << "][" << j << "] element\n";
            cin >> a[i][j];
            while(cin.fail()) {
                cout << "Incorrect input. Enter a[" << i << "][" << j << "] element\n";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> a[i][j];
            }
        }
    }
    cout << "Enter number of rows of the second matrix\n";
    cin >> b_r;
    while(cin.fail()) {
        cout << "Incorrect input. Enter number of rows of the secon matrix\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> b_r;
    }
    cout << "Enter number of columns of the second matrix\n";
    cin >> b_c;
    while(cin.fail()) {
        cout << "Incorrect input. Enter number of columns of the second matrix\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> b_c;
    }
    while (b_r <= 0 || b_c <= 0) {
        cout << "Incorrect input\n";
        cout << "Enter number of rows of the second matrix\n";
        cin >> b_r;
        cout << "Enter number of columns of the second matrix\n";
        cin >> b_c;
    }
    vector<vector<double>> b(b_r, vector<double> (b_c, 0));;
    for (int i = 0; i < b_r; i++) {
        for (int j = 0; j < b_c; j++) {
            cout << "Enter b[" << i << "][" << j << "] element\n";
            cin >> b[i][j];
            while(cin.fail()) {
                cout << "Incorrect input. bEnter [" << i << "][" << j << "] element\n";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> b[i][j];
            }
        }
    }
    char operation;
    cout << "Enter operation (+ or -)\n";
    cin >> operation;
    while (cin.fail()) {
        cout << "Incorrect input. Enter operation (+ or -)\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> operation;
    }
    if (operation == '+') {
        sum_matrix(a, b);
    } else if (operation == '-') {
        minus_matrix(a, b);
    } else {
        cout << "Wrong operation\n";
    }
    return 0;
}

int main() {
    char to_continue = 'y';
    cout << "Select data type:\n'm' - for matrix\n'n' - for numbers\n";
    char nom = 'n';
    cin >> nom;
    while (to_continue == 'y') {
        switch (nom) {
            case 'n':
                calc_num();
                break;
            case 'm':
                calc_matrix();
                break;
            default:
                while (nom != 'n' && nom != 'm') {
                    cout << "Incorrect data type:\n'm' - for matrix\n'n' - for numbers\n";
                    cin >> nom;
                }
        }

        cout << "'y' - to continue\n'q' - to quit\n'c' - to change data type and continue\n";
        cin >> to_continue;
        while (to_continue != 'y' && to_continue != 'q' && to_continue != 'c') {
            cout << "Incorrect input:\n'y' to continue\n'q' to quit\n'c' to change data type and continue\n";
            cin >> to_continue;
        }
        if (to_continue == 'c') {
            cout << "Select data type:\n'm' - for matrix\n'n' - for numbers\n";
            cin >> nom;
            to_continue = 'y';
        }

        // to_continue = 0;
    }




    return 0;
}