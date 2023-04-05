#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#ifndef X
#define X 8
#endif
#ifndef Y
#define Y 8
#endif
#ifndef N
#define N 4
#endif
/*
1 - up
2 - left
3 - right
4 - down
*/
std::default_random_engine rng(100);
/*
X = 8 Y = 8
N = 4
seed = 100
1 1 3 4 2 4 3 4
*/
struct Cell
{
    bool stopped;
    int direction;
    int x;
    int y;
};

int RandInt(int min, int max)
{
    std::uniform_int_distribution<int> dstr(min, max);
    return dstr(rng);
}

void MakeRandomAtom(Cell (&cells)[N])
{
    int k = 0;
    int flag = 0;
    while (k != N)
    {
        cells[k].x = RandInt(0, X - 1);
        cells[k].y = RandInt(0, Y - 1);
        cells[k].stopped = false;
        for (int i = 0; i < k; ++i)
        {
            if ((cells[i].x == cells[k].x) and (cells[i].y == cells[k].y))
                flag = 1;
        }
        if (flag != 1)
            k++;
        flag = 0;
    }
}

void MakeAtom_moments(Cell (&cells)[N])
{
    cells[0].stopped = false;
    cells[0].x = 2;
    cells[0].y = 2;
    cells[1].stopped = false;
    cells[1].x = 3;
    cells[1].y = 3;
    cells[2].stopped = false;
    cells[2].x = 4;
    cells[2].y = 4;
    cells[3].stopped = false;
    cells[3].x = 5;
    cells[3].y = 3;
}

void MakeDirection(Cell (&cells)[N])
{
    for (int i = 0; i < X; i++)
    {
        cells[i].direction = RandInt(1, 4);
    }
}

void MoveCells(Cell (&cells)[N], int &exit_tick)
{
    int flag;
    for (int k = 0; k < N; ++k)
    {
        flag = 0;
        if (!cells[k].stopped)
        {
            if (cells[k].direction == 1)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].y - 1) == cells[i].y) and (cells[k].x == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].y--;
                    exit_tick = 1;
                }
            }
            else if (cells[k].direction == 2)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x - 1) == cells[i].x) and (cells[k].y == cells[i].y))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x--;
                    exit_tick = 1;
                }
            }
            else if (cells[k].direction == 3)
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].x + 1) == cells[i].x) and (cells[k].y == cells[i].y))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].x++;
                    exit_tick = 1;
                }
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (((cells[k].y + 1) == cells[i].y) and (cells[k].x == cells[i].x))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cells[k].y++;
                    exit_tick = 1;
                }
            }
        }
    }
}

void Stop(Cell (&cells)[N])
{
    for (int k = 0; k < N; ++k)
    {
        if (!cells[k].stopped)
        {
            if ((cells[k].x == 0) or (cells[k].x == (X - 1)) or (cells[k].y == 0) or (cells[k].y == (Y - 1)))
            {
                cells[k].stopped = true;
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (abs(cells[i].x - cells[k].x) + abs(cells[i].y - cells[k].y) == 1)
                    {
                        cells[k].stopped = true;
                    }
                }
            }
        }
    }
}

void Tick(Cell (&cells)[N], int &exit_tick)
{
    exit_tick = 0;
    Stop(cells);
    MakeDirection(cells);
    MoveCells(cells, exit_tick);
    Stop(cells);
}

void Print(Cell (&cells)[N])
{
    int flag = 0;
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            flag = 0;
            for (int k = 0; k < N; ++k)
            {
                if (cells[k].x == j and cells[k].y == i)
                {
                    flag = 1;
                    if (cells[k].stopped)
                        std::cout << "s"
                                  << " ";
                    else
                        std::cout << "e"
                                  << " ";
                }
            }
            if (flag == 0)
            {
                std::cout << "0"
                          << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main()
{
    int exit_tick = 1;
    Cell cells[N];
    MakeAtom_moments(cells);
    Print(cells);
    Tick(cells, exit_tick);
    Print(cells);
    Tick(cells, exit_tick);
    Print(cells);
    return 0;
}