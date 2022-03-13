int minFlips (string S)
{
    // your code here
   int n = S.length();
   int first0 = '0', change1 = 0;
   int second1 = '1', change2 = 0;
   int first1 = '1', change3 = 0;
   int second0 = '0', change4 = 0;
   for(int i = 0; i < n; i+= 2){
       if(S[i] != first0) change1++;
   }
   for(int i = 1; i < n; i+= 2){
       if(S[i] != second1) change2++;
   }
   for(int i = 0; i < n; i += 2){
       if(S[i] != first1) change3++;
   }
   for(int i = 1; i < n; i += 2){
       if(S[i] != second0) change4++;
   }
   return (min(change1 + change2 ,change3 + change4));
}