#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>
#include <cstdlib>

#define PATH "./maze.txt"
#define TIME 150 // Delay em ms

struct Point {
    int x, y;
};

std::vector<Point> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Verifica se posição é válida
bool inBound(
    const std::vector<std::string>& maze,
    const std::vector<std::vector<bool>>& visiteds,
    int x, int y
) {
    return (0 <= x && x < (int)maze.size() &&
            0 <= y && y < (int)maze[0].size() &&
            maze[x][y] == '.' && !visiteds[x][y]);
}

// BFS para encontrar caminho
std::vector<Point> BFS(const std::vector<std::string>& maze, Point start, Point end) {
    int n = maze.size();
    int m = maze[0].size();

    std::vector<std::vector<bool>> visiteds(n, std::vector<bool>(m, false));
    std::vector<std::vector<Point>> parent(n, std::vector<Point>(m, {-1, -1}));

    std::queue<Point> q;
    q.push(start);
    visiteds[start.x][start.y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) break;

        for (auto d : delta) {
            int nx = curr.x + d.x;
            int ny = curr.y + d.y;

            if (inBound(maze, visiteds, nx, ny)) {
                visiteds[nx][ny] = true;
                parent[nx][ny] = curr;
                q.push({nx, ny});
            }
        }
    }

    std::vector<Point> path;
    if (!visiteds[end.x][end.y]) return path;

    for (Point p = end; p.x != -1; p = parent[p.x][p.y])
        path.push_back(p);

    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<std::string> loadMaze() {
    std::ifstream file(PATH);
    if (!file.is_open()) return {};

    std::string line;
    std::vector<std::string> maze;
    while (std::getline(file, line)) maze.push_back(line);

    file.close();
    return maze;
}

void clear_console() {
    system("cls");  // ou "clear" no Linux
}

void print_maze_state(const std::vector<std::string>& maze) {
    for (const std::string& line : maze)
        std::cout << line << "\n";
}

void animate_maze(std::vector<std::string>& maze, const std::vector<Point>& path) {
    for (size_t idx = 0; idx < path.size(); idx++) {
        Point curr = path[idx];
        maze[curr.x][curr.y] = '#';

        clear_console();
        print_maze_state(maze);
        Sleep(TIME);
    }
}

int main() {
    std::vector<std::string> maze = loadMaze();
    if (maze.empty()) {
        std::cerr << "Erro ao carregar labirinto\n";
        return 1;
    }

    Point start = {22, 2}; // Ajuste conforme seu arquivo
    Point end = {0, 71};

    std::vector<Point> path = BFS(maze, start, end);

    if (path.empty()) {
        std::cout << "Labirinto sem solução\n";
        return 0;
    }

    animate_maze(maze, path);

    return 0;
}
