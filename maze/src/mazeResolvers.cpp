#include "../includes/mazeResolvers.hpp"
#include "../includes/mazeHandler.hpp"


MazeResolvers::COORDS MazeResolvers::BFS(const MazeHandler::Maze& maze){

    const MazeHandler::MazeObject mo = maze.getMaze();
    const MazeHandler::Coord start = mo.start;
    const MazeHandler::Coord end = mo.end;
    const uint16_t height = mo.maze.size();
    const uint16_t width  = mo.maze[0].size();


    SET     visiteds (height, std::vector<bool>(width, false));
    PARENTS parent   (height, COORDS(width, {-1, -1}));  
    QUEUE   queue;


    queue.push(start);
    visiteds[start.x][start.y] = true;

    while (!queue.empty()) {
        const MazeHandler::Coord curr = queue.front();
        queue.pop();

        //if (curr.x == end.x && curr.y == end.y) break;
        if (mo.maze[curr.x][curr.y] == 'E') break;

        for (auto d : delta) {
            const int32_t nx = curr.x + d.first;
            const int32_t ny = curr.y + d.second;

            if (maze.inBounds(nx, ny)) {
                const char cell = mo.maze[nx][ny];
                if((cell == '.' || cell == ' ' || cell == 'E') && !visiteds[nx][ny]){
                    visiteds[nx][ny] = true;
                    parent[nx][ny] = curr;
                    const MazeHandler::Coord newcoord {nx, ny};
                    queue.push(newcoord);
                }
            }
        }
    }

    std::vector<MazeHandler::Coord> path;
    if (!visiteds[end.x][end.y]) return path;

    for (MazeHandler::Coord p = end; p.x != -1; p = parent[p.x][p.y])
        path.push_back(p);

    std::reverse(path.begin(), path.end());
    return path;
}