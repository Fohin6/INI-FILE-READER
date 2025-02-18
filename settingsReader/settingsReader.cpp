#include <iostream>
#include <Windows.h>
#include <string>
#include <WinBase.h>
#include <locale>
#include <codecvt>

using namespace std;

int main()
{
	//Поиск исходного файла
	char* buffer = new char[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, buffer); //Получаем текущую директорию и записываем ее
	CharToOemA(buffer, buffer);

	string re = buffer;
	string pathToSettings = re + "\\" + "settings.ini"; //Добавляем название файла к пути

	//Преобразуем std::string в std::wstring
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring widePath = converter.from_bytes(pathToSettings);

	// Получаем const wchar_t* из std::wstring
	const wchar_t* settings = widePath.c_str();

	// Выводим результат
	std::wcout << settings << std::endl;

	//Чтение занчений из файла
	wchar_t bufferForRead[256];
	int buttonId = 0;
	GetPrivateProfileString(L"BotToken", L"botToken", L"DefaultUser", bufferForRead, sizeof(bufferForRead), settings);
	int value = GetPrivateProfileInt(L"Buttons", L"button", buttonId, settings);

	//Преобразование wchar в string
	std::wstring wideStr(bufferForRead);
	std::string narrowStr(wideStr.begin(), wideStr.end());

	cout << narrowStr << endl;
	cout << value << endl;

	delete[] buffer;


	int b;
	cin >> b;


	return 0;
}
