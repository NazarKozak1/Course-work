#define _CRT_SECURE_NO_WARNINGS
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#include <string>
#include <time.h>
#include<fstream>
#include <iostream>
#include <conio.h> 
#include <windows.h>
using namespace std;

string questions[10] = { "Герцогиня Англії XVIII століття Сара Черчілль говорила : \"Ви молоді, $якщо ви ще здатні ...\"",
						"В Австралії на парковках біля деяких торгових центрів по ночах і вечорах $вмикають класичну музику, щоб відлякати когось.Кого саме ?",
						"У словнику Володимира Івановича Даля зустрічається старовинна назва $барометра.Яка ?",
						"Англійський письменник Кіплінг говорив : «Жіноча інтуїція набагато $точніше, ніж чоловіча...»",
						"Якого слова немає в мові народів Арктики ?",
						"Сусіди по вулиці знали Дмитра Івановича Менделєєва як чудового майстра $з виготовлення чого ?",
						"Одного разу в знамениту французьку в'язницю Бастилію ув'язнили не людину, $а якесь видання.Яке ?",
						"Квітка дельфиніума синя.В середні віки існувала думка, ніби цей колір $благотворно впливає на втомлені очі людини.Тому квітки дельфініума $розвішували в приміщеннях, де зазвичай займалися ... Чим ?",
						"Американський письменник Марк Твен був великим жартівником.Одного $разу він зробив жінці комплімент, захопившись її красою.$Та не належала до прихильниць Твена і відповіла : «На жаль, не можу $сказати про вас того ж».На що письменник мудро зауважив : «А ви зробіть, $як я ...».Що вона повинна була зробити ?",
						"Польський письменник Станіслав Лем написав збірку оповідань під назвою $«Абсолютна порожнеча».До цієї збірки увійшли рецензії на книги.Які ?" };

string answers[10] = { "розчаровуватися",
					  "підліток",
					  "буревісник",
					  "впевненість",
					  "війна",
					  "валіза",
					  "енциклопедія",
					  "вишивання",
					  "збрехати",
					  "вигадані" };

struct letters_info {

	COORD loc;
	char symbol;
	bool visible;

}*letter;

int len(string a) {
	for (int i = 0; i < 20; i++) {
		if (a[i] == '\0') return i;
	}
}

void print_ramk(HANDLE console) {
	COORD loc;
	SetConsoleOutputCP(866);

	loc.X = 11;
	loc.Y = 1;
	SetConsoleCursorPosition(console, loc);
	unsigned char c = 457;
	cout << c;
	c = 461;

	int krok = 0;

	for (krok = 0; krok < 77; krok++) {
		cout << c;
	}

	c = 443;
	cout << c;


	loc.X = 89;

	c = 442;

	for (krok = 0; krok < 20; krok++) {
		loc.Y++;
		SetConsoleCursorPosition(console, loc);
		cout << c;

	}
	loc.Y++;
	SetConsoleCursorPosition(console, loc);

	c = 444;
	cout << c;

	c = 461;

	for (krok = 0; krok < 77; krok++) {
		loc.X--;
		SetConsoleCursorPosition(console, loc);
		cout << c;
	}
	loc.X--;
	SetConsoleCursorPosition(console, loc);

	c = 456;
	cout << c;

	c = 442;

	for (krok = 0; krok < 20; krok++) {
		loc.Y--;
		SetConsoleCursorPosition(console, loc);
		cout << c;
	}

	SetConsoleOutputCP(1251);
}

int input_one_letter(HANDLE console, letters_info* letter, int length) {
	int coins = 0;
	COORD loc;
	char a;
	SetConsoleTextAttribute(console, 7);
	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "Введіть символ: ";
	cin >> a;

	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "                                        ";

	for (int i = 0; i < length; i++) {
		if (letter[i].symbol == a) {
			if (letter[i].visible == true);
			else {
				SetConsoleCursorPosition(console, letter[i].loc);
				letter[i].visible = true;
				cout << letter[i].symbol;
				coins = coins + 1;
			}
		}

	}


	loc.X = 0;
	loc.Y = 17;

	for (int i = 0; i < 18; i++) {
		SetConsoleCursorPosition(console, loc);
		cout << "       ";

		loc.Y++;
	}

	print_ramk(console);


	return coins;
}

char input_word(HANDLE console, letters_info* letter, int length) {
	int score = 0;
	COORD loc;
	char a[20];
	SetConsoleTextAttribute(console, 7);

	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "Введіть слово: ";
	cin >> a;


	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "                                                   ";

	if (len(a) != length) {
		SetConsoleTextAttribute(console, 7);
		return 'm';
	}

	else {
		for (int i = 0; i < length; i++) {
			if (a[i] != letter[i].symbol) return 'm';
		}

		for (int i = 0; i < length; i++) {
			loc.X = letter[i].loc.X;
			loc.Y = letter[i].loc.Y;
			SetConsoleCursorPosition(console, loc);
			cout << letter[i].symbol;
		}

		//end_game(console);


		return 'w';
	}

}



void print_question(HANDLE console, string a) {

	COORD loc;

	loc.X = 15;
	loc.Y = 5;
	SetConsoleCursorPosition(console, loc);

	for (int i = 0; i < 350; i++) {
		if (a[i] == '\0') break;
		else {
			if (a[i] == '$') {
				cout << "\n";
				loc.X = 15;
				loc.Y++;
				SetConsoleCursorPosition(console, loc);
			}
			else cout << a[i];
		}
	}
}

