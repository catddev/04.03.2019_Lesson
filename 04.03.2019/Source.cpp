#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>

using namespace std;

// 1.	Подсчитать количество слов во введенном предложении.
// a)	* между словами находится только 1 пробел
// b)	**пробелы также могут располагаться вначале и в конце предложения.
// c)	***пробелы могут располагаться вначале и в конце предложения, и между словами может быть более 1 пробела.

int countWords(const char *s) {
	int count = 0;
	for(int i=0; i<strlen(s); i++)
	{
		if (s[i] == ' ') count++;
	}
	return count + 1;
}
int countWordsByPtr(const char *s) {
	int count = 0;
	while(*s++!='\0')
	{
		if (*s == ' ') count++;
	}
	return count + 1;
}

int lotSpaces(const char*s) {
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (i == 0 || i == strlen(s) - 1) continue;
		if (s[i] == ' ') count++;
	}
	return count + 1;

}
int countOnlyWords(const char*s) {
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			if (i == strlen(s) - 1) continue;
			count++;
		}
	}
	if (s[0]==' ') return count;

	return count + 1;
}
// another variant
int countOnlyWords2(const char*s) {
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i - 1] == ' ') continue;
		if (s[i] == ' ') count++;
	} 
	if (s[0] == ' ') count--;
	if (s[strlen(s) - 1]==' ') count--;

	return count + 1;
}

//own strlen
int countStr(const char*s) {
	int k = 0;
	while (*s++ != '\0')
		k++;

	return k;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str[50] = "text";
			char s[50];
			for (int i = 0; i < strlen(str); i++)
			{
				s[i] = str[i]; // не копирует конец строки '\0';
			}
			s[strlen(str)] = '\0'; // вставляем '\0' сами
			cout << s << endl;

			for (int i = 0; i < strlen(str)/2; i++) // до половины скопировать
			{
				s[i] = str[i]; 
			}
			s[strlen(str)/2] = '\0';
			cout << s << endl;

			cin >> str; // cin считывает только до пробела, потом игнор
			cout << str << endl;

			cin.getline(str, 10); // кол-во считываемых символов, включая \0
			cin.getline(str, 50, '.'); // считает до указанного разделителя '.'
			cin.getline(str, 50, 48); // 48 - ASCII код нуля, считает до '0'

			cout << str << endl;

		}
		break;
		case 2: // 1 a
		{
			char str[100];
			cin.getline(str, 100);

			//cout << countWords(str) << endl;
			//cout << countWordsByPtr(str) << endl;

			//// 1 b
			//cout << lotSpaces(str) << endl;

			// 1 c
			cout << countOnlyWords(str) << endl;

			cout << countOnlyWords2(str) << endl;

		}
		break;
		case 3:
		{
			char str[100] = "text";
			// error: str = "Hello";

			strcpy_s(str, "Hello"); // записывает текст в массив, копирует
			cout << str << endl;
			strncpy_s(str, "Hello", 2); // копирует первые 2 символа (n)
			cout << str << endl;
		}
		break;
		case 4:
		{
			char str1[100], str2[100] = "Hello World";
			strcpy_s(str1, str2);
			cout << str1 << endl;
			strncpy_s(str1, str2 + strlen(str2) - 1, 1); // копирует последний символ второй строки
			cout << str1 << endl;
			strcpy_s(str1, str2 + strlen(str2) / 2); // в первую строку копирует вторую начиная с позиции по указателю str2+половина длины второй строки
			cout << str1 << endl;
			strncpy_s(str1, str2 + strlen(str2) / 2, 3); // (n)
			cout << str1 << endl;
			strncpy_s(str2, str2, 3);
			cout << str2 << endl;
			cout << str2[4] << endl;
		}
		break;
		case 5:
		{
			char str1[100]="Hoho", str2[100]="Hoha";
			cout << strcmp(str1, str2) << endl; //возвращает 1 если первая строка больше, 0 - если вторая больше. Сравнение идет по ASCII коду цифры, например, 'H'='H', далее 'e' больше, чем'a', стоп
			// но сранивает НЕ СУММУ, сравнение прерывается на первом символеб где появляется разница
			// если вторая строка больше вернет (-1)
			// если строки равны вернет 0;
			char str3[100] = "Halloasmb", str4[100] = "Hallob";
			cout << strcmp(str3, str4) << endl;

			cout << strncmp(str3, str4, 3) << endl; // сравнивает первые 3 символа
			cout << strcmp(str3+strlen(str3)-2, str4+strlen(str4)-2) << endl; // сравнивает только последние 2 символа

			// ОБЪЕДИНЕНИЕ
			strcat_s(str1, str2); // в конец первой строки записываем вторую
			cout << str1 << endl;
			strcat_s(str2, " "); // сначала можно добавить пробел, чтобы разделить слова из разных строк
			strcat_s(str2, str1);
			cout << str2 << endl;
			strncat_s(str2, str1, 3); // прилепить первые 3 символа
			cout << str2 << endl;
		}
		break;
		case 6:
		{
			// РАЗБИТИЕ НА СЛОВА
			char str1[50] = "This is my example for you. For my students!";
			char *p, *context;

			p = strtok_s(str1, " ", &context); // token, вычленяет часть строки до " ", сохраняет в Р адрес первой подстроки, начало оставшейся части сохранет в context, перед которым ставит NULL

			while (p != NULL)
			{
				cout << p << endl;  
				p = strtok_s(NULL, " ", &context);
				// p = strtok_s(context, " ", &context); // либо так без NULL
			}

			cout << endl;
		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}