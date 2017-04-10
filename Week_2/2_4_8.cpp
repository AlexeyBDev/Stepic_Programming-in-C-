// Напишите функцию поиска первого вхождения шаблона в текст.В качестве первого параметра функция принимает 
// текст(C - style строка), в которой нужно искать шаблон.
// В качестве второго параметра строку - шаблон(C - style строка), которую нужно найти.Функция возвращает позицию
// первого вхождения строки - шаблона, если он присутствует в строке(помните, что в C++ принято считать с 0), и - 1, 
// если шаблона в тексте нет.
//
// Учтите, что пустой шаблон(строка длины 0) можно найти в любом месте текста.
//
// Требования к реализации : при выполнении данного задания вы можете определять любые вспомогательные 
// функции, если они вам нужны.Вводить или выводить что - либо не нужно.Реализовывать функцию main не нужно.

// Очень долго не мог решить задачу. Очень помогло тестирование.

#include <iostream>
#include <iomanip>

using namespace std;

int _strstr(const char *text, const char *pattern)
{
	int i = 0;
	if (i == 0 && pattern[i] != '\0' && text[i] == '\0') return -1;
	if (i == 0 && pattern[i] == '\0' && text[i] == '\0') return 0; 

	for(i = 0; text[i] != '\0'; ++i)
	{

		for(int j = 0; text[i + j] == pattern[j] || pattern[j] == '\0'; ++j)
		{
			if (pattern[j] == '\0') return i;
		}
	}
	return (i == 0) ? 0 : -1;
}

void str_test(const char *text, const char *pattern, int answer)
{
	static int num = 1;
	cout << setw(2) << right << num << ". " 
	<< left << "\"" << setw(10) << text << "\"" << " : "
		<< "\"" << setw(10) << pattern << "\"" << " = " << answer << " : " << _strstr(text, pattern);
	cout << setiosflags(ios::boolalpha) << setw(12) << setiosflags(ios::right) << "     " 
	<< (answer == _strstr(text, pattern)) << endl;
	cout.unsetf(ios::boolalpha);
	++num;
}

void test()
{
	str_test("", "", 0);
	str_test(" ", "", 0);
	str_test("", " ", -1);
	str_test("a", "", 0);
	str_test("a", "a", 0);
	str_test("a", "b", -1);
	str_test("aa", "", 0);
	str_test("aa", "a", 0);
	str_test("ab", "a", 0);
	str_test("ba", "a", 1);
	str_test("bb", "a", -1);
	str_test("aaa", "", 0);
	str_test("aaa", "a", 0);
	str_test("abc", "b", 1);
	str_test("abc", "c", 2);
	str_test("abc", "d", -1);
	str_test("a", "aa", -1);
	str_test("a", "ba", -1);
	str_test("a", "ab", -1);
	str_test("a", "bb", -1);
	str_test("a", "aaa", -1);
	str_test("aa", "aaa", -1);
	str_test("aaa", "aaa", 0);
	str_test("aaab", "aaa", 0);
	str_test("baaa", "aaa", 1);
	str_test("baaaa", "aaa", 1);
	str_test("baaab", "aaa", 1);
	str_test("abd", "abc", -1);
	str_test("ababc", "abc", 2);
	str_test("abdabc", "abc", 3);
	//str_test("aaa\nba", "ab", 2);
	str_test("hhhhhhhhelo", "hhhhhhhell", -1);
	str_test("aaaaaaf", "aaaf", 3);
	str_test("asdwsdfasf", "wsx", -1);
	
}

int main(int argc, char* argv[])
{
	//cout << _strstr("aaab\nad", "ad") << endl;
	test();

	return 0;
}


