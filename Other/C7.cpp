#include <stdio.h>
#include <math.h>

int LStackEnds = -1; //LStack grows ->
int RStackEnds = 21; //RStack grows <-
int MStackBeg = 10;  //MStack grows ->, but rll not preference
int MStackEnds = 9;

int arr[21];
int get(int i)
{
    return arr[i];
}
void put(int i, int val)
{
    arr[i] = val;
}

void shiftMid(int shift)
{
    if (shift > 0)
    {
        for (int i = MStackEnds; i >= MStackBeg; i--)
        {
#ifndef ONLINE_JUDGE
            printf("bruh collision: shifting by %d\n", shift);
#endif
            put(i + shift, get(i));
        }
    }
    else if (shift < 0)
    {
#ifndef ONLINE_JUDGE
        printf("bruh collision: shifting by %d\n", shift);
#endif
        for (int i = MStackBeg; i <= MStackEnds; i++)
        {
            put(i + shift, get(i));
        }
    }
    MStackBeg += shift;
    MStackEnds += shift;
    //printf("bruh %d %d\n", MStackBeg, MStackEnds);
}

void push(int ident, int content)
{
    if (ident == 0)
    {
        if (LStackEnds + 1 == MStackBeg)
        { //if collision
            //printf("collision\n");
            shiftMid((RStackEnds - MStackEnds - 1) / 2);
        }
        LStackEnds++;
        put(LStackEnds, content);
        //printf("current top stack: %d, prev top stack: %d\n", get(LStackEnds), get(LStackEnds-1));
    }
    else if (ident == 1 || ident == 2)
    {
        if (MStackEnds + 1 == RStackEnds)
        {
            shiftMid((LStackEnds - MStackBeg - 1) / 2);
        }
        if (ident == 1)
        {

            MStackEnds++;

            put(MStackEnds, content);
        }
        else if (ident == 2)
        {
            RStackEnds--;
            put(RStackEnds, content);
            //printf("bruh: %d\n", get(RStackEnds));
        }
    }
}

int pop(int ident)
{
    if (ident == 0)
    {
        LStackEnds--;
        return get(LStackEnds + 1);
    }
    else if (ident == 1)
    {
        MStackEnds--;
        return get(MStackEnds + 1);
    }
    else if (ident == 2)
    {
        RStackEnds++;
        return get(RStackEnds - 1);
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    char currentOp, nextOp;
    int ident, nextIdent;
    int value, nextValue;

    while (scanf(" %c", &currentOp) != EOF)
    {
        scanf("%d", &ident);
                
        if (currentOp == 'u')
        {
            scanf("%d", &value);
            push(ident, value);
        }
        else if (currentOp == 'o')
        {
            printf("%d\n", pop(ident));
        }
    }
}
