#include <cstdio> 
template<bool> struct Value;
 
template< int n, typename = Value<true> >
struct fizzbuzz
{
        fizzbuzz()
        {
                fizzbuzz<n-1> fb;
                printf("%d\n", n);
        }
};
 
template <int n>
struct fizzbuzz< n, Value<(n == 0)> >
{
        fizzbuzz() { }
};
 
template <int n>
struct fizzbuzz< n, Value<(n > 0 && n % 15 == 0)> >
{
        fizzbuzz()
        {
                fizzbuzz<n-1> fb;
                puts("fizzbuzz");
        }
};
 
template <int n>
struct fizzbuzz< n, Value<(n > 0 && n % 3 == 0 && n % 5 != 0)> >
{
        fizzbuzz()
        {
                fizzbuzz<n-1> fb;
                puts("fizz");
        }
};
 
template <int n>
struct fizzbuzz< n, Value<(n > 0 && n % 5 == 0 && n % 3 != 0)> >
{
        fizzbuzz()
        {
                fizzbuzz<n-1> fb;
                puts("buzz");
        }
};
 
int main()
{
        fizzbuzz<LIMIT> fb;
        return 0;
}
