#include <iostream>
#include <string>
#include "User.h"

using namespace std;


/*
=================================================================
=====================    КОНСТРУКТОРЫ    ========================
=================================================================
*/


/*
Конструктор по умолчанию
*/

User::User()
{
	_usrLogin = "%";
	_usrName = "%";
	_usrPass = "%";

}




/*
Конструктор с параметрами
*/

User::User(string _usrLogin, string _usrName, string _usrPass)
{
	this->_usrLogin = _usrLogin;
	this->_usrName = _usrName;
	this->_usrPass = _usrPass;

}


/*
================================================================
=====================      ФУНКЦИИ      ========================
================================================================
*/


/*
ф-я создания Логина пользователя
*/

void User::setUsrLogin()
{
	cout << "Введите Логин пользователя: ";
	getline(cin, _usrLogin);
	cout << endl;
}



/*
ф-я создания Имени пользователя
*/

void User::setUsrName()
{
	cout << "Введите Имя пользователя: ";
	getline(cin, _usrName);
	cout << endl;
}


/*
ф-я создания Пароля пользователя
*/

void User::setUsrPass()
{
	cout << "Введите Пароль пользователя: ";
	getline(cin, _usrPass);
	cout << endl;
}




/*
ф-я создания Логина пользователя с параметрами
*/

void User::setUsrLogin(string Login)
{
	this->_usrLogin = Login;
}



/*
ф-я создания Имени пользователя с параметрами
*/

void User::setUsrName(string Name)
{
	this->_usrName = Name;
}


/*
ф-я создания Логина пользователя с параметрами
*/

void User::setUsrPass(string Pass)
{
	this->_usrPass = Pass;
}







/*
ф-я возвращающая Логин пользователя.
	Нужна для сравнения Логинов при поиске.
*/

string User::getUsrLogin()
{
	return _usrLogin;
}


/*
ф-я возвращающая Имя пользователя.
	Нужна для сравнения имен при поиске.
*/

string User::getUsrName()
{
	return _usrName;
}


/*
ф-я возвращающая Пороль пользователя.
	Нужна для сравнения Паролей при входе.
*/

string User::getUsrPass()
{
	return _usrPass;
}



/*
ф-я входа в меню пользователя
*/

void User::getUsrMenu()
{
	cout << "Имя пользователя: " << _usrName << endl;
	getMainMenu();
}



/*
ф-я вызова меню пользователя
*/

void User::getMainMenu()
{
	char swtch = 0;
	while (swtch != 'q')
	{
		cout << "Адресная книга ------ 1" << endl;
		cout << "Создать новую ветку - 2" << endl;
		cout << "Выход---------------- q" << endl;
		cin >> swtch;
		cout << endl;
		switch (swtch)
		{
			case'1':
				cout << "Адресная книга" << endl;
				break;

			case'2':
				cout << "Создать новую ветку" << endl;
				break;

			case'q':
				cout << "Выход" << endl;
				break;
			default:
				cout << " Вы не выбрали ни одну из операций " << endl;
				break;

		}

	}
}















void User::getUsrData()
{
	cout << "Логин пользователя: ";
	cout << _usrLogin;
	cout << endl;


	cout << "Имя пользователя: ";
	cout << _usrName;
	cout << endl;


	cout << "Пароль пользователя: ";
	cout << _usrPass;
	cout << endl;
}


/*
=================================================================
=====================     ДЕСТРУКТОР     ========================
=================================================================
*/

User::~User()
{

}