#### Binary Search, Ternary Search and Two Pointer

put the value of x in the function, 
check whether is monotonically increase or decreasing -> binary search
if its minima and maxima kind of then ternary.
https://codeforces.com/blog/entry/60702

1. https://codeforces.com/problemset/problem/1928/D
3. https://codeforces.com/problemset/problem/578/C

Two Pointer implementation Algo:

```

  while(second<s.size())
    {
        //while diff exist
        while(d&&second<s.size())
        {
             if(count[s[second]]==0)
        d--;
            count[s[second]]++;
            second++;
        }
        l=min(l,second-f);

        //diff=1;
        while(d!=1)
        {
                l=min(l,second-f);
                count[s[f]]--;

                if(count[s[f]]==0)
                d++;
                f++; 
        }


    }

```
