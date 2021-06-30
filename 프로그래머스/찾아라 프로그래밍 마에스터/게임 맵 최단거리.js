// 게임 맵 최단거리
function solution(maps) {
    let answer = 0;
    const dx = [0,0,1,-1], dy = [1,-1,0,0];
    let queue = [];
    const n = maps.length, m = maps[0].length;
    maps[0][0] = 2;
    queue.push([0,0]);
    while(queue.length > 0){
        let cur = queue.shift();
        for(let i = 0; i < 4; i++){
            const nx = cur[0] + dx[i], ny = cur[1] + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1){
                queue.push([nx,ny]);
                maps[nx][ny] = maps[cur[0]][cur[1]] + 1;
            }
        }
    }
    return maps[n-1][m-1] > 1 ? maps[n-1][m-1]-1 : -1;
}