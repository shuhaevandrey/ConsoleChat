#pragma once
#include <iostream>
#include "User.h"

using namespace std;

class UsrCont
{
private:
	int index{};
	int m_lenght{};
	User* m_data{};
public:
	UsrCont();

	void setNewUsr();			//ф-я создания нового пользователя

	void setNewUsr(string login, string name, string pass);	
								//ф-я создания нового пользователя с параметрами

	
	void setAddUsrLogin();		//ф-я ввода Логина при создании нового пользователя с проверкой совпадений
	void setAddUsrName();		//ф-я ввода Имени при создании нового пользователя с проверкой совпадений
	void setAddUsrPass();		//ф-я ввода Пароля при создании нового пользователя.

	void setRessize();			//ф-я увеличения размера массива в 2 раза с сохранением его элементов

	void getMainMenu();			//ф-я вызова главного меню
	bool getLoginSrch();		//ф-я поиска совпадения Логинов
	bool getNameSrch();			//ф-я поиска совпадения Имен

	bool getPassCompare(string Pass, int i);	//ф-я сравнения введеного пароля с паролем пользователя

	void getUsrIn();			//ф-я поиска пользователя и входа в аккаунт, при соблюдении всех условий. Необходима для входа.


	void getUsrData();

	~UsrCont();
};