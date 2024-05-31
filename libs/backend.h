#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>

using namespace std;

// Типы для удобства
typedef map<string, double> Variables; // Переменные
typedef map<string, vector<double>> Massives; // Массивы

// Типы токенов
enum tokentype {
    var, num, op_br, cl_br, func, op, mas, op_sbr, cl_sbr
};

// Структура для токенов
struct token {
    string name;
    tokentype type;

    token(string str, tokentype typ) {
        name = str;
        type = typ;
    }
    token() {}
};

// Тип для вектора токенов
typedef vector<token> tokens;

// Множество разделителей
extern set<char> DelimSet;
extern const string delimiters;

// Функция для создания множества разделителей
void CreateSetOfDelimiters();

// Проверка, является ли символ разделителем
bool IsDelimiter(char sym);

// Функция для создания токенов из выражения
void CreateTokensFromExpression(string& expr, tokens& texpr);

// Приоритеты операторов
extern map<string, int> prior;

void CreatePrior();

// Создание постфиксной записи из токенов
void CreatePostfixFromTokens(tokens& texpr, tokens& pexpr);

// Тип функции для операций
typedef double(*func_type)(stack<double>&);

// Карта операций
extern map<string, func_type> ops;

// Реализация операций
double fact(double n);
double op_plus(stack<double>& s);
double op_minus(stack<double>& s);
double op_mul(stack<double>& s);
double op_div(stack<double>& s);
double op_deg(stack<double>& s);
double op_opposite(stack<double>& s);
double op_factorial(stack<double>& s);
double op_odiv(stack<double>& s);
double op_and(stack<double>& s);
double op_or(stack<double>& s);
double op_not(stack<double>& s);
double op_sin(stack<double>& s);
double op_cos(stack<double>& s);
double op_tan(stack<double>& s);
double op_asin(stack<double>& s);
double op_acos(stack<double>& s);
double op_atan(stack<double>& s);

void CreateOps();

// Вычисление результата выражения
double ResultExpr(tokens& pexpr, Variables& expvars, Massives& varmas);

tokens getExpr(string expr);

double getDot(string s, double a);

double tryDif(string s, double x);

#endif // BACKEND_H
