#include<iostream>
using namespace std;
int mask;
bool contains(int x){
    return mask & (1 << x);
}

bool insert(int& mask, int x) {
    mask |= (1 << x);
}

bool erase (int& mask, int x) {
    mask &= ~(1 << x);
}

bool change (int& mask, int x) {
    mask ^= (1 << x);
}

int unite (int mask1, int mask2) { // обединение
    return mask1 | mask2;
}

int intersect(int mask1, int mask2) { // сечение
    return mask1 & mask2;
}

int substrt(int mask1, int mask2) {
    return mask1 & ~mask2;
}
int main()
{
    mask = 21;
    cout<<contains(4);
}
