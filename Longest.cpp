
#include <iostream>
using namespace std;
int FindLongestSequence(char a[20][21], int m, int n, char b[20][21], int& u, int& v, int& d) {

    int i, j, k, l, horiz = 0, vert = 0, diagonalR = 0, diagonalL = 0, elkbir, max2 = 0, maax[500], p = 0, rowind[500], colind[500], type[500];
    if (m > 20 || n > 20 || m <= 0 || n <= 0) return -1; // Invalid input

    for (i = 0; i < m; i++) {

        for (j = 0; j < n; j++) {
            horiz = 0, vert = 0, diagonalR = 0, diagonalL = 0;
            k = i + 1;

            while ((a[i][j] == a[k][j]) && k < m) {//loop elvertical
                vert++;
                k++;
            }

            k = j + 1;

            while ((a[i][j] == a[i][k]) && k < n) {//loop elhorizontal
                horiz++;
                k++;
            }

            k = i + 1;
            l = j + 1;
            while ((a[i][j] == a[k][l]) && k < m && l < n) {//diagonal right
                diagonalR++;
                k++;
                l++;
            }

            k = i - 1;
            l = j + 1;
            while ((a[i][j] == a[k][l]) && k >= 0 && l < n) {//diagonal left
                diagonalL++;
                k--;
                l++;
            }

            if ((vert > horiz) && (vert > diagonalR) && (vert > diagonalL)) {
                elkbir = vert;
                rowind[p] = i;
                colind[p] = j;
                type[p] = 1;
            }


            else if ((horiz > vert) && (horiz > diagonalR) && (horiz > diagonalL)) {
                elkbir = horiz;
                rowind[p] = i;
                colind[p] = j;
                type[p] = 0;
            }

            else if ((diagonalR > vert) && (diagonalR > horiz) && (diagonalR > diagonalL)) {
                elkbir = diagonalR;
                rowind[p] = i;
                colind[p] = j;
                type[p] = 2;
            }

            else {
                elkbir = diagonalL;
                rowind[p] = i;
                colind[p] = j;
                type[p] = 3;
            }

            maax[p] = elkbir;
            p++;
        }
    }
    for (int z = 0; z < p; z++) {

        if (max2 < maax[z]) {
            max2 = maax[z];
            u = rowind[z];
            v = colind[z];
            d = type[z];
        }
    }
    int len = max2;
    int u1 = u, v1 = v;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) b[i][j] = a[i][j];
    }

    if (d == 0) {
        while (len >= 0) {//horiz
            b[u1][v1] = '.';
            v1++;
            len--;
        }
    }
    else if (d == 1) {//vert
        while (len >= 0) {
            b[u1][v1] = '.';
            u1++;
            len--;
        }
    }

    else if (d == 2) {//diagonal down
        while (len >= 0) {
            b[u1][v1] = '.';
            u1++;
            v1++;
            len--;
        }
    }
    else {
        while (len >= 0) {//diagonal up
            b[u1][v1] = '.';
            v1++;
            u1--;
            len--;
        }
    }





    for (i = 0; i < m; i++)  b[i][n] = '\0';



    return max2 + 1;



}
void Test(char a[20][21], int m, int n)
{
    char b[20][21];
    int u, v, d;


    int len = FindLongestSequence(a, m, n, b, u, v, d);

    cout << "MaxLen=" << len << " Start=(" << u << " " << v << ") ";

    if (d == 0) cout << "Horizontal";
    else if (d == 1) cout << "Vertical";
    else if (d == 2) cout << "Diagonal \\";
    else if (d == 3) cout << "Diagonal /";
    cout << endl;

    int i;
    cout << "Array after replacing longest sequence by dots:" << endl;
    for (i = 0; i < m; i++) cout << b[i] << endl;
    cout << endl;
}

int main()
{
    char a[20][21] =
    {
        // col   0123456
                "xoxxoxo", // row 0
                "ooxooxo", // row 1
                "xxoooox", // row 2
                "oxxoxxx", // row 3
    };

    Test(a, 4, 7);

    // Output should be
    // MaxLen=4 Start=(2 2) Horizontal
    // Array after replacing longest sequence by dots:
    // xoxxoxo
    // ooxooxo
    // xx....x
    // oxxoxxx

    char w[20][21] =
    {
        // col   012345
                "xyxxox", // row 0
                "oryoox", // row 1
                "xxryoo", // row 2
                "xxxryx", // row 3
                "xxxory", // row 4
    };

    Test(w, 5, 6);

    // Output should be
    // MaxLen=5 Start=(0 1) Diagonal \,
    // Array after replacing longest sequence by dots:
    // x.xxox
    // or.oox
    // xxr.oo
    // xxxr.x
    // xxxor.

    char q[20][21] =
    {
        // col   01234567
                "xtuyxxox", // row 0
                "xuuyxxox", // row 1
                "ouiryoox", // row 2
                "xupxryoo", // row 3
                "xuexxryx", // row 4
                "xuqxxory", // row 5
                "yuqxxory", // row 6
    };

    Test(q, 7, 8);

    // Output should be
    // MaxLen=6 Start=(1 1) Vertical
    // Array after replacing longest sequence by dots:
    // xtuyxxox
    // x.uyxxox
    // o.iryoox
    // x.pxryoo
    // x.exxryx
    // x.qxxory
    // y.qxxory

    char r[20][21] =
    {
        // col   01234567
                "xtuyxxox", // row 0
                "xuuyxxox", // row 1
                "ouiryo1x", // row 2
                "xupxr1oo", // row 3
                "x1ex1ryx", // row 4
                "xuq1xory", // row 5
                "yu1xxory", // row 6
                "x11yxxox", // row 7
                "yu1xxory", // row 8
    };

    Test(r, 9, 8);

    // Output should be
    // MaxLen=6 Start=(7 1) Diagonal /
    // Array after replacing longest sequence by dots:
    // xtuyxxox
    // xuuyxxox
    // ouiryo.x
    // xupxr.oo
    // x1ex.ryx
    // xuq.xory
    // yu.xxory
    // x.1yxxox
    // yu1xxory

    return 0;
}
