#include "../includes/mazeResolvers.hpp"
#include "../includes/mazeHandler.hpp"


MazeResolvers::Path::Path() {};
MazeResolvers::Path::Path(int32_t x, int32_t y): x(x), y(y) {};


std::vector<MazeResolvers::Path> MazeResolvers::BFS(MazeHandler& maze)
{
    const Maze_T mazeObj  = maze.getMaze();
    const uint16_t height = mazeObj.maze.size();
    const uint16_t width  = mazeObj.maze[0].size();
    const Path start = {mazeObj.start_x, mazeObj.start_y};
    const Path end   = {mazeObj.end_x, mazeObj.end_y};

    SET     visiteds (height, std::vector<bool>(width, false));
    PARENTS parent   (height, std::vector<Path>(width, {-1, -1}));
    QUEUE   queue;

    queue.push(start);
    visiteds[start.x][start.y] = true;

    while (!queue.empty()) {
        Path curr = queue.front();
        queue.pop();

        //if (curr.x == end.x && curr.y == end.y) break;
        if (mazeObj.maze[curr.x][curr.y] == 'E') break;

        for (auto d : delta) {
            const int32_t nx = curr.x + d.first;
            const int32_t ny = curr.y + d.second;

            if (maze.inbounds(nx, ny)) {
                const char cell = mazeObj.maze[nx][ny];
                if((cell == '.' || cell == ' ' || cell == 'E') && !visiteds[nx][ny]){
                    visiteds[nx][ny] = true;
                    parent[nx][ny] = curr;
                    const Path newcoord {nx, ny};
                    queue.push(newcoord);
                }
            }
        }
    }

    std::vector<Path> path;
    if (!visiteds[end.x][end.y]) return path;

    for (Path p = end; p.x != -1; p = parent[p.x][p.y])
        path.push_back(p);

    std::reverse(path.begin(), path.end());
    return path;
}