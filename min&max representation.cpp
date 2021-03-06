// About the algorithm: http://www.docin.com/p-489598116.html
// It can runs faster by using extra space instand of modular arithmetic
// 'plen' is the length of S's recurring period, can be default

inline int minRepresentation(char* S, int plen = -1)
{
    int i = 0, j = 1;
    int k = 0;

    if (plen == -1)
        plen = strlen(S);

    while (k < plen - 1 && i < plen && j < plen)
    {
        int dis = S[(i + k) % plen] - S[(j + k) % plen];

        if (dis == 0)
            k++;
        else if (dis > 0)
        {
            i += k + 1;
            k = 0;
        }
        else if (dis < 0)
        {
            j += k + 1;
            k = 0;
        }
        if (i == j)
            j++;
    }
    return i;
}

inline int maxRepresentation(char* S, int plen = -1)
{
    int i = 0, j = 1;
    int k = 0;

    if (plen == -1)
        plen = strlen(S);

    while (k < plen - 1 && i < plen && j < plen)
    {
        int dis = S[(i + k) % plen] - S[(j + k) % plen];

        if (dis == 0)
            k++;
        else if (dis < 0)
        {
            i += k + 1;
            k = 0;
        }
        else if (dis > 0)
        {
            j += k + 1;
            k = 0;
        }
        if (i == j)
            j++;
    }
    return i;
}
