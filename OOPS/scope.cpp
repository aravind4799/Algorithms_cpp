#include<bits/stdc++.h>
using namespace std;

class demo{
    private:
    int privatenum=0;
    public:
    int publicnum=10;
    demo(int number): publicnum(number){
        privatenum=400;
        cout<<"VALUE OF NUM IN PRIVATE: "<<privatenum<<endl;
        cout<<"VALUE OF NUM IN PUBLIC: "<<publicnum<<endl;
    }
};
int main(){
    //heap allocation
    demo *obj = new demo(100);
    //stack allocation
    // demo obj2(500);

    return 0;
}

// order of assignment
// 1 -> inline declaration default value
// 2 -> initializer_list
// 3 -> constructor body initialization