void print_place_for_answer(HANDLE console, string answer, letters_info* letter) {
	COORD loc;

	int length = len(answer);

	loc.X = (77 - (2 * length - 1)) / 2 + 11;
	loc.Y = 12;

	SetConsoleCursorPosition(console, loc);
	//letter = new letters_info[length - 1];

	for (int i = 0; i < length; i++) {
		cout << " _";
	}

	letter[0].loc.X = loc.X + 1;
	letter[0].loc.Y = 12;
	letter[0].symbol = answer[0];
	letter[0].visible = false;
	for (int i = 1; i < length; i++) {
		letter[i].loc.X = letter[i - 1].loc.X + 2;
		letter[i].loc.Y = 12;
		letter[i].symbol = answer[i];
		letter[i].visible = false;
	}

	//return letter;
}


void menu_in_game(HANDLE console, int one_letter, int all_word, int boost, int exit) {

	COORD coord;

	if (one_letter == 1) {
		SetConsoleTextAttribute(console, 2);
		coord.X = 22;
		coord.Y = 14;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести  літеру";

		SetConsoleTextAttribute(console, 7);
		coord.X = 41;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести слово";


		SetConsoleTextAttribute(console, 7);
		coord.X = 58;
		SetConsoleCursorPosition(console, coord);
		cout << "буст";

		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";

		SetConsoleTextAttribute(console, 7);
	}

	if (all_word == 1) {
		SetConsoleTextAttribute(console, 7);
		coord.X = 22;
		coord.Y = 14;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести  літеру";

		SetConsoleTextAttribute(console, 2);
		coord.X = 41;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести слово";

		SetConsoleTextAttribute(console, 7);
		coord.X = 58;
		SetConsoleCursorPosition(console, coord);
		cout << "буст";

		SetConsoleTextAttribute(console, 7);
		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";

		SetConsoleTextAttribute(console, 7);
	}

	if (boost == 1) {
		SetConsoleTextAttribute(console, 7);
		coord.X = 22;
		coord.Y = 14;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести  літеру";

		SetConsoleTextAttribute(console, 7);
		coord.X = 41;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести слово";

		SetConsoleTextAttribute(console, 2);
		coord.X = 58;
		SetConsoleCursorPosition(console, coord);
		cout << "буст";

		SetConsoleTextAttribute(console, 7);
		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";

		SetConsoleTextAttribute(console, 7);
	}

	if (exit == 1) {
		SetConsoleTextAttribute(console, 7);
		coord.X = 22;
		coord.Y = 14;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести  літеру";

		SetConsoleTextAttribute(console, 7);
		coord.X = 41;
		SetConsoleCursorPosition(console, coord);
		cout << "ввести слово";

		SetConsoleTextAttribute(console, 7);
		coord.X = 58;
		SetConsoleCursorPosition(console, coord);
		cout << "буст";

		SetConsoleTextAttribute(console, 2);
		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";

		SetConsoleTextAttribute(console, 7);
	}
}


void output(HANDLE console, int start_, int shop_, int help_, int rekordy_, int exit_) {


	COORD coord;

	if (start_ == 1) {

		coord.X = 24;
		coord.Y = 12;
		SetConsoleCursorPosition(console, coord);
		SetConsoleTextAttribute(console, 2);
		cout << "почати";

		SetConsoleTextAttribute(console, 7);

		coord.X = 34;
		SetConsoleCursorPosition(console, coord);
		cout << "магазин";

		coord.X = 45;
		SetConsoleCursorPosition(console, coord);
		cout << "допомога";

		coord.X = 57;
		SetConsoleCursorPosition(console, coord);
		cout << "історія";


		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";
	}

	if (shop_ == 1) {

		coord.X = 24;
		coord.Y = 12;

		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "почати";


		coord.X = 34;
		SetConsoleTextAttribute(console, 2);
		SetConsoleCursorPosition(console, coord);
		cout << "магазин";


		coord.X = 45;
		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "допомога";


		coord.X = 57;
		SetConsoleCursorPosition(console, coord);
		cout << "історія";


		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";
	}

	if (help_ == 1) {

		coord.X = 24;
		coord.Y = 12;

		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "почати";


		coord.X = 34;
		SetConsoleCursorPosition(console, coord);
		cout << "магазин";


		coord.X = 45;
		SetConsoleTextAttribute(console, 2);
		SetConsoleCursorPosition(console, coord);
		cout << "допомога";


		coord.X = 57;
		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "історія";


		coord.X = 67;
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";
	}

	if (rekordy_ == 1) {

		coord.X = 24;
		coord.Y = 12;

		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "почати";


		coord.X = 34;
		SetConsoleCursorPosition(console, coord);
		cout << "магазин";


		coord.X = 45;
		SetConsoleCursorPosition(console, coord);
		cout << "допомога";


		coord.X = 57;
		SetConsoleTextAttribute(console, 2);
		SetConsoleCursorPosition(console, coord);
		cout << "історія";


		coord.X = 67;
		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";
	}

	if (exit_ == 1) {
		coord.X = 24;
		coord.Y = 12;

		SetConsoleTextAttribute(console, 7);
		SetConsoleCursorPosition(console, coord);
		cout << "почати";


		coord.X = 34;
		SetConsoleCursorPosition(console, coord);
		cout << "магазин";


		coord.X = 45;
		SetConsoleCursorPosition(console, coord);
		cout << "допомога";


		coord.X = 57;
		SetConsoleCursorPosition(console, coord);
		cout << "історія";


		coord.X = 67;
		SetConsoleTextAttribute(console, 4);
		SetConsoleCursorPosition(console, coord);
		cout << "вихід";
	}

	COORD loc;
	SetConsoleTextAttribute(console, 7);
	loc.X = 60;
	loc.Y = 19;
	SetConsoleCursorPosition(console, loc);
	SetConsoleOutputCP(866);
	cout << char(27) << '/' << char(26);
	SetConsoleOutputCP(1251);
	cout << " навігація, enter - вибір";


}

