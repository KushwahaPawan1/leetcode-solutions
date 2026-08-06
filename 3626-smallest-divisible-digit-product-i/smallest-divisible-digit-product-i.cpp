class Solution {
public:
int prodOfDigit(int num){
    string number = to_string(num);
    int prod=1;
    for(int i=0;i<number.length();i++)  prod = prod * (number[i] - '0');
      return prod;
}
    int smallestNumber(int n, int t) {
       int currProd= prodOfDigit(n);
        if(currProd%t==0) return n;
        else {
            while(currProd%t!=0){
                n++;
                currProd= prodOfDigit(n);
            }
        }
         return n;
    }
};