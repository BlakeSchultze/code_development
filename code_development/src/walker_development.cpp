//#pragma once
#include "../include/walker_development.h"
//#include "code_development.h"

int RGBLCDshield_menuLevelsV[][6]   =
{
    {1,2,3},
    {4,5,6,7},
    {8,9}, {10,11},{12,13},
    {10,13,14,15,16,17}
};
int RGBLCDshield_menuLevelsC[][3][2][6]   =
{
    {
		{{3}},
		{{2,3,4},{2,3,4}},
		{{1,2},{2,3,4,5,6,7}}
	},
    {
		{{3}},
		{{2,3,4},{2,3,4}},
		{{1,2},{2,3,4,5,6,7}}
	}
};

int RGBLCDshield_menuLevelsDD[4][3][7];

int RGBLCDshield_menuLevelsD[][4][3][7]   =
{
    {3},
    {
        {3},
        {
            {-1},
            {1,3}
        },
        {
            {-2},
            {3,2,3,4},
            {3, 2,3,4}
        },
        {
            {-2},
            {2, 1,2},
            {6, 2,3,4,5,6,7}
        }
    },
    {
        {3},
        {
            {-1},
            {1,3}
        },
        {
            {-2},
            {3,2,3,4},
            {3, 2,3,4}
        },
        {
            {-2},
            {2, 1,2},
            {6, 2,3,4,5,6,7}
        }
    },
    {
        {3},
        {
            {-1},
            {1,3}
        },
        {
            {-2},
            {3,2,3,4},
            {3, 2,3,4}
        },
        {
            {-2},
            {2, 1,2},
            {6, 2,3,4,5,6,7}
        }
    }
};
int RGBLCDshield_menuLevelsE[][4][3][7]   =
{
	{3},//0000
	{
		{3},//1000
		{
			{-1}, //1100
			{1,1111}//1110,1111
		},
		{
			{-2},//1200
			{3,1211,1212,1213},//1210-3
			{3, 1221,1222,1223}//1220-3
		},
		{
			{-2},//1300
			{2, 1311,1312},//1310-2
			{6, 1321,1322,1323,1324,1325,1326}//1320-6
		}
	},
	{
		{3}, //2000
		{
			{-1}, //2100
			{1,2111}//2110/1
		},
		{
			{-2},//2200
			{3,2211,2212,2213},//2210-3
			{3, 2221,2222,2223}//2220-3
		},
		{
			{-2},//2300
			{2, 2311,2312},//2310-2
			{6, 2321,2322,2323,2324,2325,2326}//2320-6
		}
	},
	{
		{3}, //3000
		{
			{-1}, //3100
			{1,3111}//3110/1
		},
		{
			{-2},//3200
			{3,3211,3212,3213},//3210-3
			{3,3221,3222,3223}//3220-3
		},
		{
			{-2},//3300
			{2,3311,3312},//3310-2
			{6,3321,3322,3323,3324,3325,3326}//3320-6
		}
	}
};