//void test()
//{
//	(0 == _strstr("", "")) ?
//		cout << "OK : 1" << " (" << 0 << " : " << _strstr("", "") << " )" << endl :
//		cout << "Failed : 1" << " (" << 0 << " : " << (0 == _strstr("", "")) << " )" << endl;
//	(0 == _strstr("a", "")) ? cout << "OK : 2" << " (" << 0 << " : " << (0 == _strstr("a", "")) << " )" << endl : cout << "Failed : 2" << " (" << 0 << " : " << (0 == _strstr("a", "")) << " )" << endl;
//	(0 == _strstr("a", "a")) ? cout << "OK : 3" << " (" << 0 << " : " << (0 == _strstr("a", "a")) << " )" << endl : cout << "Failed : 3" << " (" << 0 << " : " << (0 == _strstr("a", "a")) << " )" << endl;
//	(-1 == _strstr("a", "b")) ? cout << "OK : 4" << " (" << -1 << " : " << (-1 == _strstr("a", "b")) << " )" << endl : cout << "Failed : 4" << " (" << -1 << " : " << (-1 == _strstr("a", "b")) << " )" << endl;
//
//	(0 == _strstr("aa", "")) ? cout << "OK : 5" << " (" << 0 << " : " << (0 == _strstr("aa", "")) << " )" << endl : cout << "Failed : 5" << " (" << 0 << " : " << (0 == _strstr("aa", "")) << " )" << endl;
//	(0 == _strstr("aa", "a")) ? cout << "OK : 6" << " (" << 0 << " : " << (0 == _strstr("aa", "a")) << " )" << endl : cout << "Failed : 6" << " (" << 0 << " : " << (0 == _strstr("aa", "a")) << " )" << endl;
//	(0 == _strstr("ab", "a")) ? cout << "OK : 7" << " (" << 0 << " : " << (0 == _strstr("ab", "a")) << " )" << endl : cout << "Failed : 7" << " (" << 0 << " : " << (0 == _strstr("ab", "a")) << " )" << endl;
//	(1 == _strstr("ba", "a")) ? cout << "OK : 8" << " (" << 1 << " : " << (1 == _strstr("ba", "a")) << " )" << endl : cout << "Failed : 8" << " (" << 1 << " : " << (1 == _strstr("ba", "a")) << " )" << endl;
//	(-1 == _strstr("bb", "a")) ? cout << "OK : 9" << " (" << -1 << " : " << (-1 == _strstr("bb", "a")) << " )" << endl : cout << "Failed : 9" << " (" << -1 << " : " << (-1 == _strstr("bb", "a")) << " )" << endl;
//
//	(0 == _strstr("aaa", "")) ? cout << "OK : 10" << " (" << 0 << " : " << (0 == _strstr("aaa", "")) << " )" << endl : cout << "Failed : 10" << " (" << 0 << " : " << (0 == _strstr("aaa", "")) << " )" << endl;
//	(0 == _strstr("aaa", "a")) ? cout << "OK : 11" << " (" << 0 << " : " << (0 == _strstr("aaa", "a")) << " )" << endl : cout << "Failed : 11" << " (" << 0 << " : " << (0 == _strstr("aaa", "a")) << " )" << endl;
//	(1 == _strstr("abc", "b")) ? cout << "OK : 12" << " (" << 1 << " : " << (1 == _strstr("abc", "b")) << " )" << endl : cout << "Failed : 12" << " (" << 1 << " : " << (1 == _strstr("abc", "b")) << " )" << endl;
//	(2 == _strstr("abc", "c")) ? cout << "OK : 13" << " (" << 2 << " : " << (2 == _strstr("abc", "c")) << " )" << endl : cout << "Failed : 13" << " (" << 2 << " : " << (2 == _strstr("abc", "c")) << " )" << endl;
//	(-1 == _strstr("abc", "d")) ? cout << "OK : 14" << " (" << -1 << " : " << (-1 == _strstr("abc", "d")) << " )" << endl : cout << "Failed : 14" << " (" << -1 << " : " << (-1 == _strstr("abc", "d")) << " )" << endl;
//
//	(-1 == _strstr("a", "aa")) ? cout << "OK : 15" << " (" << -1 << " : " << (-1 == _strstr("a", "aa")) << " )" << endl : cout << "Failed : 15" << " (" << -1 << " : " << (-1 == _strstr("a", "aa")) << " )" << endl;
//	(-1 == _strstr("a", "ba")) ? cout << "OK : 16" << " (" << -1 << " : " << (-1 == _strstr("a", "ba")) << " )" << endl : cout << "Failed : 16" << " (" << -1 << " : " << (-1 == _strstr("a", "ba")) << " )" << endl;
//	(-1 == _strstr("a", "ab")) ? cout << "OK : 17" << " (" << -1 << " : " << (-1 == _strstr("a", "ab")) << " )" << endl : cout << "Failed : 17" << " (" << -1 << " : " << (-1 == _strstr("a", "ab")) << " )" << endl;
//	(-1 == _strstr("a", "bb")) ? cout << "OK : 18" << " (" << -1 << " : " << (-1 == _strstr("a", "bb")) << " )" << endl : cout << "Failed : 18" << " (" << -1 << " : " << (-1 == _strstr("a", "bb")) << " )" << endl;
//
//	(-1 == _strstr("a", "aaa")) ? cout << "OK : 19" << " (" << -1 << " : " << (-1 == _strstr("a", "aaa")) << " )" << endl : cout << "Failed : 19" << " (" << -1 << " : " << (-1 == _strstr("a", "aaa")) << " )" << endl;
//	(-1 == _strstr("aa", "aaa")) ? cout << "OK : 20" << " (" << -1 << " : " << (-1 == _strstr("aa", "aaa")) << " )" << endl : cout << "Failed : 20" << " (" << -1 << " : " << (-1 == _strstr("aa", "aaa")) << " )" << endl;
//	(0 == _strstr("aaa", "aaa")) ? cout << "OK : 21" << " (" << 0 << " : " << (0 == _strstr("aaa", "aaa")) << " )" << endl : cout << "Failed : 21" << " (" << 0 << " : " << (0 == _strstr("aaa", "aaa")) << " )" << endl;
//	(0 == _strstr("aaab", "aaa")) ? cout << "OK : 22" << " (" << 0 << " : " << (0 == _strstr("aaab", "aaa")) << " )" << endl : cout << "Failed : 22" << " (" << 0 << " : " << (0 == _strstr("aaab", "aaa")) << " )" << endl;
//	(1 == _strstr("baaa", "aaa")) ? cout << "OK : 23" << " (" << 1 << " : " << (1 == _strstr("baaa", "aaa")) << " )" << endl : cout << "Failed : 23" << " (" << 1 << " : " << (1 == _strstr("baaa", "aaa")) << " )" << endl;
//	(1 == _strstr("baaaa", "aaa")) ? cout << "OK : 24" << " (" << 1 << " : " << (1 == _strstr("baaaa", "aaa")) << " )" << endl : cout << "Failed : 24" << " (" << 1 << " : " << (1 == _strstr("baaaa", "aaa")) << " )" << endl;
//	(1 == _strstr("baaab", "aaa")) ? cout << "OK : 25" << " (" << 1 << " : " << (1 == _strstr("baaab", "aaa")) << " )" << endl : cout << "Failed : 25" << " (" << 1 << " : " << (1 == _strstr("baaab", "aaa")) << " )" << endl;
//	(-1 == _strstr("abd", "abc")) ? cout << "OK : 26" << " (" << -1 << " : " << (-1 == _strstr("abd", "abc")) << " )" << endl : cout << "Failed : 26" << " (" << -1 << " : " << (-1 == _strstr("abd", "abc")) << " )" << endl;
//
//	(2 == _strstr("ababc", "abc")) ? cout << "OK : 27" << " (" << 2 << " : " << (2 == _strstr("ababc", "abc")) << " )" << endl : cout << "Failed : 27" << " (" << 2 << " : " << (2 == _strstr("ababc", "abc")) << " )" << endl;
//	(3 == _strstr("abdabc", "abc")) ? cout << "OK : 28" << " (" << 3 << " : " << (3 == _strstr("abdabc", "abc")) << " )" << endl : cout << "Failed : 28" << " (" << 3 << " : " << (3 == _strstr("abdabc", "abc")) << " )" << endl;
//
//}