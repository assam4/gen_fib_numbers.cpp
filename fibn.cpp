#include <iostream>
#include <iterator>
#include <type_traits>

static const unsigned First_num = 0 ;
static const unsigned Second_num = 1 ;
static const unsigned Without_trace = 0 ;
static const unsigned First_prev = 1 ;
static const unsigned Second_prev = 2 ;

void get_Fibonacci_numbers(unsigned count ,unsigned  coefficient)
{
unsigned value_1 = First_num ;
unsigned value_2 = Second_num ;

do{
    value_2 += value_1 ;
    value_1 = value_2 - value_1 ;
    if(value_1 % coefficient == Without_trace)
   {std::cout << value_1 << " "  ;
    --count ;
   }
 } while(count) ;

 std::cout << std::endl;
 
 return ;
}

// creating forward iterator to use generating numbers

class Fibonacci_iterator
{
public:
    using value_type = unsigned;
    using reference = value_type&;
    using pointer = value_type*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    Fibonacci_iterator(unsigned c)
    : m_current(First_num) , m_next (Second_num) , m_coefficient(c)
    { }

    unsigned operator* () {return m_current ; }

    Fibonacci_iterator& operator++ ()
    {
        do{
             m_next += m_current ;
             m_current = m_next - m_current ; }
        while(m_current % m_coefficient != Without_trace) ;
    
        return *this ;
    }

    bool operator != (Fibonacci_iterator& other)
    {
            return m_current != other.m_current ;
    }

private:
    unsigned m_current ;
    unsigned m_next ;
    unsigned m_coefficient ;
};

void get_Fibonacci_numbers_2 (unsigned count ,unsigned coefficient)
{
    Fibonacci_iterator begin(coefficient);
    while(count)
    {
        std::cout << *(++begin) << " " ;
        --count ;
    }

    static_assert(  std::is_same<std::iterator_traits<Fibonacci_iterator>::iterator_category    
                    , std::forward_iterator_tag>::value 
                    , "FibonacciIterator is not a forward iterator!" );
    return ;
}

int main ()

{
    std::cout << " Generating Fibonacci numbers by Simple function " << std::endl ;
    get_Fibonacci_numbers (5 , 3);
    std::cout << " Generating same numbers by using forward iterator " << std::endl ;
    get_Fibonacci_numbers_2(5,3);
    return 0 ;
}