int LCDshield_num_sublevels(int menu_levels[][4][3][7], int* path, int new_level)
{
    //int num_sublevels = menu_levels[path[0]][path[1]][path[2]][path[3]];
    //return num_sublevels;
    return menu_levels[path[0]][path[1]][path[2]][path[3]];
}
void walker_development()
{
	cout << RGBLCDshield_menuLevelsV[0][0] << endl;
	cout << RGBLCDshield_menuLevelsV[1][0] << endl;
	cout << RGBLCDshield_menuLevelsV[1][1] << endl;
	cout << RGBLCDshield_menuLevelsV[1][2] << endl;
	cout << RGBLCDshield_menuLevelsV[0][1] << endl;
	cout << RGBLCDshield_menuLevelsV[2][1] << endl;
	cout << RGBLCDshield_menuLevelsV[2][2] << endl;
	cout << RGBLCDshield_menuLevelsV[2][3] << endl;
	cout << RGBLCDshield_menuLevelsV[2][4] << endl;
	cout << RGBLCDshield_menuLevelsV[3][0] << endl;

	//int         RGBLCDshield_menuLevelsDDD[4][3][7] = {RGBLCDshield_menuLevelsD[2]};
	//int         RGBLCDshield_menuLevelsDDD[] = {*(*RGBLCDshield_menuLevelsD[1][1])};
	cout << "[0][0][0][0] : " << RGBLCDshield_menuLevelsD[0][0][0][0] << endl;
	cout << "[1][0][0][0] : "<< RGBLCDshield_menuLevelsD[1][0][0][0] << endl;
	cout << "[1][1][0][0] : "<< RGBLCDshield_menuLevelsD[1][1][0][0] << endl;
	cout << "[1][2][0][0] : "<< RGBLCDshield_menuLevelsD[1][2][0][0] << endl;
	cout << "[1][3][0][0] : "<< RGBLCDshield_menuLevelsD[1][3][0][0] << endl;
	cout << "[0][1][0][0] : "<< RGBLCDshield_menuLevelsD[0][1][0][0] << endl;
	cout << "[2][1][0][0] : "<< RGBLCDshield_menuLevelsD[2][1][0][0] << endl;
	cout << "[2][2][0][0] : "<< RGBLCDshield_menuLevelsD[2][2][0][0] << endl;
	cout << "[2][3][0][0] : "<< RGBLCDshield_menuLevelsD[2][3][0][0] << endl;
	cout << "[2][4][0][0] : "<< RGBLCDshield_menuLevelsD[2][4][0][0] << endl;
	cout << "[3][0][0][0] : "<< RGBLCDshield_menuLevelsD[3][0][0][0] << endl;

	cout << "[0][0][1][0] : "<< RGBLCDshield_menuLevelsD[0][0][1][0] << endl;
	cout << "[1][0][1][0] : "<< RGBLCDshield_menuLevelsD[1][0][1][0] << endl;
	cout << "[1][1][1][0] : "<< RGBLCDshield_menuLevelsD[1][1][1][0] << endl;
	cout << "[1][2][1][0] : "<< RGBLCDshield_menuLevelsD[1][2][1][0] << endl;
	cout << "[1][3][1][0] : "<< RGBLCDshield_menuLevelsD[1][3][1][0] << endl;
	cout << "[0][1][1][0] : "<< RGBLCDshield_menuLevelsD[0][1][1][0] << endl;
	cout << "[2][1][1][0] : "<< RGBLCDshield_menuLevelsD[2][1][1][0] << endl;
	cout << "[2][2][1][0] : "<< RGBLCDshield_menuLevelsD[2][2][1][0] << endl;
	cout << "[2][3][1][0] : "<< RGBLCDshield_menuLevelsD[2][3][1][0] << endl;
	cout << "[2][4][1][0] : "<< RGBLCDshield_menuLevelsD[2][4][1][0] << endl;
	cout << "[3][0][1][0] : "<< RGBLCDshield_menuLevelsD[3][0][1][0] << endl;

	cout << "[0][0][1][1] : "<< RGBLCDshield_menuLevelsD[0][0][1][1] << endl;
	cout << "[1][0][1][1] : "<< RGBLCDshield_menuLevelsD[1][0][1][1] << endl;
	cout << "[1][1][1][1] : "<< RGBLCDshield_menuLevelsD[1][1][1][1] << endl;
	cout << "[1][2][1][1] : "<< RGBLCDshield_menuLevelsD[1][2][1][1] << endl;
	cout << "[1][3][1][1] : "<< RGBLCDshield_menuLevelsD[1][3][1][1] << endl;
	cout << "[0][1][1][1] : "<< RGBLCDshield_menuLevelsD[0][1][1][1] << endl;
	cout << "[2][1][1][1] : "<< RGBLCDshield_menuLevelsD[2][1][1][1] << endl;
	cout << "[2][2][1][1] : "<< RGBLCDshield_menuLevelsD[2][2][1][1] << endl;
	cout << "[2][3][1][1] : "<< RGBLCDshield_menuLevelsD[2][3][1][1] << endl;
	cout << "[2][4][1][1] : "<< RGBLCDshield_menuLevelsD[2][4][1][1] << endl;
	cout << "[3][0][1][1] : "<< RGBLCDshield_menuLevelsD[3][0][1][1] << endl;

	cout << "RGBLCDshield_menuLevelsE[][4][3][7] " << endl<< endl;
	cout << "[0][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[0][0][0][0] << endl;
	cout << "[1][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[1][0][0][0] << endl;
	cout << "[1][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[1][1][0][0] << endl;
	cout << "[1][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[1][2][0][0] << endl;
	cout << "[1][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[1][3][0][0] << endl;


	cout << "[1][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[1][1][1][0] << endl;
	cout << "[1][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[1][2][1][0] << endl;
	cout << "[1][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[1][2][2][0] << endl;
	cout << "[1][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[1][3][1][0] << endl;
	cout << "[1][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[1][3][2][0] << endl;

	cout << "[1][1][1][1] : "<< RGBLCDshield_menuLevelsE[1][1][1][1] << endl;
	cout << "[1][2][1][1] : "<< RGBLCDshield_menuLevelsE[1][2][1][1] << endl;
	cout << "[1][2][1][2] : "<< RGBLCDshield_menuLevelsE[1][2][1][2] << endl;
	cout << "[1][2][1][3] : "<< RGBLCDshield_menuLevelsE[1][2][1][3] << endl;
	cout << "[1][2][2][1] : "<< RGBLCDshield_menuLevelsE[1][2][2][1] << endl;
	cout << "[1][2][2][2] : "<< RGBLCDshield_menuLevelsE[1][2][2][2] << endl;
	cout << "[1][2][2][3] : "<< RGBLCDshield_menuLevelsE[1][2][2][3] << endl;
	cout << "[1][3][1][1] : "<< RGBLCDshield_menuLevelsE[1][3][1][1] << endl;
	cout << "[1][3][1][2] : "<< RGBLCDshield_menuLevelsE[1][3][1][2] << endl;
	cout << "[1][3][2][1] : "<< RGBLCDshield_menuLevelsE[1][3][2][1] << endl;
	cout << "[1][3][2][2] : "<< RGBLCDshield_menuLevelsE[1][3][2][2] << endl;
	cout << "[1][3][2][3] : "<< RGBLCDshield_menuLevelsE[1][3][2][3] << endl;
	cout << "[1][3][2][4] : "<< RGBLCDshield_menuLevelsE[1][3][2][4] << endl;
	cout << "[1][3][2][5] : "<< RGBLCDshield_menuLevelsE[1][3][2][5] << endl;
	cout << "[1][3][2][6] : "<< RGBLCDshield_menuLevelsE[1][3][2][6] << endl;

	cout << "[2][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[2][0][0][0] << endl;
	cout << "[2][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[2][1][0][0] << endl;
	cout << "[2][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[2][2][0][0] << endl;
	cout << "[2][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[2][3][0][0] << endl;

	cout << "[2][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[2][1][1][0] << endl;
	cout << "[2][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[2][2][1][0] << endl;
	cout << "[2][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[2][2][2][0] << endl;
	cout << "[2][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[2][3][1][0] << endl;
	cout << "[2][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[2][3][2][0] << endl;


	cout << "[2][1][1][1] : "<< RGBLCDshield_menuLevelsE[2][1][1][1] << endl;
	cout << "[2][2][1][1] : "<< RGBLCDshield_menuLevelsE[2][2][1][1] << endl;
	cout << "[2][2][1][2] : "<< RGBLCDshield_menuLevelsE[2][2][1][2] << endl;
	cout << "[2][2][1][3] : "<< RGBLCDshield_menuLevelsE[2][2][1][3] << endl;
	cout << "[2][2][2][1] : "<< RGBLCDshield_menuLevelsE[2][2][2][1] << endl;
	cout << "[2][2][2][2] : "<< RGBLCDshield_menuLevelsE[2][2][2][2] << endl;
	cout << "[2][2][2][3] : "<< RGBLCDshield_menuLevelsE[2][2][2][3] << endl;
	cout << "[2][3][1][1] : "<< RGBLCDshield_menuLevelsE[2][3][1][1] << endl;
	cout << "[2][3][1][2] : "<< RGBLCDshield_menuLevelsE[2][3][1][2] << endl;
	cout << "[2][3][2][1] : "<< RGBLCDshield_menuLevelsE[2][3][2][1] << endl;
	cout << "[2][3][2][2] : "<< RGBLCDshield_menuLevelsE[2][3][2][2] << endl;
	cout << "[2][3][2][3] : "<< RGBLCDshield_menuLevelsE[2][3][2][3] << endl;
	cout << "[2][3][2][4] : "<< RGBLCDshield_menuLevelsE[2][3][2][4] << endl;
	cout << "[2][3][2][5] : "<< RGBLCDshield_menuLevelsE[2][3][2][5] << endl;
	cout << "[2][3][2][6] : "<< RGBLCDshield_menuLevelsE[2][3][2][6] << endl;

	cout << "[3][0][0][0] : 3="<< RGBLCDshield_menuLevelsE[3][0][0][0] << endl;
	cout << "[3][1][0][0] : -1="<< RGBLCDshield_menuLevelsE[3][1][0][0] << endl;
	cout << "[3][2][0][0] : -2="<< RGBLCDshield_menuLevelsE[3][2][0][0] << endl;
	cout << "[3][3][0][0] : -2="<< RGBLCDshield_menuLevelsE[3][3][0][0] << endl;

	cout << "[3][1][1][0] : 1="<< RGBLCDshield_menuLevelsE[3][1][1][0] << endl;
	cout << "[3][2][1][0] : 3="<< RGBLCDshield_menuLevelsE[3][2][1][0] << endl;
	cout << "[3][2][2][0] : 3="<< RGBLCDshield_menuLevelsE[3][2][2][0] << endl;
	cout << "[3][3][1][0] : 2="<< RGBLCDshield_menuLevelsE[3][3][1][0] << endl;
	cout << "[3][3][2][0] : 6="<< RGBLCDshield_menuLevelsE[3][3][2][0] << endl;

	cout << "[3][1][1][1] : "<< RGBLCDshield_menuLevelsE[3][1][1][1] << endl;
	cout << "[3][2][1][1] : "<< RGBLCDshield_menuLevelsE[3][2][1][1] << endl;
	cout << "[3][2][1][2] : "<< RGBLCDshield_menuLevelsE[3][2][1][2] << endl;
	cout << "[3][2][1][3] : "<< RGBLCDshield_menuLevelsE[3][2][1][3] << endl;
	cout << "[3][2][2][1] : "<< RGBLCDshield_menuLevelsE[3][2][2][1] << endl;
	cout << "[3][2][2][2] : "<< RGBLCDshield_menuLevelsE[3][2][2][2] << endl;
	cout << "[3][2][2][3] : "<< RGBLCDshield_menuLevelsE[3][2][2][3] << endl;
	cout << "[3][3][1][1] : "<< RGBLCDshield_menuLevelsE[3][3][1][1] << endl;
	cout << "[3][3][1][2] : "<< RGBLCDshield_menuLevelsE[3][3][1][2] << endl;
	cout << "[3][3][2][1] : "<< RGBLCDshield_menuLevelsE[3][3][2][1] << endl;
	cout << "[3][3][2][2] : "<< RGBLCDshield_menuLevelsE[3][3][2][2] << endl;
	cout << "[3][3][2][3] : "<< RGBLCDshield_menuLevelsE[3][3][2][3] << endl;
	cout << "[3][3][2][4] : "<< RGBLCDshield_menuLevelsE[3][3][2][4] << endl;
	cout << "[3][3][2][5] : "<< RGBLCDshield_menuLevelsE[3][3][2][5] << endl;
	cout << "[3][3][2][6] : "<< RGBLCDshield_menuLevelsE[3][3][2][6] << endl;

	int path[] = {2,2,0,0};
	int sublvls = LCDshield_num_sublevels(RGBLCDshield_menuLevelsE, path, 1);
	cout << "sublvls = "<< sublvls << endl;

	//cout << "0 : "<< RGBLCDshield_menuLevelsDDD[0] << endl;
	//cout << "1 : "<< RGBLCDshield_menuLevelsDDD[1] << endl;
	//cout << "2 : "<< RGBLCDshield_menuLevelsDDD[2] << endl;
	cout << ((-1 + 50) % 50 ) << endl;
	cout << ((49 + 50) % 50 ) << endl;
	cout << ((48 + 50) % 50 ) << endl;
	unsigned int p = 3;
	unsigned int bound = 50;
	unsigned int umaxval = std::numeric_limits<unsigned int>::max();
	//int maxval = std::numeric_limits<int>::max() - std::numeric_limits<int>::min()-1;
	cout << (std::min(p-- + umaxval, bound)) << endl;
	cout << (std::min((p-- + umaxval),bound)) << endl;
	cout << (std::min((p-- + umaxval),bound)) << endl;
	cout << (std::min((p-- + umaxval),bound)) << endl;
	cout << (umaxval) << endl;
}