void dop(HANDLE console, int vybir) {
	int n = vybir % 5;
	if ((n == 1) || (n == -4)) output(console, 1, 0, 0, 0, 0);
	if ((n == 2) || (n == -3)) output(console, 0, 1, 0, 0, 0);
	if ((n == 3) || (n == -2)) output(console, 0, 0, 1, 0, 0);
	if ((n == 4) || (n == -1)) output(console, 0, 0, 0, 1, 0);
	if (n == 0) output(console, 0, 0, 0, 0, 1);
}

void dop2(HANDLE console, int vybir, string question, string answer) {
	int n = vybir % 4;
	if ((n == 1) || (n == -3)) menu_in_game(console, 1, 0, 0, 0);
	if ((n == 2) || (n == -2)) menu_in_game(console, 0, 1, 0, 0);
	if ((n == 3) || (n == -1)) menu_in_game(console, 0, 0, 1, 0);
	if (n == 0) menu_in_game(console, 0, 0, 0, 1);
}




int choose(HANDLE console) {

	output(console, 1, 0, 0, 0, 0);

	int key = 10;
	int vybir = 1;

	while (key != 13)
	{
		if (_kbhit() != 0)
		{
			key = _getch();

			if (key == 77) {
				vybir++;
				Sleep(10);
				dop(console, vybir);
			}

			if (key == 75) {
				vybir--;
				Sleep(10);
				dop(console, vybir);
			}
		}

	}

	return vybir;
};

int choose_in_game(HANDLE console, string question, string answer) {

	menu_in_game(console, 1, 0, 0, 0);

	int vybir = 1;
	int key = 0;
	int a = 0;

	while (key != 13) {
		if (_kbhit != NULL) {
			key = _getch();

			if (key == 77) {
				vybir++;
				Sleep(10);
				dop2(console, vybir, question, answer);
			}
			if (key == 75) {
				vybir--;
				Sleep(10);
				dop2(console, vybir, question, answer);
			}
		}
	}

	return vybir;
}

void output_exit(HANDLE console, int yes, int no) {

	COORD loc;

	if (yes == 1) {

		loc.X = 44;
		loc.Y = 18;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 2);
		cout << "так";

		loc.X = 56;
		loc.Y = 18;

		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 7);
		cout << "ні";
	}

	if (no == 1) {

		loc.X = 44;
		loc.Y = 18;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 7);
		cout << "так";

		loc.X = 56;
		loc.Y = 18;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 4);
		cout << "ні";

		SetConsoleTextAttribute(console, 7);
	}
}


void dop5(HANDLE console, int vybir) {

	vybir = vybir % 2;

	if ((vybir == 1) || (vybir == -1)) output_exit(console, 1, 0);
	if (vybir == 0) output_exit(console, 0, 1);

}

int choose_exit(HANDLE console) {

	int vybir = 1;
	int key = 0;

	while (key != 13)
	{
		if (_kbhit() != 0)
		{
			key = _getch();

			if (key == 77) {
				vybir++;
				Sleep(10);
				dop5(console, vybir);
			}

			if (key == 75) {
				vybir--;
				Sleep(10);
				dop5(console, vybir);
			}
		}

	}

	return vybir;

}

void show_score(HANDLE console, int score) {
	COORD loc;

	loc.Y = 3;
	loc.X = 15;
	SetConsoleCursorPosition(console, loc);



	cout << "к-сть монет: " << score;

}


void clear(HANDLE console) {

	COORD loc;

	loc.X = 13;
	loc.Y = 3;

	for (; loc.Y <= 20; loc.Y++) {
		SetConsoleCursorPosition(console, loc);
		cout << "                                                                            ";
	}
};

void clear_description(HANDLE console) {

	COORD loc;

	loc.X = 50;
	loc.Y = 7;
	SetConsoleCursorPosition(console, loc);
	for (int i = 0; i < 10; i++) {
		cout << "                                      ";
		loc.Y++;
		SetConsoleCursorPosition(console, loc);
	}

}


void return_return(int a[4]) {

	ifstream f;

	f.open("inf.txt");

	for (int i = 0; i <= 3; i++) {
		f >> a[i];
	}

	f.close();
}

