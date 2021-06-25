// Level1: 완주하지 못한 선수
function solution(participant, completion) {
    participant.sort()
    completion.sort()
    completion.push(" ")
    for(let i = 0 ; i < completion.length; i++){
        if(completion[i] !== participant[i]) return participant[i]
    }
    
}