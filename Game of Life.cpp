// Devang Choudhary
// C++

#include <bits/stdc++.h>
using namespace std;
class Cells
{
    public:
    bool grid[8][8]; // to store the Coordinates

    Cells()
    {
        memset(grid, false, sizeof(grid));    // initialization   
    }
    
    void calculate_next(vector< pair<int,int> > vect)
    {
        int len = vect.size(), x, y;
        // accept input
        for(int i=0; i<len; i++)
        {
            x = vect[i].first;
            y = vect[i].second;
            grid[x][y] = true;
        } 

        bool temp[8][8]; // used temp so that current calcuations are unaffected
        memset(temp, false, sizeof(temp));
        // update Live <--> Dead
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                temp[i][j] = check(i,j);
            }
        }
        
        // Update Grid
        memcpy(grid, temp, sizeof(grid));

    }

    bool check(int i, int j)
    {
        // to calculate no. of Live neighbours

        int count = 0;
        if(i<7)
        {
            if(grid[i+1][j] == true) count++;
            if(j<7 && ( grid[i+1][j+1] == true) ) count++;
            if(j>0 && ( grid[i+1][j-1] == true) ) count++;
        }
        if(i>0)
        {
            if(grid[i-1][j] == true) count++;
            if(j<7 && ( grid[i-1][j+1] == true) ) count++;
            if(j>0 && ( grid[i-1][j-1] == true) ) count++;
        }

        if(j<7 && (grid[i][j+1] == true) ) count++;
        if(j>0 && (grid[i][j-1] == true) ) count++;

        
        if(count == 3) return true;
        if(count == 2) return grid[i][j];

        return false;
                
    }


    void print_grid()
    {
        cout<<"Coordinates of Live cells for next generation are: "<<endl;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(grid[i][j] == true)
                {
                    cout<<i<<", "<<j<<endl;
                }
            }
        }
        cout<<"-----------------------------------------";
    }

    
};

int main() {
    Cells cells;

    vector< pair<int,int> > vect;

    int input, x, y;
    cout<<"Enter total no. of live cells"<<endl;
    cin>>input;
    
    for(int i=0; i<input; i++)
    {
        cout<<"Enter Coordinates of live cell number:"<<i+1<<endl;
        cin >> x >> y;
        vect.push_back( make_pair(x,y) );
    }

    cells.calculate_next(vect);
    cells.print_grid();
    return 0;
}