void output_menu_in_shop(HANDLE console, int b1, int b2, int b3, int ex) {
	COORD loc;

	int a[4] = { 0,0,0,0 };
	return_return(a);

	if (b1 == 1) {

		clear_description(console);

		loc.X = 16;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 2);
		cout << "\"одна літера\"" << "(" << a[1] << ")";

		SetConsoleTextAttribute(console, 7);

		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "\"подвійні монети\"" << "(" << a[2] << ")";


		loc.Y = 13;
		SetConsoleCursorPosition(console, loc);

		cout << "\"+1 спроба\"" << "(" << a[3] << ")";

		loc.Y = 16;
		SetConsoleCursorPosition(console, loc);

		cout << "вихід";

		loc.X = 50;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);

		cout << "Введіть номер літери, щоб вивести її.\n";


		loc.X = 50;
		loc.Y = 8;
		SetConsoleCursorPosition(console, loc);

		cout << "Якщо введений номер не не відповідає";


		loc.X = 50;
		loc.Y = 9;
		SetConsoleCursorPosition(console, loc);

		cout << "жодній літері, або літера вже видна, ";


		loc.X = 50;
		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "то нічого не станеться";

		loc.X = 50;
		loc.Y = 11;
		SetConsoleCursorPosition(console, loc);

		cout << "(окрім того, що ви втратите буст)";

		loc.X = 50;
		loc.Y = 13;
		SetConsoleCursorPosition(console, loc);

		cout << "Ціна: 5 монет";
	}
	if (b2 == 1) {

		clear_description(console);

		loc.X = 16;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 7);
		cout << "\"одна літера\"" << "(" << a[1] << ")";

		SetConsoleTextAttribute(console, 2);

		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "\"подвійні монети\"" << "(" << a[2] << ")";

		SetConsoleTextAttribute(console, 7);
		loc.Y = 13;
		SetConsoleCursorPosition(console, loc);

		cout << "\"+1 спроба\"" << "(" << a[3] << ")";

		loc.Y = 16;
		SetConsoleCursorPosition(console, loc);

		cout << "вихід";

		loc.X = 50;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);

		cout << "можна використати тільки на початку ";

		loc.X = 50;
		loc.Y = 8;
		SetConsoleCursorPosition(console, loc);

		cout << "гри. У разі виграшу ви ";

		loc.X = 50;
		loc.Y = 9;
		SetConsoleCursorPosition(console, loc);

		cout << "отримуете подвійні монети.";

		loc.X = 50;
		loc.Y = 11;
		SetConsoleCursorPosition(console, loc);

		cout << "Ціна: 20 монет";
	}

	if (b3 == 1) {

		clear_description(console);

		loc.X = 16;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 7);
		cout << "\"одна літера\"" << "(" << a[1] << ")";

		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "\"подвійні монети\"" << "(" << a[2] << ")";

		SetConsoleTextAttribute(console, 2);
		loc.Y = 13;
		SetConsoleCursorPosition(console, loc);

		cout << "\"+1 спроба\"" << "(" << a[3] << ")";

		SetConsoleTextAttribute(console, 7);

		loc.Y = 16;
		SetConsoleCursorPosition(console, loc);

		cout << "вихід";

		loc.X = 50;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);

		cout << "Використайте, щоб отримати ";

		loc.X = 50;
		loc.Y = 8;
		SetConsoleCursorPosition(console, loc);

		cout << "ще одну спробу.";

		loc.X = 50;
		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "Ціна: 10 монет";

	}

	if (ex == 1) {

		clear_description(console);

		loc.X = 16;
		loc.Y = 7;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 7);
		cout << "\"одна літера\"" << "(" << a[1] << ")";


		loc.Y = 10;
		SetConsoleCursorPosition(console, loc);

		cout << "\"подвійні монети\"" << "(" << a[2] << ")";


		loc.Y = 13;
		SetConsoleCursorPosition(console, loc);

		cout << "\"+1 спроба\"" << "(" << a[3] << ")";

		loc.Y = 16;
		SetConsoleCursorPosition(console, loc);
		SetConsoleTextAttribute(console, 4);
		cout << "вихід";

	}

	SetConsoleTextAttribute(console, 7);
	loc.X = 60;
	loc.Y = 19;
	SetConsoleCursorPosition(console, loc);
	SetConsoleOutputCP(866);
	unsigned char symbol1 = 24, symbol2 = 25;
	cout << symbol1 << '/' << symbol2;
	SetConsoleOutputCP(1251);
	cout << " навігація, enter - вибір";
}


void dop3(HANDLE console, int vybir) {

	int n = vybir % 4;

	if ((n == 1) || (n == -3)) output_menu_in_shop(console, 1, 0, 0, 0);
	if ((n == 2) || (n == -2)) output_menu_in_shop(console, 0, 1, 0, 0);
	if ((n == 3) || (n == -1)) output_menu_in_shop(console, 0, 0, 1, 0);
	if (n == 0) output_menu_in_shop(console, 0, 0, 0, 1);


}

int choose_in_shop(HANDLE console, int h1, int  h2, int  h3) {

	int vybir = 1;

	if (h1 == 1) { output_menu_in_shop(console, 1, 0, 0, 0); vybir = 1; }
	if (h2 == 1) { output_menu_in_shop(console, 0, 1, 0, 0); vybir = 2; }
	if (h3 == 1) { output_menu_in_shop(console, 0, 0, 1, 0); vybir = 3; }



	int key = 0;

	while (key != 13)
	{
		if (_kbhit() != 0)
		{
			key = _getch();

			if (key == 80) {
				vybir++;
				Sleep(10);
				dop3(console, vybir);
			}

			if (key == 72) {
				vybir--;
				Sleep(10);
				dop3(console, vybir);
			}
		}

	}

	return vybir;

}





void write_to_info(int a[4]) {

	ofstream f;
	f.open("inf.txt", ios::trunc);

	for (int i = 0; i < 4; i++) {
		f << a[i] << "\n";
	}

	f.close();
}



