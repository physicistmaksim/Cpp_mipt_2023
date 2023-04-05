#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#ifndef M
#define M 1
#endif
/*
1 - up
2 - left
3 - right
4 - down
*/
std::default_random_engine rng(100);

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

void MakeDirection(Cell (&cells)[M], int N)
{
    for (int i = 0; i < N; i++)
    {
        cells[i].direction = RandInt(1, 4);
    }
}

void MoveCells(Cell (&cells)[M], int &exit_tick, int N)
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

void Stop(Cell (&cells)[M], int X, int N)
{
    for (int k = 0; k < N; ++k)
    {
        if (!cells[k].stopped)
        {
            if ((cells[k].x == 0) or (cells[k].x == (X - 1)) or (cells[k].y == 0) or (cells[k].y == (X - 1)))
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

void Tick(Cell (&cells)[M], int &exit_tick, int X, int N, int &counter)
{
    exit_tick = 0;
    Stop(cells, X, N);
    MakeDirection(cells, N);
    MoveCells(cells, exit_tick, N);
    counter++;
}

int main()
{
    int X = 100;
    int exit_tick = 1;
    int N = 1;
    Cell cells[M];
    int step_counter = 0;
    while (X < 5000)
    {
        step_counter = 0;
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 100; ++i)
        {
            exit_tick = 1;
            cells[0].stopped = false;
            cells[0].x = X / 2;
            cells[0].y = X / 2;
            while (exit_tick == 1)
            {
                Tick(cells, exit_tick, X, N, step_counter);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << X << "," << (static_cast<float>(time_span.count()) / static_cast<float>(100)) << "," << (static_cast<float>(step_counter) / static_cast<float>(100)) << std::endl;
        X = X + 20;
    }
    return 0;
}