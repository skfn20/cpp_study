#include<iostream>

using namespace std;

// find number of the element in the set
int bitCount(int x)
{
    if(x==0) return 0;
    return x %2 + bitCount(x/2);
}    

int main()
{
    int fullPizza = (1 << 20) -1; // 20 all on (111...1 -> num of 1  == 20)

    
    // add nth element in the set
    int n  = 3;
    int toppings = 3;
    toppings |= (1<< n);

    // bit operations return value is not 0 or 1
    if(toppings & (1<<n)) cout << "Pepperoni is in" << endl;

    // turn off the nth bit
    toppings &= ~(1<<n);
    if(toppings & (1<<n)) cout << "Pepperoni is in" << endl;

    // toggle the element(using the xor operation)
    toppings ^= (1<<n);

    int a = 10;
    int b  =20;

    int added = ( a|b); //a b union
    int intersetion = (a & b); 
    int removed = (a & ~b);
    int toggled = (a ^ b);

    // find the smallest 1
    int firstTopping = (toppings & -toppings);

    // removing the smallest 1 
    toppings &= (toppings-1);

    for(int subset =fullPizza; subset;  subset=((subset-1)&fullPizza)){
        
    }

    return 0;
} 