void shop(HANDLE console) {

	int a[4] = { 0,0,0,0 };

	return_return(a);

	clear(console);

	COORD loc;
	loc.Y = 4;
	loc.X = 13;

	SetConsoleCursorPosition(console, loc);
	cout << "к-сть монет: " << a[0];

	loc.X = 50;
	SetConsoleCursorPosition(console, loc);

	cout << "пояснення:";

	int vybir = choose_in_shop(console, 1, 0, 0);

	loc.Y = 4;
	loc.X = 26;


	while (vybir % 4 != 0) {
		if (a[0] > 0) {
			if (((vybir % 4 == 1) || (vybir % 4 == -3)) && (a[0] - 5 >= 0)) { a[0] -= 5; SetConsoleCursorPosition(console, loc); cout << "      "; SetConsoleCursorPosition(console, loc);  cout << a[0];  a[1]++; write_to_info(a); output_menu_in_shop(console, 1, 0, 0, 0);  vybir = choose_in_shop(console, 1, 0, 0); }
			if (((vybir % 4 == 1) || (vybir % 4 == -3)) && (a[0] - 5 < 0)) vybir = choose_in_shop(console, 1, 0, 0);
			if (((vybir % 4 == 2) || (vybir % 4 == -2)) && (a[0] - 20 >= 0)) { a[0] -= 20; SetConsoleCursorPosition(console, loc); cout << "      "; SetConsoleCursorPosition(console, loc); cout << a[0];  a[2]++;  write_to_info(a); output_menu_in_shop(console, 0, 1, 0, 0); vybir = choose_in_shop(console, 0, 1, 0); }
			if (((vybir % 4 == 2) || (vybir % 4 == -2)) && (a[0] - 20 < 0)) vybir = choose_in_shop(console, 0, 1, 0);
			if (((vybir % 4 == 3) || (vybir % 4 == -1)) && (a[0] - 10 >= 0)) { a[0] -= 10; SetConsoleCursorPosition(console, loc); cout << "      "; SetConsoleCursorPosition(console, loc); cout << a[0];  a[3]++;  write_to_info(a); output_menu_in_shop(console, 0, 0, 1, 0); vybir = choose_in_shop(console, 0, 0, 1); }
			if (((vybir % 4 == 3) || (vybir % 4 == -1)) && (a[0] - 10 < 0))  vybir = choose_in_shop(console, 0, 0, 1);
		}
		else {
			if ((vybir % 4 == 1) || (vybir % 4 == -3)) vybir = choose_in_shop(console, 1, 0, 0);
			if ((vybir % 4 == 2) || (vybir % 4 == -2)) vybir = choose_in_shop(console, 0, 1, 0);
			if ((vybir % 4 == 3) || (vybir % 4 == -1))  vybir = choose_in_shop(console, 0, 0, 1);
		}
	}
	clear(console);

	//write_to_info(a);
	//write_to_info(a);

	return;
}

int count_of_strings_file() {
	int n = 0;
	ifstream fin;
	char a[50];
	fin.open("hist.txt", ios::in);

	while (fin.getline(a, 50)) n++;

	fin.close();
	return n;
}

void clear_window(HANDLE console) {

	COORD loc;

	loc.X = 0;
	loc.Y = 0;

	for (int i = 0; i < 30; i++) {
		SetConsoleCursorPosition(console, loc);
		cout << "                                                                                                                              ";
		loc.Y++;
	}


}

void history(HANDLE console, int n) {

	// очистка екрана
	COORD loc;
	loc.X = 20;
	loc.Y = 12;
	SetConsoleCursorPosition(console, loc);

	cout << "                                                         ";

	loc.X = 39;
	loc.Y = 3;
	SetConsoleCursorPosition(console, loc);
	cout << "Список недавніх ігор:";


	ifstream fin;
	fin.open("hist.txt", ios::in || ios::beg);

	char info[30];
	int X = 38, Y = 5;
	loc.X = X;

	int i = 0;

	if (n > 6) {
		for (int j = 0; j < n - 7; j++) fin.getline(info, 50);
	}

	for (; i < n; i++) {
		fin.getline(info, 30);
		loc.Y = Y;
		SetConsoleCursorPosition(console, loc);
		Y += 2;
		cout << info;
		if (Y >= 20) break;
	}


	loc.X = 15;
	loc.Y = 20;
	SetConsoleCursorPosition(console, loc);
	cout << "Щоб повернутись до меню, натисніть enter";

	int key = 1;

	while (key != 13) {
		if (_kbhit() != 0)
		{
			key = _getch();
		}
	}

	clear(console);
}

void help(HANDLE console) {
	clear_window(console);

	COORD loc;

	loc.X = 0;
	loc.Y = 3;

	SetConsoleCursorPosition(console, loc);
	SetConsoleTextAttribute(console, 7);

	cout << "Правила гри:\n\n";

	cout << "На початку гри у гравця немає монет, якщо він вгадує одну літеру, то він отримує 1 монету.\nЯкщо він називає слово,то він отримує n + 3 монет,де n - к-сть літер у слові, якщо\nгравець не вгадує слово за 10 спроб, то гра зупиняється, гравець програє і втрачає всі монети, \nнабрані за гру.";

	cout << "\n\n";

	cout << "Символ \"_\" позначає 1 літеру, такі символи через пробіл будуть означати слово\n";

	cout << "Наприклад такий запис: \"_ _ _ _\" означає слово з чотирьох літер\n\n";

	cout << "Щоб повернутись до меню, натисніть enter";

	int key = 1, n;

	while (key != 13) {
		if (_kbhit() != 0)
		{
			key = _getch();
		}
	}

	clear_window(console);
}

