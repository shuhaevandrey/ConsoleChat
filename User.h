#pragma once
#include <iostream>
#include <string>


using namespace std;

/*
Класс "Пользователя" который хранит в себе Логин, Имя и Пароль.
Содержит в себе 2 конструктора:
	1. по умолчанию - будет вызываться при каждом новом создании
						пользователя с параметрами по умолчанию
	2. с параметрами - сделан для того, чтобы в конструторе контейнера 
						сразу создать пользователя с указанием всех переменных
*/

class User
{
	private:
		string _usrLogin;
		string _usrName;
		string _usrPass;
	public:
		User();
		User(string _usrLogin, string _usrName, string _usrPass);

		void setUsrLogin();				//ф-я создания Логина пользователя
		void setUsrName();				//ф-я создания Имени пользователя
		void setUsrPass();				//ф-я создания Пароля пользователя
		void setUsrLogin(string Login);	//ф-я создания Логина пользователя с параметрами
		void setUsrName(string Name);	//ф-я создания Имени пользователя с параметрами
		void setUsrPass(string Pass);	//ф-я создания Пароля пользователя с параметрами


		string getUsrLogin();			//ф-я возвращающая Логин пользователя.
		string getUsrName();			//ф-я возвращающая Имя пользователя.
		string getUsrPass();			//ф-я возвращающая Пароль пользователя.
		void getUsrMenu();				//ф-я входа в меню пользователя
		void getMainMenu();				//ф-я вызова меню пользователя





		void getUsrData();

		~User();
};
