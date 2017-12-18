#include <iostream>
#include <vector>

using namespace std;

/**
    You are given a range of integers (A,B) where A and B are inclusive. Create a function that will return
    the number of prime numbers in that given range. For the range (11,19) the function should return 4.
*/
int PrimeCount(int A, int B)
{
    int numPrimes = 0;
    int nonDevisibleNum = -1;
    vector <int> primeNums;

    //Checks all numbers in the given range
    for(int c = A; c <= B; c++)
    {
        if(c%1 == 0 && c%c == 0)
        {
            nonDevisibleNum = c;
            cout << c << " could be prime "<< endl;

            for(int a = 2; a < B; a++)
            {
                if(a != c)
                {
                    //Checks if they are not devisible by every other number in the same range
                    if(c%a != 0)
                    {
                        //cout << c << "%" << a << " = "<< c%a << endl;
                        nonDevisibleNum = c;
                    }

                    if (c%a == 0)
                    {//Checks if the number that the numbers that c is devisible isitself
                        cout << c << "%" << a << " = "<< c%a<< endl;
                        nonDevisibleNum = -1;
                        break;
                    }
                }
            }
        }

        //Checking if nonDevisibleNum stores a positive number in the range given
        cout <<"nonDevisibleNum is " << nonDevisibleNum <<"\n" << endl;

        //if at this point nonDevisibleNum is -1 then the number is not prime
        if(nonDevisibleNum >= A)
        {
            numPrimes++;
            //cout << "adding prime " << nonDevisibleNum << endl;
            primeNums.push_back(nonDevisibleNum);
        }else if(nonDevisibleNum == -1 )
        {
            //nothing happens
        }

        cout << "Current Prime Nums: ";
        for(int c = 0; c < primeNums.size(); c++)
        {
            cout << primeNums.at(c) << ", ";
        }
        cout << " \n\n";
    }

    return numPrimes;
}


int main()
{
    cout << "Number of primes in the given range is:  "<<PrimeCount(11, 19) << endl;

    return 0;
}
