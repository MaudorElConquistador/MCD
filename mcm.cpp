#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int mcm(int a, int b){
    /*a numero mayor , b numero menor */ 
    if (a%b == 0){
        return b;
    }
    int modulo = a % b; 
    if( a%modulo != 0 ){
        modulo = mcm(b,modulo);
    }
    return modulo;
}

int middle(vector<int> &rnumbers){
    int result;
    if( int(rnumbers.size()) == 2 ){
        result = mcm(rnumbers[1], rnumbers[0]);
        return result;
    }
    result = mcm(rnumbers[1], rnumbers[0]);
    int x = 0;
    for (unsigned i = 2; i <= rnumbers.size() - 1; i++)
    {
        x++;
        result = mcm(rnumbers[i], result);
    
    }
    
    return result; 
}


int main(){
    int flag;
    vector<int> numbers;

    cout << "Ingresa los numeros de los cuales quieras el minimo comun multiplo \n";
    cout << "Cuando hayas terminado ingresa el 0 \n";
    
    do{
        cin >> flag;
        if(flag != 0)
            numbers.push_back(flag);
    }while(flag != 0);

    sort(numbers.begin(), numbers.end());
    cout << "Maximo comun divisor: \n" << middle(numbers) << " \n";
    return 0;
}