#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#ifndef X
#define X 50
#endif
#ifndef Y
#define Y 50
#endif
#ifndef N
#define N 10
#endif
/*
0 - nothing
1 - up
2 - left
3 - right
4 - down
*/

int exit_tick = 0;
std::default_random_engine rng(1001);

struct Cell
{
    bool empty;
    bool stopped;
    int direction;
    int x;
    int y;
};
Cell cells[N];

void MakeRandomAtom()
{
    int k = 0;
    int flag = 0;
    std::uniform_int_distribution<int> randx(0, X - 1);
    std::uniform_int_distribution<int> randy(0, Y - 1);
    while (k != N)
    {
        cells[k].x = randx(rng);
        cells[k].y = randy(rng);
        for (int i = 0; i < k; ++i)
        {
            if (cells[i].x == cells[k].x and cells[i].y == cells[k].y)
            {
                flag = 1;
            }
        }
        if (flag != 1)
            k++;
        flag = 0;
    }
}

int RandomNumbInRange(int min, int max)
{
    std::uniform_int_distribution<int> dstr(min, max);
    return dstr(rng);
}

void MakeDirection(Cell (&cells)[N])
{
    for (int i = 0; i < X; i++)
    {
        cells[i].direction = RandomNumbInRange(1, 4);
    }
}

void MoveCells(Cell (&cells)[N])
{
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            if ((i != X) and (i != 0))
            {
                if ((j = 0) and (grid.cells[i][j + 1].direction == 2) and (grid.cells[i][j + 1].empty) and (!grid.cells[i][j + 1].stopped))
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i][j + 1].empty = false;
                    exit_tick = 1;
                }
                else if ((j = Y) and (grid.cells[i][j - 1].direction == 3) and (grid.cells[i][j - 1].empty) and (!grid.cells[i][j - 1].stopped))
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i][j - 1].empty = false;
                    exit_tick = 1;
                }
            }
            else if ((j != Y) and (j != 0))
            {
                if ((i = 0) and (grid.cells[i + 1][j].direction == 1) and (grid.cells[i + 1][j].empty) and (!grid.cells[i + 1][j].stopped))
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i + 1][j].empty = false;
                    exit_tick = 1;
                }
                else if ((i = X) and (grid.cells[i - 1][j].direction == 4) and (grid.cells[i - 1][j].empty) and (!grid.cells[i - 1][j].stopped))
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i - 1][j].empty = false;
                    exit_tick = 1;
                }
            }
            else if ((i != 0) and (j != 0) and (i != X) and (j != Y))
            {
                if (grid.cells[i + 1][j].direction == 1 and grid.cells[i + 1][j].empty and !grid.cells[i + 1][j].stopped)
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i + 1][j].empty = false;
                    exit_tick = 1;
                }
                else if (grid.cells[i - 1][j].direction == 4 and grid.cells[i - 1][j].empty and !grid.cells[i - 1][j].stopped)
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i - 1][j].empty = false;
                    exit_tick = 1;
                }
                else if (grid.cells[i][j + 1].direction == 2 and grid.cells[i][j + 1].empty and !grid.cells[i][j + 1].stopped)
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i][j + 1].empty = false;
                    exit_tick = 1;
                }
                else if (grid.cells[i][j - 1].direction == 3 and grid.cells[i][j - 1].empty and !grid.cells[i][j - 1].stopped)
                {
                    grid.cells[i][j].empty = true;
                    grid.cells[i][j - 1].empty = false;
                    exit_tick = 1;
                }
            }
        }
    }
}

void Stop(Cell (&cells)[N])
{
    for (int k = 0; i < N; ++i)
    {
        if (!cells[k].stopped)
        {
            if ((cells[k].x == 0) or (cells[k].x == X) or (cells[k].y == 0) or (cells[k].y == Y))
            {
                cells[k].stopped = true;
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if (abs(cells[i].x - cells[k].x) + abs(cells[i].y - cells.[k].y) == 1)
                    {
                        cells[k].stopped = true;
                    }
                }
            }
        }
    }
}

void Tick(Cell (&cells)[N])
{
    exit_tick = 0;
    Stop(cells);
    MakeDirection(cells);
    MoveCells(cells);
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
                if (cells[k].x == i and cells[k].y == j)
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
    auto begin = std::chrono::steady_clock::now();
    while (exit_tick == 1)
    {
        Tick(cells);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Print(cells);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << time_span.count() << std::endl;
    return 0;
}