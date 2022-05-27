class Solution {
public:
    int numberOfSteps (int num) 
  {
     int ans=0;
    while(num)
    {
        ans++;
       if(num&1)
       {
         num--;
         ans++;
       }
       num/=2;
    }
    return max(0 , ans - 1);   
  }
};