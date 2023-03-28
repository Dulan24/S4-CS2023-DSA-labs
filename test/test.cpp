
#include <iostream>
#include <cmath>
//test

using namespace std;

class rectangle
{private:
    int length;
    int bredth;

public:
rectangle (){
    length=1;
    bredth=1;
}
rectangle(int l, int b){
     length = l;
     bredth = b;
}

int area(){
    return length*bredth;
}

int perimeter(){
    return 2*(length+bredth);
}

void changeLength(int l){
    length = l;
}

void getLength(){
    return length;
}

// ~rectangle(); // distructor

};


int main(){
    rectangle r(10,5);
    // r.initialize(10,5);
    cout << r.area();
    cout << r.perimeter();
    r.changeLength(20);
    cout << r.getLength();
}