void output_boost(HANDLE console, int b1, int b2, int b3, int& kil_b1, int& kil_b2, int& kil_b3, int exit) {

	COORD loc;

	loc.X = 27;
	loc.Y = 14;
	SetConsoleCursorPosition(console, loc);

	cout << "                                                ";

	if (b1 == 1) {

		SetConsoleTextAttribute(console, 2);

		loc.X = 15;
		SetConsoleCursorPosition(console, loc);
		cout << "\"одна літера\"" << "(" << kil_b1 << ")";

		SetConsoleTextAttribute(console, 7);

		loc.X = 33;
		SetConsoleCursorPosition(console, loc);
		cout << "\"подвійні монети\"" << "(" << kil_b2 << ")";

		loc.X = 59;
		SetConsoleCursorPosition(console, loc);
		cout << "\"+1 спроба\"" << "(" << kil_b3 << ")";

		loc.X = 77;
		SetConsoleCursorPosition(console, loc);
		cout << "назад";


	}
	if (b2 == 1) {

		SetConsoleTextAttribute(console, 7);

		loc.X = 15;
		SetConsoleCursorPosition(console, loc);
		cout << "\"одна літера\"" << "(" << kil_b1 << ")";

		SetConsoleTextAttribute(console, 2);

		loc.X = 33;
		SetConsoleCursorPosition(console, loc);
		cout << "\"подвійні монети\"" << "(" << kil_b2 << ")";

		SetConsoleTextAttribute(console, 7);

		loc.X = 59;
		SetConsoleCursorPosition(console, loc);
		cout << "\"+1 спроба\"" << "(" << kil_b3 << ")";

		loc.X = 77;
		SetConsoleCursorPosition(console, loc);
		cout << "назад";

	}
	if (b3 == 1) {

		SetConsoleTextAttribute(console, 7);

		loc.X = 15;
		SetConsoleCursorPosition(console, loc);
		cout << "\"одна літера\"" << "(" << kil_b1 << ")";

		loc.X = 33;
		SetConsoleCursorPosition(console, loc);
		cout << "\"подвійні монети\"" << "(" << kil_b2 << ")";

		SetConsoleTextAttribute(console, 2);

		loc.X = 59;
		SetConsoleCursorPosition(console, loc);
		cout << "\"+1 спроба\"" << "(" << kil_b3 << ")";

		SetConsoleTextAttribute(console, 7);
		loc.X = 77;
		SetConsoleCursorPosition(console, loc);
		cout << "назад";


	}
	if (exit == 1) {
		SetConsoleTextAttribute(console, 7);

		loc.X = 15;
		SetConsoleCursorPosition(console, loc);
		cout << "\"одна літера\"" << "(" << kil_b1 << ")";

		loc.X = 33;
		SetConsoleCursorPosition(console, loc);
		cout << "\"подвійні монети\"" << "(" << kil_b2 << ")";

		loc.X = 59;
		SetConsoleCursorPosition(console, loc);
		cout << "\"+1 спроба\"" << "(" << kil_b3 << ")";

		SetConsoleTextAttribute(console, 2);

		loc.X = 77;
		SetConsoleCursorPosition(console, loc);
		cout << "назад";

	}
}

void dop4(HANDLE console, int vybir, int& kil_b1, int& kil_b2, int& kil_b3) {

	vybir = vybir % 4;

	if ((vybir == 1) || (vybir == -3)) output_boost(console, 1, 0, 0, kil_b1, kil_b2, kil_b3, 0);
	if ((vybir == 2) || (vybir == -2)) output_boost(console, 0, 1, 0, kil_b1, kil_b2, kil_b3, 0);
	if ((vybir == 3) || (vybir == -1)) output_boost(console, 0, 0, 1, kil_b1, kil_b2, kil_b3, 0);
	if (vybir == 0) output_boost(console, 0, 0, 0, kil_b1, kil_b2, kil_b3, 1);

}

int choose_boost(HANDLE console, int& kil_b1, int& kil_b2, int& kil_b3) {

	int key = 0, vybir = 1;

	output_boost(console, 1, 0, 0, kil_b1, kil_b2, kil_b3, 0);

	while (key != 13)
	{
		if (_kbhit() != 0)
		{
			key = _getch();

			if (key == 77) {
				vybir++;
				Sleep(10);
				dop4(console, vybir, kil_b1, kil_b2, kil_b3);
			}

			if (key == 75) {
				vybir--;
				Sleep(10);
				dop4(console, vybir, kil_b1, kil_b2, kil_b3);
			}
		}

	}

	return vybir % 4;


}





void print_result(HANDLE console, int attemps, int coins, int upgr, const char a[]) {

	COORD loc;


	loc.Y = 4;
	loc.X = 46;
	SetConsoleCursorPosition(console, loc);
	cout << a;

	loc.Y = 6;
	loc.X = 15;
	SetConsoleCursorPosition(console, loc);

	cout << "результати:";

	loc.X = 20;
	loc.Y = 8;
	SetConsoleCursorPosition(console, loc);

	cout << "кількість спроб: " << attemps;

	loc.X = 20;
	loc.Y = 10;
	SetConsoleCursorPosition(console, loc);

	cout << "набрані монети: " << coins;

	loc.X = 20;
	loc.Y = 10;
	SetConsoleCursorPosition(console, loc);

	cout << "набрані монети: " << coins;

	loc.X = 20;
	loc.Y = 12;
	SetConsoleCursorPosition(console, loc);

	cout << "використано бустів: " << upgr;
}

