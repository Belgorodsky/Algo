#if 0
=========================================================
*************************HEAPSORT************************
=========================================================
********************TIME COMPLEXITY**********************
    BEST: Ω(n+k)    AVERAGE: Θ(n+k)     WORST: O(n^2)
=========================================================
********************SPACE COMPLEXITY*********************
                       WORST: O(n)
=========================================================
You have plenty of assorted DoB (Date of Birth) slips, 
you need to sort them. One way is to go through the list 
and place each of the slip in a month-wise column. Then 
re-arrange inside the month column, the slips using 
some simple sort method.

When the input numbers (content) are within certain range
and they are uniformly distributed in that range, then
bucket sort can be made. First we divide the range into 
a smaller sub-ranges called bucket or bin. For example 
if the input is between 0 to 50, divide the range into 
10 sub-ranges of bucket size 5 (first bucket is 0 to 4, 
next one 5 to 9, etc). Have a some hash function 
to place the input numbers into one of these buckets 
such that always the numbers are hashed to increasing 
order buckets. In the example we just use input number 
divided by 5 as the hash function. 
#endif

#include <iostream>
#include <queue>

size_t n, k, r;
bool hasSignedValues;

void print(int *input)
{
    for( int i = 0; i < n; ++i)
        std::cout << input[i] << " ";
    std::cout << std::endl;
}

int hash(int value)
{
    static int divider = hasSignedValues ? 2 * r / k : r / k;
    return value / divider;
}

void doInsertionSortForBucket(int input[], int len)
{
    while( len-- > 0) {
        if ( input[len] > input[len+1] ) 
        {
            int tmp = std::move(input[len]);
            input[len] = std::move(input[len+1]);
            input[len+1] = std::move(tmp);
        }
        else
        {
            return;
        }
    }
}

void bucketsort(int input[])
{
    std::queue<int> *buckets[k];
    for ( int i = 0; i < k; ++i)
        buckets[i] = new std::queue<int>;

    // Hash the input and insert the content into approproate bucket based on hash
    for( int i = 0; i < n; ++i)
    {
        int hashValue = hash(input[i]);
        if(hashValue >= k)
            hashValue = k - 1;

        buckets[hashValue]->push(input[i]);
    }
    //extract th content from each of buckets in order
    //using insertion sort
    int outputIdx = 0;
    for( int i = 0; i < k; ++i )
    {
        if ( buckets[i]->size() == 1 ) {
            input[outputIdx++] = buckets[i]->front();
            std::cout << buckets[i]->front() << " | ";
            buckets[i]->pop();
        }
        if ( buckets[i]->size() > 1 )
        {
            while (!buckets[i]->empty())
            {
                input[outputIdx] = buckets[i]->front();
                doInsertionSortForBucket(input, outputIdx);
                std::cout << buckets[i]->front() << " ";
                buckets[i]->pop();
                outputIdx++;
            }
            std::cout << "| ";
        }
    }
    // clear buckets 
    for(int i = 0; i < k; ++i)
        delete buckets[i];
}


int main()
{
    std::cout << "Enter the size of the array" << std::endl;
    std::cin >> n;
    int val;
    int i = 0;
    int input[n];
    memset(input, 0, sizeof(input));

    std::cout << "Enter space separated array" << std::endl;
    while( std::cin >> val )
    {
        input[i++] = val;
        if(i == n) break;
    }

    n = i;

    std::cout << "Enter count of buckets" << std::endl;
    std::cin >> k;

    std::cout << "Enter values range size" << std::endl;
    std::cin >> r;
    
    std::cout << "Has signed values [0/1]" << std::endl;
    std::cin >> val;
    hasSignedValues = val;

    std::cout << "Input: ";
    print(input);
    std::cout << "Bucketed list: " ;
    bucketsort(input);
    std::cout << "\nOutput: ";
    print(input);
    return 0;

}
