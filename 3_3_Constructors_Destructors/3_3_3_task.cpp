/*
Реализованные в предыдущих заданиях конструкторы и деструктор берут на себя работу по управлению ресурсами. 
Теперь можно дополнить структуру String различными полезными методами.

Для работы со строками можно придумать множество полезных методов 
(подумайте, какие методы пригодились бы вам, и чего вам не хватает для их реализации). 
Примером такого метода может послужить метод append — он добавляет копию строки-аргумента в конец текущей строки 
(т.е. в конец строки, у которой он был вызван). 

String s1("Hello,");
String s2(" world!");

s1.append(s2); // теперь s1 хранит "Hello, world!"
Ваша задача реализовать метод append.

При выполнении задания будьте аккуратны при работе с памятью — при вызове метода не должно возникать утечек памяти. 
Кроме того, не забудьте, что size хранит размер без учета завершающего 0 символа. 

*/

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
    void append(String & other) {
        char * temp = new char[size + other.size+1];
        for(size_t i = 0; i < size; ++i)
            temp[i] = str[i];
        for(size_t j=0; j < other.size; ++j)
            temp[size+j] = other.str[j];
        temp[size + other.size] = 0;
     
        delete[] str;
        str = temp;
        size += other.size;
    }

	size_t size;
	char *str;
};



