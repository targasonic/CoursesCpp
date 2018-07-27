?*
Вам дан класс Foo:

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};
Как видно, создатель класса не хотел чтобы его использовали и "спрятал" конструктор класса. Но вам очень нужен объект этого класса, чтобы передать его в функцию foo_says:

void foo_says(const Foo& foo) { foo.say(); }
В этом задании вам нужно реализовать функцию get_foo (сигнатура которой намерено не приводится в задании полностью, вам нужно подумать и вывести ее самостоятельно) так, чтобы следующий код компилировался и работал:

foo_says(get_foo(msg));
Где msg — произвольная C-style строка.
*/

/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 *
 * #include <iostream>
 *        
 * struct Foo {
 *     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 * protected:
 *     Foo(const char *msg) : msg(msg) { }
 * private:
 *     const char *msg;
 * };
 * 
 * void foo_says(const Foo &foo) { foo.say(); }
 *
 */

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));


Foo get_foo(const char *msg) {
    struct Foo1 : Foo {
        public:
        Foo1(const char *msg) : Foo(msg) { }
    };
    
    //Объявляем объект наследник, у которого в качестве аргумента msg и его возвращаем.
    Foo1 f = Foo1(msg);
    return f;
}
