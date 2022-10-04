#include <iostream>
#include "UsrCont.h"
#include "User.h"

using namespace std;

UsrCont::UsrCont()
{
	index = 0;
	m_lenght = 2;
	m_data = new User[m_lenght];

			/*
			Далее, чтоб не вводить при запуске каждого пользователя, 
			идут функции создания пользователя с параметрами.
			Проверки на совпадения в них нет.
			*/
	setNewUsr("Admin", "Админ", "1111");
	setNewUsr("Kolya", "Коля", "2222");
	setNewUsr("Olya", "Оля", "3333");
	setNewUsr("Sasha", "Саша", "4444");
	setNewUsr("Masha", "Маша", "5555");
	setNewUsr("Vasya", "Вася", "5555");
}

/*
================================================================
=====================      ФУНКЦИИ      ========================
================================================================
*/


/*
ф-я создания нового пользователя.
при недостаточном размере массива, он увеличивается в 2 раза и после
добавляется новый пользователь по (index)
*/

void UsrCont::setNewUsr()
{
	if (index < m_lenght)
	{
		setAddUsrLogin();
		setAddUsrName();
		setAddUsrPass();
	}
	else
	{
		setRessize();
		setAddUsrLogin();
		setAddUsrName();
		setAddUsrPass();
	}
}


/*
ф-я создания нового пользователя с параметрами
*/

void UsrCont::setNewUsr(string login, string name, string pass)
{
	if (index < m_lenght)
	{
		m_data[index].setUsrLogin(login);
		m_data[index].setUsrName(name);
		m_data[index].setUsrPass(pass);
		++index;
	}
	else
	{
		setRessize();
		m_data[index].setUsrLogin(login);
		m_data[index].setUsrName(name);
		m_data[index].setUsrPass(pass);
		++index;
	}
}


/*
ф-я ввода Логина при создании нового пользователя с проверкой 
совпадений Логинов нового пользователя с ранее создаными.
При совпадении Логинов, его требуется ввести заново.
*/

void UsrCont::setAddUsrLogin()
{

	cout << "index" << index << endl;
	m_data[index].setUsrLogin();
	while (getLoginSrch() == true)
	{
		if (getLoginSrch() == true)
		{
			cout << "Пользователь с таким Логином уже существует. Придумайте другой Логин" << endl;
			m_data[index].setUsrLogin();
		}
		else
		{

		}
	}
}


/*
ф-я ввода Имени при создании нового пользователя с проверкой
совпадений Имен нового пользователя с ранее создаными.
При совпадении Имен, его требуется ввести заново.
*/

void UsrCont::setAddUsrName()
{
	cout << "index" << index << endl;
	m_data[index].setUsrName();
	while (getNameSrch() == true)
	{
		if (getNameSrch() == true)
		{
			cout << "Пользователь с таким именем уже существует. Придумайте другое имя" << endl;
			m_data[index].setUsrName();
		}
		else
		{

		}
	}
}


/*
ф-я ввода Пароля при создании нового пользователя.
*/

void UsrCont::setAddUsrPass()
{
	cout << "index" << index << endl;
	m_data[index].setUsrPass();
	++index;
}


/*
ф-я увеличения размера массива в 2 раза с сохранением его элементов
*/

void UsrCont::setRessize()
{
	m_lenght = m_lenght * 2;
	User* data = new User[m_lenght];
	for (int i = 0; i < index; ++i)
	{
		data[i] = m_data[i];
	}

	delete[] m_data;

	m_data = data;

	cout << "Массив увеличен в 2 раза и равен " << m_lenght << " элементам" << endl;
}



/*
ф-я вызова главного меню
*/


void UsrCont::getMainMenu()
{
	char swtch = '0';
	while (swtch != 'q')
	{
		cout << "Войти в Аккаунт------ 1" << endl;
		cout << "Создать Аккаунт ----- 2" << endl;
		cout << "Выход---------------- q" << endl;
		cin >> swtch;
		switch (swtch)
		{
		case'1':
			cout << "Вход в Аккаунт" << endl;
			setAddUsrLogin();  //КОСТЫЛЬ!!! Без него ввод логина невозможен. Перескакивает и логин остается пустым. В чем причина понять не могу.
			getUsrIn();
			break;

		case'2':
			cout << "Новый Аккаунт" << endl;
			setAddUsrLogin();  //КОСТЫЛЬ!!! Без него ввод логина невозможен. Перескакивает и логин остается пустым. В чем причина понять не могу.
			setNewUsr();
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


/*
ф-я поиска совпадения Логинов
*/

bool UsrCont::getLoginSrch()
{
	bool compare = false;

	for (int i = 0; (i < index) && (compare == false); ++i)
	{
		if (m_data[index].getUsrLogin() == m_data[i].getUsrLogin())
		{
			compare = true;
		}
		else
		{
			compare = false;
		}
	}

	return compare;
}


/*
ф-я поиска совпадения Имен
*/

bool UsrCont::getNameSrch()
{
	bool compare = false;

	for (int i = 0; (i < index) && (compare == false); ++i)
	{
		if (m_data[index].getUsrName() == m_data[i].getUsrName())
		{
			compare = true;
		}
		else
		{
			compare = false;
		}
	}

	return compare;
}



/*
ф-я сравнения введеного пароля с паролем пользователя
*/

bool UsrCont::getPassCompare(string Pass, int i)
{
	bool compare = false;
	if (Pass == m_data[i].getUsrPass())
	{
		compare = true;
	}
	else
	{
		compare = false;
	}

	return compare;

}


/*
ф-я поиска пользователя и входа в аккаунт, при соблюдении всех условий. Необходима для входа.
*/

void UsrCont::getUsrIn()
{
	cout << "Введите логин под которым хотите войти: " << endl;
	string Login;
	getline(cin, Login);
	cout << endl;
	for (int i = 0; i < index; ++i)
	{
		if (Login == m_data[i].getUsrLogin())
		{
			cout << "Введите пароль" << endl;
			string Pass;
			getline(cin, Pass);
			cout << endl;
			if (getPassCompare(Pass, i) == true)
			{

				m_data[i].getMainMenu();
			}
			else
			{
				cout << "Неправильный пароль" << endl;
			}
		}
		else if (i == index)
		{
			cout << "Такого пользователя не существует" << endl;
		}
		else
		{

		}
	}


}


void UsrCont::getUsrData()
{
	for (int i = 0; i < index; ++i)
	{
		m_data[i].getUsrData();
	}
}

UsrCont::~UsrCont()
{
	delete[] m_data;
}