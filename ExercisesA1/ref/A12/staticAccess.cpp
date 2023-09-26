#include <iostream>

using namespace std;

class Number{
    private:
        static int accessCount;

    public:
        static int zero(){++accessCount;return 0;}
        static int getCount() { return accessCount; }
};

int Number::accessCount = 0;
	
int main(){
    Number::zero();
    cout << Number::getCount() << endl;
}
