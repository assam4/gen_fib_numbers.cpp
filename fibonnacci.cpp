#include <iostream>
#include <ranges>

void sum (unsigned& fisrt , unsigned& second)
{
 second += fisrt ;
 fisrt = second - fisrt ;
}

unsigned gen_next_num()
{
    static unsigned a = 0 , b = 1 ;

while(true)
{
    if(a % 2 == 0) break ;
    sum(a,b) ;
}

auto result = a ;
sum(a,b);
return result ;
}


int main () 
{
    auto next_num = gen_next_num();
 
 auto check = [&] (auto x) 
 { 
    if(x == next_num)
    {
      next_num = gen_next_num();
      return true ;
    }
    return false ;

 } ;

    auto range  = std::ranges::views::iota(0)
                 | std::ranges::views::filter(check)
                 | std::ranges::views::take(5) ;

    for (auto i : range)
    std::cout << i << " " << std::endl ;
}