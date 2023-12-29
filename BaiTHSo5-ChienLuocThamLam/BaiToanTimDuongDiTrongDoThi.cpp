/*
De bai : Cho 1 do thi vo huong , co san trong so 
Yeu cau : Hay tim duong di ngan nhat tu dinh A -> B 
(duong di co tong chi phi tot nhat)

Cach giai quyet : Su dung tham lam , tim buoc di toi uu o 
moi buoc lap 

Tai moi dinh , kiem tra xem da di qua hay chua , tim trong so ngan
nhat trong so cac dinh xung quanh , di den diem nao thi danh dau 
lai dinh do

Bieu dien ma tran ke 
 	A   B   C   D   E    F    H   I   G 
 A  0  -1  16  10  19   -1   -1  -1  -1
 B -1   0  -1  -1  -1    3   12   5   8
 C 16  -1   0  18  -1   -1   20  -1  -1
 D 10  -1  18   0   7    7   -1  -1   8
 E 19  -1  -1   7   0   -1   15   9  -1 
 F -1   3  -1   7  -1    0   15  -1   2 
 H -1  12  20  -1  -1   15    0  -1  -1 
 I -1  -1  -1  -1   9   -1   -1   0   4
 G -1   8  -1   8  -1    2   -1   4   0
*/
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum
// cost path for all the paths
void findMinRoute(vector<vector<int> > tsp)
{
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
 
    // Starting from the 0th indexed
    // city i.e., the first city
    visitedRouteList[0] = 1;
    int route[tsp.size()];
 
    // Traverse the adjacency
    // matrix tsp[][]
    while (i < tsp.size() && j < tsp[i].size())
    {
 
        // Corner of the Matrix
        if (counter >= tsp[i].size() - 1)
        {
            break;
        }
 
        // If this path is unvisited then
        // and if the cost is less then
        // update the cost
        if (j != i && (visitedRouteList[j] == 0))
        {
            if (tsp[i][j] < min)
            {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;
 
        // Check all paths from the
        // ith indexed city
        if (j == tsp[i].size())
        {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }
 
    // Update the ending city in array
    // from city which was last visited
    i = route[counter - 1] - 1;
 
    for (j = 0; j < tsp.size(); j++)
    {
 
        if ((i != j) && tsp[i][j] < min) 
        {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;
 
    // Started from the node where
    // we finished as well.
    cout << ("Minimum Cost is : ");
    cout << (sum);
}
 

int main()
{
   
    vector<vector<int> > tsp = { { -1, 10, 15, 20 },
                                 { 10, -1, 35, 25 },
                                 { 15, 35, -1, 30 },
                                 { 20, 25, 30, -1 } };
 
    findMinRoute(tsp);
    
    return 0; 
}