void write_to_history_file(HANDLE console, const char a[]) {

	ofstream fout;
	ifstream fin;
	int b = 0;
	char r[50];

	fout.open("hist.txt", ios::app);

	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);

	fout << timeinfo->tm_hour << ":" << timeinfo->tm_min << "  " << timeinfo->tm_mday << "." << timeinfo->tm_mon + 1 << "." << timeinfo->tm_year + 1900 << " " << a << "\n";
}

void boost_1(HANDLE console, letters_info* letter, int length) {

	COORD loc;
	int a;
	char b;

	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "Введіть номер літери: ";
	cin >> a;

	loc.Y = 16;
	loc.X = 30;
	SetConsoleCursorPosition(console, loc);
	cout << "                                        ";

	if (a == 0) return;

	if ((a < 0) || (a > length));
	else {
		for (int i = 1; i <= length; i++) {
			if (i == a) {
				SetConsoleTextAttribute(console, 7);
				SetConsoleCursorPosition(console, letter[i - 1].loc);
				cout << letter[i - 1].symbol;
				letter[i - 1].visible = true;
			}
		}
	}

	loc.Y = 14;
	loc.X = 12;
	SetConsoleCursorPosition(console, loc);

	cout << "                                                                          ";
}

void boost_2(HANDLE console) {
	COORD loc;

	loc.Y = 14;
	loc.X = 12;
	SetConsoleCursorPosition(console, loc);

	cout << "                                                                          ";
}

void boost_3(HANDLE console, int* attemps) {
	*attemps += 2;
	COORD loc;

	loc.Y = 14;
	loc.X = 12;
	SetConsoleCursorPosition(console, loc);

	cout << "                                                                          ";

}

char gaming(HANDLE console, int* attemps, int* coins, int& boost1, int& boost2, int& boost3, int& count_boost, int coins_in_file, bool* double_coins) {

	int length, vybir, vybir_boost, vybir_exit = 0, res = 0, aq[4] = { 0,0,0,0 };
	string question, answer;
	ifstream fin_question, fin_answer;
	ofstream fout_history;
	
	clear(console);
	SetConsoleTextAttribute(console, 7);


	COORD loc;

	srand(time(NULL));
	int a = rand() % 9 + 1;

	question = questions[a];
	answer = answers[a];

	fout_history.open("hist.txt", ios::app);


	loc.X = 40;
	loc.Y = 13;

	SetConsoleCursorPosition(console, loc);

	/*
	cout << "Гра почнеться через: ";
	loc.X = 61;

	for (int i = 3; i >= 1; i--) {
		cout << i;
		Sleep(1000);
		SetConsoleCursorPosition(console, loc);

	}
	*/
	//system("cls");
	clear(console);


	//print_ramk(console);


	SetConsoleTextAttribute(console, 7);
	loc.X = 60;
	loc.Y = 19;
	SetConsoleCursorPosition(console, loc);
	SetConsoleOutputCP(866);
	cout << char(27) << '/' << char(26);
	SetConsoleOutputCP(1251);
	cout << " навігація, enter - вибір";

	show_score(console, 0);

	print_question(console, question);

	length = len(answer);
	letters_info* letter = new letters_info[length];
	print_place_for_answer(console, answer, letter);


	loc.X = 63;
	loc.Y = 3;
	SetConsoleCursorPosition(console, loc);
	cout << "к-сть спроб: " << *attemps;



	vybir = choose_in_game(console, question, answer);

	bool is_first_try = true;

	while (*attemps > 0) {

		if ((vybir % 4 == 2) || (vybir % 4 == -2)) {
			char temp = input_word(console, letter, length);

			*attemps -= 1;

			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << "  ";
			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << *attemps;

			if (temp == 'w') {
				loc.Y = 20;
				loc.X = 15;
				SetConsoleCursorPosition(console, loc);
				cout << "щоб повернутись до меню - натисніть esc";


				loc.X = 60;
				loc.Y = 19;
				SetConsoleCursorPosition(console, loc);

				cout << "                            ";


				int key = 0;

				*coins += len(answer) + 3;


				show_score(console, *coins);

				while (key != 27) {
					key = _getch();
				}


				return 'w';
			}

			if (temp == 'm') {

				loc.Y = 16;
				loc.X = 25;
				SetConsoleCursorPosition(console, loc);
				cout << "                      ";

				menu_in_game(console, 1, 0, 0, 0);

				vybir = choose_in_game(console, question, answer);
			}

		}
		if ((vybir % 4 == 1) || (vybir % 4 == -3)) {
			*coins = *coins + input_one_letter(console, letter, length);
			show_score(console, *coins);
			*attemps -= 1;
			SetConsoleTextAttribute(console, 7);
			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << "  ";
			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << *attemps;

			vybir = choose_in_game(console, question, answer);
		}

		if ((vybir % 4 == -1) || (vybir % 4 == 3)) {

			vybir_boost = choose_boost(console, boost1, boost2, boost3);

			int temp = 1;

			if (((vybir_boost == 1) || (vybir_boost == -3)) && (boost1 >= 1)) { boost_1(console, letter, length); boost1 -= 1; 	count_boost += 1; }
			if (((vybir_boost == 1) || (vybir_boost == -3)) && (boost1 < 1)) *attemps += 1;
			if (((vybir_boost == 2) || (vybir_boost == -2)) && (boost2 >= 1) && (is_first_try == true)) { *double_coins = true; boost2 -= 1;	count_boost += 1; }
			if (((vybir_boost == 2) || (vybir_boost == -2)) && (boost2 >= 1) && (is_first_try == false)) *attemps += 1;
			if (((vybir_boost == 2) || (vybir_boost == -2)) && (boost2 < 1) && (is_first_try == true)) *attemps += 1;
			if (((vybir_boost == 2) || (vybir_boost == -2)) && (boost2 < 1) && (is_first_try == false)) *attemps += 1;
			if (((vybir_boost == 3) || (vybir_boost == -1)) && (boost3 >= 1)) { *attemps += 2; boost3 -= 1; temp = 0;	count_boost += 1; }
			if (((vybir_boost == 3) || (vybir_boost == -1)) && (boost3 < 1) && (temp == 1)) *attemps += 1;
			if (vybir_boost == 0) *attemps += 1;

			loc.X = 12;
			loc.Y = 14;
			SetConsoleCursorPosition(console, loc);
			cout << "                                                                            ";



			SetConsoleTextAttribute(console, 7);
			*attemps -= 1;
			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << "   ";
			loc.X = 76;
			loc.Y = 3;
			SetConsoleCursorPosition(console, loc);
			cout << *attemps;

			aq[0] = coins_in_file;
			aq[1] = boost1;
			aq[2] = boost2;
			aq[3] = boost3;

			write_to_info(aq);

			menu_in_game(console, 1, 0, 0, 0);
			vybir = choose_in_game(console, question, answer);
		}
		if (vybir % 4 == 0) {

			output_exit(console, 1, 0);

			loc.X = 45;
			loc.Y = 16;
			SetConsoleCursorPosition(console, loc);
			cout << "Ви впевнені?";

			vybir_exit = choose_exit(console);

			if (vybir_exit % 2 == 0) {

				loc.X = 45;
				loc.Y = 16;
				SetConsoleCursorPosition(console, loc);

				cout << "                           ";

				loc.X = 40;
				loc.Y = 18;
				SetConsoleCursorPosition(console, loc);

				cout << "                           ";

				menu_in_game(console, 1, 0, 0, 0);
				vybir = choose_in_game(console, question, answer);
			}
			if ((vybir_exit % 2 == 1) || (vybir_exit % 2 == -1)) return 'i';

		}
		is_first_try = false;

		for (int i = 0; i < length; i++) {
			if (letter[i].visible == true) res++;
		}
		if (res == len(answer)) {

			return 'w';
		}

		res = 0;
	}




	SetConsoleTextAttribute(console, 7);

	loc.X = 63;
	loc.Y = 3;
	SetConsoleCursorPosition(console, loc);
	cout << "к-сть спроб: " << 0;


	fin_answer.close();
	fin_question.close();
	fout_history.close();
	delete[] letter;

	return 'l';


}

