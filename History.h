#ifndef HISTORY_INCLUDED
#define HISTORY_INCLUDED


class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    // no need for a destructor, for there can be no memory leaks
    
private:
    int     m_rows;
    int     m_cols;
    int     m_colspot[1000];  // 1000 is an arbitrarily large number that will never be reached within the game
    int     m_rowspot[1000];
    int     m_numspots;
        // Up to m_numspots in both m_colspot and m_rowspot, there will be the corresponding number
        //  representing the column and row number of a flatulan that failed to convert
};

#endif  // HISTORY_INCLUDED