void start(HANDLE console) {

	SetConsoleTextAttribute(console, 7);

	int info[4] = { 0,0,0,0 };
	int attemps = 10;
	int coins_in_file = 0;
	int temp = attemps;
	int count_boost = 0;
	int coins = 0;
	bool double_coins = false;
	int* pointer_coins = &coins;
	return_return(info);

	coins_in_file = info[0];

	COORD loc;

	char b = gaming(console, &attemps, pointer_coins, info[1], info[2], info[3], count_boost, coins_in_file, &double_coins);


	loc.X = 60;
	loc.Y = 19;
	SetConsoleCursorPosition(console, loc);

	cout << "                            ";



	temp = temp - attemps;

	loc.X = 15;
	loc.Y = 3;

	SetConsoleCursorPosition(console, loc);
	cout << "                                                                         ";

	for (int i = 5; i <= 16; i++) {
		loc.Y = i;
		loc.X = 15;
		SetConsoleCursorPosition(console, loc);
		cout << "                                                                         ";
	}
	if (double_coins == true) coins = coins * 2;
	if (b == 'w') { print_result(console, temp, coins, count_boost, "Перемога!!!"); write_to_history_file(console, "перемога"); }
	if (b == 'l') { coins = 0; print_result(console, temp, coins, count_boost, "Програш :("); write_to_history_file(console, "програш"); }
	if (b == 'i') { clear(console); return; }
	coins_in_file += coins;

	info[0] = coins_in_file;
	write_to_info(info);


	//кінець
	loc.Y = 20;
	loc.X = 15;
	SetConsoleCursorPosition(console, loc);
	cout << "щоб повернутись до меню - натисніть esc";

	int key = 0;

	while (key != 27) {
		key = _getch();
	}

	clear(console);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream inf;
	inf.open("inf.txt");

	if (!inf) {

		ofstream inf_maker;
		inf_maker.open("inf.txt");

		for (int i = 0; i < 4; i++) {
			inf_maker << 0 << "\n";
		}
	}

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc;
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(console, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(console, &cursor_info);
	SetConsoleTitle(L"Вгадай слово");
	print_ramk(console);

	int vybir = choose(console);

	while (vybir % 5 != 0) {
		if ((vybir % 5 == 1) || (vybir % 5 == -4)) {
			start(console);
			vybir = choose(console);
		}
		if ((vybir % 5 == 2) || (vybir % 5 == -3)) {
			shop(console);
			vybir = choose(console);
		}
		if ((vybir % 5 == 3) || (vybir % 5 == -2)) {
			help(console);
			print_ramk(console);
			vybir = choose(console);
		}
		if ((vybir % 5 == 4) || (vybir % 5 == -1)) {
			clear(console);
			print_ramk(console);
			history(console, count_of_strings_file());
			vybir = choose(console);
		}
	}
	return 0;
}